// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef _Vtop___024unit_H_
#define _Vtop___024unit_H_

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

class Vtop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop___024unit) {
  public:
    
    // PORTS
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vtop__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    Vtop___024unit& operator= (const Vtop___024unit&);  ///< Copying not allowed
    Vtop___024unit(const Vtop___024unit&);  ///< Copying not allowed
  public:
    Vtop___024unit(const char* name="TOP");
    ~Vtop___024unit();
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
