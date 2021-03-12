# Copyright 2017 Embecosm Limited <www.embecosm.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Makefile for Verilator model of RI5CY
# Contributor: Jeremy Bennett <jeremy.bennett@embecosm.com>

# Tools

VERILATOR = verilator
VDIR = obj_dir
CPPFLAGS = -I$(VDIR) `pkg-config --cflags verilator`
CXXFLAGS = -Wall -Werror -std=c++11 -faligned-new
CXX = g++
LD = g++

# Testbench

SRC = testbench.cpp

OBJS = testbench.o

EXE = testbench

# top module name

TOP = top

# Verilator elements

VSRC = cluster_clock_gating.sv            \
       dp_ram.sv                          \
       ram.sv                             \
       top.sv                             \
       ../rtl/include/apu_core_package.sv     \
       ../rtl/include/riscv_defines.sv        \
       ../rtl/include/riscv_tracer_defines.sv \
       ../rtl/register_file_test_wrap.sv      \
	   ../rtl/riscv_str_ops.sv				  \
       ../rtl/riscv_alu.sv                    \
       ../rtl/riscv_alu_basic.sv              \
       ../rtl/riscv_alu_div.sv                \
       ../rtl/riscv_compressed_decoder.sv     \
       ../rtl/riscv_controller.sv             \
       ../rtl/riscv_cs_registers.sv           \
       ../rtl/riscv_debug_unit.sv             \
       ../rtl/riscv_decoder.sv                \
       ../rtl/riscv_int_controller.sv         \
       ../rtl/riscv_ex_stage.sv               \
       ../rtl/riscv_hwloop_controller.sv      \
       ../rtl/riscv_hwloop_regs.sv            \
       ../rtl/riscv_id_stage.sv               \
       ../rtl/riscv_if_stage.sv               \
       ../rtl/riscv_load_store_unit.sv        \
       ../rtl/riscv_mult.sv                   \
       ../rtl/riscv_prefetch_buffer.sv        \
       ../rtl/riscv_prefetch_L0_buffer.sv     \
       ../rtl/riscv_register_file.sv          \
       ../rtl/riscv_core.sv                   \
       ../rtl/riscv_apu_disp.sv               \
       ../rtl/riscv_L0_buffer.sv              
#test_tag


VINC = ../rtl/include

VOBJS = $(VDIR)/verilated.o       \
        $(VDIR)/verilated_vcd_c.o

VLIB = $(VDIR)/V$(TOP)__ALL.a

VSMK = V$(TOP).mk
VMK  = $(VDIR)/$(VSMK)

.PHONY: all

all: $(EXE) examples.bin

# Build the executable

$(EXE): $(VLIB) $(VOBJS) $(OBJS)
	$(LD) -o $@ $(OBJS) $(VLIB) $(VOBJS)

$(VOBJS): $(VMK)
	for f in $@; \
	do \
		sf=$$(basename $$f); \
		$(MAKE) -C $(VDIR) -f $(VSMK) $$sf; \
	done

$(VLIB): $(VMK)
	make -C $(VDIR) -f V$(TOP).mk

$(VDIR)/$(TOP): $(VDIR) $(VMK)
	$(MAKE) -C $(VDIR) -f $(VSMK)

$(VDIR):
	mkdir -p $@

$(VMK): $(VSRC)
	verilator -O3 -CFLAGS "-O3 -g3 -std=gnu++11" \
                  -Wno-CASEINCOMPLETE -Wno-LITENDIAN -Wno-UNOPT \
	          -Wno-UNOPTFLAT -Wno-WIDTH -Wno-fatal --top-module top \
	          --Mdir $(VDIR) --trace -DPULP_FPGA_EMUL -cc \
	          +incdir+$(VINC) $(VSRC) $(SRC) --exe

examples.bin: examples.elf
	riscv32-unknown-elf-objcopy --dump-section .text=examples.bin examples.elf

examples.elf: examples.o examples.ld
	riscv32-unknown-elf-ld -T examples.ld examples.o -o examples.elf

examples.o: examples.s
	riscv32-unknown-elf-as -march=rv32im examples.s -o examples.o

#examples.o: examples.s
#	riscv32-unknown-elf-gcc -march=rv32imc examples.s -o examples.o


.PHONY: clean
clean:
	$(RM) -r $(VDIR)
	$(RM) $(EXE) $(OBJS)
