// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop_ram__A14.h"     // For This
#include "Vtop__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop_ram__A14) {
    VL_CELL (dp_ram_i, Vtop_dp_ram__A14);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_ram__A14::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop_ram__A14::~Vtop_ram__A14() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop_ram__A14::_combo__TOP__top__ram_i__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ram__A14::_combo__TOP__top__ram_i__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top__ram_i.__PVT__data_gnt_o = vlSymsp->TOP__top.__PVT__data_req;
    vlSymsp->TOP__top__ram_i.__PVT__instr_gnt_o = vlSymsp->TOP__top.__PVT__instr_req;
}

VL_INLINE_OPT void Vtop_ram__A14::_sequent__TOP__top__ram_i__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ram__A14::_sequent__TOP__top__ram_i__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ram.sv:78
    vlSymsp->TOP__top__ram_i.__PVT__instr_rvalid_o 
	= vlSymsp->TOP__top.__PVT__instr_req;
    // ALWAYS at ram.sv:78
    vlSymsp->TOP__top__ram_i.__PVT__data_rvalid_o = vlSymsp->TOP__top.__PVT__data_req;
}

void Vtop_ram__A14::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ram__A14::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__instr_req_i = VL_RAND_RESET_I(1);
    __PVT__instr_addr_i = VL_RAND_RESET_I(20);
    VL_RAND_RESET_W(128,__PVT__instr_rdata_o);
    __PVT__instr_rvalid_o = VL_RAND_RESET_I(1);
    __PVT__instr_gnt_o = VL_RAND_RESET_I(1);
    __PVT__data_req_i = VL_RAND_RESET_I(1);
    __PVT__data_addr_i = VL_RAND_RESET_I(20);
    __PVT__data_we_i = VL_RAND_RESET_I(1);
    __PVT__data_be_i = VL_RAND_RESET_I(4);
    __PVT__data_wdata_i = VL_RAND_RESET_I(32);
    __PVT__data_rdata_o = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128,__PVT__data_rdata_o_m128);
    __PVT__data_rvalid_o = VL_RAND_RESET_I(1);
    __PVT__data_gnt_o = VL_RAND_RESET_I(1);
}
