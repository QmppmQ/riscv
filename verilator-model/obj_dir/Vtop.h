// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

class Vtop__Syms;
class Vtop_top;
class VerilatedVcd;

//----------

VL_MODULE(Vtop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_top*          	top;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_i,0,0);
    VL_IN8(rstn_i,0,0);
    VL_IN8(irq_i,0,0);
    VL_IN8(irq_id_i,4,0);
    VL_OUT8(irq_ack_o,0,0);
    VL_OUT8(irq_id_o,4,0);
    VL_IN8(irq_sec_i,0,0);
    VL_OUT8(sec_lvl_o,0,0);
    VL_IN8(debug_req_i,0,0);
    VL_OUT8(debug_gnt_o,0,0);
    VL_OUT8(debug_rvalid_o,0,0);
    VL_IN8(debug_we_i,0,0);
    VL_OUT8(debug_halted_o,0,0);
    VL_IN8(fetch_enable_i,0,0);
    VL_OUT8(core_busy_o,0,0);
    VL_IN16(debug_addr_i,14,0);
    VL_IN(debug_wdata_i,31,0);
    VL_OUT(debug_rdata_o,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__VinpClk__TOP__top____PVT__u0__DOT__clk_,0,0);
    VL_SIG8(__Vclklast__TOP__clk_i,0,0);
    VL_SIG8(__Vclklast__TOP__rstn_i,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__top____PVT__u0__DOT__clk_,0,0);
    VL_SIG8(__Vchglast__TOP__top__debug_halted_o,0,0);
    VL_SIG8(__Vchglast__TOP__top__instr_req,0,0);
    VL_SIG8(__Vchglast__TOP__top__data_req,0,0);
    VL_SIG8(__Vchglast__TOP__top__u0__DOT__clk_,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__ex_ready,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_ex,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_wb,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__dbg_req,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__dbg_stall,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__if_valid,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__use_last,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__use_hwlp,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__valid,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__fetch_valid,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__id_stage_i__DOT__deassert_we,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__id_stage_i__DOT__jr_stall,0,0);
    VL_SIG8(__Vchglast__TOP__top__riscv_core_i__DOT__id_stage_i__DOT__load_stall,0,0);
    VL_SIGW(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes,159,0,5);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__str_op_result,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__mac_op_result,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__id_stage_i__DOT__imm_shuffle_type,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y0,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y1,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y2,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y3,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__ymax,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes,31,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a,16,0);
    VL_SIG(__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b,16,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vtop& operator= (const Vtop&);  ///< Copying not allowed
    Vtop(const Vtop&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__6(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__10(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__11(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__12(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__13(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__14(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__15(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__16(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__17(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__9(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
