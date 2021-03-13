// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef _Vtop_ram__A14_H_
#define _Vtop_ram__A14_H_

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

class Vtop__Syms;
class Vtop_dp_ram__A14;
class VerilatedVcd;

//----------

VL_MODULE(Vtop_ram__A14) {
  public:
    // CELLS
    Vtop_dp_ram__A14*  	dp_ram_i;
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__instr_req_i,0,0);
    VL_OUT8(__PVT__instr_rvalid_o,0,0);
    VL_OUT8(__PVT__instr_gnt_o,0,0);
    VL_IN8(__PVT__data_req_i,0,0);
    VL_IN8(__PVT__data_we_i,0,0);
    VL_IN8(__PVT__data_be_i,3,0);
    VL_OUT8(__PVT__data_rvalid_o,0,0);
    VL_OUT8(__PVT__data_gnt_o,0,0);
    VL_IN(__PVT__instr_addr_i,19,0);
    VL_OUTW(__PVT__instr_rdata_o,127,0,4);
    VL_IN(__PVT__data_addr_i,19,0);
    VL_IN(__PVT__data_wdata_i,31,0);
    VL_OUT(__PVT__data_rdata_o,31,0);
    VL_OUTW(__PVT__data_rdata_o_m128,127,0,4);
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vtop__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    Vtop_ram__A14& operator= (const Vtop_ram__A14&);  ///< Copying not allowed
    Vtop_ram__A14(const Vtop_ram__A14&);  ///< Copying not allowed
  public:
    Vtop_ram__A14(const char* name="TOP");
    ~Vtop_ram__A14();
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
    static void _combo__TOP__top__ram_i__1(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _sequent__TOP__top__ram_i__3(Vtop__Syms* __restrict vlSymsp);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
