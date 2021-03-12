// Copyright 2017 Embecosm Limited <www.embecosm.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Simple Verilator model test bench
// Contributor Jeremy Bennett <jeremy.bennett@embecosm.com>
// Contributor Graham Markall <graham.markall@embecosm.com>

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"
#include "Vtop__Syms.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdint>
#include <cstdlib>
#include <string>
//test_tag
//#include <stdio.h>
//test_tag

using std::cout;
using std::cerr;
using std::endl;

// Number of cycles to run for
const uint32_t CYCLES_TO_RUN_FOR = 30000;

// Count of clock ticks

static vluint64_t  cpuTime = 0;

// Debug registers

const uint16_t DBG_CTRL    = 0x0000;  //!< Debug control
const uint16_t DBG_HIT     = 0x0004;  //!< Debug hit
const uint16_t DBG_IE      = 0x0008;  //!< Debug interrupt enable
const uint16_t DBG_CAUSE   = 0x000c;  //!< Debug cause (why entered debug)
const uint16_t DBG_GPR0    = 0x0400;  //!< General purpose register 0
const uint16_t DBG_GPR31   = 0x047c;  //!< General purpose register 41
const uint16_t DBG_NPC     = 0x2000;  //!< Next PC
const uint16_t DBG_PPC     = 0x2004;  //!< Prev PC

// Debug register flags

const uint32_t DBG_CTRL_HALT = 0x00010000;    //!< Halt core
const uint32_t DBG_CTRL_SSTE = 0x00000001;    //!< Single step core

static uint64_t mCycleCnt = 0;

Vtop *cpu;
VerilatedVcdC * tfp;

// Clock the CPU for a given number of cycles, dumping to the trace file at
// each clock edge.
void clockSpin(uint32_t cycles)
{
  for (uint32_t i = 0; i < cycles; i++)
  {
      cpu->clk_i = 0;
      cpu->eval ();
      cpuTime += 5;
      tfp->dump (cpuTime);
      cpu->clk_i = 1;
      cpu->eval ();
      cpuTime += 5;
      tfp->dump (cpuTime);
      mCycleCnt++;
  }
}

// Read/write a debug register.
void debugAccess(uint32_t addr, uint32_t& val, bool write_enable)
{
  cpu->debug_req_i   = 1;
  cpu->debug_addr_i  = addr;
  cpu->debug_we_i    = write_enable ? 1 : 0;

  if (write_enable)
  {
    cpu->debug_wdata_i = val;
  }

  // Access has been acknowledged when we get the grant signal asserted.
  do
    {
      clockSpin(1);
    }
  while (cpu->debug_gnt_o == 0);

  // Don't need to request once we get the grant.
  cpu->debug_req_i = 0;

  if (!write_enable)
  {
    // For reads, we need to read the data when we get rvalid_o.
    // This could be on the same cycle as the grant, or later.
    while (cpu->debug_rvalid_o == 0)
    {
      clockSpin(1);
    }
    val = cpu->debug_rdata_o;
  }
}

// Read a debug register
uint32_t debugRead(uint32_t addr)
{
  uint32_t val;
  debugAccess(addr, val, false);
  return val;
}

// Write a debug register
void debugWrite(uint32_t addr, uint32_t val)
{
  debugAccess(addr, val, true);
}

// Cycle the clock until the debug unit reports that the CPU is halted.
void waitForDebugStall()
{
  // Assume that stall could happen at any point - we don't need to wait a cycle
  // to check if it's stalled before reading
  while (!(debugRead(DBG_CTRL) & DBG_CTRL_HALT))
  {
    clockSpin(1);
  }
}

// Single-step the CPU
void stepSingle ()
{
  cout << "DBG_CTRL  " << std::hex << debugRead(DBG_CTRL) << std::dec << endl;
  cout << "DBG_HIT   " << std::hex << debugRead(DBG_HIT) << std::dec << endl;
  cout << "DBG_CAUSE " << std::hex << debugRead(DBG_CAUSE) << std::dec << endl;
  cout << "DBG_NPC   " << std::hex << debugRead(DBG_NPC) << std::dec << endl;
  cout << "DBG_PPC   " << std::hex << debugRead(DBG_PPC) << std::dec << endl;

  cout << "About to do one single step" << endl;

  // Clear DBG_HIT
  debugWrite(DBG_HIT, 0);

  // Write SSTE into the debug register
  debugWrite(DBG_CTRL, DBG_CTRL_SSTE);

  // Wait until the step is completed
  waitForDebugStall();
}

// Execution begins at 0x80, so that's where we write our code.
uint32_t addr = 0x80;

// Write an instruction into memory at the current address.

void writeInst(uint32_t inst)
{
  cout << std::hex << std::setw(8) << std::setfill(' ') << addr << ": "
                   << std::setw(8) << std::setfill('0') << inst << endl << std::dec;

  cpu->top->ram_i->dp_ram_i->writeByte (addr + 0x0, (inst >>  0) & 0xFF);
  cpu->top->ram_i->dp_ram_i->writeByte (addr + 0x1, (inst >>  8) & 0xFF);
  cpu->top->ram_i->dp_ram_i->writeByte (addr + 0x2, (inst >> 16) & 0xFF);
  cpu->top->ram_i->dp_ram_i->writeByte (addr + 0x3, (inst >> 24) & 0xFF);

  addr += 4;
}

// Load a program from a file and write it to the core's memory.

void loadProgram(std::string fileName)
{
  cout << "Reading program from " << fileName << endl;

  // Read entire file.
  std::ifstream binary(fileName, std::ios::binary);

  if (!binary.is_open()) {
    cerr << "Error opening " << fileName << endl << endl;
    exit(EXIT_FAILURE);
  }

  std::vector<unsigned char> buf(std::istreambuf_iterator<char>(binary), {});

  // Check there is a multiple of 4 bytes (if not something went wrong and we
  // must have a partial instruction (or just complete rubbish) somewhere.
  if ((buf.size() % 4) != 0) {
    cerr << "Code size " << buf.size() << " is not a multiple of 4 bytes - exiting." << endl;
    exit(EXIT_FAILURE);
  }

  // Convert to words
  size_t nWords = buf.size() / 4;
  std::vector<uint32_t> code;
  for (size_t i = 0; i < nWords; ++i) {
    uint32_t word = 0;
    word |= buf[i*4 + 0] <<  0;
    word |= buf[i*4 + 1] <<  8;
    word |= buf[i*4 + 2] << 16;
    word |= buf[i*4 + 3] << 24;
    code.push_back(word);
  }

  cout << "Writing program to memory" << endl << endl;

  for (auto& inst: code)
    writeInst(inst);

  cout << endl;
}

int
main (int    argc,
      char * argv[])
{
  // Instantiate the model
  cpu = new Vtop;

  // Open VCD
  Verilated::traceEverOn (true);
  tfp = new VerilatedVcdC;
  cpu->trace (tfp, 99);
  tfp->open ("model.vcd");

  // Fix some signals for now.
  cpu->irq_i          = 0;
  cpu->debug_req_i    = 0;
  cpu->fetch_enable_i = 0;

  // Cycle through reset
  cpu->rstn_i = 0;
  clockSpin(5);
  cpu->rstn_i = 1;

  // Put instructions in memory from default file (or as specified)
  if (argc == 2)
    loadProgram(argv[1]);
  else if (argc > 2) {
    cerr << "Usage: ./testbench.cpp [test code]" << endl << endl;
    exit(EXIT_FAILURE);
  } else {
    loadProgram("examples.bin");
  }

  cout << "About to halt and set traps on exceptions" << endl;

  // Try to halt the CPU in the same way as in spi_debug_test.svh
  debugWrite(DBG_CTRL, debugRead(DBG_CTRL) | DBG_CTRL_HALT);

  // Let things run for a few cycles while the CPU waits in a halted state,
  // simply to check that doing so doesn't cause any errors.
  clockSpin(5);

  // Set traps on exceptions
  debugWrite(DBG_IE, 0xF);

  cout << "About to resume" << endl;

  uint32_t new_ctrl = debugRead(DBG_CTRL) & ~DBG_CTRL_HALT;
  debugWrite(DBG_CTRL, new_ctrl);

  cpu->fetch_enable_i = 1;

  cout << "Cycling clock to run for a few instructions" << endl;
  clockSpin(CYCLES_TO_RUN_FOR);

  cout << "Halting" << endl;

  debugWrite(DBG_CTRL, debugRead(DBG_CTRL) | DBG_CTRL_HALT);
  waitForDebugStall();

  // Close VCD

  tfp->close ();

  // Tidy up

  delete tfp;
  delete cpu;

}

//! Function to handle $time calls in the Verilog

double
sc_time_stamp ()
{
  return cpuTime;

}

// Local Variables:
// mode: C++
// c-file-style: "gnu"
// show-trailing-whitespace: t
// End:
