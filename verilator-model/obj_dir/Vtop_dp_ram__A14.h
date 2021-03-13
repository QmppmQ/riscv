// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef _Vtop_dp_ram__A14_H_
#define _Vtop_dp_ram__A14_H_

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

class Vtop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop_dp_ram__A14) {
  public:
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__en_a_i,0,0);
    VL_IN8(__PVT__we_a_i,0,0);
    VL_IN8(__PVT__be_a_i,3,0);
    VL_IN8(__PVT__en_b_i,0,0);
    VL_IN8(__PVT__we_b_i,0,0);
    VL_IN8(__PVT__be_b_i,3,0);
    VL_IN(__PVT__addr_a_i,19,0);
    VL_IN(__PVT__wdata_a_i,31,0);
    VL_OUTW(__PVT__rdata_a_o,127,0,4);
    VL_IN(__PVT__addr_b_i,19,0);
    VL_IN(__PVT__wdata_b_i,31,0);
    VL_OUT(__PVT__rdata_b_o,31,0);
    VL_OUTW(__PVT__rdata_c_o,127,0,4);
    
    // LOCAL SIGNALS
    VL_SIG8(__PVT__mem[1048576],7,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vtop__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    Vtop_dp_ram__A14& operator= (const Vtop_dp_ram__A14&);  ///< Copying not allowed
    Vtop_dp_ram__A14(const Vtop_dp_ram__A14&);  ///< Copying not allowed
  public:
    Vtop_dp_ram__A14(const char* name="TOP");
    ~Vtop_dp_ram__A14();
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void _sequent__TOP__top__ram_i__dp_ram_i__1(Vtop__Syms* __restrict vlSymsp);
    uint32_t readByte(uint32_t byte_addr);
    void writeByte(uint32_t byte_addr, uint32_t val);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
