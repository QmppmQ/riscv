// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+958,"clk_i",-1);
	vcdp->declBit  (c+959,"rstn_i",-1);
	vcdp->declBit  (c+960,"irq_i",-1);
	vcdp->declBus  (c+961,"irq_id_i",-1,4,0);
	vcdp->declBit  (c+962,"irq_ack_o",-1);
	vcdp->declBus  (c+963,"irq_id_o",-1,4,0);
	vcdp->declBit  (c+964,"irq_sec_i",-1);
	vcdp->declBit  (c+965,"sec_lvl_o",-1);
	vcdp->declBit  (c+966,"debug_req_i",-1);
	vcdp->declBit  (c+967,"debug_gnt_o",-1);
	vcdp->declBit  (c+968,"debug_rvalid_o",-1);
	vcdp->declBus  (c+969,"debug_addr_i",-1,14,0);
	vcdp->declBit  (c+970,"debug_we_i",-1);
	vcdp->declBus  (c+971,"debug_wdata_i",-1,31,0);
	vcdp->declBus  (c+972,"debug_rdata_o",-1,31,0);
	vcdp->declBit  (c+973,"debug_halted_o",-1);
	vcdp->declBit  (c+974,"fetch_enable_i",-1);
	vcdp->declBit  (c+975,"core_busy_o",-1);
	vcdp->declBus  (c+979,"top INSTR_RDATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+980,"top ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+981,"top BOOT_ADDR",-1,31,0);
	vcdp->declBit  (c+958,"top clk_i",-1);
	vcdp->declBit  (c+959,"top rstn_i",-1);
	vcdp->declBit  (c+960,"top irq_i",-1);
	vcdp->declBus  (c+961,"top irq_id_i",-1,4,0);
	vcdp->declBit  (c+15,"top irq_ack_o",-1);
	vcdp->declBus  (c+713,"top irq_id_o",-1,4,0);
	vcdp->declBit  (c+964,"top irq_sec_i",-1);
	vcdp->declBit  (c+714,"top sec_lvl_o",-1);
	vcdp->declBit  (c+966,"top debug_req_i",-1);
	vcdp->declBit  (c+16,"top debug_gnt_o",-1);
	vcdp->declBit  (c+715,"top debug_rvalid_o",-1);
	vcdp->declBus  (c+969,"top debug_addr_i",-1,14,0);
	vcdp->declBit  (c+970,"top debug_we_i",-1);
	vcdp->declBus  (c+971,"top debug_wdata_i",-1,31,0);
	vcdp->declBus  (c+17,"top debug_rdata_o",-1,31,0);
	vcdp->declBit  (c+18,"top debug_halted_o",-1);
	vcdp->declBit  (c+974,"top fetch_enable_i",-1);
	vcdp->declBit  (c+19,"top core_busy_o",-1);
	vcdp->declBit  (c+20,"top instr_req",-1);
	vcdp->declBit  (c+20,"top instr_gnt",-1);
	vcdp->declBit  (c+843,"top instr_rvalid",-1);
	vcdp->declBus  (c+21,"top instr_addr",-1,21,0);
	vcdp->declArray(c+844,"top instr_rdata",-1,127,0);
	{int i; for (i=0; i<16; i++) {
		vcdp->declBus  (c+22+i*1,"top con_data",(i+0),31,0);}}
	vcdp->declBit  (c+38,"top data_req",-1);
	vcdp->declBit  (c+38,"top data_gnt",-1);
	vcdp->declBit  (c+848,"top data_rvalid",-1);
	vcdp->declBus  (c+552,"top data_addr",-1,21,0);
	vcdp->declBit  (c+863,"top data_we",-1);
	vcdp->declBus  (c+595,"top data_be",-1,3,0);
	vcdp->declBus  (c+849,"top data_rdata",-1,31,0);
	vcdp->declBus  (c+556,"top data_wdata",-1,31,0);
	vcdp->declArray(c+982,"top con_data_o",-1,511,0);
	vcdp->declBit  (c+998,"top clk_o",-1);
	vcdp->declArray(c+39,"top y0",-1,67,0);
	vcdp->declArray(c+42,"top y1",-1,67,0);
	vcdp->declArray(c+45,"top y2",-1,67,0);
	vcdp->declArray(c+48,"top y3",-1,67,0);
	vcdp->declBit  (c+858,"top led",-1);
	vcdp->declBit  (c+859,"top cs",-1);
	vcdp->declBit  (c+716,"top mem_a1",-1);
	vcdp->declBit  (c+51,"top mac_flag",-1);
	vcdp->declBit  (c+850,"top con_cnt",-1);
	vcdp->declBit  (c+959,"top u0 reset",-1);
	vcdp->declBit  (c+958,"top u0 clk",-1);
	vcdp->declArray(c+39,"top u0 y1",-1,67,0);
	vcdp->declArray(c+42,"top u0 y2",-1,67,0);
	vcdp->declArray(c+45,"top u0 y3",-1,67,0);
	vcdp->declArray(c+48,"top u0 y4",-1,67,0);
	vcdp->declBus  (c+860,"top u0 led",-1,6,0);
	vcdp->declBus  (c+861,"top u0 cs",-1,7,0);
	vcdp->declBus  (c+862,"top u0 cnt",-1,2,0);
	vcdp->declBit  (c+717,"top u0 clk_",-1);
	vcdp->declBus  (c+52,"top u0 y1_l",-1,6,0);
	vcdp->declBus  (c+53,"top u0 y1_h",-1,6,0);
	vcdp->declBus  (c+54,"top u0 y2_l",-1,6,0);
	vcdp->declBus  (c+55,"top u0 y2_h",-1,6,0);
	vcdp->declBus  (c+56,"top u0 y3_l",-1,6,0);
	vcdp->declBus  (c+57,"top u0 y3_h",-1,6,0);
	vcdp->declBus  (c+58,"top u0 y4_l",-1,6,0);
	vcdp->declBus  (c+59,"top u0 y4_h",-1,6,0);
	vcdp->declBit  (c+958,"top u0 divider0 clk",-1);
	vcdp->declBit  (c+959,"top u0 divider0 reset",-1);
	vcdp->declBit  (c+717,"top u0 divider0 clk_out",-1);
	vcdp->declBus  (c+718,"top u0 divider0 cnt",-1,15,0);
	vcdp->declBus  (c+60,"top u0 u0 y_i",-1,3,0);
	vcdp->declBus  (c+52,"top u0 u0 y_o",-1,6,0);
	vcdp->declBus  (c+61,"top u0 u1 y_i",-1,3,0);
	vcdp->declBus  (c+53,"top u0 u1 y_o",-1,6,0);
	vcdp->declBus  (c+62,"top u0 u2 y_i",-1,3,0);
	vcdp->declBus  (c+54,"top u0 u2 y_o",-1,6,0);
	vcdp->declBus  (c+63,"top u0 u3 y_i",-1,3,0);
	vcdp->declBus  (c+55,"top u0 u3 y_o",-1,6,0);
	vcdp->declBus  (c+64,"top u0 u4 y_i",-1,3,0);
	vcdp->declBus  (c+56,"top u0 u4 y_o",-1,6,0);
	vcdp->declBus  (c+65,"top u0 u5 y_i",-1,3,0);
	vcdp->declBus  (c+57,"top u0 u5 y_o",-1,6,0);
	vcdp->declBus  (c+66,"top u0 u6 y_i",-1,3,0);
	vcdp->declBus  (c+58,"top u0 u6 y_o",-1,6,0);
	vcdp->declBus  (c+67,"top u0 u7 y_i",-1,3,0);
	vcdp->declBus  (c+59,"top u0 u7 y_o",-1,6,0);
	vcdp->declBus  (c+999,"top riscv_core_i N_EXT_PERF_COUNTERS",-1,31,0);
	vcdp->declBus  (c+979,"top riscv_core_i INSTR_RDATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i PULP_SECURE",-1,31,0);
	vcdp->declBus  (c+1000,"top riscv_core_i PULP_CLUSTER",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i FPU",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i SHARED_FP",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i SHARED_DSP_MULT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i SHARED_INT_DIV",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i SHARED_FP_DIVSQRT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i WAPUTYPE",-1,31,0);
	vcdp->declBus  (c+1001,"top riscv_core_i APU_NARGS_CPU",-1,31,0);
	vcdp->declBus  (c+1002,"top riscv_core_i APU_WOP_CPU",-1,31,0);
	vcdp->declBus  (c+1003,"top riscv_core_i APU_NDSFLAGS_CPU",-1,31,0);
	vcdp->declBus  (c+1004,"top riscv_core_i APU_NUSFLAGS_CPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i clk_i",-1);
	vcdp->declBit  (c+959,"top riscv_core_i rst_ni",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i clock_en_i",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i test_en_i",-1);
	vcdp->declBit  (c+1006,"top riscv_core_i fregfile_disable_i",-1);
	vcdp->declBus  (c+981,"top riscv_core_i boot_addr_i",-1,31,0);
	vcdp->declBus  (c+1007,"top riscv_core_i core_id_i",-1,3,0);
	vcdp->declBus  (c+1008,"top riscv_core_i cluster_id_i",-1,5,0);
	vcdp->declBit  (c+20,"top riscv_core_i instr_req_o",-1);
	vcdp->declBit  (c+20,"top riscv_core_i instr_gnt_i",-1);
	vcdp->declBit  (c+843,"top riscv_core_i instr_rvalid_i",-1);
	vcdp->declBus  (c+68,"top riscv_core_i instr_addr_o",-1,31,0);
	vcdp->declArray(c+844,"top riscv_core_i instr_rdata_i",-1,127,0);
	vcdp->declBit  (c+38,"top riscv_core_i data_req_o",-1);
	vcdp->declBit  (c+38,"top riscv_core_i data_gnt_i",-1);
	vcdp->declBit  (c+848,"top riscv_core_i data_rvalid_i",-1);
	vcdp->declBit  (c+863,"top riscv_core_i data_we_o",-1);
	vcdp->declBus  (c+595,"top riscv_core_i data_be_o",-1,3,0);
	vcdp->declBus  (c+553,"top riscv_core_i data_addr_o",-1,31,0);
	vcdp->declBus  (c+556,"top riscv_core_i data_wdata_o",-1,31,0);
	vcdp->declBus  (c+849,"top riscv_core_i data_rdata_i",-1,31,0);
	vcdp->declBit  (c+1009,"top riscv_core_i data_err_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i apu_master_req_o",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i apu_master_ready_o",-1);
	vcdp->declBit  (c+1010,"top riscv_core_i apu_master_gnt_i",-1);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+1+i*1,"top riscv_core_i apu_master_operands_o",(i+0),31,0);}}
	vcdp->declBus  (c+1008,"top riscv_core_i apu_master_op_o",-1,5,0);
	vcdp->declBus  (c+1011,"top riscv_core_i apu_master_type_o",-1,-1,0);
	vcdp->declBus  (c+1012,"top riscv_core_i apu_master_flags_o",-1,14,0);
	vcdp->declBit  (c+1013,"top riscv_core_i apu_master_valid_i",-1);
	vcdp->declBus  (c+1014,"top riscv_core_i apu_master_result_i",-1,31,0);
	vcdp->declBus  (c+1015,"top riscv_core_i apu_master_flags_i",-1,4,0);
	vcdp->declBit  (c+960,"top riscv_core_i irq_i",-1);
	vcdp->declBus  (c+961,"top riscv_core_i irq_id_i",-1,4,0);
	vcdp->declBit  (c+15,"top riscv_core_i irq_ack_o",-1);
	vcdp->declBus  (c+713,"top riscv_core_i irq_id_o",-1,4,0);
	vcdp->declBit  (c+964,"top riscv_core_i irq_sec_i",-1);
	vcdp->declBit  (c+714,"top riscv_core_i sec_lvl_o",-1);
	vcdp->declBit  (c+966,"top riscv_core_i debug_req_i",-1);
	vcdp->declBit  (c+16,"top riscv_core_i debug_gnt_o",-1);
	vcdp->declBit  (c+715,"top riscv_core_i debug_rvalid_o",-1);
	vcdp->declBus  (c+969,"top riscv_core_i debug_addr_i",-1,14,0);
	vcdp->declBit  (c+970,"top riscv_core_i debug_we_i",-1);
	vcdp->declBus  (c+971,"top riscv_core_i debug_wdata_i",-1,31,0);
	vcdp->declBus  (c+17,"top riscv_core_i debug_rdata_o",-1,31,0);
	vcdp->declBit  (c+18,"top riscv_core_i debug_halted_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i debug_halt_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i debug_resume_i",-1);
	vcdp->declBit  (c+974,"top riscv_core_i fetch_enable_i",-1);
	vcdp->declBit  (c+19,"top riscv_core_i core_busy_o",-1);
	vcdp->declBus  (c+1016,"top riscv_core_i ext_perf_counters_i",-1,-1,0);
	vcdp->declBus  (c+719,"top riscv_core_i mem_a1",-1,31,0);
	vcdp->declArray(c+39,"top riscv_core_i y0",-1,67,0);
	vcdp->declArray(c+42,"top riscv_core_i y1",-1,67,0);
	vcdp->declArray(c+45,"top riscv_core_i y2",-1,67,0);
	vcdp->declArray(c+48,"top riscv_core_i y3",-1,67,0);
	vcdp->declBit  (c+51,"top riscv_core_i mac_flag",-1);
	vcdp->declBus  (c+851,"top riscv_core_i con_cnt",-1,31,0);
	{int i; for (i=0; i<16; i++) {
		vcdp->declBus  (c+69+i*1,"top riscv_core_i con_data",(i+0),31,0);}}
	vcdp->declBus  (c+1017,"top riscv_core_i N_HWLP",-1,31,0);
	vcdp->declBus  (c+1000,"top riscv_core_i N_HWLP_BITS",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i APU",-1,31,0);
	vcdp->declBus  (c+85,"top riscv_core_i str_operator",-1,1,0);
	vcdp->declBit  (c+86,"top riscv_core_i str_op_en",-1);
	vcdp->declBus  (c+87,"top riscv_core_i str_op_result",-1,31,0);
	vcdp->declBus  (c+88,"top riscv_core_i str_operand",-1,31,0);
	vcdp->declBus  (c+89,"top riscv_core_i mac_operator",-1,2,0);
	vcdp->declBit  (c+90,"top riscv_core_i mac_op_en",-1);
	vcdp->declBus  (c+91,"top riscv_core_i mac_op_result",-1,31,0);
	vcdp->declBus  (c+92,"top riscv_core_i mac_operand1",-1,31,0);
	vcdp->declBus  (c+93,"top riscv_core_i mac_operand2",-1,31,0);
	vcdp->declBit  (c+94,"top riscv_core_i wb23_active",-1);
	vcdp->declBit  (c+536,"top riscv_core_i wb_finish",-1);
	vcdp->declBus  (c+95,"top riscv_core_i mem_wdata",-1,31,0);
	vcdp->declBit  (c+1018,"top riscv_core_i wb23_flag",-1);
	vcdp->declBit  (c+96,"top riscv_core_i con_active",-1);
	vcdp->declBit  (c+1019,"top riscv_core_i w_wb_active",-1);
	vcdp->declBit  (c+596,"top riscv_core_i is_hwlp_id",-1);
	vcdp->declBus  (c+864,"top riscv_core_i hwlp_dec_cnt_id",-1,1,0);
	vcdp->declBit  (c+865,"top riscv_core_i instr_valid_id",-1);
	vcdp->declBus  (c+866,"top riscv_core_i instr_rdata_id",-1,31,0);
	vcdp->declBit  (c+867,"top riscv_core_i is_compressed_id",-1);
	vcdp->declBit  (c+868,"top riscv_core_i illegal_c_insn_id",-1);
	vcdp->declBus  (c+869,"top riscv_core_i pc_if",-1,31,0);
	vcdp->declBus  (c+870,"top riscv_core_i pc_id",-1,31,0);
	vcdp->declBit  (c+97,"top riscv_core_i clear_instr_valid",-1);
	vcdp->declBit  (c+98,"top riscv_core_i pc_set",-1);
	vcdp->declBus  (c+99,"top riscv_core_i pc_mux_id",-1,2,0);
	vcdp->declBus  (c+100,"top riscv_core_i exc_pc_mux_id",-1,1,0);
	vcdp->declBus  (c+101,"top riscv_core_i exc_cause",-1,5,0);
	vcdp->declBit  (c+102,"top riscv_core_i trap_addr_mux",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i lsu_load_err",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i lsu_store_err",-1);
	vcdp->declBit  (c+103,"top riscv_core_i is_decoding",-1);
	vcdp->declBit  (c+871,"top riscv_core_i useincr_addr_ex",-1);
	vcdp->declBit  (c+597,"top riscv_core_i data_misaligned",-1);
	vcdp->declBit  (c+104,"top riscv_core_i mult_multicycle",-1);
	vcdp->declBus  (c+105,"top riscv_core_i jump_target_id",-1,31,0);
	vcdp->declBus  (c+872,"top riscv_core_i jump_target_ex",-1,31,0);
	vcdp->declBit  (c+873,"top riscv_core_i branch_in_ex",-1);
	vcdp->declBit  (c+598,"top riscv_core_i branch_decision",-1);
	vcdp->declBit  (c+106,"top riscv_core_i ctrl_busy",-1);
	vcdp->declBit  (c+107,"top riscv_core_i if_busy",-1);
	vcdp->declBit  (c+537,"top riscv_core_i lsu_busy",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i apu_busy",-1);
	vcdp->declBus  (c+874,"top riscv_core_i pc_ex",-1,31,0);
	vcdp->declBit  (c+875,"top riscv_core_i alu_en_ex",-1);
	vcdp->declBus  (c+876,"top riscv_core_i alu_operator_ex",-1,6,0);
	vcdp->declBus  (c+877,"top riscv_core_i alu_operand_a_ex",-1,31,0);
	vcdp->declBus  (c+878,"top riscv_core_i alu_operand_b_ex",-1,31,0);
	vcdp->declBus  (c+872,"top riscv_core_i alu_operand_c_ex",-1,31,0);
	vcdp->declBus  (c+879,"top riscv_core_i bmask_a_ex",-1,4,0);
	vcdp->declBus  (c+880,"top riscv_core_i bmask_b_ex",-1,4,0);
	vcdp->declBus  (c+881,"top riscv_core_i imm_vec_ext_ex",-1,1,0);
	vcdp->declBus  (c+882,"top riscv_core_i alu_vec_mode_ex",-1,1,0);
	vcdp->declBus  (c+883,"top riscv_core_i mult_operator_ex",-1,2,0);
	vcdp->declBus  (c+884,"top riscv_core_i mult_operand_a_ex",-1,31,0);
	vcdp->declBus  (c+885,"top riscv_core_i mult_operand_b_ex",-1,31,0);
	vcdp->declBus  (c+886,"top riscv_core_i mult_operand_c_ex",-1,31,0);
	vcdp->declBit  (c+887,"top riscv_core_i mult_en_ex",-1);
	vcdp->declBit  (c+888,"top riscv_core_i mult_sel_subword_ex",-1);
	vcdp->declBus  (c+889,"top riscv_core_i mult_signed_mode_ex",-1,1,0);
	vcdp->declBus  (c+890,"top riscv_core_i mult_imm_ex",-1,4,0);
	vcdp->declBus  (c+891,"top riscv_core_i mult_dot_op_a_ex",-1,31,0);
	vcdp->declBus  (c+892,"top riscv_core_i mult_dot_op_b_ex",-1,31,0);
	vcdp->declBus  (c+893,"top riscv_core_i mult_dot_op_c_ex",-1,31,0);
	vcdp->declBus  (c+894,"top riscv_core_i mult_dot_signed_ex",-1,1,0);
	vcdp->declBus  (c+895,"top riscv_core_i fpu_op_ex",-1,3,0);
	vcdp->declBus  (c+1020,"top riscv_core_i fprec_csr",-1,4,0);
	vcdp->declBus  (c+1021,"top riscv_core_i frm_csr",-1,2,0);
	vcdp->declBus  (c+1020,"top riscv_core_i fflags",-1,4,0);
	vcdp->declBus  (c+1020,"top riscv_core_i fflags_csr",-1,4,0);
	vcdp->declBit  (c+1009,"top riscv_core_i fflags_we",-1);
	vcdp->declBit  (c+896,"top riscv_core_i apu_en_ex",-1);
	vcdp->declBus  (c+897,"top riscv_core_i apu_type_ex",-1,-1,0);
	vcdp->declBus  (c+898,"top riscv_core_i apu_flags_ex",-1,14,0);
	vcdp->declBus  (c+899,"top riscv_core_i apu_op_ex",-1,5,0);
	vcdp->declBus  (c+900,"top riscv_core_i apu_lat_ex",-1,1,0);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+599+i*1,"top riscv_core_i apu_operands_ex",(i+0),31,0);}}
	vcdp->declBus  (c+901,"top riscv_core_i apu_waddr_ex",-1,5,0);
	vcdp->declBus  (c+1022,"top riscv_core_i apu_read_regs",-1,17,0);
	vcdp->declBus  (c+1021,"top riscv_core_i apu_read_regs_valid",-1,2,0);
	vcdp->declBit  (c+1009,"top riscv_core_i apu_read_dep",-1);
	vcdp->declBus  (c+1023,"top riscv_core_i apu_write_regs",-1,11,0);
	vcdp->declBus  (c+1011,"top riscv_core_i apu_write_regs_valid",-1,1,0);
	vcdp->declBit  (c+1009,"top riscv_core_i apu_write_dep",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i perf_apu_type",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i perf_apu_cont",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i perf_apu_dep",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i perf_apu_wb",-1);
	vcdp->declBus  (c+902,"top riscv_core_i regfile_waddr_ex",-1,5,0);
	vcdp->declBit  (c+903,"top riscv_core_i regfile_we_ex",-1);
	vcdp->declBus  (c+720,"top riscv_core_i regfile_waddr_fw_wb_o",-1,5,0);
	vcdp->declBit  (c+586,"top riscv_core_i regfile_we_wb",-1);
	vcdp->declBus  (c+602,"top riscv_core_i regfile_wdata",-1,31,0);
	vcdp->declBus  (c+904,"top riscv_core_i regfile_alu_waddr_ex",-1,5,0);
	vcdp->declBit  (c+905,"top riscv_core_i regfile_alu_we_ex",-1);
	vcdp->declBus  (c+904,"top riscv_core_i regfile_alu_waddr_fw",-1,5,0);
	vcdp->declBit  (c+603,"top riscv_core_i regfile_alu_we_fw",-1);
	vcdp->declBus  (c+108,"top riscv_core_i regfile_alu_wdata_fw",-1,31,0);
	vcdp->declBit  (c+906,"top riscv_core_i csr_access_ex",-1);
	vcdp->declBus  (c+907,"top riscv_core_i csr_op_ex",-1,1,0);
	vcdp->declBus  (c+1024,"top riscv_core_i mtvec",-1,23,0);
	vcdp->declBus  (c+1025,"top riscv_core_i utvec",-1,23,0);
	vcdp->declBit  (c+841,"top riscv_core_i csr_access",-1);
	vcdp->declBus  (c+109,"top riscv_core_i csr_op",-1,1,0);
	vcdp->declBus  (c+604,"top riscv_core_i csr_addr",-1,11,0);
	vcdp->declBus  (c+908,"top riscv_core_i csr_addr_int",-1,11,0);
	vcdp->declBus  (c+605,"top riscv_core_i csr_rdata",-1,31,0);
	vcdp->declBus  (c+606,"top riscv_core_i csr_wdata",-1,31,0);
	vcdp->declBus  (c+721,"top riscv_core_i current_priv_lvl",-1,1,0);
	vcdp->declBit  (c+863,"top riscv_core_i data_we_ex",-1);
	vcdp->declBus  (c+909,"top riscv_core_i data_type_ex",-1,1,0);
	vcdp->declBit  (c+910,"top riscv_core_i data_sign_ext_ex",-1);
	vcdp->declBus  (c+911,"top riscv_core_i data_reg_offset_ex",-1,1,0);
	vcdp->declBit  (c+912,"top riscv_core_i data_req_ex",-1);
	vcdp->declBit  (c+913,"top riscv_core_i data_load_event_ex",-1);
	vcdp->declBit  (c+914,"top riscv_core_i data_misaligned_ex",-1);
	vcdp->declBus  (c+602,"top riscv_core_i lsu_rdata",-1,31,0);
	vcdp->declBit  (c+110,"top riscv_core_i halt_if",-1);
	vcdp->declBit  (c+111,"top riscv_core_i id_ready",-1);
	vcdp->declBit  (c+112,"top riscv_core_i ex_ready",-1);
	vcdp->declBit  (c+113,"top riscv_core_i id_valid",-1);
	vcdp->declBit  (c+114,"top riscv_core_i ex_valid",-1);
	vcdp->declBit  (c+115,"top riscv_core_i wb_valid",-1);
	vcdp->declBit  (c+116,"top riscv_core_i lsu_ready_ex",-1);
	vcdp->declBit  (c+115,"top riscv_core_i lsu_ready_wb",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i apu_ready_wb",-1);
	vcdp->declBit  (c+117,"top riscv_core_i instr_req_int",-1);
	vcdp->declBit  (c+587,"top riscv_core_i m_irq_enable",-1);
	vcdp->declBit  (c+722,"top riscv_core_i u_irq_enable",-1);
	vcdp->declBit  (c+118,"top riscv_core_i csr_irq_sec",-1);
	vcdp->declBus  (c+119,"top riscv_core_i epc",-1,31,0);
	vcdp->declBit  (c+120,"top riscv_core_i csr_save_cause",-1);
	vcdp->declBit  (c+121,"top riscv_core_i csr_save_if",-1);
	vcdp->declBit  (c+122,"top riscv_core_i csr_save_id",-1);
	vcdp->declBus  (c+123,"top riscv_core_i csr_cause",-1,5,0);
	vcdp->declBit  (c+124,"top riscv_core_i csr_restore_mret_id",-1);
	vcdp->declBit  (c+125,"top riscv_core_i csr_restore_uret_id",-1);
	vcdp->declQuad (c+723,"top riscv_core_i hwlp_start",-1,63,0);
	vcdp->declQuad (c+725,"top riscv_core_i hwlp_end",-1,63,0);
	vcdp->declQuad (c+727,"top riscv_core_i hwlp_cnt",-1,63,0);
	vcdp->declBus  (c+126,"top riscv_core_i csr_hwlp_regid",-1,0,0);
	vcdp->declBus  (c+127,"top riscv_core_i csr_hwlp_we",-1,2,0);
	vcdp->declBus  (c+128,"top riscv_core_i csr_hwlp_data",-1,31,0);
	vcdp->declBus  (c+729,"top riscv_core_i dbg_settings",-1,5,0);
	vcdp->declBit  (c+129,"top riscv_core_i dbg_req",-1);
	vcdp->declBit  (c+130,"top riscv_core_i dbg_ack",-1);
	vcdp->declBit  (c+131,"top riscv_core_i dbg_stall",-1);
	vcdp->declBit  (c+132,"top riscv_core_i dbg_trap",-1);
	vcdp->declBit  (c+730,"top riscv_core_i dbg_reg_rreq",-1);
	vcdp->declBus  (c+731,"top riscv_core_i dbg_reg_raddr",-1,5,0);
	vcdp->declBus  (c+133,"top riscv_core_i dbg_reg_rdata",-1,31,0);
	vcdp->declBit  (c+134,"top riscv_core_i dbg_reg_wreq",-1);
	vcdp->declBus  (c+976,"top riscv_core_i dbg_reg_waddr",-1,5,0);
	vcdp->declBus  (c+971,"top riscv_core_i dbg_reg_wdata",-1,31,0);
	vcdp->declBit  (c+732,"top riscv_core_i dbg_csr_req",-1);
	vcdp->declBus  (c+733,"top riscv_core_i dbg_csr_addr",-1,11,0);
	vcdp->declBit  (c+135,"top riscv_core_i dbg_csr_we",-1);
	vcdp->declBus  (c+734,"top riscv_core_i dbg_csr_wdata",-1,31,0);
	vcdp->declBus  (c+734,"top riscv_core_i dbg_jump_addr",-1,31,0);
	vcdp->declBit  (c+735,"top riscv_core_i dbg_jump_req",-1);
	vcdp->declBit  (c+136,"top riscv_core_i perf_imiss",-1);
	vcdp->declBit  (c+137,"top riscv_core_i perf_jump",-1);
	vcdp->declBit  (c+138,"top riscv_core_i perf_jr_stall",-1);
	vcdp->declBit  (c+139,"top riscv_core_i perf_ld_stall",-1);
	vcdp->declBit  (c+140,"top riscv_core_i perf_pipeline_stall",-1);
	vcdp->declBit  (c+141,"top riscv_core_i core_ctrl_firstfetch",-1);
	vcdp->declBit  (c+543,"top riscv_core_i core_busy_int",-1);
	vcdp->declBit  (c+736,"top riscv_core_i core_busy_q",-1);
	vcdp->declBit  (c+142,"top riscv_core_i is_interrupt",-1);
	vcdp->declBit  (c+958,"top riscv_core_i clk",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i clock_en",-1);
	vcdp->declBit  (c+977,"top riscv_core_i dbg_busy",-1);
	vcdp->declBit  (c+143,"top riscv_core_i sleeping",-1);
	vcdp->declBit  (c+958,"top riscv_core_i core_clock_gate_i clk_i",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i core_clock_gate_i en_i",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i core_clock_gate_i test_en_i",-1);
	vcdp->declBit  (c+958,"top riscv_core_i core_clock_gate_i clk_o",-1);
	vcdp->declBus  (c+1017,"top riscv_core_i if_stage_i N_HWLP",-1,31,0);
	vcdp->declBus  (c+979,"top riscv_core_i if_stage_i RDATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i if_stage_i FPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i if_stage_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i if_stage_i rst_n",-1);
	vcdp->declBus  (c+1024,"top riscv_core_i if_stage_i m_trap_base_addr_i",-1,23,0);
	vcdp->declBus  (c+1025,"top riscv_core_i if_stage_i u_trap_base_addr_i",-1,23,0);
	vcdp->declBit  (c+102,"top riscv_core_i if_stage_i trap_addr_mux_i",-1);
	vcdp->declBus  (c+1024,"top riscv_core_i if_stage_i boot_addr_i",-1,23,0);
	vcdp->declBit  (c+117,"top riscv_core_i if_stage_i req_i",-1);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i instr_req_o",-1);
	vcdp->declBus  (c+68,"top riscv_core_i if_stage_i instr_addr_o",-1,31,0);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i instr_gnt_i",-1);
	vcdp->declBit  (c+843,"top riscv_core_i if_stage_i instr_rvalid_i",-1);
	vcdp->declArray(c+844,"top riscv_core_i if_stage_i instr_rdata_i",-1,127,0);
	vcdp->declBus  (c+864,"top riscv_core_i if_stage_i hwlp_dec_cnt_id_o",-1,1,0);
	vcdp->declBit  (c+596,"top riscv_core_i if_stage_i is_hwlp_id_o",-1);
	vcdp->declBit  (c+865,"top riscv_core_i if_stage_i instr_valid_id_o",-1);
	vcdp->declBus  (c+866,"top riscv_core_i if_stage_i instr_rdata_id_o",-1,31,0);
	vcdp->declBit  (c+867,"top riscv_core_i if_stage_i is_compressed_id_o",-1);
	vcdp->declBit  (c+868,"top riscv_core_i if_stage_i illegal_c_insn_id_o",-1);
	vcdp->declBus  (c+869,"top riscv_core_i if_stage_i pc_if_o",-1,31,0);
	vcdp->declBus  (c+870,"top riscv_core_i if_stage_i pc_id_o",-1,31,0);
	vcdp->declBit  (c+97,"top riscv_core_i if_stage_i clear_instr_valid_i",-1);
	vcdp->declBit  (c+98,"top riscv_core_i if_stage_i pc_set_i",-1);
	vcdp->declBus  (c+119,"top riscv_core_i if_stage_i exception_pc_reg_i",-1,31,0);
	vcdp->declBus  (c+99,"top riscv_core_i if_stage_i pc_mux_i",-1,2,0);
	vcdp->declBus  (c+100,"top riscv_core_i if_stage_i exc_pc_mux_i",-1,1,0);
	vcdp->declBus  (c+144,"top riscv_core_i if_stage_i exc_vec_pc_mux_i",-1,4,0);
	vcdp->declBus  (c+105,"top riscv_core_i if_stage_i jump_target_id_i",-1,31,0);
	vcdp->declBus  (c+872,"top riscv_core_i if_stage_i jump_target_ex_i",-1,31,0);
	vcdp->declQuad (c+723,"top riscv_core_i if_stage_i hwlp_start_i",-1,63,0);
	vcdp->declQuad (c+725,"top riscv_core_i if_stage_i hwlp_end_i",-1,63,0);
	vcdp->declQuad (c+727,"top riscv_core_i if_stage_i hwlp_cnt_i",-1,63,0);
	vcdp->declBus  (c+734,"top riscv_core_i if_stage_i dbg_jump_addr_i",-1,31,0);
	vcdp->declBit  (c+735,"top riscv_core_i if_stage_i dbg_jump_req_i",-1);
	vcdp->declBit  (c+110,"top riscv_core_i if_stage_i halt_if_i",-1);
	vcdp->declBit  (c+111,"top riscv_core_i if_stage_i id_ready_i",-1);
	vcdp->declBit  (c+107,"top riscv_core_i if_stage_i if_busy_o",-1);
	vcdp->declBit  (c+136,"top riscv_core_i if_stage_i perf_imiss_o",-1);
	vcdp->declBus  (c+737,"top riscv_core_i if_stage_i offset_fsm_cs",-1,0,0);
	vcdp->declBus  (c+145,"top riscv_core_i if_stage_i offset_fsm_ns",-1,0,0);
	vcdp->declBit  (c+146,"top riscv_core_i if_stage_i if_valid",-1);
	vcdp->declBit  (c+147,"top riscv_core_i if_stage_i if_ready",-1);
	vcdp->declBit  (c+148,"top riscv_core_i if_stage_i valid",-1);
	vcdp->declBit  (c+107,"top riscv_core_i if_stage_i prefetch_busy",-1);
	vcdp->declBit  (c+149,"top riscv_core_i if_stage_i branch_req",-1);
	vcdp->declBus  (c+150,"top riscv_core_i if_stage_i fetch_addr_n",-1,31,0);
	vcdp->declBit  (c+151,"top riscv_core_i if_stage_i fetch_valid",-1);
	vcdp->declBit  (c+152,"top riscv_core_i if_stage_i fetch_ready",-1);
	vcdp->declBus  (c+153,"top riscv_core_i if_stage_i fetch_rdata",-1,31,0);
	vcdp->declBus  (c+869,"top riscv_core_i if_stage_i fetch_addr",-1,31,0);
	vcdp->declBit  (c+915,"top riscv_core_i if_stage_i is_hwlp_id_q",-1);
	vcdp->declBit  (c+154,"top riscv_core_i if_stage_i fetch_is_hwlp",-1);
	vcdp->declBus  (c+155,"top riscv_core_i if_stage_i exc_pc",-1,31,0);
	vcdp->declBit  (c+607,"top riscv_core_i if_stage_i hwlp_jump",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i if_stage_i hwlp_branch",-1);
	vcdp->declBus  (c+608,"top riscv_core_i if_stage_i hwlp_target",-1,31,0);
	vcdp->declBus  (c+609,"top riscv_core_i if_stage_i hwlp_dec_cnt",-1,1,0);
	vcdp->declBus  (c+916,"top riscv_core_i if_stage_i hwlp_dec_cnt_if",-1,1,0);
	vcdp->declBus  (c+156,"top riscv_core_i if_stage_i trap_base_addr",-1,23,0);
	vcdp->declBus  (c+157,"top riscv_core_i if_stage_i instr_decompressed",-1,31,0);
	vcdp->declBit  (c+158,"top riscv_core_i if_stage_i illegal_c_insn",-1);
	vcdp->declBit  (c+159,"top riscv_core_i if_stage_i instr_compressed_int",-1);
	vcdp->declBus  (c+1017,"top riscv_core_i if_stage_i hwloop_controller_i N_REGS",-1,31,0);
	vcdp->declBus  (c+869,"top riscv_core_i if_stage_i hwloop_controller_i current_pc_i",-1,31,0);
	vcdp->declQuad (c+723,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_start_addr_i",-1,63,0);
	vcdp->declQuad (c+725,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_end_addr_i",-1,63,0);
	vcdp->declQuad (c+727,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_counter_i",-1,63,0);
	vcdp->declBus  (c+609,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_dec_cnt_o",-1,1,0);
	vcdp->declBus  (c+610,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_dec_cnt_id_i",-1,1,0);
	vcdp->declBit  (c+607,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_jump_o",-1);
	vcdp->declBus  (c+608,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_targ_addr_o",-1,31,0);
	vcdp->declBus  (c+611,"top riscv_core_i if_stage_i hwloop_controller_i pc_is_end_addr",-1,1,0);
	vcdp->declBus  (c+612,"top riscv_core_i if_stage_i hwloop_controller_i j",-1,31,0);
	// Tracing: top riscv_core_i if_stage_i hwloop_controller_i i // Ignored: Verilator trace_off at ../rtl/riscv_hwloop_controller.sv:57
	vcdp->declBus  (c+999,"top riscv_core_i if_stage_i compressed_decoder_i FPU",-1,31,0);
	vcdp->declBus  (c+153,"top riscv_core_i if_stage_i compressed_decoder_i instr_i",-1,31,0);
	vcdp->declBus  (c+157,"top riscv_core_i if_stage_i compressed_decoder_i instr_o",-1,31,0);
	vcdp->declBit  (c+159,"top riscv_core_i if_stage_i compressed_decoder_i is_compressed_o",-1);
	vcdp->declBit  (c+158,"top riscv_core_i if_stage_i compressed_decoder_i illegal_instr_o",-1);
	vcdp->declBus  (c+979,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i RDATA_IN_WIDTH",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i rst_n",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i req_i",-1);
	vcdp->declBit  (c+149,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i branch_i",-1);
	vcdp->declBus  (c+160,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_i",-1,31,0);
	vcdp->declBit  (c+607,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i hwloop_i",-1);
	vcdp->declBus  (c+608,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i hwloop_target_i",-1,31,0);
	vcdp->declBit  (c+152,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i ready_i",-1);
	vcdp->declBit  (c+151,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i valid_o",-1);
	vcdp->declBus  (c+153,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i rdata_o",-1,31,0);
	vcdp->declBus  (c+869,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_o",-1,31,0);
	vcdp->declBit  (c+154,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i is_hwlp_o",-1);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i instr_req_o",-1);
	vcdp->declBus  (c+68,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i instr_addr_o",-1,31,0);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i instr_gnt_i",-1);
	vcdp->declBit  (c+843,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i instr_rvalid_i",-1);
	vcdp->declArray(c+844,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i instr_rdata_i",-1,127,0);
	vcdp->declBit  (c+107,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i busy_o",-1);
	vcdp->declBit  (c+107,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i busy_L0",-1);
	vcdp->declBus  (c+917,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i CS",-1,3,0);
	vcdp->declBus  (c+161,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i NS",-1,3,0);
	vcdp->declBit  (c+162,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i do_fetch",-1);
	vcdp->declBit  (c+163,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i do_hwlp",-1);
	vcdp->declBit  (c+164,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i do_hwlp_int",-1);
	vcdp->declBit  (c+165,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i use_last",-1);
	vcdp->declBit  (c+166,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i save_rdata_last",-1);
	vcdp->declBit  (c+167,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i use_hwlp",-1);
	vcdp->declBit  (c+168,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i save_rdata_hwlp",-1);
	vcdp->declBit  (c+169,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i valid",-1);
	vcdp->declBit  (c+613,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i hwlp_is_crossword",-1);
	vcdp->declBit  (c+614,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i is_crossword",-1);
	vcdp->declBit  (c+170,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i next_is_crossword",-1);
	vcdp->declBit  (c+171,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i next_valid",-1);
	vcdp->declBit  (c+172,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i next_upper_compressed",-1);
	vcdp->declBit  (c+918,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i fetch_possible",-1);
	vcdp->declBit  (c+615,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i upper_is_compressed",-1);
	vcdp->declBus  (c+869,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_q",-1,31,0);
	vcdp->declBus  (c+173,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_n",-1,31,0);
	vcdp->declBus  (c+174,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_int",-1,31,0);
	vcdp->declBus  (c+919,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_aligned_next",-1,31,0);
	vcdp->declBus  (c+175,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_real_next",-1,31,0);
	vcdp->declBit  (c+920,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i is_hwlp_q",-1);
	vcdp->declBit  (c+176,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i is_hwlp_n",-1);
	vcdp->declBus  (c+921,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i rdata_last_q",-1,31,0);
	vcdp->declBit  (c+177,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i valid_L0",-1);
	vcdp->declArray(c+616,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i rdata_L0",-1,127,0);
	vcdp->declBus  (c+738,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i addr_L0",-1,31,0);
	vcdp->declBit  (c+178,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i fetch_valid",-1);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i fetch_gnt",-1);
	vcdp->declBus  (c+179,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i rdata",-1,31,0);
	vcdp->declBus  (c+557,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i rdata_unaligned",-1,31,0);
	vcdp->declBit  (c+180,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i aligned_is_compressed",-1);
	vcdp->declBit  (c+181,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i unaligned_is_compressed",-1);
	vcdp->declBit  (c+620,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i hwlp_aligned_is_compressed",-1);
	vcdp->declBit  (c+621,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i hwlp_unaligned_is_compressed",-1);
	vcdp->declBus  (c+979,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i RDATA_IN_WIDTH",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i rst_n",-1);
	vcdp->declBit  (c+162,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i prefetch_i",-1);
	vcdp->declBus  (c+175,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i prefetch_addr_i",-1,31,0);
	vcdp->declBit  (c+149,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i branch_i",-1);
	vcdp->declBus  (c+160,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i branch_addr_i",-1,31,0);
	vcdp->declBit  (c+182,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i hwlp_i",-1);
	vcdp->declBus  (c+608,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i hwlp_addr_i",-1,31,0);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i fetch_gnt_o",-1);
	vcdp->declBit  (c+178,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i fetch_valid_o",-1);
	vcdp->declBit  (c+177,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i valid_o",-1);
	vcdp->declArray(c+616,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i rdata_o",-1,127,0);
	vcdp->declBus  (c+738,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i addr_o",-1,31,0);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i instr_req_o",-1);
	vcdp->declBus  (c+68,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i instr_addr_o",-1,31,0);
	vcdp->declBit  (c+20,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i instr_gnt_i",-1);
	vcdp->declBit  (c+843,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i instr_rvalid_i",-1);
	vcdp->declArray(c+844,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i instr_rdata_i",-1,127,0);
	vcdp->declBit  (c+107,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i busy_o",-1);
	vcdp->declBus  (c+739,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i CS",-1,2,0);
	vcdp->declBus  (c+183,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i NS",-1,2,0);
	vcdp->declArray(c+740,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i L0_buffer",-1,127,0);
	vcdp->declBus  (c+738,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i addr_q",-1,31,0);
	vcdp->declBus  (c+184,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i instr_addr_int",-1,31,0);
	vcdp->declBit  (c+185,"top riscv_core_i if_stage_i genblk1 prefetch_128 prefetch_buffer_i L0_buffer_i valid",-1);
	vcdp->declBus  (c+1017,"top riscv_core_i id_stage_i N_HWLP",-1,31,0);
	vcdp->declBus  (c+1000,"top riscv_core_i id_stage_i N_HWLP_BITS",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i PULP_SECURE",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i FPU",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i APU",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i SHARED_FP",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i SHARED_DSP_MULT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i SHARED_INT_DIV",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i SHARED_FP_DIVSQRT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i WAPUTYPE",-1,31,0);
	vcdp->declBus  (c+1001,"top riscv_core_i id_stage_i APU_NARGS_CPU",-1,31,0);
	vcdp->declBus  (c+1002,"top riscv_core_i id_stage_i APU_WOP_CPU",-1,31,0);
	vcdp->declBus  (c+1003,"top riscv_core_i id_stage_i APU_NDSFLAGS_CPU",-1,31,0);
	vcdp->declBus  (c+1004,"top riscv_core_i id_stage_i APU_NUSFLAGS_CPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i id_stage_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i id_stage_i rst_n",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i id_stage_i test_en_i",-1);
	vcdp->declBit  (c+1006,"top riscv_core_i id_stage_i fregfile_disable_i",-1);
	vcdp->declBit  (c+974,"top riscv_core_i id_stage_i fetch_enable_i",-1);
	vcdp->declBit  (c+106,"top riscv_core_i id_stage_i ctrl_busy_o",-1);
	vcdp->declBit  (c+141,"top riscv_core_i id_stage_i core_ctrl_firstfetch_o",-1);
	vcdp->declBit  (c+103,"top riscv_core_i id_stage_i is_decoding_o",-1);
	vcdp->declBus  (c+864,"top riscv_core_i id_stage_i hwlp_dec_cnt_i",-1,1,0);
	vcdp->declBit  (c+596,"top riscv_core_i id_stage_i is_hwlp_i",-1);
	vcdp->declBit  (c+865,"top riscv_core_i id_stage_i instr_valid_i",-1);
	vcdp->declBus  (c+866,"top riscv_core_i id_stage_i instr_rdata_i",-1,31,0);
	vcdp->declBit  (c+117,"top riscv_core_i id_stage_i instr_req_o",-1);
	vcdp->declBit  (c+873,"top riscv_core_i id_stage_i branch_in_ex_o",-1);
	vcdp->declBit  (c+598,"top riscv_core_i id_stage_i branch_decision_i",-1);
	vcdp->declBus  (c+105,"top riscv_core_i id_stage_i jump_target_o",-1,31,0);
	vcdp->declBit  (c+97,"top riscv_core_i id_stage_i clear_instr_valid_o",-1);
	vcdp->declBit  (c+98,"top riscv_core_i id_stage_i pc_set_o",-1);
	vcdp->declBus  (c+99,"top riscv_core_i id_stage_i pc_mux_o",-1,2,0);
	vcdp->declBus  (c+100,"top riscv_core_i id_stage_i exc_pc_mux_o",-1,1,0);
	vcdp->declBit  (c+102,"top riscv_core_i id_stage_i trap_addr_mux_o",-1);
	vcdp->declBit  (c+868,"top riscv_core_i id_stage_i illegal_c_insn_i",-1);
	vcdp->declBit  (c+867,"top riscv_core_i id_stage_i is_compressed_i",-1);
	vcdp->declBus  (c+869,"top riscv_core_i id_stage_i pc_if_i",-1,31,0);
	vcdp->declBus  (c+870,"top riscv_core_i id_stage_i pc_id_i",-1,31,0);
	vcdp->declBit  (c+110,"top riscv_core_i id_stage_i halt_if_o",-1);
	vcdp->declBit  (c+111,"top riscv_core_i id_stage_i id_ready_o",-1);
	vcdp->declBit  (c+112,"top riscv_core_i id_stage_i ex_ready_i",-1);
	vcdp->declBit  (c+115,"top riscv_core_i id_stage_i wb_ready_i",-1);
	vcdp->declBit  (c+113,"top riscv_core_i id_stage_i id_valid_o",-1);
	vcdp->declBit  (c+114,"top riscv_core_i id_stage_i ex_valid_i",-1);
	vcdp->declBus  (c+874,"top riscv_core_i id_stage_i pc_ex_o",-1,31,0);
	vcdp->declBus  (c+877,"top riscv_core_i id_stage_i alu_operand_a_ex_o",-1,31,0);
	vcdp->declBus  (c+878,"top riscv_core_i id_stage_i alu_operand_b_ex_o",-1,31,0);
	vcdp->declBus  (c+872,"top riscv_core_i id_stage_i alu_operand_c_ex_o",-1,31,0);
	vcdp->declBus  (c+879,"top riscv_core_i id_stage_i bmask_a_ex_o",-1,4,0);
	vcdp->declBus  (c+880,"top riscv_core_i id_stage_i bmask_b_ex_o",-1,4,0);
	vcdp->declBus  (c+881,"top riscv_core_i id_stage_i imm_vec_ext_ex_o",-1,1,0);
	vcdp->declBus  (c+882,"top riscv_core_i id_stage_i alu_vec_mode_ex_o",-1,1,0);
	vcdp->declBus  (c+902,"top riscv_core_i id_stage_i regfile_waddr_ex_o",-1,5,0);
	vcdp->declBit  (c+903,"top riscv_core_i id_stage_i regfile_we_ex_o",-1);
	vcdp->declBus  (c+904,"top riscv_core_i id_stage_i regfile_alu_waddr_ex_o",-1,5,0);
	vcdp->declBit  (c+905,"top riscv_core_i id_stage_i regfile_alu_we_ex_o",-1);
	vcdp->declBus  (c+85,"top riscv_core_i id_stage_i str_operator_o",-1,1,0);
	vcdp->declBit  (c+86,"top riscv_core_i id_stage_i str_op_en_o",-1);
	vcdp->declBus  (c+88,"top riscv_core_i id_stage_i str_operand_ex_o",-1,31,0);
	vcdp->declBus  (c+89,"top riscv_core_i id_stage_i mac_operator_o",-1,2,0);
	vcdp->declBit  (c+90,"top riscv_core_i id_stage_i mac_op_en_o",-1);
	vcdp->declBus  (c+92,"top riscv_core_i id_stage_i mac_operand_ex_o1",-1,31,0);
	vcdp->declBus  (c+93,"top riscv_core_i id_stage_i mac_operand_ex_o2",-1,31,0);
	vcdp->declBit  (c+96,"top riscv_core_i id_stage_i con_active",-1);
	vcdp->declBit  (c+536,"top riscv_core_i id_stage_i wb_finish",-1);
	vcdp->declBus  (c+719,"top riscv_core_i id_stage_i mem_a1",-1,31,0);
	vcdp->declBit  (c+875,"top riscv_core_i id_stage_i alu_en_ex_o",-1);
	vcdp->declBus  (c+876,"top riscv_core_i id_stage_i alu_operator_ex_o",-1,6,0);
	vcdp->declBus  (c+883,"top riscv_core_i id_stage_i mult_operator_ex_o",-1,2,0);
	vcdp->declBus  (c+884,"top riscv_core_i id_stage_i mult_operand_a_ex_o",-1,31,0);
	vcdp->declBus  (c+885,"top riscv_core_i id_stage_i mult_operand_b_ex_o",-1,31,0);
	vcdp->declBus  (c+886,"top riscv_core_i id_stage_i mult_operand_c_ex_o",-1,31,0);
	vcdp->declBit  (c+887,"top riscv_core_i id_stage_i mult_en_ex_o",-1);
	vcdp->declBit  (c+888,"top riscv_core_i id_stage_i mult_sel_subword_ex_o",-1);
	vcdp->declBus  (c+889,"top riscv_core_i id_stage_i mult_signed_mode_ex_o",-1,1,0);
	vcdp->declBus  (c+890,"top riscv_core_i id_stage_i mult_imm_ex_o",-1,4,0);
	vcdp->declBus  (c+891,"top riscv_core_i id_stage_i mult_dot_op_a_ex_o",-1,31,0);
	vcdp->declBus  (c+892,"top riscv_core_i id_stage_i mult_dot_op_b_ex_o",-1,31,0);
	vcdp->declBus  (c+893,"top riscv_core_i id_stage_i mult_dot_op_c_ex_o",-1,31,0);
	vcdp->declBus  (c+894,"top riscv_core_i id_stage_i mult_dot_signed_ex_o",-1,1,0);
	vcdp->declBus  (c+895,"top riscv_core_i id_stage_i fpu_op_ex_o",-1,3,0);
	vcdp->declBit  (c+896,"top riscv_core_i id_stage_i apu_en_ex_o",-1);
	vcdp->declBus  (c+897,"top riscv_core_i id_stage_i apu_type_ex_o",-1,-1,0);
	vcdp->declBus  (c+899,"top riscv_core_i id_stage_i apu_op_ex_o",-1,5,0);
	vcdp->declBus  (c+900,"top riscv_core_i id_stage_i apu_lat_ex_o",-1,1,0);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+922+i*1,"top riscv_core_i id_stage_i apu_operands_ex_o",(i+0),31,0);}}
	vcdp->declBus  (c+898,"top riscv_core_i id_stage_i apu_flags_ex_o",-1,14,0);
	vcdp->declBus  (c+901,"top riscv_core_i id_stage_i apu_waddr_ex_o",-1,5,0);
	vcdp->declBus  (c+1022,"top riscv_core_i id_stage_i apu_read_regs_o",-1,17,0);
	vcdp->declBus  (c+1021,"top riscv_core_i id_stage_i apu_read_regs_valid_o",-1,2,0);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i apu_read_dep_i",-1);
	vcdp->declBus  (c+1023,"top riscv_core_i id_stage_i apu_write_regs_o",-1,11,0);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i apu_write_regs_valid_o",-1,1,0);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i apu_write_dep_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i apu_perf_dep_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i apu_busy_i",-1);
	vcdp->declBus  (c+1021,"top riscv_core_i id_stage_i frm_i",-1,2,0);
	vcdp->declBit  (c+906,"top riscv_core_i id_stage_i csr_access_ex_o",-1);
	vcdp->declBus  (c+907,"top riscv_core_i id_stage_i csr_op_ex_o",-1,1,0);
	vcdp->declBus  (c+721,"top riscv_core_i id_stage_i current_priv_lvl_i",-1,1,0);
	vcdp->declBit  (c+118,"top riscv_core_i id_stage_i csr_irq_sec_o",-1);
	vcdp->declBus  (c+123,"top riscv_core_i id_stage_i csr_cause_o",-1,5,0);
	vcdp->declBit  (c+121,"top riscv_core_i id_stage_i csr_save_if_o",-1);
	vcdp->declBit  (c+122,"top riscv_core_i id_stage_i csr_save_id_o",-1);
	vcdp->declBit  (c+124,"top riscv_core_i id_stage_i csr_restore_mret_id_o",-1);
	vcdp->declBit  (c+125,"top riscv_core_i id_stage_i csr_restore_uret_id_o",-1);
	vcdp->declBit  (c+120,"top riscv_core_i id_stage_i csr_save_cause_o",-1);
	vcdp->declQuad (c+723,"top riscv_core_i id_stage_i hwlp_start_o",-1,63,0);
	vcdp->declQuad (c+725,"top riscv_core_i id_stage_i hwlp_end_o",-1,63,0);
	vcdp->declQuad (c+727,"top riscv_core_i id_stage_i hwlp_cnt_o",-1,63,0);
	vcdp->declBus  (c+126,"top riscv_core_i id_stage_i csr_hwlp_regid_i",-1,0,0);
	vcdp->declBus  (c+127,"top riscv_core_i id_stage_i csr_hwlp_we_i",-1,2,0);
	vcdp->declBus  (c+128,"top riscv_core_i id_stage_i csr_hwlp_data_i",-1,31,0);
	vcdp->declBit  (c+912,"top riscv_core_i id_stage_i data_req_ex_o",-1);
	vcdp->declBit  (c+863,"top riscv_core_i id_stage_i data_we_ex_o",-1);
	vcdp->declBus  (c+909,"top riscv_core_i id_stage_i data_type_ex_o",-1,1,0);
	vcdp->declBit  (c+910,"top riscv_core_i id_stage_i data_sign_ext_ex_o",-1);
	vcdp->declBus  (c+911,"top riscv_core_i id_stage_i data_reg_offset_ex_o",-1,1,0);
	vcdp->declBit  (c+913,"top riscv_core_i id_stage_i data_load_event_ex_o",-1);
	vcdp->declBit  (c+914,"top riscv_core_i id_stage_i data_misaligned_ex_o",-1);
	vcdp->declBit  (c+871,"top riscv_core_i id_stage_i prepost_useincr_ex_o",-1);
	vcdp->declBit  (c+597,"top riscv_core_i id_stage_i data_misaligned_i",-1);
	vcdp->declBit  (c+960,"top riscv_core_i id_stage_i irq_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i irq_sec_i",-1);
	vcdp->declBus  (c+961,"top riscv_core_i id_stage_i irq_id_i",-1,4,0);
	vcdp->declBit  (c+587,"top riscv_core_i id_stage_i m_irq_enable_i",-1);
	vcdp->declBit  (c+722,"top riscv_core_i id_stage_i u_irq_enable_i",-1);
	vcdp->declBit  (c+15,"top riscv_core_i id_stage_i irq_ack_o",-1);
	vcdp->declBus  (c+713,"top riscv_core_i id_stage_i irq_id_o",-1,4,0);
	vcdp->declBus  (c+101,"top riscv_core_i id_stage_i exc_cause_o",-1,5,0);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i lsu_load_err_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i lsu_store_err_i",-1);
	vcdp->declBus  (c+729,"top riscv_core_i id_stage_i dbg_settings_i",-1,5,0);
	vcdp->declBit  (c+129,"top riscv_core_i id_stage_i dbg_req_i",-1);
	vcdp->declBit  (c+130,"top riscv_core_i id_stage_i dbg_ack_o",-1);
	vcdp->declBit  (c+131,"top riscv_core_i id_stage_i dbg_stall_i",-1);
	vcdp->declBit  (c+132,"top riscv_core_i id_stage_i dbg_trap_o",-1);
	vcdp->declBit  (c+730,"top riscv_core_i id_stage_i dbg_reg_rreq_i",-1);
	vcdp->declBus  (c+731,"top riscv_core_i id_stage_i dbg_reg_raddr_i",-1,5,0);
	vcdp->declBus  (c+133,"top riscv_core_i id_stage_i dbg_reg_rdata_o",-1,31,0);
	vcdp->declBit  (c+134,"top riscv_core_i id_stage_i dbg_reg_wreq_i",-1);
	vcdp->declBus  (c+976,"top riscv_core_i id_stage_i dbg_reg_waddr_i",-1,5,0);
	vcdp->declBus  (c+971,"top riscv_core_i id_stage_i dbg_reg_wdata_i",-1,31,0);
	vcdp->declBit  (c+735,"top riscv_core_i id_stage_i dbg_jump_req_i",-1);
	vcdp->declBus  (c+720,"top riscv_core_i id_stage_i regfile_waddr_wb_i",-1,5,0);
	vcdp->declBit  (c+586,"top riscv_core_i id_stage_i regfile_we_wb_i",-1);
	vcdp->declBus  (c+602,"top riscv_core_i id_stage_i regfile_wdata_wb_i",-1,31,0);
	vcdp->declBus  (c+904,"top riscv_core_i id_stage_i regfile_alu_waddr_fw_i",-1,5,0);
	vcdp->declBit  (c+603,"top riscv_core_i id_stage_i regfile_alu_we_fw_i",-1);
	vcdp->declBus  (c+108,"top riscv_core_i id_stage_i regfile_alu_wdata_fw_i",-1,31,0);
	vcdp->declBit  (c+104,"top riscv_core_i id_stage_i mult_multicycle_i",-1);
	vcdp->declBit  (c+137,"top riscv_core_i id_stage_i perf_jump_o",-1);
	vcdp->declBit  (c+138,"top riscv_core_i id_stage_i perf_jr_stall_o",-1);
	vcdp->declBit  (c+139,"top riscv_core_i id_stage_i perf_ld_stall_o",-1);
	vcdp->declBit  (c+140,"top riscv_core_i id_stage_i perf_pipeline_stall_o",-1);
	vcdp->declBus  (c+866,"top riscv_core_i id_stage_i instr",-1,31,0);
	vcdp->declBus  (c+85,"top riscv_core_i id_stage_i str_operator",-1,1,0);
	vcdp->declBit  (c+86,"top riscv_core_i id_stage_i str_op_en",-1);
	vcdp->declBus  (c+89,"top riscv_core_i id_stage_i mac_operator",-1,2,0);
	vcdp->declBit  (c+90,"top riscv_core_i id_stage_i mac_op_en",-1);
	vcdp->declBit  (c+186,"top riscv_core_i id_stage_i deassert_we",-1);
	vcdp->declBit  (c+187,"top riscv_core_i id_stage_i illegal_insn_dec",-1);
	vcdp->declBit  (c+188,"top riscv_core_i id_stage_i ebrk_insn",-1);
	vcdp->declBit  (c+189,"top riscv_core_i id_stage_i mret_insn_dec",-1);
	vcdp->declBit  (c+190,"top riscv_core_i id_stage_i uret_insn_dec",-1);
	vcdp->declBit  (c+191,"top riscv_core_i id_stage_i ecall_insn_dec",-1);
	vcdp->declBit  (c+192,"top riscv_core_i id_stage_i pipe_flush_dec",-1);
	vcdp->declBit  (c+193,"top riscv_core_i id_stage_i rega_used_dec",-1);
	vcdp->declBit  (c+194,"top riscv_core_i id_stage_i regb_used_dec",-1);
	vcdp->declBit  (c+195,"top riscv_core_i id_stage_i regc_used_dec",-1);
	vcdp->declBit  (c+622,"top riscv_core_i id_stage_i branch_taken_ex",-1);
	vcdp->declBus  (c+196,"top riscv_core_i id_stage_i jump_in_id",-1,1,0);
	vcdp->declBus  (c+197,"top riscv_core_i id_stage_i jump_in_dec",-1,1,0);
	vcdp->declBit  (c+597,"top riscv_core_i id_stage_i misaligned_stall",-1);
	vcdp->declBit  (c+138,"top riscv_core_i id_stage_i jr_stall",-1);
	vcdp->declBit  (c+139,"top riscv_core_i id_stage_i load_stall",-1);
	vcdp->declBit  (c+558,"top riscv_core_i id_stage_i csr_apu_stall",-1);
	vcdp->declBit  (c+198,"top riscv_core_i id_stage_i instr_multicycle",-1);
	vcdp->declBit  (c+199,"top riscv_core_i id_stage_i halt_id",-1);
	vcdp->declBus  (c+623,"top riscv_core_i id_stage_i imm_i_type",-1,31,0);
	vcdp->declBus  (c+925,"top riscv_core_i id_stage_i imm_iz_type",-1,31,0);
	vcdp->declBus  (c+926,"top riscv_core_i id_stage_i imm_s_type",-1,31,0);
	vcdp->declBus  (c+927,"top riscv_core_i id_stage_i imm_sb_type",-1,31,0);
	vcdp->declBus  (c+928,"top riscv_core_i id_stage_i imm_u_type",-1,31,0);
	vcdp->declBus  (c+929,"top riscv_core_i id_stage_i imm_uj_type",-1,31,0);
	vcdp->declBus  (c+930,"top riscv_core_i id_stage_i imm_z_type",-1,31,0);
	vcdp->declBus  (c+931,"top riscv_core_i id_stage_i imm_s2_type",-1,31,0);
	vcdp->declBus  (c+932,"top riscv_core_i id_stage_i imm_bi_type",-1,31,0);
	vcdp->declBus  (c+933,"top riscv_core_i id_stage_i imm_s3_type",-1,31,0);
	vcdp->declBus  (c+934,"top riscv_core_i id_stage_i imm_vs_type",-1,31,0);
	vcdp->declBus  (c+624,"top riscv_core_i id_stage_i imm_vu_type",-1,31,0);
	vcdp->declBus  (c+935,"top riscv_core_i id_stage_i imm_shuffleb_type",-1,31,0);
	vcdp->declBus  (c+936,"top riscv_core_i id_stage_i imm_shuffleh_type",-1,31,0);
	vcdp->declBus  (c+200,"top riscv_core_i id_stage_i imm_shuffle_type",-1,31,0);
	vcdp->declBus  (c+937,"top riscv_core_i id_stage_i imm_clip_type",-1,31,0);
	vcdp->declBus  (c+559,"top riscv_core_i id_stage_i imm_a",-1,31,0);
	vcdp->declBus  (c+560,"top riscv_core_i id_stage_i imm_b",-1,31,0);
	vcdp->declBus  (c+105,"top riscv_core_i id_stage_i jump_target",-1,31,0);
	vcdp->declBit  (c+744,"top riscv_core_i id_stage_i irq_req_ctrl",-1);
	vcdp->declBit  (c+745,"top riscv_core_i id_stage_i irq_sec_ctrl",-1);
	vcdp->declBus  (c+713,"top riscv_core_i id_stage_i irq_id_ctrl",-1,4,0);
	vcdp->declBit  (c+201,"top riscv_core_i id_stage_i exc_ack",-1);
	vcdp->declBit  (c+202,"top riscv_core_i id_stage_i exc_kill",-1);
	vcdp->declBus  (c+938,"top riscv_core_i id_stage_i regfile_addr_ra_id",-1,5,0);
	vcdp->declBus  (c+939,"top riscv_core_i id_stage_i regfile_addr_rb_id",-1,5,0);
	vcdp->declBus  (c+203,"top riscv_core_i id_stage_i regfile_addr_rc_id",-1,5,0);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i regfile_fp_a",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i regfile_fp_b",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i regfile_fp_c",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i regfile_fp_d",-1);
	vcdp->declBus  (c+940,"top riscv_core_i id_stage_i regfile_waddr_id",-1,5,0);
	vcdp->declBus  (c+940,"top riscv_core_i id_stage_i regfile_alu_waddr_id",-1,5,0);
	vcdp->declBit  (c+204,"top riscv_core_i id_stage_i regfile_alu_we_id",-1);
	vcdp->declBus  (c+625,"top riscv_core_i id_stage_i regfile_data_ra_id",-1,31,0);
	vcdp->declBus  (c+842,"top riscv_core_i id_stage_i regfile_data_rb_id",-1,31,0);
	vcdp->declBus  (c+133,"top riscv_core_i id_stage_i regfile_data_rc_id",-1,31,0);
	vcdp->declBit  (c+205,"top riscv_core_i id_stage_i alu_en",-1);
	vcdp->declBus  (c+206,"top riscv_core_i id_stage_i alu_operator",-1,6,0);
	vcdp->declBus  (c+207,"top riscv_core_i id_stage_i alu_op_a_mux_sel",-1,2,0);
	vcdp->declBus  (c+208,"top riscv_core_i id_stage_i alu_op_b_mux_sel",-1,2,0);
	vcdp->declBus  (c+209,"top riscv_core_i id_stage_i alu_op_c_mux_sel",-1,1,0);
	vcdp->declBus  (c+210,"top riscv_core_i id_stage_i regc_mux",-1,1,0);
	vcdp->declBus  (c+211,"top riscv_core_i id_stage_i imm_a_mux_sel",-1,0,0);
	vcdp->declBus  (c+212,"top riscv_core_i id_stage_i imm_b_mux_sel",-1,3,0);
	vcdp->declBus  (c+213,"top riscv_core_i id_stage_i jump_target_mux_sel",-1,1,0);
	vcdp->declBus  (c+214,"top riscv_core_i id_stage_i mult_operator",-1,2,0);
	vcdp->declBit  (c+215,"top riscv_core_i id_stage_i mult_en",-1);
	vcdp->declBit  (c+216,"top riscv_core_i id_stage_i mult_int_en",-1);
	vcdp->declBit  (c+217,"top riscv_core_i id_stage_i mult_sel_subword",-1);
	vcdp->declBus  (c+218,"top riscv_core_i id_stage_i mult_signed_mode",-1,1,0);
	vcdp->declBit  (c+219,"top riscv_core_i id_stage_i mult_dot_en",-1);
	vcdp->declBus  (c+220,"top riscv_core_i id_stage_i mult_dot_signed",-1,1,0);
	vcdp->declBus  (c+1007,"top riscv_core_i id_stage_i fpu_op",-1,3,0);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i apu_en",-1);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i apu_type",-1,-1,0);
	vcdp->declBus  (c+1008,"top riscv_core_i id_stage_i apu_op",-1,5,0);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i apu_lat",-1,1,0);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+4+i*1,"top riscv_core_i id_stage_i apu_operands",(i+0),31,0);}}
	vcdp->declBus  (c+1012,"top riscv_core_i id_stage_i apu_flags",-1,14,0);
	vcdp->declBus  (c+1008,"top riscv_core_i id_stage_i apu_waddr",-1,5,0);
	vcdp->declBus  (c+1026,"top riscv_core_i id_stage_i apu_read_regs",-1,17,0);
	vcdp->declBus  (c+1027,"top riscv_core_i id_stage_i apu_read_regs_valid",-1,2,0);
	vcdp->declBus  (c+1028,"top riscv_core_i id_stage_i apu_write_regs",-1,11,0);
	vcdp->declBus  (c+1029,"top riscv_core_i id_stage_i apu_write_regs_valid",-1,1,0);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i apu_flags_src",-1,-1,0);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i apu_stall",-1);
	vcdp->declBus  (c+1021,"top riscv_core_i id_stage_i fp_rnd_mode",-1,2,0);
	vcdp->declBit  (c+221,"top riscv_core_i id_stage_i regfile_we_id",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i id_stage_i regfile_alu_waddr_mux_sel",-1);
	vcdp->declBit  (c+222,"top riscv_core_i id_stage_i data_we_id",-1);
	vcdp->declBus  (c+223,"top riscv_core_i id_stage_i data_type_id",-1,1,0);
	vcdp->declBit  (c+224,"top riscv_core_i id_stage_i data_sign_ext_id",-1);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i data_reg_offset_id",-1,1,0);
	vcdp->declBit  (c+225,"top riscv_core_i id_stage_i data_req_id",-1);
	vcdp->declBit  (c+226,"top riscv_core_i id_stage_i data_load_event_id",-1);
	vcdp->declBus  (c+227,"top riscv_core_i id_stage_i hwloop_regid",-1,0,0);
	vcdp->declBus  (c+941,"top riscv_core_i id_stage_i hwloop_regid_int",-1,0,0);
	vcdp->declBus  (c+228,"top riscv_core_i id_stage_i hwloop_we",-1,2,0);
	vcdp->declBus  (c+229,"top riscv_core_i id_stage_i hwloop_we_int",-1,2,0);
	vcdp->declBit  (c+230,"top riscv_core_i id_stage_i hwloop_target_mux_sel",-1);
	vcdp->declBit  (c+231,"top riscv_core_i id_stage_i hwloop_start_mux_sel",-1);
	vcdp->declBit  (c+232,"top riscv_core_i id_stage_i hwloop_cnt_mux_sel",-1);
	vcdp->declBus  (c+233,"top riscv_core_i id_stage_i hwloop_target",-1,31,0);
	vcdp->declBus  (c+234,"top riscv_core_i id_stage_i hwloop_start",-1,31,0);
	vcdp->declBus  (c+235,"top riscv_core_i id_stage_i hwloop_start_int",-1,31,0);
	vcdp->declBus  (c+236,"top riscv_core_i id_stage_i hwloop_end",-1,31,0);
	vcdp->declBus  (c+237,"top riscv_core_i id_stage_i hwloop_cnt",-1,31,0);
	vcdp->declBus  (c+238,"top riscv_core_i id_stage_i hwloop_cnt_int",-1,31,0);
	vcdp->declBit  (c+239,"top riscv_core_i id_stage_i hwloop_valid",-1);
	vcdp->declBit  (c+240,"top riscv_core_i id_stage_i csr_access",-1);
	vcdp->declBus  (c+241,"top riscv_core_i id_stage_i csr_op",-1,1,0);
	vcdp->declBit  (c+242,"top riscv_core_i id_stage_i csr_status",-1);
	vcdp->declBit  (c+243,"top riscv_core_i id_stage_i prepost_useincr",-1);
	vcdp->declBus  (c+244,"top riscv_core_i id_stage_i operand_a_fw_mux_sel",-1,1,0);
	vcdp->declBus  (c+245,"top riscv_core_i id_stage_i operand_b_fw_mux_sel",-1,1,0);
	vcdp->declBus  (c+246,"top riscv_core_i id_stage_i operand_c_fw_mux_sel",-1,1,0);
	vcdp->declBus  (c+247,"top riscv_core_i id_stage_i operand_a_fw_id",-1,31,0);
	vcdp->declBus  (c+248,"top riscv_core_i id_stage_i operand_b_fw_id",-1,31,0);
	vcdp->declBus  (c+249,"top riscv_core_i id_stage_i operand_c_fw_id",-1,31,0);
	vcdp->declBus  (c+250,"top riscv_core_i id_stage_i operand_b",-1,31,0);
	vcdp->declBus  (c+251,"top riscv_core_i id_stage_i operand_b_vec",-1,31,0);
	vcdp->declBus  (c+252,"top riscv_core_i id_stage_i alu_operand_a",-1,31,0);
	vcdp->declBus  (c+253,"top riscv_core_i id_stage_i alu_operand_b",-1,31,0);
	vcdp->declBus  (c+254,"top riscv_core_i id_stage_i alu_operand_c",-1,31,0);
	vcdp->declBus  (c+255,"top riscv_core_i id_stage_i bmask_a_mux",-1,0,0);
	vcdp->declBus  (c+256,"top riscv_core_i id_stage_i bmask_b_mux",-1,1,0);
	vcdp->declBit  (c+257,"top riscv_core_i id_stage_i alu_bmask_a_mux_sel",-1);
	vcdp->declBit  (c+258,"top riscv_core_i id_stage_i alu_bmask_b_mux_sel",-1);
	vcdp->declBus  (c+259,"top riscv_core_i id_stage_i mult_imm_mux",-1,0,0);
	vcdp->declBus  (c+260,"top riscv_core_i id_stage_i bmask_a_id_imm",-1,4,0);
	vcdp->declBus  (c+261,"top riscv_core_i id_stage_i bmask_b_id_imm",-1,4,0);
	vcdp->declBus  (c+262,"top riscv_core_i id_stage_i bmask_a_id",-1,4,0);
	vcdp->declBus  (c+263,"top riscv_core_i id_stage_i bmask_b_id",-1,4,0);
	vcdp->declBus  (c+626,"top riscv_core_i id_stage_i imm_vec_ext_id",-1,1,0);
	vcdp->declBus  (c+561,"top riscv_core_i id_stage_i mult_imm_id",-1,4,0);
	vcdp->declBus  (c+264,"top riscv_core_i id_stage_i alu_vec_mode",-1,1,0);
	vcdp->declBit  (c+265,"top riscv_core_i id_stage_i scalar_replication",-1);
	vcdp->declBit  (c+266,"top riscv_core_i id_stage_i reg_d_ex_is_reg_a_id",-1);
	vcdp->declBit  (c+562,"top riscv_core_i id_stage_i reg_d_ex_is_reg_b_id",-1);
	vcdp->declBit  (c+563,"top riscv_core_i id_stage_i reg_d_ex_is_reg_c_id",-1);
	vcdp->declBit  (c+267,"top riscv_core_i id_stage_i reg_d_wb_is_reg_a_id",-1);
	vcdp->declBit  (c+544,"top riscv_core_i id_stage_i reg_d_wb_is_reg_b_id",-1);
	vcdp->declBit  (c+538,"top riscv_core_i id_stage_i reg_d_wb_is_reg_c_id",-1);
	vcdp->declBit  (c+268,"top riscv_core_i id_stage_i reg_d_alu_is_reg_a_id",-1);
	vcdp->declBit  (c+564,"top riscv_core_i id_stage_i reg_d_alu_is_reg_b_id",-1);
	vcdp->declBit  (c+565,"top riscv_core_i id_stage_i reg_d_alu_is_reg_c_id",-1);
	// Tracing: top riscv_core_i id_stage_i genblk1 apu_tie_off i // Ignored: Verilator trace_off at ../rtl/riscv_id_stage.sv:935
	vcdp->declBus  (c+1002,"top riscv_core_i id_stage_i registers_i ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+1030,"top riscv_core_i id_stage_i registers_i DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i registers_i FPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i id_stage_i registers_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i id_stage_i registers_i rst_n",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i id_stage_i registers_i test_en_i",-1);
	vcdp->declBit  (c+1006,"top riscv_core_i id_stage_i registers_i fregfile_disable_i",-1);
	vcdp->declBus  (c+938,"top riscv_core_i id_stage_i registers_i raddr_a_i",-1,5,0);
	vcdp->declBus  (c+625,"top riscv_core_i id_stage_i registers_i rdata_a_o",-1,31,0);
	vcdp->declBus  (c+939,"top riscv_core_i id_stage_i registers_i raddr_b_i",-1,5,0);
	vcdp->declBus  (c+842,"top riscv_core_i id_stage_i registers_i rdata_b_o",-1,31,0);
	vcdp->declBus  (c+539,"top riscv_core_i id_stage_i registers_i raddr_c_i",-1,5,0);
	vcdp->declBus  (c+133,"top riscv_core_i id_stage_i registers_i rdata_c_o",-1,31,0);
	vcdp->declBus  (c+720,"top riscv_core_i id_stage_i registers_i waddr_a_i",-1,5,0);
	vcdp->declBus  (c+602,"top riscv_core_i id_stage_i registers_i wdata_a_i",-1,31,0);
	vcdp->declBit  (c+586,"top riscv_core_i id_stage_i registers_i we_a_i",-1);
	vcdp->declBus  (c+978,"top riscv_core_i id_stage_i registers_i waddr_b_i",-1,5,0);
	vcdp->declBus  (c+269,"top riscv_core_i id_stage_i registers_i wdata_b_i",-1,31,0);
	vcdp->declBit  (c+566,"top riscv_core_i id_stage_i registers_i we_b_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i registers_i BIST",-1);
	vcdp->declBit  (c+1031,"top riscv_core_i id_stage_i registers_i CSN_T",-1);
	vcdp->declBit  (c+1032,"top riscv_core_i id_stage_i registers_i WEN_T",-1);
	vcdp->declBus  (c+1033,"top riscv_core_i id_stage_i registers_i A_T",-1,5,0);
	vcdp->declBus  (c+1034,"top riscv_core_i id_stage_i registers_i D_T",-1,31,0);
	vcdp->declBus  (c+625,"top riscv_core_i id_stage_i registers_i Q_T",-1,31,0);
	vcdp->declBus  (c+719,"top riscv_core_i id_stage_i registers_i mem_a1",-1,31,0);
	vcdp->declBus  (c+938,"top riscv_core_i id_stage_i registers_i ReadAddr_a_muxed",-1,5,0);
	vcdp->declBit  (c+586,"top riscv_core_i id_stage_i registers_i WriteEnable_a_muxed",-1);
	vcdp->declBus  (c+720,"top riscv_core_i id_stage_i registers_i WriteAddr_a_muxed",-1,5,0);
	vcdp->declBus  (c+602,"top riscv_core_i id_stage_i registers_i WriteData_a_muxed",-1,31,0);
	vcdp->declBit  (c+566,"top riscv_core_i id_stage_i registers_i WriteEnable_b_muxed",-1);
	vcdp->declBus  (c+978,"top riscv_core_i id_stage_i registers_i WriteAddr_b_muxed",-1,5,0);
	vcdp->declBus  (c+269,"top riscv_core_i id_stage_i registers_i WriteData_b_muxed",-1,31,0);
	vcdp->declBus  (c+746,"top riscv_core_i id_stage_i registers_i TestReadAddr_Q",-1,5,0);
	vcdp->declBus  (c+1002,"top riscv_core_i id_stage_i registers_i riscv_register_file_i ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+1030,"top riscv_core_i id_stage_i registers_i riscv_register_file_i DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i registers_i riscv_register_file_i FPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i id_stage_i registers_i riscv_register_file_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rst_n",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i id_stage_i registers_i riscv_register_file_i test_en_i",-1);
	vcdp->declBit  (c+1006,"top riscv_core_i id_stage_i registers_i riscv_register_file_i fregfile_disable_i",-1);
	vcdp->declBus  (c+938,"top riscv_core_i id_stage_i registers_i riscv_register_file_i raddr_a_i",-1,5,0);
	vcdp->declBus  (c+625,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rdata_a_o",-1,31,0);
	vcdp->declBus  (c+939,"top riscv_core_i id_stage_i registers_i riscv_register_file_i raddr_b_i",-1,5,0);
	vcdp->declBus  (c+842,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rdata_b_o",-1,31,0);
	vcdp->declBus  (c+539,"top riscv_core_i id_stage_i registers_i riscv_register_file_i raddr_c_i",-1,5,0);
	vcdp->declBus  (c+133,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rdata_c_o",-1,31,0);
	vcdp->declBus  (c+720,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_a_i",-1,5,0);
	vcdp->declBus  (c+602,"top riscv_core_i id_stage_i registers_i riscv_register_file_i wdata_a_i",-1,31,0);
	vcdp->declBit  (c+586,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_a_i",-1);
	vcdp->declBus  (c+978,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_b_i",-1,5,0);
	vcdp->declBus  (c+269,"top riscv_core_i id_stage_i registers_i riscv_register_file_i wdata_b_i",-1,31,0);
	vcdp->declBit  (c+566,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_b_i",-1);
	vcdp->declBus  (c+719,"top riscv_core_i id_stage_i registers_i riscv_register_file_i mem_a1",-1,31,0);
	vcdp->declBus  (c+1030,"top riscv_core_i id_stage_i registers_i riscv_register_file_i NUM_WORDS",-1,31,0);
	vcdp->declBus  (c+1030,"top riscv_core_i id_stage_i registers_i riscv_register_file_i NUM_FP_WORDS",-1,31,0);
	vcdp->declBus  (c+1030,"top riscv_core_i id_stage_i registers_i riscv_register_file_i NUM_TOT_WORDS",-1,31,0);
	vcdp->declArray(c+747,"top riscv_core_i id_stage_i registers_i riscv_register_file_i mem",-1,1023,0);
	vcdp->declArray(c+1035,"top riscv_core_i id_stage_i registers_i riscv_register_file_i mem_fp",-1,1023,0);
	vcdp->declBit  (c+1005,"top riscv_core_i id_stage_i registers_i riscv_register_file_i fregfile_ena",-1);
	vcdp->declBus  (c+720,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_a",-1,5,0);
	vcdp->declBus  (c+978,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_b",-1,5,0);
	vcdp->declBus  (c+588,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_a_dec",-1,31,0);
	vcdp->declBus  (c+270,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_b_dec",-1,31,0);
	// Tracing: top riscv_core_i id_stage_i registers_i riscv_register_file_i i // Ignored: Verilator trace_off at ../rtl/riscv_register_file.sv:143
	// Tracing: top riscv_core_i id_stage_i registers_i riscv_register_file_i l // Ignored: Verilator trace_off at ../rtl/riscv_register_file.sv:143
	vcdp->declBus  (c+1067,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_a_decoder unnamedblk1 i",-1,31,0);
	vcdp->declBus  (c+1067,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_b_decoder unnamedblk2 i",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i FPU",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i PULP_SECURE",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i SHARED_FP",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i SHARED_DSP_MULT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i SHARED_INT_DIV",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i SHARED_FP_DIVSQRT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i WAPUTYPE",-1,31,0);
	vcdp->declBus  (c+1002,"top riscv_core_i id_stage_i decoder_i APU_WOP_CPU",-1,31,0);
	vcdp->declBit  (c+186,"top riscv_core_i id_stage_i decoder_i deassert_we_i",-1);
	vcdp->declBit  (c+597,"top riscv_core_i id_stage_i decoder_i data_misaligned_i",-1);
	vcdp->declBit  (c+104,"top riscv_core_i id_stage_i decoder_i mult_multicycle_i",-1);
	vcdp->declBit  (c+198,"top riscv_core_i id_stage_i decoder_i instr_multicycle_o",-1);
	vcdp->declBit  (c+187,"top riscv_core_i id_stage_i decoder_i illegal_insn_o",-1);
	vcdp->declBit  (c+188,"top riscv_core_i id_stage_i decoder_i ebrk_insn_o",-1);
	vcdp->declBit  (c+189,"top riscv_core_i id_stage_i decoder_i mret_insn_o",-1);
	vcdp->declBit  (c+190,"top riscv_core_i id_stage_i decoder_i uret_insn_o",-1);
	vcdp->declBit  (c+191,"top riscv_core_i id_stage_i decoder_i ecall_insn_o",-1);
	vcdp->declBit  (c+192,"top riscv_core_i id_stage_i decoder_i pipe_flush_o",-1);
	vcdp->declBit  (c+193,"top riscv_core_i id_stage_i decoder_i rega_used_o",-1);
	vcdp->declBit  (c+194,"top riscv_core_i id_stage_i decoder_i regb_used_o",-1);
	vcdp->declBit  (c+195,"top riscv_core_i id_stage_i decoder_i regc_used_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i decoder_i reg_fp_a_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i decoder_i reg_fp_b_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i decoder_i reg_fp_c_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i decoder_i reg_fp_d_o",-1);
	vcdp->declBus  (c+255,"top riscv_core_i id_stage_i decoder_i bmask_a_mux_o",-1,0,0);
	vcdp->declBus  (c+256,"top riscv_core_i id_stage_i decoder_i bmask_b_mux_o",-1,1,0);
	vcdp->declBit  (c+257,"top riscv_core_i id_stage_i decoder_i alu_bmask_a_mux_sel_o",-1);
	vcdp->declBit  (c+258,"top riscv_core_i id_stage_i decoder_i alu_bmask_b_mux_sel_o",-1);
	vcdp->declBus  (c+866,"top riscv_core_i id_stage_i decoder_i instr_rdata_i",-1,31,0);
	vcdp->declBit  (c+868,"top riscv_core_i id_stage_i decoder_i illegal_c_insn_i",-1);
	vcdp->declBit  (c+205,"top riscv_core_i id_stage_i decoder_i alu_en_o",-1);
	vcdp->declBus  (c+206,"top riscv_core_i id_stage_i decoder_i alu_operator_o",-1,6,0);
	vcdp->declBus  (c+207,"top riscv_core_i id_stage_i decoder_i alu_op_a_mux_sel_o",-1,2,0);
	vcdp->declBus  (c+208,"top riscv_core_i id_stage_i decoder_i alu_op_b_mux_sel_o",-1,2,0);
	vcdp->declBus  (c+209,"top riscv_core_i id_stage_i decoder_i alu_op_c_mux_sel_o",-1,1,0);
	vcdp->declBus  (c+264,"top riscv_core_i id_stage_i decoder_i alu_vec_mode_o",-1,1,0);
	vcdp->declBit  (c+265,"top riscv_core_i id_stage_i decoder_i scalar_replication_o",-1);
	vcdp->declBus  (c+211,"top riscv_core_i id_stage_i decoder_i imm_a_mux_sel_o",-1,0,0);
	vcdp->declBus  (c+212,"top riscv_core_i id_stage_i decoder_i imm_b_mux_sel_o",-1,3,0);
	vcdp->declBus  (c+210,"top riscv_core_i id_stage_i decoder_i regc_mux_o",-1,1,0);
	vcdp->declBus  (c+214,"top riscv_core_i id_stage_i decoder_i mult_operator_o",-1,2,0);
	vcdp->declBit  (c+216,"top riscv_core_i id_stage_i decoder_i mult_int_en_o",-1);
	vcdp->declBit  (c+219,"top riscv_core_i id_stage_i decoder_i mult_dot_en_o",-1);
	vcdp->declBus  (c+259,"top riscv_core_i id_stage_i decoder_i mult_imm_mux_o",-1,0,0);
	vcdp->declBit  (c+217,"top riscv_core_i id_stage_i decoder_i mult_sel_subword_o",-1);
	vcdp->declBus  (c+218,"top riscv_core_i id_stage_i decoder_i mult_signed_mode_o",-1,1,0);
	vcdp->declBus  (c+220,"top riscv_core_i id_stage_i decoder_i mult_dot_signed_o",-1,1,0);
	vcdp->declBus  (c+1007,"top riscv_core_i id_stage_i decoder_i fpu_op_o",-1,3,0);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i decoder_i apu_en_o",-1);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i decoder_i apu_type_o",-1,-1,0);
	vcdp->declBus  (c+1008,"top riscv_core_i id_stage_i decoder_i apu_op_o",-1,5,0);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i decoder_i apu_lat_o",-1,1,0);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i decoder_i apu_flags_src_o",-1,-1,0);
	vcdp->declBus  (c+1021,"top riscv_core_i id_stage_i decoder_i fp_rnd_mode_o",-1,2,0);
	vcdp->declBit  (c+221,"top riscv_core_i id_stage_i decoder_i regfile_mem_we_o",-1);
	vcdp->declBit  (c+204,"top riscv_core_i id_stage_i decoder_i regfile_alu_we_o",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i id_stage_i decoder_i regfile_alu_waddr_sel_o",-1);
	vcdp->declBit  (c+240,"top riscv_core_i id_stage_i decoder_i csr_access_o",-1);
	vcdp->declBit  (c+242,"top riscv_core_i id_stage_i decoder_i csr_status_o",-1);
	vcdp->declBus  (c+241,"top riscv_core_i id_stage_i decoder_i csr_op_o",-1,1,0);
	vcdp->declBus  (c+721,"top riscv_core_i id_stage_i decoder_i current_priv_lvl_i",-1,1,0);
	vcdp->declBit  (c+225,"top riscv_core_i id_stage_i decoder_i data_req_o",-1);
	vcdp->declBit  (c+222,"top riscv_core_i id_stage_i decoder_i data_we_o",-1);
	vcdp->declBit  (c+243,"top riscv_core_i id_stage_i decoder_i prepost_useincr_o",-1);
	vcdp->declBus  (c+223,"top riscv_core_i id_stage_i decoder_i data_type_o",-1,1,0);
	vcdp->declBit  (c+224,"top riscv_core_i id_stage_i decoder_i data_sign_extension_o",-1);
	vcdp->declBus  (c+1011,"top riscv_core_i id_stage_i decoder_i data_reg_offset_o",-1,1,0);
	vcdp->declBit  (c+226,"top riscv_core_i id_stage_i decoder_i data_load_event_o",-1);
	vcdp->declBus  (c+229,"top riscv_core_i id_stage_i decoder_i hwloop_we_o",-1,2,0);
	vcdp->declBit  (c+230,"top riscv_core_i id_stage_i decoder_i hwloop_target_mux_sel_o",-1);
	vcdp->declBit  (c+231,"top riscv_core_i id_stage_i decoder_i hwloop_start_mux_sel_o",-1);
	vcdp->declBit  (c+232,"top riscv_core_i id_stage_i decoder_i hwloop_cnt_mux_sel_o",-1);
	vcdp->declBus  (c+197,"top riscv_core_i id_stage_i decoder_i jump_in_dec_o",-1,1,0);
	vcdp->declBus  (c+196,"top riscv_core_i id_stage_i decoder_i jump_in_id_o",-1,1,0);
	vcdp->declBus  (c+213,"top riscv_core_i id_stage_i decoder_i jump_target_mux_sel_o",-1,1,0);
	vcdp->declBus  (c+85,"top riscv_core_i id_stage_i decoder_i str_operator_o",-1,1,0);
	vcdp->declBit  (c+86,"top riscv_core_i id_stage_i decoder_i str_op_en_o",-1);
	vcdp->declBus  (c+89,"top riscv_core_i id_stage_i decoder_i mac_operator_o",-1,2,0);
	vcdp->declBit  (c+90,"top riscv_core_i id_stage_i decoder_i mac_op_en_o",-1);
	vcdp->declBit  (c+96,"top riscv_core_i id_stage_i decoder_i con_active",-1);
	vcdp->declBit  (c+958,"top riscv_core_i id_stage_i decoder_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i id_stage_i decoder_i rst_n",-1);
	vcdp->declBit  (c+536,"top riscv_core_i id_stage_i decoder_i wb_finish",-1);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_FP",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_DSP_MULT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_INT_MULT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_INT_DIV",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_ADDSUB",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_MULT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_CAST",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_MAC",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_DIV",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_SQRT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i decoder_i APUTYPE_DIVSQRT",-1,31,0);
	vcdp->declBit  (c+271,"top riscv_core_i id_stage_i decoder_i regfile_mem_we",-1);
	vcdp->declBit  (c+272,"top riscv_core_i id_stage_i decoder_i regfile_alu_we",-1);
	vcdp->declBit  (c+273,"top riscv_core_i id_stage_i decoder_i data_req",-1);
	vcdp->declBus  (c+274,"top riscv_core_i id_stage_i decoder_i hwloop_we",-1,2,0);
	vcdp->declBit  (c+275,"top riscv_core_i id_stage_i decoder_i csr_illegal",-1);
	vcdp->declBus  (c+197,"top riscv_core_i id_stage_i decoder_i jump_in_id",-1,1,0);
	vcdp->declBus  (c+276,"top riscv_core_i id_stage_i decoder_i csr_op",-1,1,0);
	vcdp->declBit  (c+277,"top riscv_core_i id_stage_i decoder_i mult_int_en",-1);
	vcdp->declBit  (c+278,"top riscv_core_i id_stage_i decoder_i mult_dot_en",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i decoder_i apu_en",-1);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i controller_i FPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i id_stage_i controller_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i id_stage_i controller_i rst_n",-1);
	vcdp->declBit  (c+974,"top riscv_core_i id_stage_i controller_i fetch_enable_i",-1);
	vcdp->declBit  (c+106,"top riscv_core_i id_stage_i controller_i ctrl_busy_o",-1);
	vcdp->declBit  (c+141,"top riscv_core_i id_stage_i controller_i first_fetch_o",-1);
	vcdp->declBit  (c+103,"top riscv_core_i id_stage_i controller_i is_decoding_o",-1);
	vcdp->declBit  (c+536,"top riscv_core_i id_stage_i controller_i wb_finish",-1);
	vcdp->declBit  (c+186,"top riscv_core_i id_stage_i controller_i deassert_we_o",-1);
	vcdp->declBit  (c+187,"top riscv_core_i id_stage_i controller_i illegal_insn_i",-1);
	vcdp->declBit  (c+191,"top riscv_core_i id_stage_i controller_i ecall_insn_i",-1);
	vcdp->declBit  (c+189,"top riscv_core_i id_stage_i controller_i mret_insn_i",-1);
	vcdp->declBit  (c+190,"top riscv_core_i id_stage_i controller_i uret_insn_i",-1);
	vcdp->declBit  (c+192,"top riscv_core_i id_stage_i controller_i pipe_flush_i",-1);
	vcdp->declBit  (c+188,"top riscv_core_i id_stage_i controller_i ebrk_insn_i",-1);
	vcdp->declBit  (c+242,"top riscv_core_i id_stage_i controller_i csr_status_i",-1);
	vcdp->declBit  (c+198,"top riscv_core_i id_stage_i controller_i instr_multicycle_i",-1);
	vcdp->declBit  (c+865,"top riscv_core_i id_stage_i controller_i instr_valid_i",-1);
	vcdp->declBit  (c+117,"top riscv_core_i id_stage_i controller_i instr_req_o",-1);
	vcdp->declBit  (c+98,"top riscv_core_i id_stage_i controller_i pc_set_o",-1);
	vcdp->declBus  (c+99,"top riscv_core_i id_stage_i controller_i pc_mux_o",-1,2,0);
	vcdp->declBus  (c+100,"top riscv_core_i id_stage_i controller_i exc_pc_mux_o",-1,1,0);
	vcdp->declBit  (c+102,"top riscv_core_i id_stage_i controller_i trap_addr_mux_o",-1);
	vcdp->declBit  (c+912,"top riscv_core_i id_stage_i controller_i data_req_ex_i",-1);
	vcdp->declBit  (c+597,"top riscv_core_i id_stage_i controller_i data_misaligned_i",-1);
	vcdp->declBit  (c+226,"top riscv_core_i id_stage_i controller_i data_load_event_i",-1);
	vcdp->declBit  (c+104,"top riscv_core_i id_stage_i controller_i mult_multicycle_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i controller_i apu_en_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i controller_i apu_read_dep_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i controller_i apu_write_dep_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i controller_i apu_stall_o",-1);
	vcdp->declBit  (c+622,"top riscv_core_i id_stage_i controller_i branch_taken_ex_i",-1);
	vcdp->declBus  (c+196,"top riscv_core_i id_stage_i controller_i jump_in_id_i",-1,1,0);
	vcdp->declBus  (c+197,"top riscv_core_i id_stage_i controller_i jump_in_dec_i",-1,1,0);
	vcdp->declBit  (c+960,"top riscv_core_i id_stage_i controller_i irq_i",-1);
	vcdp->declBit  (c+744,"top riscv_core_i id_stage_i controller_i irq_req_ctrl_i",-1);
	vcdp->declBit  (c+745,"top riscv_core_i id_stage_i controller_i irq_sec_ctrl_i",-1);
	vcdp->declBus  (c+713,"top riscv_core_i id_stage_i controller_i irq_id_ctrl_i",-1,4,0);
	vcdp->declBit  (c+587,"top riscv_core_i id_stage_i controller_i m_IE_i",-1);
	vcdp->declBit  (c+722,"top riscv_core_i id_stage_i controller_i u_IE_i",-1);
	vcdp->declBus  (c+721,"top riscv_core_i id_stage_i controller_i current_priv_lvl_i",-1,1,0);
	vcdp->declBit  (c+15,"top riscv_core_i id_stage_i controller_i irq_ack_o",-1);
	vcdp->declBus  (c+713,"top riscv_core_i id_stage_i controller_i irq_id_o",-1,4,0);
	vcdp->declBus  (c+101,"top riscv_core_i id_stage_i controller_i exc_cause_o",-1,5,0);
	vcdp->declBit  (c+201,"top riscv_core_i id_stage_i controller_i exc_ack_o",-1);
	vcdp->declBit  (c+202,"top riscv_core_i id_stage_i controller_i exc_kill_o",-1);
	vcdp->declBit  (c+121,"top riscv_core_i id_stage_i controller_i csr_save_if_o",-1);
	vcdp->declBit  (c+122,"top riscv_core_i id_stage_i controller_i csr_save_id_o",-1);
	vcdp->declBus  (c+123,"top riscv_core_i id_stage_i controller_i csr_cause_o",-1,5,0);
	vcdp->declBit  (c+118,"top riscv_core_i id_stage_i controller_i csr_irq_sec_o",-1);
	vcdp->declBit  (c+124,"top riscv_core_i id_stage_i controller_i csr_restore_mret_id_o",-1);
	vcdp->declBit  (c+125,"top riscv_core_i id_stage_i controller_i csr_restore_uret_id_o",-1);
	vcdp->declBit  (c+120,"top riscv_core_i id_stage_i controller_i csr_save_cause_o",-1);
	vcdp->declBit  (c+129,"top riscv_core_i id_stage_i controller_i dbg_req_i",-1);
	vcdp->declBit  (c+130,"top riscv_core_i id_stage_i controller_i dbg_ack_o",-1);
	vcdp->declBit  (c+131,"top riscv_core_i id_stage_i controller_i dbg_stall_i",-1);
	vcdp->declBit  (c+735,"top riscv_core_i id_stage_i controller_i dbg_jump_req_i",-1);
	vcdp->declBus  (c+729,"top riscv_core_i id_stage_i controller_i dbg_settings_i",-1,5,0);
	vcdp->declBit  (c+132,"top riscv_core_i id_stage_i controller_i dbg_trap_o",-1);
	vcdp->declBus  (c+940,"top riscv_core_i id_stage_i controller_i regfile_alu_waddr_id_i",-1,5,0);
	vcdp->declBit  (c+903,"top riscv_core_i id_stage_i controller_i regfile_we_ex_i",-1);
	vcdp->declBus  (c+902,"top riscv_core_i id_stage_i controller_i regfile_waddr_ex_i",-1,5,0);
	vcdp->declBit  (c+586,"top riscv_core_i id_stage_i controller_i regfile_we_wb_i",-1);
	vcdp->declBit  (c+603,"top riscv_core_i id_stage_i controller_i regfile_alu_we_fw_i",-1);
	vcdp->declBus  (c+244,"top riscv_core_i id_stage_i controller_i operand_a_fw_mux_sel_o",-1,1,0);
	vcdp->declBus  (c+245,"top riscv_core_i id_stage_i controller_i operand_b_fw_mux_sel_o",-1,1,0);
	vcdp->declBus  (c+246,"top riscv_core_i id_stage_i controller_i operand_c_fw_mux_sel_o",-1,1,0);
	vcdp->declBit  (c+266,"top riscv_core_i id_stage_i controller_i reg_d_ex_is_reg_a_i",-1);
	vcdp->declBit  (c+562,"top riscv_core_i id_stage_i controller_i reg_d_ex_is_reg_b_i",-1);
	vcdp->declBit  (c+563,"top riscv_core_i id_stage_i controller_i reg_d_ex_is_reg_c_i",-1);
	vcdp->declBit  (c+267,"top riscv_core_i id_stage_i controller_i reg_d_wb_is_reg_a_i",-1);
	vcdp->declBit  (c+544,"top riscv_core_i id_stage_i controller_i reg_d_wb_is_reg_b_i",-1);
	vcdp->declBit  (c+538,"top riscv_core_i id_stage_i controller_i reg_d_wb_is_reg_c_i",-1);
	vcdp->declBit  (c+268,"top riscv_core_i id_stage_i controller_i reg_d_alu_is_reg_a_i",-1);
	vcdp->declBit  (c+564,"top riscv_core_i id_stage_i controller_i reg_d_alu_is_reg_b_i",-1);
	vcdp->declBit  (c+565,"top riscv_core_i id_stage_i controller_i reg_d_alu_is_reg_c_i",-1);
	vcdp->declBit  (c+110,"top riscv_core_i id_stage_i controller_i halt_if_o",-1);
	vcdp->declBit  (c+199,"top riscv_core_i id_stage_i controller_i halt_id_o",-1);
	vcdp->declBit  (c+597,"top riscv_core_i id_stage_i controller_i misaligned_stall_o",-1);
	vcdp->declBit  (c+138,"top riscv_core_i id_stage_i controller_i jr_stall_o",-1);
	vcdp->declBit  (c+139,"top riscv_core_i id_stage_i controller_i load_stall_o",-1);
	vcdp->declBit  (c+111,"top riscv_core_i id_stage_i controller_i id_ready_i",-1);
	vcdp->declBit  (c+114,"top riscv_core_i id_stage_i controller_i ex_valid_i",-1);
	vcdp->declBit  (c+115,"top riscv_core_i id_stage_i controller_i wb_ready_i",-1);
	vcdp->declBit  (c+137,"top riscv_core_i id_stage_i controller_i perf_jump_o",-1);
	vcdp->declBit  (c+138,"top riscv_core_i id_stage_i controller_i perf_jr_stall_o",-1);
	vcdp->declBit  (c+139,"top riscv_core_i id_stage_i controller_i perf_ld_stall_o",-1);
	vcdp->declBit  (c+140,"top riscv_core_i id_stage_i controller_i perf_pipeline_stall_o",-1);
	vcdp->declBus  (c+779,"top riscv_core_i id_stage_i controller_i ctrl_fsm_cs",-1,4,0);
	vcdp->declBus  (c+279,"top riscv_core_i id_stage_i controller_i ctrl_fsm_ns",-1,4,0);
	vcdp->declBit  (c+280,"top riscv_core_i id_stage_i controller_i jump_done",-1);
	vcdp->declBit  (c+780,"top riscv_core_i id_stage_i controller_i jump_done_q",-1);
	vcdp->declBit  (c+281,"top riscv_core_i id_stage_i controller_i jump_in_dec",-1);
	vcdp->declBit  (c+282,"top riscv_core_i id_stage_i controller_i branch_in_id",-1);
	vcdp->declBit  (c+283,"top riscv_core_i id_stage_i controller_i boot_done",-1);
	vcdp->declBit  (c+781,"top riscv_core_i id_stage_i controller_i boot_done_q",-1);
	vcdp->declBit  (c+284,"top riscv_core_i id_stage_i controller_i irq_enable_int",-1);
	vcdp->declBus  (c+999,"top riscv_core_i id_stage_i int_controller_i PULP_SECURE",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i id_stage_i int_controller_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i id_stage_i int_controller_i rst_n",-1);
	vcdp->declBit  (c+744,"top riscv_core_i id_stage_i int_controller_i irq_req_ctrl_o",-1);
	vcdp->declBit  (c+745,"top riscv_core_i id_stage_i int_controller_i irq_sec_ctrl_o",-1);
	vcdp->declBus  (c+713,"top riscv_core_i id_stage_i int_controller_i irq_id_ctrl_o",-1,4,0);
	vcdp->declBit  (c+201,"top riscv_core_i id_stage_i int_controller_i ctrl_ack_i",-1);
	vcdp->declBit  (c+202,"top riscv_core_i id_stage_i int_controller_i ctrl_kill_i",-1);
	vcdp->declBit  (c+960,"top riscv_core_i id_stage_i int_controller_i irq_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i id_stage_i int_controller_i irq_sec_i",-1);
	vcdp->declBus  (c+961,"top riscv_core_i id_stage_i int_controller_i irq_id_i",-1,4,0);
	vcdp->declBit  (c+587,"top riscv_core_i id_stage_i int_controller_i m_IE_i",-1);
	vcdp->declBit  (c+722,"top riscv_core_i id_stage_i int_controller_i u_IE_i",-1);
	vcdp->declBus  (c+721,"top riscv_core_i id_stage_i int_controller_i current_priv_lvl_i",-1,1,0);
	vcdp->declBus  (c+782,"top riscv_core_i id_stage_i int_controller_i exc_ctrl_cs",-1,1,0);
	vcdp->declBus  (c+1068,"top riscv_core_i id_stage_i int_controller_i exc_ctrl_ns",-1,1,0);
	vcdp->declBit  (c+587,"top riscv_core_i id_stage_i int_controller_i irq_enable_ext",-1);
	vcdp->declBus  (c+713,"top riscv_core_i id_stage_i int_controller_i irq_id_q",-1,4,0);
	vcdp->declBit  (c+745,"top riscv_core_i id_stage_i int_controller_i irq_sec_q",-1);
	vcdp->declBus  (c+1017,"top riscv_core_i id_stage_i hwloop_regs_i N_REGS",-1,31,0);
	vcdp->declBus  (c+1000,"top riscv_core_i id_stage_i hwloop_regs_i N_REG_BITS",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i id_stage_i hwloop_regs_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i id_stage_i hwloop_regs_i rst_n",-1);
	vcdp->declBus  (c+234,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_start_data_i",-1,31,0);
	vcdp->declBus  (c+236,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_end_data_i",-1,31,0);
	vcdp->declBus  (c+237,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_cnt_data_i",-1,31,0);
	vcdp->declBus  (c+228,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_we_i",-1,2,0);
	vcdp->declBus  (c+227,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_regid_i",-1,0,0);
	vcdp->declBit  (c+239,"top riscv_core_i id_stage_i hwloop_regs_i valid_i",-1);
	vcdp->declBus  (c+864,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_dec_cnt_i",-1,1,0);
	vcdp->declQuad (c+723,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_start_addr_o",-1,63,0);
	vcdp->declQuad (c+725,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_end_addr_o",-1,63,0);
	vcdp->declQuad (c+727,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_counter_o",-1,63,0);
	vcdp->declQuad (c+723,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_start_q",-1,63,0);
	vcdp->declQuad (c+725,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_end_q",-1,63,0);
	vcdp->declQuad (c+727,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_counter_q",-1,63,0);
	vcdp->declQuad (c+589,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_counter_n",-1,63,0);
	vcdp->declBus  (c+783,"top riscv_core_i id_stage_i hwloop_regs_i i",-1,31,0);
	// Tracing: top riscv_core_i id_stage_i hwloop_regs_i k // Ignored: Verilator trace_off at ../rtl/riscv_hwloop_regs.sv:101
	vcdp->declBus  (c+999,"top riscv_core_i ex_stage_i FPU",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i ex_stage_i SHARED_FP",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i ex_stage_i SHARED_DSP_MULT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i ex_stage_i SHARED_INT_DIV",-1,31,0);
	vcdp->declBus  (c+1001,"top riscv_core_i ex_stage_i APU_NARGS_CPU",-1,31,0);
	vcdp->declBus  (c+1002,"top riscv_core_i ex_stage_i APU_WOP_CPU",-1,31,0);
	vcdp->declBus  (c+1003,"top riscv_core_i ex_stage_i APU_NDSFLAGS_CPU",-1,31,0);
	vcdp->declBus  (c+1004,"top riscv_core_i ex_stage_i APU_NUSFLAGS_CPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i ex_stage_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i ex_stage_i rst_n",-1);
	vcdp->declBus  (c+876,"top riscv_core_i ex_stage_i alu_operator_i",-1,6,0);
	vcdp->declBus  (c+877,"top riscv_core_i ex_stage_i alu_operand_a_i",-1,31,0);
	vcdp->declBus  (c+878,"top riscv_core_i ex_stage_i alu_operand_b_i",-1,31,0);
	vcdp->declBus  (c+872,"top riscv_core_i ex_stage_i alu_operand_c_i",-1,31,0);
	vcdp->declBit  (c+875,"top riscv_core_i ex_stage_i alu_en_i",-1);
	vcdp->declBus  (c+879,"top riscv_core_i ex_stage_i bmask_a_i",-1,4,0);
	vcdp->declBus  (c+880,"top riscv_core_i ex_stage_i bmask_b_i",-1,4,0);
	vcdp->declBus  (c+881,"top riscv_core_i ex_stage_i imm_vec_ext_i",-1,1,0);
	vcdp->declBus  (c+882,"top riscv_core_i ex_stage_i alu_vec_mode_i",-1,1,0);
	vcdp->declBus  (c+883,"top riscv_core_i ex_stage_i mult_operator_i",-1,2,0);
	vcdp->declBus  (c+884,"top riscv_core_i ex_stage_i mult_operand_a_i",-1,31,0);
	vcdp->declBus  (c+885,"top riscv_core_i ex_stage_i mult_operand_b_i",-1,31,0);
	vcdp->declBus  (c+886,"top riscv_core_i ex_stage_i mult_operand_c_i",-1,31,0);
	vcdp->declBit  (c+887,"top riscv_core_i ex_stage_i mult_en_i",-1);
	vcdp->declBit  (c+888,"top riscv_core_i ex_stage_i mult_sel_subword_i",-1);
	vcdp->declBus  (c+889,"top riscv_core_i ex_stage_i mult_signed_mode_i",-1,1,0);
	vcdp->declBus  (c+890,"top riscv_core_i ex_stage_i mult_imm_i",-1,4,0);
	vcdp->declBus  (c+891,"top riscv_core_i ex_stage_i mult_dot_op_a_i",-1,31,0);
	vcdp->declBus  (c+892,"top riscv_core_i ex_stage_i mult_dot_op_b_i",-1,31,0);
	vcdp->declBus  (c+893,"top riscv_core_i ex_stage_i mult_dot_op_c_i",-1,31,0);
	vcdp->declBus  (c+894,"top riscv_core_i ex_stage_i mult_dot_signed_i",-1,1,0);
	vcdp->declBit  (c+104,"top riscv_core_i ex_stage_i mult_multicycle_o",-1);
	vcdp->declBus  (c+895,"top riscv_core_i ex_stage_i fpu_op_i",-1,3,0);
	vcdp->declBus  (c+1020,"top riscv_core_i ex_stage_i fpu_prec_i",-1,4,0);
	vcdp->declBus  (c+1020,"top riscv_core_i ex_stage_i fpu_fflags_o",-1,4,0);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i fpu_fflags_we_o",-1);
	vcdp->declBit  (c+86,"top riscv_core_i ex_stage_i str_op_en_i",-1);
	vcdp->declBus  (c+85,"top riscv_core_i ex_stage_i str_operator_i",-1,1,0);
	vcdp->declBus  (c+88,"top riscv_core_i ex_stage_i str_operand_i",-1,31,0);
	vcdp->declBus  (c+87,"top riscv_core_i ex_stage_i str_op_result",-1,31,0);
	vcdp->declBit  (c+90,"top riscv_core_i ex_stage_i mac_op_en_i",-1);
	vcdp->declBus  (c+89,"top riscv_core_i ex_stage_i mac_operator_i",-1,2,0);
	vcdp->declBus  (c+92,"top riscv_core_i ex_stage_i mac_operand_i1",-1,31,0);
	vcdp->declBus  (c+93,"top riscv_core_i ex_stage_i mac_operand_i2",-1,31,0);
	vcdp->declBus  (c+91,"top riscv_core_i ex_stage_i mac_op_result",-1,31,0);
	vcdp->declBus  (c+851,"top riscv_core_i ex_stage_i con_data_cnt",-1,31,0);
	vcdp->declBus  (c+849,"top riscv_core_i ex_stage_i mem_rdata",-1,31,0);
	vcdp->declBit  (c+96,"top riscv_core_i ex_stage_i con_active",-1);
	vcdp->declBit  (c+51,"top riscv_core_i ex_stage_i mac_flag",-1);
	vcdp->declBit  (c+94,"top riscv_core_i ex_stage_i wb23_active",-1);
	vcdp->declBit  (c+1019,"top riscv_core_i ex_stage_i w_wb_active",-1);
	vcdp->declBit  (c+536,"top riscv_core_i ex_stage_i wb_finish",-1);
	vcdp->declBus  (c+95,"top riscv_core_i ex_stage_i mem_wdata",-1,31,0);
	vcdp->declBit  (c+896,"top riscv_core_i ex_stage_i apu_en_i",-1);
	vcdp->declBus  (c+899,"top riscv_core_i ex_stage_i apu_op_i",-1,5,0);
	vcdp->declBus  (c+900,"top riscv_core_i ex_stage_i apu_lat_i",-1,1,0);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+627+i*1,"top riscv_core_i ex_stage_i apu_operands_i",(i+0),31,0);}}
	vcdp->declBus  (c+901,"top riscv_core_i ex_stage_i apu_waddr_i",-1,5,0);
	vcdp->declBus  (c+898,"top riscv_core_i ex_stage_i apu_flags_i",-1,14,0);
	vcdp->declBus  (c+1022,"top riscv_core_i ex_stage_i apu_read_regs_i",-1,17,0);
	vcdp->declBus  (c+1021,"top riscv_core_i ex_stage_i apu_read_regs_valid_i",-1,2,0);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_read_dep_o",-1);
	vcdp->declBus  (c+1023,"top riscv_core_i ex_stage_i apu_write_regs_i",-1,11,0);
	vcdp->declBus  (c+1011,"top riscv_core_i ex_stage_i apu_write_regs_valid_i",-1,1,0);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_write_dep_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_perf_type_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_perf_cont_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_perf_wb_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_busy_o",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i ex_stage_i apu_ready_wb_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_master_req_o",-1);
	vcdp->declBit  (c+1005,"top riscv_core_i ex_stage_i apu_master_ready_o",-1);
	vcdp->declBit  (c+1010,"top riscv_core_i ex_stage_i apu_master_gnt_i",-1);
	{int i; for (i=0; i<3; i++) {
		vcdp->declBus  (c+7+i*1,"top riscv_core_i ex_stage_i apu_master_operands_o",(i+0),31,0);}}
	vcdp->declBus  (c+1008,"top riscv_core_i ex_stage_i apu_master_op_o",-1,5,0);
	vcdp->declBit  (c+1013,"top riscv_core_i ex_stage_i apu_master_valid_i",-1);
	vcdp->declBus  (c+1014,"top riscv_core_i ex_stage_i apu_master_result_i",-1,31,0);
	vcdp->declBit  (c+912,"top riscv_core_i ex_stage_i lsu_en_i",-1);
	vcdp->declBus  (c+602,"top riscv_core_i ex_stage_i lsu_rdata_i",-1,31,0);
	vcdp->declBit  (c+873,"top riscv_core_i ex_stage_i branch_in_ex_i",-1);
	vcdp->declBus  (c+904,"top riscv_core_i ex_stage_i regfile_alu_waddr_i",-1,5,0);
	vcdp->declBit  (c+905,"top riscv_core_i ex_stage_i regfile_alu_we_i",-1);
	vcdp->declBit  (c+903,"top riscv_core_i ex_stage_i regfile_we_i",-1);
	vcdp->declBus  (c+902,"top riscv_core_i ex_stage_i regfile_waddr_i",-1,5,0);
	vcdp->declBit  (c+906,"top riscv_core_i ex_stage_i csr_access_i",-1);
	vcdp->declBus  (c+605,"top riscv_core_i ex_stage_i csr_rdata_i",-1,31,0);
	vcdp->declBus  (c+720,"top riscv_core_i ex_stage_i regfile_waddr_wb_o",-1,5,0);
	vcdp->declBit  (c+586,"top riscv_core_i ex_stage_i regfile_we_wb_o",-1);
	vcdp->declBus  (c+602,"top riscv_core_i ex_stage_i regfile_wdata_wb_o",-1,31,0);
	vcdp->declBus  (c+904,"top riscv_core_i ex_stage_i regfile_alu_waddr_fw_o",-1,5,0);
	vcdp->declBit  (c+603,"top riscv_core_i ex_stage_i regfile_alu_we_fw_o",-1);
	vcdp->declBus  (c+108,"top riscv_core_i ex_stage_i regfile_alu_wdata_fw_o",-1,31,0);
	vcdp->declBus  (c+872,"top riscv_core_i ex_stage_i jump_target_o",-1,31,0);
	vcdp->declBit  (c+598,"top riscv_core_i ex_stage_i branch_decision_o",-1);
	vcdp->declBit  (c+116,"top riscv_core_i ex_stage_i lsu_ready_ex_i",-1);
	vcdp->declBit  (c+112,"top riscv_core_i ex_stage_i ex_ready_o",-1);
	vcdp->declBit  (c+114,"top riscv_core_i ex_stage_i ex_valid_o",-1);
	vcdp->declBit  (c+115,"top riscv_core_i ex_stage_i wb_ready_i",-1);
	vcdp->declArray(c+39,"top riscv_core_i ex_stage_i y0",-1,67,0);
	vcdp->declArray(c+42,"top riscv_core_i ex_stage_i y1",-1,67,0);
	vcdp->declArray(c+45,"top riscv_core_i ex_stage_i y2",-1,67,0);
	vcdp->declArray(c+48,"top riscv_core_i ex_stage_i y3",-1,67,0);
	{int i; for (i=0; i<16; i++) {
		vcdp->declBus  (c+285+i*1,"top riscv_core_i ex_stage_i con_data",(i+0),31,0);}}
	vcdp->declBit  (c+301,"top riscv_core_i ex_stage_i str_op_ready",-1);
	vcdp->declBit  (c+302,"top riscv_core_i ex_stage_i mac_op_ready",-1);
	vcdp->declBus  (c+303,"top riscv_core_i ex_stage_i alu_result",-1,31,0);
	vcdp->declBus  (c+304,"top riscv_core_i ex_stage_i mult_result",-1,31,0);
	vcdp->declBit  (c+598,"top riscv_core_i ex_stage_i alu_cmp_result",-1);
	vcdp->declBit  (c+784,"top riscv_core_i ex_stage_i regfile_we_lsu",-1);
	vcdp->declBus  (c+720,"top riscv_core_i ex_stage_i regfile_waddr_lsu",-1,5,0);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i wb_contention",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i wb_contention_lsu",-1);
	vcdp->declBit  (c+305,"top riscv_core_i ex_stage_i alu_ready",-1);
	vcdp->declBit  (c+306,"top riscv_core_i ex_stage_i mult_ready",-1);
	vcdp->declBit  (c+1069,"top riscv_core_i ex_stage_i fpu_busy",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_valid",-1);
	vcdp->declBus  (c+1008,"top riscv_core_i ex_stage_i apu_waddr",-1,5,0);
	vcdp->declBus  (c+1070,"top riscv_core_i ex_stage_i apu_result",-1,31,0);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_stall",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_active",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_singlecycle",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i apu_multicycle",-1);
	vcdp->declBit  (c+1071,"top riscv_core_i ex_stage_i apu_req",-1);
	vcdp->declBit  (c+1072,"top riscv_core_i ex_stage_i apu_ready",-1);
	vcdp->declBit  (c+1073,"top riscv_core_i ex_stage_i apu_gnt",-1);
	vcdp->declBit  (c+958,"top riscv_core_i ex_stage_i riscv_str_ops_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i ex_stage_i riscv_str_ops_i rst_n",-1);
	vcdp->declBit  (c+86,"top riscv_core_i ex_stage_i riscv_str_ops_i enable_i",-1);
	vcdp->declBus  (c+85,"top riscv_core_i ex_stage_i riscv_str_ops_i operator_i",-1,1,0);
	vcdp->declBus  (c+88,"top riscv_core_i ex_stage_i riscv_str_ops_i operand_i",-1,31,0);
	vcdp->declBit  (c+112,"top riscv_core_i ex_stage_i riscv_str_ops_i ex_ready_i",-1);
	vcdp->declBus  (c+87,"top riscv_core_i ex_stage_i riscv_str_ops_i result_o",-1,31,0);
	vcdp->declBit  (c+301,"top riscv_core_i ex_stage_i riscv_str_ops_i ready_o",-1);
	vcdp->declBus  (c+785,"top riscv_core_i ex_stage_i riscv_str_ops_i leet_CS",-1,2,0);
	vcdp->declBus  (c+307,"top riscv_core_i ex_stage_i riscv_str_ops_i leet_NS",-1,2,0);
	vcdp->declBit  (c+301,"top riscv_core_i ex_stage_i riscv_str_ops_i leet_ready",-1);
	vcdp->declBit  (c+308,"top riscv_core_i ex_stage_i riscv_str_ops_i leet_active",-1);
	vcdp->declBus  (c+309,"top riscv_core_i ex_stage_i riscv_str_ops_i leet_intermediate",-1,31,0);
	vcdp->declBus  (c+310,"top riscv_core_i ex_stage_i riscv_str_ops_i char_",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i ex_stage_i riscv_mac_ops_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i ex_stage_i riscv_mac_ops_i rst_n",-1);
	vcdp->declBit  (c+90,"top riscv_core_i ex_stage_i riscv_mac_ops_i enable_i",-1);
	vcdp->declBus  (c+89,"top riscv_core_i ex_stage_i riscv_mac_ops_i operator_i",-1,2,0);
	vcdp->declBus  (c+92,"top riscv_core_i ex_stage_i riscv_mac_ops_i operand_i1",-1,31,0);
	vcdp->declBus  (c+93,"top riscv_core_i ex_stage_i riscv_mac_ops_i operand_i2",-1,31,0);
	vcdp->declBit  (c+112,"top riscv_core_i ex_stage_i riscv_mac_ops_i ex_ready_i",-1);
	vcdp->declBus  (c+851,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_data_cnt",-1,31,0);
	vcdp->declBus  (c+849,"top riscv_core_i ex_stage_i riscv_mac_ops_i mem_rdata",-1,31,0);
	vcdp->declBus  (c+95,"top riscv_core_i ex_stage_i riscv_mac_ops_i mem_wdata",-1,31,0);
	vcdp->declBit  (c+94,"top riscv_core_i ex_stage_i riscv_mac_ops_i wb23_active",-1);
	vcdp->declBit  (c+536,"top riscv_core_i ex_stage_i riscv_mac_ops_i wb_finish",-1);
	vcdp->declBit  (c+1019,"top riscv_core_i ex_stage_i riscv_mac_ops_i w_wb_active",-1);
	vcdp->declBus  (c+91,"top riscv_core_i ex_stage_i riscv_mac_ops_i result_o",-1,31,0);
	vcdp->declBit  (c+96,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_active_o",-1);
	vcdp->declBit  (c+302,"top riscv_core_i ex_stage_i riscv_mac_ops_i ready_o",-1);
	vcdp->declBit  (c+51,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_flag",-1);
	vcdp->declArray(c+39,"top riscv_core_i ex_stage_i riscv_mac_ops_i y0_o",-1,67,0);
	vcdp->declArray(c+42,"top riscv_core_i ex_stage_i riscv_mac_ops_i y1_o",-1,67,0);
	vcdp->declArray(c+45,"top riscv_core_i ex_stage_i riscv_mac_ops_i y2_o",-1,67,0);
	vcdp->declArray(c+48,"top riscv_core_i ex_stage_i riscv_mac_ops_i y3_o",-1,67,0);
	{int i; for (i=0; i<16; i++) {
		vcdp->declBus  (c+311+i*1,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_data",(i+0),31,0);}}
	vcdp->declBus  (c+786,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_cs",-1,2,0);
	vcdp->declBus  (c+327,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_ns",-1,2,0);
	vcdp->declBus  (c+787,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_2x2_cs",-1,2,0);
	vcdp->declBus  (c+328,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_2x2_ns",-1,2,0);
	vcdp->declBus  (c+788,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_cs",-1,2,0);
	vcdp->declBus  (c+329,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_ns",-1,2,0);
	vcdp->declBit  (c+789,"top riscv_core_i ex_stage_i riscv_mac_ops_i wb23_cs",-1);
	vcdp->declBit  (c+330,"top riscv_core_i ex_stage_i riscv_mac_ops_i wb23_ns",-1);
	vcdp->declBit  (c+1074,"top riscv_core_i ex_stage_i riscv_mac_ops_i w_wb_cs",-1);
	vcdp->declBit  (c+1075,"top riscv_core_i ex_stage_i riscv_mac_ops_i w_wb_ns",-1);
	vcdp->declBus  (c+1076,"top riscv_core_i ex_stage_i riscv_mac_ops_i w_rank",-1,3,0);
	vcdp->declBit  (c+331,"top riscv_core_i ex_stage_i riscv_mac_ops_i wb_flag",-1);
	vcdp->declBit  (c+1077,"top riscv_core_i ex_stage_i riscv_mac_ops_i w_wb_ready",-1);
	vcdp->declBit  (c+332,"top riscv_core_i ex_stage_i riscv_mac_ops_i wb23_ready",-1);
	vcdp->declBit  (c+333,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_ready",-1);
	vcdp->declBit  (c+334,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_ready",-1);
	vcdp->declBit  (c+335,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_active",-1);
	vcdp->declBit  (c+336,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_2x2_ready",-1);
	vcdp->declBit  (c+337,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_2x2_active",-1);
	vcdp->declBus  (c+338,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_operand",-1,31,0);
	vcdp->declBus  (c+339,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_mult1",-1,15,0);
	vcdp->declBus  (c+340,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_mult2",-1,15,0);
	vcdp->declBus  (c+341,"top riscv_core_i ex_stage_i riscv_mac_ops_i mac_add",-1,31,0);
	vcdp->declBus  (c+342,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_operand_1",-1,31,0);
	vcdp->declBus  (c+343,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_operand_2",-1,31,0);
	vcdp->declBus  (c+344,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_mult1",-1,15,0);
	vcdp->declBus  (c+345,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_mult2",-1,15,0);
	vcdp->declBus  (c+346,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_mult3",-1,15,0);
	vcdp->declBus  (c+347,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_mult4",-1,15,0);
	vcdp->declBus  (c+348,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_add",-1,31,0);
	vcdp->declBit  (c+96,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_active",-1);
	vcdp->declBit  (c+790,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_active_d",-1);
	vcdp->declBit  (c+791,"top riscv_core_i ex_stage_i riscv_mac_ops_i enable_i_d",-1);
	vcdp->declBus  (c+349,"top riscv_core_i ex_stage_i riscv_mac_ops_i max",-1,31,0);
	vcdp->declBus  (c+1030,"top riscv_core_i ex_stage_i riscv_mac_ops_i nbit",-1,31,0);
	vcdp->declBus  (c+350,"top riscv_core_i ex_stage_i riscv_mac_ops_i w0",-1,31,0);
	vcdp->declBus  (c+351,"top riscv_core_i ex_stage_i riscv_mac_ops_i w1",-1,31,0);
	vcdp->declBus  (c+352,"top riscv_core_i ex_stage_i riscv_mac_ops_i w2",-1,31,0);
	vcdp->declBus  (c+353,"top riscv_core_i ex_stage_i riscv_mac_ops_i w3",-1,31,0);
	vcdp->declBus  (c+354,"top riscv_core_i ex_stage_i riscv_mac_ops_i w4",-1,31,0);
	vcdp->declBus  (c+355,"top riscv_core_i ex_stage_i riscv_mac_ops_i w5",-1,31,0);
	vcdp->declBus  (c+356,"top riscv_core_i ex_stage_i riscv_mac_ops_i w6",-1,31,0);
	vcdp->declBus  (c+357,"top riscv_core_i ex_stage_i riscv_mac_ops_i w7",-1,31,0);
	vcdp->declBus  (c+358,"top riscv_core_i ex_stage_i riscv_mac_ops_i w8",-1,31,0);
	vcdp->declBus  (c+359,"top riscv_core_i ex_stage_i riscv_mac_ops_i y0",-1,31,0);
	vcdp->declBus  (c+360,"top riscv_core_i ex_stage_i riscv_mac_ops_i y1",-1,31,0);
	vcdp->declBus  (c+361,"top riscv_core_i ex_stage_i riscv_mac_ops_i y2",-1,31,0);
	vcdp->declBus  (c+362,"top riscv_core_i ex_stage_i riscv_mac_ops_i y3",-1,31,0);
	vcdp->declBus  (c+363,"top riscv_core_i ex_stage_i riscv_mac_ops_i ymax",-1,31,0);
	vcdp->declArray(c+364,"top riscv_core_i ex_stage_i riscv_mac_ops_i M0_0_0",-1,66,0);
	vcdp->declArray(c+367,"top riscv_core_i ex_stage_i riscv_mac_ops_i M0_0_3",-1,66,0);
	vcdp->declArray(c+370,"top riscv_core_i ex_stage_i riscv_mac_ops_i M3_0_0",-1,66,0);
	vcdp->declArray(c+373,"top riscv_core_i ex_stage_i riscv_mac_ops_i M3_0_3",-1,66,0);
	vcdp->declArray(c+376,"top riscv_core_i ex_stage_i riscv_mac_ops_i M0_0_1",-1,67,0);
	vcdp->declArray(c+379,"top riscv_core_i ex_stage_i riscv_mac_ops_i M0_0_2",-1,67,0);
	vcdp->declArray(c+382,"top riscv_core_i ex_stage_i riscv_mac_ops_i M3_0_1",-1,67,0);
	vcdp->declArray(c+385,"top riscv_core_i ex_stage_i riscv_mac_ops_i M3_0_2",-1,67,0);
	vcdp->declArray(c+388,"top riscv_core_i ex_stage_i riscv_mac_ops_i M1_0_0",-1,68,0);
	vcdp->declArray(c+391,"top riscv_core_i ex_stage_i riscv_mac_ops_i M1_0_3",-1,68,0);
	vcdp->declArray(c+394,"top riscv_core_i ex_stage_i riscv_mac_ops_i M2_0_0",-1,68,0);
	vcdp->declArray(c+397,"top riscv_core_i ex_stage_i riscv_mac_ops_i M2_0_3",-1,68,0);
	vcdp->declArray(c+400,"top riscv_core_i ex_stage_i riscv_mac_ops_i M0_0",-1,70,0);
	vcdp->declArray(c+403,"top riscv_core_i ex_stage_i riscv_mac_ops_i M3_0",-1,70,0);
	vcdp->declArray(c+406,"top riscv_core_i ex_stage_i riscv_mac_ops_i M0_1",-1,69,0);
	vcdp->declArray(c+409,"top riscv_core_i ex_stage_i riscv_mac_ops_i M3_1",-1,69,0);
	vcdp->declArray(c+412,"top riscv_core_i ex_stage_i riscv_mac_ops_i M1_0_1",-1,69,0);
	vcdp->declArray(c+415,"top riscv_core_i ex_stage_i riscv_mac_ops_i M1_0_2",-1,69,0);
	vcdp->declArray(c+418,"top riscv_core_i ex_stage_i riscv_mac_ops_i M2_0_1",-1,69,0);
	vcdp->declArray(c+421,"top riscv_core_i ex_stage_i riscv_mac_ops_i M2_0_2",-1,69,0);
	vcdp->declArray(c+424,"top riscv_core_i ex_stage_i riscv_mac_ops_i M1_1",-1,71,0);
	vcdp->declArray(c+427,"top riscv_core_i ex_stage_i riscv_mac_ops_i M2_1",-1,71,0);
	vcdp->declArray(c+430,"top riscv_core_i ex_stage_i riscv_mac_ops_i M1_0",-1,72,0);
	vcdp->declArray(c+433,"top riscv_core_i ex_stage_i riscv_mac_ops_i M2_0",-1,72,0);
	vcdp->declQuad (c+436,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid0_0",-1,33,0);
	vcdp->declQuad (c+438,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid0_1",-1,33,0);
	vcdp->declQuad (c+440,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid3_0",-1,33,0);
	vcdp->declQuad (c+442,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid3_1",-1,33,0);
	vcdp->declQuad (c+444,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid1_0",-1,35,0);
	vcdp->declQuad (c+446,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid1_1",-1,35,0);
	vcdp->declQuad (c+448,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid2_0",-1,35,0);
	vcdp->declQuad (c+450,"top riscv_core_i ex_stage_i riscv_mac_ops_i mid2_1",-1,35,0);
	vcdp->declBit  (c+452,"top riscv_core_i ex_stage_i riscv_mac_ops_i con_data_flag",-1);
	vcdp->declBit  (c+453,"top riscv_core_i ex_stage_i riscv_mac_ops_i wb23_flag",-1);
	vcdp->declBus  (c+999,"top riscv_core_i ex_stage_i alu_i SHARED_INT_DIV",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i ex_stage_i alu_i FPU",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i ex_stage_i alu_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i ex_stage_i alu_i rst_n",-1);
	vcdp->declBit  (c+875,"top riscv_core_i ex_stage_i alu_i enable_i",-1);
	vcdp->declBus  (c+876,"top riscv_core_i ex_stage_i alu_i operator_i",-1,6,0);
	vcdp->declBus  (c+877,"top riscv_core_i ex_stage_i alu_i operand_a_i",-1,31,0);
	vcdp->declBus  (c+878,"top riscv_core_i ex_stage_i alu_i operand_b_i",-1,31,0);
	vcdp->declBus  (c+872,"top riscv_core_i ex_stage_i alu_i operand_c_i",-1,31,0);
	vcdp->declBus  (c+882,"top riscv_core_i ex_stage_i alu_i vector_mode_i",-1,1,0);
	vcdp->declBus  (c+879,"top riscv_core_i ex_stage_i alu_i bmask_a_i",-1,4,0);
	vcdp->declBus  (c+880,"top riscv_core_i ex_stage_i alu_i bmask_b_i",-1,4,0);
	vcdp->declBus  (c+881,"top riscv_core_i ex_stage_i alu_i imm_vec_ext_i",-1,1,0);
	vcdp->declBus  (c+303,"top riscv_core_i ex_stage_i alu_i result_o",-1,31,0);
	vcdp->declBit  (c+598,"top riscv_core_i ex_stage_i alu_i comparison_result_o",-1);
	vcdp->declBit  (c+305,"top riscv_core_i ex_stage_i alu_i ready_o",-1);
	vcdp->declBit  (c+112,"top riscv_core_i ex_stage_i alu_i ex_ready_i",-1);
	vcdp->declBus  (c+630,"top riscv_core_i ex_stage_i alu_i operand_a_rev",-1,31,0);
	vcdp->declBus  (c+942,"top riscv_core_i ex_stage_i alu_i operand_a_neg",-1,31,0);
	vcdp->declBus  (c+631,"top riscv_core_i ex_stage_i alu_i operand_a_neg_rev",-1,31,0);
	// Tracing: top riscv_core_i ex_stage_i alu_i k // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:65
	// Tracing: top riscv_core_i ex_stage_i alu_i m // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:74
	vcdp->declBus  (c+943,"top riscv_core_i ex_stage_i alu_i operand_b_neg",-1,31,0);
	vcdp->declBus  (c+454,"top riscv_core_i ex_stage_i alu_i div_shift",-1,5,0);
	vcdp->declBit  (c+632,"top riscv_core_i ex_stage_i alu_i div_valid",-1);
	vcdp->declBus  (c+633,"top riscv_core_i ex_stage_i alu_i bmask",-1,31,0);
	vcdp->declBit  (c+634,"top riscv_core_i ex_stage_i alu_i adder_op_b_negate",-1);
	vcdp->declBus  (c+635,"top riscv_core_i ex_stage_i alu_i adder_op_a",-1,31,0);
	vcdp->declBus  (c+636,"top riscv_core_i ex_stage_i alu_i adder_op_b",-1,31,0);
	vcdp->declQuad (c+637,"top riscv_core_i ex_stage_i alu_i adder_in_a",-1,35,0);
	vcdp->declQuad (c+639,"top riscv_core_i ex_stage_i alu_i adder_in_b",-1,35,0);
	vcdp->declBus  (c+641,"top riscv_core_i ex_stage_i alu_i adder_result",-1,31,0);
	vcdp->declQuad (c+642,"top riscv_core_i ex_stage_i alu_i adder_result_expanded",-1,36,0);
	vcdp->declBus  (c+644,"top riscv_core_i ex_stage_i alu_i adder_round_value",-1,31,0);
	vcdp->declBus  (c+645,"top riscv_core_i ex_stage_i alu_i adder_round_result",-1,31,0);
	vcdp->declBit  (c+646,"top riscv_core_i ex_stage_i alu_i shift_left",-1);
	vcdp->declBit  (c+647,"top riscv_core_i ex_stage_i alu_i shift_use_round",-1);
	vcdp->declBit  (c+648,"top riscv_core_i ex_stage_i alu_i shift_arithmetic",-1);
	vcdp->declBus  (c+455,"top riscv_core_i ex_stage_i alu_i shift_amt_left",-1,31,0);
	vcdp->declBus  (c+456,"top riscv_core_i ex_stage_i alu_i shift_amt",-1,31,0);
	vcdp->declBus  (c+457,"top riscv_core_i ex_stage_i alu_i shift_amt_int",-1,31,0);
	vcdp->declBus  (c+944,"top riscv_core_i ex_stage_i alu_i shift_amt_norm",-1,31,0);
	vcdp->declBus  (c+649,"top riscv_core_i ex_stage_i alu_i shift_op_a",-1,31,0);
	vcdp->declBus  (c+458,"top riscv_core_i ex_stage_i alu_i shift_result",-1,31,0);
	vcdp->declBus  (c+459,"top riscv_core_i ex_stage_i alu_i shift_right_result",-1,31,0);
	vcdp->declBus  (c+460,"top riscv_core_i ex_stage_i alu_i shift_left_result",-1,31,0);
	vcdp->declQuad (c+650,"top riscv_core_i ex_stage_i alu_i shift_op_a_32",-1,63,0);
	// Tracing: top riscv_core_i ex_stage_i alu_i j // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:289
	vcdp->declBus  (c+652,"top riscv_core_i ex_stage_i alu_i is_equal",-1,3,0);
	vcdp->declBus  (c+653,"top riscv_core_i ex_stage_i alu_i is_greater",-1,3,0);
	vcdp->declBus  (c+654,"top riscv_core_i ex_stage_i alu_i f_is_greater",-1,3,0);
	vcdp->declBus  (c+655,"top riscv_core_i ex_stage_i alu_i cmp_signed",-1,3,0);
	vcdp->declBus  (c+656,"top riscv_core_i ex_stage_i alu_i is_equal_vec",-1,3,0);
	vcdp->declBus  (c+657,"top riscv_core_i ex_stage_i alu_i is_greater_vec",-1,3,0);
	// Tracing: top riscv_core_i ex_stage_i alu_i i // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:352
	vcdp->declBus  (c+658,"top riscv_core_i ex_stage_i alu_i cmp_result",-1,3,0);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i alu_i f_is_qnan",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i alu_i f_is_snan",-1);
	vcdp->declBus  (c+659,"top riscv_core_i ex_stage_i alu_i f_is_nan",-1,3,0);
	vcdp->declBus  (c+660,"top riscv_core_i ex_stage_i alu_i result_minmax",-1,31,0);
	vcdp->declBus  (c+1078,"top riscv_core_i ex_stage_i alu_i fp_canonical_nan",-1,31,0);
	vcdp->declBus  (c+661,"top riscv_core_i ex_stage_i alu_i sel_minmax",-1,3,0);
	vcdp->declBit  (c+945,"top riscv_core_i ex_stage_i alu_i do_min",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i ex_stage_i alu_i minmax_is_fp_special",-1);
	vcdp->declBus  (c+662,"top riscv_core_i ex_stage_i alu_i minmax_b",-1,31,0);
	vcdp->declBus  (c+1078,"top riscv_core_i ex_stage_i alu_i fclass_result",-1,31,0);
	vcdp->declBus  (c+1078,"top riscv_core_i ex_stage_i alu_i f_sign_inject_result",-1,31,0);
	vcdp->declBus  (c+663,"top riscv_core_i ex_stage_i alu_i clip_result",-1,31,0);
	vcdp->declBit  (c+664,"top riscv_core_i ex_stage_i alu_i clip_is_lower_neg",-1);
	vcdp->declBit  (c+946,"top riscv_core_i ex_stage_i alu_i clip_is_lower_u",-1);
	vcdp->declBus  (c+665,"top riscv_core_i ex_stage_i alu_i shuffle_byte_sel",-1,7,0);
	vcdp->declBus  (c+666,"top riscv_core_i ex_stage_i alu_i shuffle_reg_sel",-1,3,0);
	vcdp->declBus  (c+667,"top riscv_core_i ex_stage_i alu_i shuffle_reg1_sel",-1,1,0);
	vcdp->declBus  (c+668,"top riscv_core_i ex_stage_i alu_i shuffle_reg0_sel",-1,1,0);
	vcdp->declBus  (c+669,"top riscv_core_i ex_stage_i alu_i shuffle_through",-1,3,0);
	vcdp->declBus  (c+670,"top riscv_core_i ex_stage_i alu_i shuffle_r1",-1,31,0);
	vcdp->declBus  (c+671,"top riscv_core_i ex_stage_i alu_i shuffle_r0",-1,31,0);
	vcdp->declBus  (c+672,"top riscv_core_i ex_stage_i alu_i shuffle_r1_in",-1,31,0);
	vcdp->declBus  (c+673,"top riscv_core_i ex_stage_i alu_i shuffle_r0_in",-1,31,0);
	vcdp->declBus  (c+674,"top riscv_core_i ex_stage_i alu_i shuffle_result",-1,31,0);
	vcdp->declBus  (c+675,"top riscv_core_i ex_stage_i alu_i pack_result",-1,31,0);
	vcdp->declBus  (c+676,"top riscv_core_i ex_stage_i alu_i ff_input",-1,31,0);
	vcdp->declBus  (c+677,"top riscv_core_i ex_stage_i alu_i cnt_result",-1,5,0);
	vcdp->declBus  (c+567,"top riscv_core_i ex_stage_i alu_i clb_result",-1,5,0);
	vcdp->declBus  (c+568,"top riscv_core_i ex_stage_i alu_i ff1_result",-1,4,0);
	vcdp->declBit  (c+569,"top riscv_core_i ex_stage_i alu_i ff_no_one",-1);
	vcdp->declBus  (c+570,"top riscv_core_i ex_stage_i alu_i fl1_result",-1,4,0);
	vcdp->declBus  (c+461,"top riscv_core_i ex_stage_i alu_i bitop_result",-1,5,0);
	vcdp->declBit  (c+947,"top riscv_core_i ex_stage_i alu_i extract_is_signed",-1);
	vcdp->declBit  (c+571,"top riscv_core_i ex_stage_i alu_i extract_sign",-1);
	vcdp->declBus  (c+948,"top riscv_core_i ex_stage_i alu_i bmask_first",-1,31,0);
	vcdp->declBus  (c+678,"top riscv_core_i ex_stage_i alu_i bmask_inv",-1,31,0);
	vcdp->declBus  (c+572,"top riscv_core_i ex_stage_i alu_i bextins_and",-1,31,0);
	vcdp->declBus  (c+462,"top riscv_core_i ex_stage_i alu_i bextins_result",-1,31,0);
	vcdp->declBus  (c+679,"top riscv_core_i ex_stage_i alu_i bclr_result",-1,31,0);
	vcdp->declBus  (c+680,"top riscv_core_i ex_stage_i alu_i bset_result",-1,31,0);
	vcdp->declBus  (c+591,"top riscv_core_i ex_stage_i alu_i result_div",-1,31,0);
	vcdp->declBit  (c+305,"top riscv_core_i ex_stage_i alu_i div_ready",-1);
	vcdp->declBit  (c+949,"top riscv_core_i ex_stage_i alu_i int_div div_signed",-1);
	vcdp->declBit  (c+681,"top riscv_core_i ex_stage_i alu_i int_div div_op_a_signed",-1);
	vcdp->declBit  (c+950,"top riscv_core_i ex_stage_i alu_i int_div div_op_b_signed",-1);
	vcdp->declBus  (c+573,"top riscv_core_i ex_stage_i alu_i int_div div_shift_int",-1,5,0);
	vcdp->declBus  (c+877,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i in_i",-1,31,0);
	vcdp->declBus  (c+677,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i result_o",-1,5,0);
	vcdp->declBus  (c+682,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l1",-1,31,0);
	vcdp->declBus  (c+683,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l2",-1,23,0);
	vcdp->declBus  (c+684,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l3",-1,15,0);
	vcdp->declBus  (c+685,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l4",-1,9,0);
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_popcnt_i l // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1129
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_popcnt_i m // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1129
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_popcnt_i n // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1129
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_popcnt_i p // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1129
	vcdp->declBus  (c+1030,"top riscv_core_i ex_stage_i alu_i alu_ff_i LEN",-1,31,0);
	vcdp->declBus  (c+676,"top riscv_core_i ex_stage_i alu_i alu_ff_i in_i",-1,31,0);
	vcdp->declBus  (c+568,"top riscv_core_i ex_stage_i alu_i alu_ff_i first_one_o",-1,4,0);
	vcdp->declBit  (c+569,"top riscv_core_i ex_stage_i alu_i alu_ff_i no_ones_o",-1);
	vcdp->declBus  (c+1004,"top riscv_core_i ex_stage_i alu_i alu_ff_i NUM_LEVELS",-1,31,0);
	vcdp->declArray(c+10,"top riscv_core_i ex_stage_i alu_i alu_ff_i index_lut",-1,159,0);
	vcdp->declBus  (c+574,"top riscv_core_i ex_stage_i alu_i alu_ff_i sel_nodes",-1,31,0);
	vcdp->declArray(c+575,"top riscv_core_i ex_stage_i alu_i alu_ff_i index_nodes",-1,159,0);
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_ff_i j // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1065
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_ff_i k // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1072
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_ff_i l // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1073
	// Tracing: top riscv_core_i ex_stage_i alu_i alu_ff_i level // Ignored: Verilator trace_off at ../rtl/riscv_alu.sv:1074
	vcdp->declBus  (c+1030,"top riscv_core_i ex_stage_i alu_i int_div div_i C_WIDTH",-1,31,0);
	vcdp->declBus  (c+1002,"top riscv_core_i ex_stage_i alu_i int_div div_i C_LOG_WIDTH",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i ex_stage_i alu_i int_div div_i Clk_CI",-1);
	vcdp->declBit  (c+959,"top riscv_core_i ex_stage_i alu_i int_div div_i Rst_RBI",-1);
	vcdp->declBus  (c+878,"top riscv_core_i ex_stage_i alu_i int_div div_i OpA_DI",-1,31,0);
	vcdp->declBus  (c+460,"top riscv_core_i ex_stage_i alu_i int_div div_i OpB_DI",-1,31,0);
	vcdp->declBus  (c+454,"top riscv_core_i ex_stage_i alu_i int_div div_i OpBShift_DI",-1,5,0);
	vcdp->declBit  (c+686,"top riscv_core_i ex_stage_i alu_i int_div div_i OpBIsZero_SI",-1);
	vcdp->declBit  (c+681,"top riscv_core_i ex_stage_i alu_i int_div div_i OpBSign_SI",-1);
	vcdp->declBus  (c+951,"top riscv_core_i ex_stage_i alu_i int_div div_i OpCode_SI",-1,1,0);
	vcdp->declBit  (c+632,"top riscv_core_i ex_stage_i alu_i int_div div_i InVld_SI",-1);
	vcdp->declBit  (c+112,"top riscv_core_i ex_stage_i alu_i int_div div_i OutRdy_SI",-1);
	vcdp->declBit  (c+305,"top riscv_core_i ex_stage_i alu_i int_div div_i OutVld_SO",-1);
	vcdp->declBus  (c+591,"top riscv_core_i ex_stage_i alu_i int_div div_i Res_DO",-1,31,0);
	vcdp->declBus  (c+792,"top riscv_core_i ex_stage_i alu_i int_div div_i ResReg_DP",-1,31,0);
	vcdp->declBus  (c+545,"top riscv_core_i ex_stage_i alu_i int_div div_i ResReg_DN",-1,31,0);
	vcdp->declBus  (c+592,"top riscv_core_i ex_stage_i alu_i int_div div_i ResReg_DP_rev",-1,31,0);
	vcdp->declBus  (c+793,"top riscv_core_i ex_stage_i alu_i int_div div_i AReg_DP",-1,31,0);
	vcdp->declBus  (c+546,"top riscv_core_i ex_stage_i alu_i int_div div_i AReg_DN",-1,31,0);
	vcdp->declBus  (c+794,"top riscv_core_i ex_stage_i alu_i int_div div_i BReg_DP",-1,31,0);
	vcdp->declBus  (c+540,"top riscv_core_i ex_stage_i alu_i int_div div_i BReg_DN",-1,31,0);
	vcdp->declBit  (c+547,"top riscv_core_i ex_stage_i alu_i int_div div_i RemSel_SN",-1);
	vcdp->declBit  (c+795,"top riscv_core_i ex_stage_i alu_i int_div div_i RemSel_SP",-1);
	vcdp->declBit  (c+548,"top riscv_core_i ex_stage_i alu_i int_div div_i CompInv_SN",-1);
	vcdp->declBit  (c+796,"top riscv_core_i ex_stage_i alu_i int_div div_i CompInv_SP",-1);
	vcdp->declBit  (c+549,"top riscv_core_i ex_stage_i alu_i int_div div_i ResInv_SN",-1);
	vcdp->declBit  (c+797,"top riscv_core_i ex_stage_i alu_i int_div div_i ResInv_SP",-1);
	vcdp->declBus  (c+463,"top riscv_core_i ex_stage_i alu_i int_div div_i AddMux_D",-1,31,0);
	vcdp->declBus  (c+580,"top riscv_core_i ex_stage_i alu_i int_div div_i AddOut_D",-1,31,0);
	vcdp->declBus  (c+464,"top riscv_core_i ex_stage_i alu_i int_div div_i AddTmp_D",-1,31,0);
	vcdp->declBus  (c+541,"top riscv_core_i ex_stage_i alu_i int_div div_i BMux_D",-1,31,0);
	vcdp->declBus  (c+593,"top riscv_core_i ex_stage_i alu_i int_div div_i OutMux_D",-1,31,0);
	vcdp->declBus  (c+798,"top riscv_core_i ex_stage_i alu_i int_div div_i Cnt_DP",-1,5,0);
	vcdp->declBus  (c+542,"top riscv_core_i ex_stage_i alu_i int_div div_i Cnt_DN",-1,5,0);
	vcdp->declBit  (c+799,"top riscv_core_i ex_stage_i alu_i int_div div_i CntZero_S",-1);
	vcdp->declBit  (c+465,"top riscv_core_i ex_stage_i alu_i int_div div_i ARegEn_S",-1);
	vcdp->declBit  (c+466,"top riscv_core_i ex_stage_i alu_i int_div div_i BRegEn_S",-1);
	vcdp->declBit  (c+467,"top riscv_core_i ex_stage_i alu_i int_div div_i ResRegEn_S",-1);
	vcdp->declBit  (c+687,"top riscv_core_i ex_stage_i alu_i int_div div_i ABComp_S",-1);
	vcdp->declBit  (c+581,"top riscv_core_i ex_stage_i alu_i int_div div_i PmSel_S",-1);
	vcdp->declBit  (c+468,"top riscv_core_i ex_stage_i alu_i int_div div_i LoadEn_S",-1);
	vcdp->declBus  (c+469,"top riscv_core_i ex_stage_i alu_i int_div div_i State_SN",-1,1,0);
	vcdp->declBus  (c+800,"top riscv_core_i ex_stage_i alu_i int_div div_i State_SP",-1,1,0);
	// Tracing: top riscv_core_i ex_stage_i alu_i int_div div_i index // Ignored: Verilator trace_off at ../rtl/riscv_alu_div.sv:89
	vcdp->declBus  (c+999,"top riscv_core_i ex_stage_i mult_i SHARED_DSP_MULT",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i ex_stage_i mult_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i ex_stage_i mult_i rst_n",-1);
	vcdp->declBit  (c+887,"top riscv_core_i ex_stage_i mult_i enable_i",-1);
	vcdp->declBus  (c+883,"top riscv_core_i ex_stage_i mult_i operator_i",-1,2,0);
	vcdp->declBit  (c+888,"top riscv_core_i ex_stage_i mult_i short_subword_i",-1);
	vcdp->declBus  (c+889,"top riscv_core_i ex_stage_i mult_i short_signed_i",-1,1,0);
	vcdp->declBus  (c+884,"top riscv_core_i ex_stage_i mult_i op_a_i",-1,31,0);
	vcdp->declBus  (c+885,"top riscv_core_i ex_stage_i mult_i op_b_i",-1,31,0);
	vcdp->declBus  (c+886,"top riscv_core_i ex_stage_i mult_i op_c_i",-1,31,0);
	vcdp->declBus  (c+890,"top riscv_core_i ex_stage_i mult_i imm_i",-1,4,0);
	vcdp->declBus  (c+894,"top riscv_core_i ex_stage_i mult_i dot_signed_i",-1,1,0);
	vcdp->declBus  (c+891,"top riscv_core_i ex_stage_i mult_i dot_op_a_i",-1,31,0);
	vcdp->declBus  (c+892,"top riscv_core_i ex_stage_i mult_i dot_op_b_i",-1,31,0);
	vcdp->declBus  (c+893,"top riscv_core_i ex_stage_i mult_i dot_op_c_i",-1,31,0);
	vcdp->declBus  (c+304,"top riscv_core_i ex_stage_i mult_i result_o",-1,31,0);
	vcdp->declBit  (c+104,"top riscv_core_i ex_stage_i mult_i multicycle_o",-1);
	vcdp->declBit  (c+306,"top riscv_core_i ex_stage_i mult_i ready_o",-1);
	vcdp->declBit  (c+112,"top riscv_core_i ex_stage_i mult_i ex_ready_i",-1);
	vcdp->declBus  (c+470,"top riscv_core_i ex_stage_i mult_i short_op_a",-1,16,0);
	vcdp->declBus  (c+471,"top riscv_core_i ex_stage_i mult_i short_op_b",-1,16,0);
	vcdp->declQuad (c+550,"top riscv_core_i ex_stage_i mult_i short_op_c",-1,32,0);
	vcdp->declQuad (c+472,"top riscv_core_i ex_stage_i mult_i short_mul",-1,33,0);
	vcdp->declQuad (c+474,"top riscv_core_i ex_stage_i mult_i short_mac",-1,33,0);
	vcdp->declBus  (c+952,"top riscv_core_i ex_stage_i mult_i short_round",-1,31,0);
	vcdp->declBus  (c+953,"top riscv_core_i ex_stage_i mult_i short_round_tmp",-1,31,0);
	vcdp->declQuad (c+476,"top riscv_core_i ex_stage_i mult_i short_result",-1,33,0);
	vcdp->declBit  (c+478,"top riscv_core_i ex_stage_i mult_i short_mac_msb1",-1);
	vcdp->declBit  (c+479,"top riscv_core_i ex_stage_i mult_i short_mac_msb0",-1);
	vcdp->declBus  (c+582,"top riscv_core_i ex_stage_i mult_i short_imm",-1,4,0);
	vcdp->declBus  (c+480,"top riscv_core_i ex_stage_i mult_i short_subword",-1,1,0);
	vcdp->declBus  (c+481,"top riscv_core_i ex_stage_i mult_i short_signed",-1,1,0);
	vcdp->declBit  (c+482,"top riscv_core_i ex_stage_i mult_i short_shift_arith",-1);
	vcdp->declBus  (c+483,"top riscv_core_i ex_stage_i mult_i mulh_imm",-1,4,0);
	vcdp->declBus  (c+484,"top riscv_core_i ex_stage_i mult_i mulh_subword",-1,1,0);
	vcdp->declBus  (c+485,"top riscv_core_i ex_stage_i mult_i mulh_signed",-1,1,0);
	vcdp->declBit  (c+486,"top riscv_core_i ex_stage_i mult_i mulh_shift_arith",-1);
	vcdp->declBit  (c+801,"top riscv_core_i ex_stage_i mult_i mulh_carry_q",-1);
	vcdp->declBit  (c+487,"top riscv_core_i ex_stage_i mult_i mulh_active",-1);
	vcdp->declBit  (c+488,"top riscv_core_i ex_stage_i mult_i mulh_save",-1);
	vcdp->declBit  (c+489,"top riscv_core_i ex_stage_i mult_i mulh_clearcarry",-1);
	vcdp->declBit  (c+306,"top riscv_core_i ex_stage_i mult_i mulh_ready",-1);
	vcdp->declBus  (c+802,"top riscv_core_i ex_stage_i mult_i mulh_CS",-1,2,0);
	vcdp->declBus  (c+490,"top riscv_core_i ex_stage_i mult_i mulh_NS",-1,2,0);
	vcdp->declBus  (c+954,"top riscv_core_i ex_stage_i mult_i int_op_a_msu",-1,31,0);
	vcdp->declBus  (c+955,"top riscv_core_i ex_stage_i mult_i int_op_b_msu",-1,31,0);
	vcdp->declBus  (c+956,"top riscv_core_i ex_stage_i mult_i int_result",-1,31,0);
	vcdp->declBit  (c+957,"top riscv_core_i ex_stage_i mult_i int_is_msu",-1);
	vcdp->declBus  (c+688,"top riscv_core_i ex_stage_i mult_i dot_char_result",-1,31,0);
	vcdp->declBus  (c+689,"top riscv_core_i ex_stage_i mult_i dot_short_result",-1,31,0);
	vcdp->declQuad (c+690,"top riscv_core_i ex_stage_i mult_i genblk1 dot_char_op_a",-1,35,0);
	vcdp->declQuad (c+692,"top riscv_core_i ex_stage_i mult_i genblk1 dot_char_op_b",-1,35,0);
	vcdp->declArray(c+694,"top riscv_core_i ex_stage_i mult_i genblk1 dot_char_mul",-1,71,0);
	vcdp->declQuad (c+697,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_op_a",-1,33,0);
	vcdp->declQuad (c+699,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_op_b",-1,33,0);
	vcdp->declArray(c+701,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_mul",-1,67,0);
	vcdp->declBit  (c+958,"top riscv_core_i load_store_unit_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i load_store_unit_i rst_n",-1);
	vcdp->declBit  (c+38,"top riscv_core_i load_store_unit_i data_req_o",-1);
	vcdp->declBit  (c+38,"top riscv_core_i load_store_unit_i data_gnt_i",-1);
	vcdp->declBit  (c+848,"top riscv_core_i load_store_unit_i data_rvalid_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i load_store_unit_i data_err_i",-1);
	vcdp->declBus  (c+553,"top riscv_core_i load_store_unit_i data_addr_o",-1,31,0);
	vcdp->declBit  (c+863,"top riscv_core_i load_store_unit_i data_we_o",-1);
	vcdp->declBus  (c+595,"top riscv_core_i load_store_unit_i data_be_o",-1,3,0);
	vcdp->declBus  (c+556,"top riscv_core_i load_store_unit_i data_wdata_o",-1,31,0);
	vcdp->declBus  (c+849,"top riscv_core_i load_store_unit_i data_rdata_i",-1,31,0);
	vcdp->declBit  (c+863,"top riscv_core_i load_store_unit_i data_we_ex_i",-1);
	vcdp->declBus  (c+909,"top riscv_core_i load_store_unit_i data_type_ex_i",-1,1,0);
	vcdp->declBus  (c+872,"top riscv_core_i load_store_unit_i data_wdata_ex_i",-1,31,0);
	vcdp->declBus  (c+911,"top riscv_core_i load_store_unit_i data_reg_offset_ex_i",-1,1,0);
	vcdp->declBit  (c+910,"top riscv_core_i load_store_unit_i data_sign_ext_ex_i",-1);
	vcdp->declBus  (c+602,"top riscv_core_i load_store_unit_i data_rdata_ex_o",-1,31,0);
	vcdp->declBit  (c+912,"top riscv_core_i load_store_unit_i data_req_ex_i",-1);
	vcdp->declBus  (c+877,"top riscv_core_i load_store_unit_i operand_a_ex_i",-1,31,0);
	vcdp->declBus  (c+878,"top riscv_core_i load_store_unit_i operand_b_ex_i",-1,31,0);
	vcdp->declBit  (c+871,"top riscv_core_i load_store_unit_i addr_useincr_ex_i",-1);
	vcdp->declBit  (c+914,"top riscv_core_i load_store_unit_i data_misaligned_ex_i",-1);
	vcdp->declBit  (c+597,"top riscv_core_i load_store_unit_i data_misaligned_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i load_store_unit_i load_err_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i load_store_unit_i store_err_o",-1);
	vcdp->declBit  (c+116,"top riscv_core_i load_store_unit_i lsu_ready_ex_o",-1);
	vcdp->declBit  (c+115,"top riscv_core_i load_store_unit_i lsu_ready_wb_o",-1);
	vcdp->declBit  (c+114,"top riscv_core_i load_store_unit_i ex_valid_i",-1);
	vcdp->declBit  (c+537,"top riscv_core_i load_store_unit_i busy_o",-1);
	vcdp->declBit  (c+96,"top riscv_core_i load_store_unit_i con_active",-1);
	vcdp->declBus  (c+92,"top riscv_core_i load_store_unit_i data_addr_con_start",-1,31,0);
	vcdp->declBus  (c+93,"top riscv_core_i load_store_unit_i con_max",-1,31,0);
	vcdp->declBus  (c+851,"top riscv_core_i load_store_unit_i con_cnt",-1,31,0);
	vcdp->declBit  (c+51,"top riscv_core_i load_store_unit_i mac_flag",-1);
	vcdp->declBit  (c+94,"top riscv_core_i load_store_unit_i wb23_active",-1);
	vcdp->declBit  (c+1019,"top riscv_core_i load_store_unit_i w_wb_active",-1);
	vcdp->declBus  (c+95,"top riscv_core_i load_store_unit_i mem_wdata",-1,31,0);
	vcdp->declBus  (c+852,"top riscv_core_i load_store_unit_i data_addr_con",-1,31,0);
	vcdp->declBus  (c+853,"top riscv_core_i load_store_unit_i data_req_ex_i_d",-1,31,0);
	vcdp->declBus  (c+704,"top riscv_core_i load_store_unit_i data_addr_int",-1,31,0);
	vcdp->declBus  (c+803,"top riscv_core_i load_store_unit_i data_type_q",-1,1,0);
	vcdp->declBus  (c+804,"top riscv_core_i load_store_unit_i rdata_offset_q",-1,1,0);
	vcdp->declBit  (c+805,"top riscv_core_i load_store_unit_i data_sign_ext_q",-1);
	vcdp->declBit  (c+806,"top riscv_core_i load_store_unit_i data_we_q",-1);
	vcdp->declBus  (c+705,"top riscv_core_i load_store_unit_i wdata_offset",-1,1,0);
	vcdp->declBus  (c+595,"top riscv_core_i load_store_unit_i data_be",-1,3,0);
	vcdp->declBus  (c+556,"top riscv_core_i load_store_unit_i data_wdata",-1,31,0);
	vcdp->declBit  (c+914,"top riscv_core_i load_store_unit_i misaligned_st",-1);
	vcdp->declBus  (c+807,"top riscv_core_i load_store_unit_i CS",-1,1,0);
	vcdp->declBus  (c+491,"top riscv_core_i load_store_unit_i NS",-1,1,0);
	vcdp->declBus  (c+808,"top riscv_core_i load_store_unit_i rdata_q",-1,31,0);
	vcdp->declBus  (c+706,"top riscv_core_i load_store_unit_i data_rdata_ext",-1,31,0);
	vcdp->declBus  (c+838,"top riscv_core_i load_store_unit_i rdata_w_ext",-1,31,0);
	vcdp->declBus  (c+839,"top riscv_core_i load_store_unit_i rdata_h_ext",-1,31,0);
	vcdp->declBus  (c+840,"top riscv_core_i load_store_unit_i rdata_b_ext",-1,31,0);
	vcdp->declBus  (c+1017,"top riscv_core_i cs_registers_i N_HWLP",-1,31,0);
	vcdp->declBus  (c+1000,"top riscv_core_i cs_registers_i N_HWLP_BITS",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i cs_registers_i N_EXT_CNT",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i cs_registers_i APU",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i cs_registers_i FPU",-1,31,0);
	vcdp->declBus  (c+999,"top riscv_core_i cs_registers_i PULP_SECURE",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i cs_registers_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i cs_registers_i rst_n",-1);
	vcdp->declBus  (c+1007,"top riscv_core_i cs_registers_i core_id_i",-1,3,0);
	vcdp->declBus  (c+1008,"top riscv_core_i cs_registers_i cluster_id_i",-1,5,0);
	vcdp->declBus  (c+1024,"top riscv_core_i cs_registers_i mtvec_o",-1,23,0);
	vcdp->declBus  (c+1025,"top riscv_core_i cs_registers_i utvec_o",-1,23,0);
	vcdp->declBus  (c+1024,"top riscv_core_i cs_registers_i boot_addr_i",-1,23,0);
	vcdp->declBit  (c+841,"top riscv_core_i cs_registers_i csr_access_i",-1);
	vcdp->declBus  (c+604,"top riscv_core_i cs_registers_i csr_addr_i",-1,11,0);
	vcdp->declBus  (c+606,"top riscv_core_i cs_registers_i csr_wdata_i",-1,31,0);
	vcdp->declBus  (c+109,"top riscv_core_i cs_registers_i csr_op_i",-1,1,0);
	vcdp->declBus  (c+605,"top riscv_core_i cs_registers_i csr_rdata_o",-1,31,0);
	vcdp->declBus  (c+1021,"top riscv_core_i cs_registers_i frm_o",-1,2,0);
	vcdp->declBus  (c+1020,"top riscv_core_i cs_registers_i fprec_o",-1,4,0);
	vcdp->declBus  (c+1020,"top riscv_core_i cs_registers_i fflags_i",-1,4,0);
	vcdp->declBit  (c+1009,"top riscv_core_i cs_registers_i fflags_we_i",-1);
	vcdp->declBit  (c+587,"top riscv_core_i cs_registers_i m_irq_enable_o",-1);
	vcdp->declBit  (c+722,"top riscv_core_i cs_registers_i u_irq_enable_o",-1);
	vcdp->declBit  (c+118,"top riscv_core_i cs_registers_i csr_irq_sec_i",-1);
	vcdp->declBit  (c+714,"top riscv_core_i cs_registers_i sec_lvl_o",-1);
	vcdp->declBus  (c+119,"top riscv_core_i cs_registers_i epc_o",-1,31,0);
	vcdp->declBus  (c+721,"top riscv_core_i cs_registers_i priv_lvl_o",-1,1,0);
	vcdp->declBus  (c+869,"top riscv_core_i cs_registers_i pc_if_i",-1,31,0);
	vcdp->declBus  (c+870,"top riscv_core_i cs_registers_i pc_id_i",-1,31,0);
	vcdp->declBit  (c+121,"top riscv_core_i cs_registers_i csr_save_if_i",-1);
	vcdp->declBit  (c+122,"top riscv_core_i cs_registers_i csr_save_id_i",-1);
	vcdp->declBit  (c+124,"top riscv_core_i cs_registers_i csr_restore_mret_i",-1);
	vcdp->declBit  (c+125,"top riscv_core_i cs_registers_i csr_restore_uret_i",-1);
	vcdp->declBus  (c+123,"top riscv_core_i cs_registers_i csr_cause_i",-1,5,0);
	vcdp->declBit  (c+120,"top riscv_core_i cs_registers_i csr_save_cause_i",-1);
	vcdp->declQuad (c+723,"top riscv_core_i cs_registers_i hwlp_start_i",-1,63,0);
	vcdp->declQuad (c+725,"top riscv_core_i cs_registers_i hwlp_end_i",-1,63,0);
	vcdp->declQuad (c+727,"top riscv_core_i cs_registers_i hwlp_cnt_i",-1,63,0);
	vcdp->declBus  (c+128,"top riscv_core_i cs_registers_i hwlp_data_o",-1,31,0);
	vcdp->declBus  (c+126,"top riscv_core_i cs_registers_i hwlp_regid_o",-1,0,0);
	vcdp->declBus  (c+127,"top riscv_core_i cs_registers_i hwlp_we_o",-1,2,0);
	vcdp->declBit  (c+113,"top riscv_core_i cs_registers_i id_valid_i",-1);
	vcdp->declBit  (c+867,"top riscv_core_i cs_registers_i is_compressed_i",-1);
	vcdp->declBit  (c+103,"top riscv_core_i cs_registers_i is_decoding_i",-1);
	vcdp->declBit  (c+136,"top riscv_core_i cs_registers_i imiss_i",-1);
	vcdp->declBit  (c+98,"top riscv_core_i cs_registers_i pc_set_i",-1);
	vcdp->declBit  (c+137,"top riscv_core_i cs_registers_i jump_i",-1);
	vcdp->declBit  (c+873,"top riscv_core_i cs_registers_i branch_i",-1);
	vcdp->declBit  (c+598,"top riscv_core_i cs_registers_i branch_taken_i",-1);
	vcdp->declBit  (c+139,"top riscv_core_i cs_registers_i ld_stall_i",-1);
	vcdp->declBit  (c+138,"top riscv_core_i cs_registers_i jr_stall_i",-1);
	vcdp->declBit  (c+140,"top riscv_core_i cs_registers_i pipeline_stall_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i cs_registers_i apu_typeconflict_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i cs_registers_i apu_contention_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i cs_registers_i apu_dep_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i cs_registers_i apu_wb_i",-1);
	vcdp->declBit  (c+583,"top riscv_core_i cs_registers_i mem_load_i",-1);
	vcdp->declBit  (c+584,"top riscv_core_i cs_registers_i mem_store_i",-1);
	vcdp->declBus  (c+1016,"top riscv_core_i cs_registers_i ext_counters_i",-1,-1,0);
	vcdp->declBus  (c+999,"top riscv_core_i cs_registers_i N_APU_CNT",-1,31,0);
	vcdp->declBus  (c+1079,"top riscv_core_i cs_registers_i N_PERF_COUNTERS",-1,31,0);
	vcdp->declBus  (c+1079,"top riscv_core_i cs_registers_i PERF_EXT_ID",-1,31,0);
	vcdp->declBus  (c+1079,"top riscv_core_i cs_registers_i PERF_APU_ID",-1,31,0);
	vcdp->declBus  (c+1079,"top riscv_core_i cs_registers_i N_PERF_REGS",-1,31,0);
	vcdp->declBus  (c+128,"top riscv_core_i cs_registers_i csr_wdata_int",-1,31,0);
	vcdp->declBus  (c+594,"top riscv_core_i cs_registers_i csr_rdata_int",-1,31,0);
	vcdp->declBit  (c+492,"top riscv_core_i cs_registers_i csr_we_int",-1);
	vcdp->declBus  (c+1080,"top riscv_core_i cs_registers_i frm_q",-1,2,0);
	vcdp->declBus  (c+493,"top riscv_core_i cs_registers_i frm_n",-1,2,0);
	vcdp->declBus  (c+1081,"top riscv_core_i cs_registers_i fflags_q",-1,4,0);
	vcdp->declBus  (c+494,"top riscv_core_i cs_registers_i fflags_n",-1,4,0);
	vcdp->declBus  (c+1082,"top riscv_core_i cs_registers_i fprec_q",-1,4,0);
	vcdp->declBus  (c+495,"top riscv_core_i cs_registers_i fprec_n",-1,4,0);
	vcdp->declBus  (c+809,"top riscv_core_i cs_registers_i mepc_q",-1,31,0);
	vcdp->declBus  (c+496,"top riscv_core_i cs_registers_i mepc_n",-1,31,0);
	vcdp->declBus  (c+1083,"top riscv_core_i cs_registers_i uepc_q",-1,31,0);
	vcdp->declBus  (c+1084,"top riscv_core_i cs_registers_i uepc_n",-1,31,0);
	vcdp->declBus  (c+497,"top riscv_core_i cs_registers_i exception_pc",-1,31,0);
	vcdp->declBus  (c+810,"top riscv_core_i cs_registers_i mstatus_q",-1,5,0);
	vcdp->declBus  (c+498,"top riscv_core_i cs_registers_i mstatus_n",-1,5,0);
	vcdp->declBus  (c+811,"top riscv_core_i cs_registers_i mcause_q",-1,5,0);
	vcdp->declBus  (c+499,"top riscv_core_i cs_registers_i mcause_n",-1,5,0);
	vcdp->declBus  (c+1085,"top riscv_core_i cs_registers_i ucause_q",-1,5,0);
	vcdp->declBus  (c+1086,"top riscv_core_i cs_registers_i ucause_n",-1,5,0);
	vcdp->declBus  (c+1024,"top riscv_core_i cs_registers_i mtvec_n",-1,23,0);
	vcdp->declBus  (c+1024,"top riscv_core_i cs_registers_i mtvec_q",-1,23,0);
	vcdp->declBus  (c+1087,"top riscv_core_i cs_registers_i mtvec_reg_q",-1,23,0);
	vcdp->declBus  (c+1088,"top riscv_core_i cs_registers_i utvec_n",-1,23,0);
	vcdp->declBus  (c+1025,"top riscv_core_i cs_registers_i utvec_q",-1,23,0);
	vcdp->declBit  (c+500,"top riscv_core_i cs_registers_i is_irq",-1);
	vcdp->declBus  (c+501,"top riscv_core_i cs_registers_i priv_lvl_n",-1,1,0);
	vcdp->declBus  (c+721,"top riscv_core_i cs_registers_i priv_lvl_q",-1,1,0);
	vcdp->declBus  (c+1089,"top riscv_core_i cs_registers_i priv_lvl_reg_q",-1,1,0);
	vcdp->declBit  (c+812,"top riscv_core_i cs_registers_i id_valid_q",-1);
	vcdp->declBus  (c+585,"top riscv_core_i cs_registers_i PCCR_in",-1,11,0);
	vcdp->declBus  (c+502,"top riscv_core_i cs_registers_i PCCR_inc",-1,11,0);
	vcdp->declBus  (c+813,"top riscv_core_i cs_registers_i PCCR_inc_q",-1,11,0);
	vcdp->declArray(c+814,"top riscv_core_i cs_registers_i PCCR_q",-1,383,0);
	vcdp->declArray(c+503,"top riscv_core_i cs_registers_i PCCR_n",-1,383,0);
	vcdp->declBus  (c+515,"top riscv_core_i cs_registers_i PCMR_n",-1,1,0);
	vcdp->declBus  (c+826,"top riscv_core_i cs_registers_i PCMR_q",-1,1,0);
	vcdp->declBus  (c+516,"top riscv_core_i cs_registers_i PCER_n",-1,11,0);
	vcdp->declBus  (c+827,"top riscv_core_i cs_registers_i PCER_q",-1,11,0);
	vcdp->declBus  (c+707,"top riscv_core_i cs_registers_i perf_rdata",-1,31,0);
	vcdp->declBus  (c+708,"top riscv_core_i cs_registers_i pccr_index",-1,4,0);
	vcdp->declBit  (c+709,"top riscv_core_i cs_registers_i pccr_all_sel",-1);
	vcdp->declBit  (c+710,"top riscv_core_i cs_registers_i is_pccr",-1);
	vcdp->declBit  (c+711,"top riscv_core_i cs_registers_i is_pcer",-1);
	vcdp->declBit  (c+712,"top riscv_core_i cs_registers_i is_pcmr",-1);
	// Tracing: top riscv_core_i cs_registers_i i // Ignored: Verilator trace_off at ../rtl/riscv_cs_registers.sv:717
	vcdp->declBus  (c+1090,"top riscv_core_i cs_registers_i unnamedblk1 i",-1,31,0);
	vcdp->declBus  (c+828,"top riscv_core_i cs_registers_i unnamedblk3 i",-1,31,0);
	vcdp->declBus  (c+829,"top riscv_core_i cs_registers_i unnamedblk2 i",-1,31,0);
	vcdp->declBit  (c+958,"top riscv_core_i debug_unit_i clk",-1);
	vcdp->declBit  (c+959,"top riscv_core_i debug_unit_i rst_n",-1);
	vcdp->declBit  (c+966,"top riscv_core_i debug_unit_i debug_req_i",-1);
	vcdp->declBit  (c+16,"top riscv_core_i debug_unit_i debug_gnt_o",-1);
	vcdp->declBit  (c+715,"top riscv_core_i debug_unit_i debug_rvalid_o",-1);
	vcdp->declBus  (c+969,"top riscv_core_i debug_unit_i debug_addr_i",-1,14,0);
	vcdp->declBit  (c+970,"top riscv_core_i debug_unit_i debug_we_i",-1);
	vcdp->declBus  (c+971,"top riscv_core_i debug_unit_i debug_wdata_i",-1,31,0);
	vcdp->declBus  (c+17,"top riscv_core_i debug_unit_i debug_rdata_o",-1,31,0);
	vcdp->declBit  (c+18,"top riscv_core_i debug_unit_i debug_halted_o",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i debug_unit_i debug_halt_i",-1);
	vcdp->declBit  (c+1009,"top riscv_core_i debug_unit_i debug_resume_i",-1);
	vcdp->declBus  (c+729,"top riscv_core_i debug_unit_i settings_o",-1,5,0);
	vcdp->declBit  (c+132,"top riscv_core_i debug_unit_i trap_i",-1);
	vcdp->declBus  (c+101,"top riscv_core_i debug_unit_i exc_cause_i",-1,5,0);
	vcdp->declBit  (c+131,"top riscv_core_i debug_unit_i stall_o",-1);
	vcdp->declBit  (c+129,"top riscv_core_i debug_unit_i dbg_req_o",-1);
	vcdp->declBit  (c+130,"top riscv_core_i debug_unit_i dbg_ack_i",-1);
	vcdp->declBit  (c+730,"top riscv_core_i debug_unit_i regfile_rreq_o",-1);
	vcdp->declBus  (c+731,"top riscv_core_i debug_unit_i regfile_raddr_o",-1,5,0);
	vcdp->declBus  (c+133,"top riscv_core_i debug_unit_i regfile_rdata_i",-1,31,0);
	vcdp->declBit  (c+134,"top riscv_core_i debug_unit_i regfile_wreq_o",-1);
	vcdp->declBus  (c+976,"top riscv_core_i debug_unit_i regfile_waddr_o",-1,5,0);
	vcdp->declBus  (c+971,"top riscv_core_i debug_unit_i regfile_wdata_o",-1,31,0);
	vcdp->declBit  (c+732,"top riscv_core_i debug_unit_i csr_req_o",-1);
	vcdp->declBus  (c+733,"top riscv_core_i debug_unit_i csr_addr_o",-1,11,0);
	vcdp->declBit  (c+135,"top riscv_core_i debug_unit_i csr_we_o",-1);
	vcdp->declBus  (c+734,"top riscv_core_i debug_unit_i csr_wdata_o",-1,31,0);
	vcdp->declBus  (c+605,"top riscv_core_i debug_unit_i csr_rdata_i",-1,31,0);
	vcdp->declBus  (c+869,"top riscv_core_i debug_unit_i pc_if_i",-1,31,0);
	vcdp->declBus  (c+870,"top riscv_core_i debug_unit_i pc_id_i",-1,31,0);
	vcdp->declBus  (c+874,"top riscv_core_i debug_unit_i pc_ex_i",-1,31,0);
	vcdp->declBit  (c+913,"top riscv_core_i debug_unit_i data_load_event_i",-1);
	vcdp->declBit  (c+865,"top riscv_core_i debug_unit_i instr_valid_id_i",-1);
	vcdp->declBit  (c+143,"top riscv_core_i debug_unit_i sleeping_i",-1);
	vcdp->declBit  (c+873,"top riscv_core_i debug_unit_i branch_in_ex_i",-1);
	vcdp->declBit  (c+598,"top riscv_core_i debug_unit_i branch_taken_i",-1);
	vcdp->declBit  (c+735,"top riscv_core_i debug_unit_i jump_req_o",-1);
	vcdp->declBus  (c+734,"top riscv_core_i debug_unit_i jump_addr_o",-1,31,0);
	vcdp->declBus  (c+830,"top riscv_core_i debug_unit_i rdata_sel_q",-1,2,0);
	vcdp->declBus  (c+517,"top riscv_core_i debug_unit_i rdata_sel_n",-1,2,0);
	vcdp->declBus  (c+831,"top riscv_core_i debug_unit_i state_q",-1,0,0);
	vcdp->declBus  (c+518,"top riscv_core_i debug_unit_i state_n",-1,0,0);
	vcdp->declBus  (c+729,"top riscv_core_i debug_unit_i settings_q",-1,5,0);
	vcdp->declBus  (c+519,"top riscv_core_i debug_unit_i settings_n",-1,5,0);
	vcdp->declBus  (c+832,"top riscv_core_i debug_unit_i addr_q",-1,14,0);
	vcdp->declBus  (c+734,"top riscv_core_i debug_unit_i wdata_q",-1,31,0);
	vcdp->declBit  (c+730,"top riscv_core_i debug_unit_i regfile_rreq_q",-1);
	vcdp->declBit  (c+520,"top riscv_core_i debug_unit_i regfile_rreq_n",-1);
	vcdp->declBit  (c+833,"top riscv_core_i debug_unit_i regfile_fp_sel_q",-1);
	vcdp->declBit  (c+521,"top riscv_core_i debug_unit_i regfile_fp_sel_n",-1);
	vcdp->declBit  (c+735,"top riscv_core_i debug_unit_i jump_req_q",-1);
	vcdp->declBit  (c+522,"top riscv_core_i debug_unit_i jump_req_n",-1);
	vcdp->declBit  (c+732,"top riscv_core_i debug_unit_i csr_req_q",-1);
	vcdp->declBit  (c+523,"top riscv_core_i debug_unit_i csr_req_n",-1);
	vcdp->declBit  (c+134,"top riscv_core_i debug_unit_i regfile_wreq",-1);
	vcdp->declBit  (c+524,"top riscv_core_i debug_unit_i regfile_fp_wr",-1);
	vcdp->declBus  (c+834,"top riscv_core_i debug_unit_i stall_cs",-1,1,0);
	vcdp->declBus  (c+525,"top riscv_core_i debug_unit_i stall_ns",-1,1,0);
	vcdp->declBus  (c+526,"top riscv_core_i debug_unit_i dbg_rdata",-1,31,0);
	vcdp->declBit  (c+527,"top riscv_core_i debug_unit_i dbg_resume",-1);
	vcdp->declBit  (c+528,"top riscv_core_i debug_unit_i dbg_halt",-1);
	vcdp->declBus  (c+835,"top riscv_core_i debug_unit_i dbg_cause_q",-1,5,0);
	vcdp->declBus  (c+529,"top riscv_core_i debug_unit_i dbg_cause_n",-1,5,0);
	vcdp->declBit  (c+836,"top riscv_core_i debug_unit_i dbg_ssth_q",-1);
	vcdp->declBit  (c+530,"top riscv_core_i debug_unit_i dbg_ssth_n",-1);
	vcdp->declBit  (c+531,"top riscv_core_i debug_unit_i ssth_clear",-1);
	vcdp->declBus  (c+837,"top riscv_core_i debug_unit_i pc_tracking_fsm_cs",-1,1,0);
	vcdp->declBus  (c+532,"top riscv_core_i debug_unit_i pc_tracking_fsm_ns",-1,1,0);
	vcdp->declBus  (c+533,"top riscv_core_i debug_unit_i ppc_int",-1,31,0);
	vcdp->declBus  (c+534,"top riscv_core_i debug_unit_i npc_int",-1,31,0);
	vcdp->declBus  (c+1091,"top ram_i ADDR_WIDTH",-1,31,0);
	vcdp->declBit  (c+958,"top ram_i clk",-1);
	vcdp->declBit  (c+20,"top ram_i instr_req_i",-1);
	vcdp->declBus  (c+535,"top ram_i instr_addr_i",-1,19,0);
	vcdp->declArray(c+844,"top ram_i instr_rdata_o",-1,127,0);
	vcdp->declBit  (c+843,"top ram_i instr_rvalid_o",-1);
	vcdp->declBit  (c+20,"top ram_i instr_gnt_o",-1);
	vcdp->declBit  (c+38,"top ram_i data_req_i",-1);
	vcdp->declBus  (c+554,"top ram_i data_addr_i",-1,19,0);
	vcdp->declBit  (c+863,"top ram_i data_we_i",-1);
	vcdp->declBus  (c+595,"top ram_i data_be_i",-1,3,0);
	vcdp->declBus  (c+556,"top ram_i data_wdata_i",-1,31,0);
	vcdp->declBus  (c+849,"top ram_i data_rdata_o",-1,31,0);
	vcdp->declArray(c+854,"top ram_i data_rdata_o_m128",-1,127,0);
	vcdp->declBit  (c+848,"top ram_i data_rvalid_o",-1);
	vcdp->declBit  (c+38,"top ram_i data_gnt_o",-1);
	vcdp->declBus  (c+1091,"top ram_i dp_ram_i ADDR_WIDTH",-1,31,0);
	vcdp->declBit  (c+958,"top ram_i dp_ram_i clk",-1);
	vcdp->declBit  (c+20,"top ram_i dp_ram_i en_a_i",-1);
	vcdp->declBus  (c+535,"top ram_i dp_ram_i addr_a_i",-1,19,0);
	vcdp->declBus  (c+1078,"top ram_i dp_ram_i wdata_a_i",-1,31,0);
	vcdp->declArray(c+844,"top ram_i dp_ram_i rdata_a_o",-1,127,0);
	vcdp->declBit  (c+1009,"top ram_i dp_ram_i we_a_i",-1);
	vcdp->declBus  (c+1092,"top ram_i dp_ram_i be_a_i",-1,3,0);
	vcdp->declBit  (c+38,"top ram_i dp_ram_i en_b_i",-1);
	vcdp->declBus  (c+554,"top ram_i dp_ram_i addr_b_i",-1,19,0);
	vcdp->declBus  (c+556,"top ram_i dp_ram_i wdata_b_i",-1,31,0);
	vcdp->declBus  (c+849,"top ram_i dp_ram_i rdata_b_o",-1,31,0);
	vcdp->declArray(c+854,"top ram_i dp_ram_i rdata_c_o",-1,127,0);
	vcdp->declBit  (c+863,"top ram_i dp_ram_i we_b_i",-1);
	vcdp->declBus  (c+595,"top ram_i dp_ram_i be_b_i",-1,3,0);
	vcdp->declBus  (c+1093,"top ram_i dp_ram_i bytes",-1,31,0);
	// Tracing: top ram_i dp_ram_i mem // Ignored: Wide memory > --trace-max-array ents at dp_ram.sv:38
	vcdp->declBus  (c+555,"top ram_i dp_ram_i addr_b_int",-1,19,0);
	vcdp->declBus  (c+999,"apu_core_package SHARED_INT_MULT",-1,31,0);
	vcdp->declBus  (c+1017,"apu_core_package APU_FLAGS_FP",-1,31,0);
	vcdp->declBus  (c+1000,"apu_core_package PIPE_REG_DSP_MULT",-1,31,0);
	vcdp->declBus  (c+999,"apu_core_package APU_FLAGS_DSP_MULT",-1,31,0);
	vcdp->declBus  (c+1000,"apu_core_package APU_FLAGS_INT_MULT",-1,31,0);
	vcdp->declBus  (c+1000,"apu_core_package PIPE_REG_ADDSUB",-1,31,0);
	vcdp->declBus  (c+1000,"apu_core_package PIPE_REG_MULT",-1,31,0);
	vcdp->declBus  (c+1000,"apu_core_package PIPE_REG_CAST",-1,31,0);
	vcdp->declBus  (c+1017,"apu_core_package PIPE_REG_MAC",-1,31,0);
	vcdp->declBus  (c+1094,"apu_core_package PIPE_REG_DIV",-1,31,0);
	vcdp->declBus  (c+1004,"apu_core_package PIPE_REG_SQRT",-1,31,0);
	vcdp->declBus  (c+1095,"riscv_defines OPCODE_SYSTEM",-1,6,0);
	vcdp->declBus  (c+1096,"riscv_defines OPCODE_FENCE",-1,6,0);
	vcdp->declBus  (c+1097,"riscv_defines OPCODE_OP",-1,6,0);
	vcdp->declBus  (c+1098,"riscv_defines OPCODE_OPIMM",-1,6,0);
	vcdp->declBus  (c+1099,"riscv_defines OPCODE_STORE",-1,6,0);
	vcdp->declBus  (c+1100,"riscv_defines OPCODE_LOAD",-1,6,0);
	vcdp->declBus  (c+1101,"riscv_defines OPCODE_BRANCH",-1,6,0);
	vcdp->declBus  (c+1102,"riscv_defines OPCODE_JALR",-1,6,0);
	vcdp->declBus  (c+1103,"riscv_defines OPCODE_JAL",-1,6,0);
	vcdp->declBus  (c+1104,"riscv_defines OPCODE_AUIPC",-1,6,0);
	vcdp->declBus  (c+1105,"riscv_defines OPCODE_LUI",-1,6,0);
	vcdp->declBus  (c+1106,"riscv_defines OPCODE_OP_FP",-1,6,0);
	vcdp->declBus  (c+1107,"riscv_defines OPCODE_OP_FMADD",-1,6,0);
	vcdp->declBus  (c+1108,"riscv_defines OPCODE_OP_FNMADD",-1,6,0);
	vcdp->declBus  (c+1109,"riscv_defines OPCODE_OP_FMSUB",-1,6,0);
	vcdp->declBus  (c+1110,"riscv_defines OPCODE_OP_FNMSUB",-1,6,0);
	vcdp->declBus  (c+1111,"riscv_defines OPCODE_STORE_FP",-1,6,0);
	vcdp->declBus  (c+1112,"riscv_defines OPCODE_LOAD_FP",-1,6,0);
	vcdp->declBus  (c+1113,"riscv_defines OPCODE_STR_OPS",-1,6,0);
	vcdp->declBus  (c+1017,"riscv_defines STR_OP_WIDTH",-1,31,0);
	vcdp->declBus  (c+1011,"riscv_defines STR_OP_UPPER",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines STR_OP_LOWER",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines STR_OP_LEET",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines STR_OP_ROT13",-1,1,0);
	vcdp->declBus  (c+1117,"riscv_defines OPCODE_MAC_OPS",-1,6,0);
	vcdp->declBus  (c+1001,"riscv_defines MAC_OP_WIDTH",-1,31,0);
	vcdp->declBus  (c+1021,"riscv_defines MAC_OP",-1,2,0);
	vcdp->declBus  (c+1118,"riscv_defines CON_2X2_OP",-1,2,0);
	vcdp->declBus  (c+1119,"riscv_defines CON_OP",-1,2,0);
	vcdp->declBus  (c+1120,"riscv_defines WB23_OP",-1,2,0);
	vcdp->declBus  (c+1121,"riscv_defines MAX_POOL_OP",-1,2,0);
	vcdp->declBus  (c+1122,"riscv_defines RELU_OP",-1,2,0);
	vcdp->declBus  (c+1123,"riscv_defines W_WB_OP",-1,2,0);
	vcdp->declBus  (c+1124,"riscv_defines OPCODE_PULP_OP",-1,6,0);
	vcdp->declBus  (c+1125,"riscv_defines OPCODE_VECOP",-1,6,0);
	vcdp->declBus  (c+1126,"riscv_defines OPCODE_HWLOOP",-1,6,0);
	vcdp->declBus  (c+1115,"riscv_defines REGC_S1",-1,1,0);
	vcdp->declBus  (c+1011,"riscv_defines REGC_S4",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines REGC_RD",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines REGC_ZERO",-1,1,0);
	vcdp->declBus  (c+1127,"riscv_defines ALU_OP_WIDTH",-1,31,0);
	vcdp->declBus  (c+1128,"riscv_defines ALU_ADD",-1,6,0);
	vcdp->declBus  (c+1129,"riscv_defines ALU_SUB",-1,6,0);
	vcdp->declBus  (c+1130,"riscv_defines ALU_ADDU",-1,6,0);
	vcdp->declBus  (c+1131,"riscv_defines ALU_SUBU",-1,6,0);
	vcdp->declBus  (c+1132,"riscv_defines ALU_ADDR",-1,6,0);
	vcdp->declBus  (c+1133,"riscv_defines ALU_SUBR",-1,6,0);
	vcdp->declBus  (c+1134,"riscv_defines ALU_ADDUR",-1,6,0);
	vcdp->declBus  (c+1135,"riscv_defines ALU_SUBUR",-1,6,0);
	vcdp->declBus  (c+1136,"riscv_defines ALU_XOR",-1,6,0);
	vcdp->declBus  (c+1137,"riscv_defines ALU_OR",-1,6,0);
	vcdp->declBus  (c+1138,"riscv_defines ALU_AND",-1,6,0);
	vcdp->declBus  (c+1139,"riscv_defines ALU_SRA",-1,6,0);
	vcdp->declBus  (c+1140,"riscv_defines ALU_SRL",-1,6,0);
	vcdp->declBus  (c+1141,"riscv_defines ALU_ROR",-1,6,0);
	vcdp->declBus  (c+1111,"riscv_defines ALU_SLL",-1,6,0);
	vcdp->declBus  (c+1142,"riscv_defines ALU_BEXT",-1,6,0);
	vcdp->declBus  (c+1143,"riscv_defines ALU_BEXTU",-1,6,0);
	vcdp->declBus  (c+1144,"riscv_defines ALU_BINS",-1,6,0);
	vcdp->declBus  (c+1117,"riscv_defines ALU_BCLR",-1,6,0);
	vcdp->declBus  (c+1145,"riscv_defines ALU_BSET",-1,6,0);
	vcdp->declBus  (c+1146,"riscv_defines ALU_FF1",-1,6,0);
	vcdp->declBus  (c+1105,"riscv_defines ALU_FL1",-1,6,0);
	vcdp->declBus  (c+1147,"riscv_defines ALU_CNT",-1,6,0);
	vcdp->declBus  (c+1148,"riscv_defines ALU_CLB",-1,6,0);
	vcdp->declBus  (c+1149,"riscv_defines ALU_EXTS",-1,6,0);
	vcdp->declBus  (c+1150,"riscv_defines ALU_EXT",-1,6,0);
	vcdp->declBus  (c+1151,"riscv_defines ALU_LTS",-1,6,0);
	vcdp->declBus  (c+1152,"riscv_defines ALU_LTU",-1,6,0);
	vcdp->declBus  (c+1153,"riscv_defines ALU_LES",-1,6,0);
	vcdp->declBus  (c+1154,"riscv_defines ALU_LEU",-1,6,0);
	vcdp->declBus  (c+1155,"riscv_defines ALU_GTS",-1,6,0);
	vcdp->declBus  (c+1156,"riscv_defines ALU_GTU",-1,6,0);
	vcdp->declBus  (c+1157,"riscv_defines ALU_GES",-1,6,0);
	vcdp->declBus  (c+1113,"riscv_defines ALU_GEU",-1,6,0);
	vcdp->declBus  (c+1158,"riscv_defines ALU_EQ",-1,6,0);
	vcdp->declBus  (c+1159,"riscv_defines ALU_NE",-1,6,0);
	vcdp->declBus  (c+1160,"riscv_defines ALU_SLTS",-1,6,0);
	vcdp->declBus  (c+1100,"riscv_defines ALU_SLTU",-1,6,0);
	vcdp->declBus  (c+1161,"riscv_defines ALU_SLETS",-1,6,0);
	vcdp->declBus  (c+1112,"riscv_defines ALU_SLETU",-1,6,0);
	vcdp->declBus  (c+1162,"riscv_defines ALU_ABS",-1,6,0);
	vcdp->declBus  (c+1163,"riscv_defines ALU_CLIP",-1,6,0);
	vcdp->declBus  (c+1104,"riscv_defines ALU_CLIPU",-1,6,0);
	vcdp->declBus  (c+1164,"riscv_defines ALU_INS",-1,6,0);
	vcdp->declBus  (c+1165,"riscv_defines ALU_MIN",-1,6,0);
	vcdp->declBus  (c+1166,"riscv_defines ALU_MINU",-1,6,0);
	vcdp->declBus  (c+1167,"riscv_defines ALU_MAX",-1,6,0);
	vcdp->declBus  (c+1098,"riscv_defines ALU_MAXU",-1,6,0);
	vcdp->declBus  (c+1168,"riscv_defines ALU_DIVU",-1,6,0);
	vcdp->declBus  (c+1169,"riscv_defines ALU_DIV",-1,6,0);
	vcdp->declBus  (c+1170,"riscv_defines ALU_REMU",-1,6,0);
	vcdp->declBus  (c+1097,"riscv_defines ALU_REM",-1,6,0);
	vcdp->declBus  (c+1171,"riscv_defines ALU_SHUF",-1,6,0);
	vcdp->declBus  (c+1172,"riscv_defines ALU_SHUF2",-1,6,0);
	vcdp->declBus  (c+1173,"riscv_defines ALU_PCKLO",-1,6,0);
	vcdp->declBus  (c+1174,"riscv_defines ALU_PCKHI",-1,6,0);
	vcdp->declBus  (c+1175,"riscv_defines ALU_FKEEP",-1,6,0);
	vcdp->declBus  (c+1176,"riscv_defines ALU_FSGNJ",-1,6,0);
	vcdp->declBus  (c+1177,"riscv_defines ALU_FSGNJN",-1,6,0);
	vcdp->declBus  (c+1178,"riscv_defines ALU_FSGNJX",-1,6,0);
	vcdp->declBus  (c+1107,"riscv_defines ALU_FEQ",-1,6,0);
	vcdp->declBus  (c+1179,"riscv_defines ALU_FLT",-1,6,0);
	vcdp->declBus  (c+1180,"riscv_defines ALU_FLE",-1,6,0);
	vcdp->declBus  (c+1181,"riscv_defines ALU_FMAX",-1,6,0);
	vcdp->declBus  (c+1109,"riscv_defines ALU_FMIN",-1,6,0);
	vcdp->declBus  (c+1182,"riscv_defines ALU_FCLASS",-1,6,0);
	vcdp->declBus  (c+1021,"riscv_defines MUL_MAC32",-1,2,0);
	vcdp->declBus  (c+1118,"riscv_defines MUL_MSU32",-1,2,0);
	vcdp->declBus  (c+1119,"riscv_defines MUL_I",-1,2,0);
	vcdp->declBus  (c+1120,"riscv_defines MUL_IR",-1,2,0);
	vcdp->declBus  (c+1121,"riscv_defines MUL_DOT8",-1,2,0);
	vcdp->declBus  (c+1122,"riscv_defines MUL_DOT16",-1,2,0);
	vcdp->declBus  (c+1123,"riscv_defines MUL_H",-1,2,0);
	vcdp->declBus  (c+1011,"riscv_defines VEC_MODE32",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines VEC_MODE16",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines VEC_MODE8",-1,1,0);
	vcdp->declBus  (c+1011,"riscv_defines CSR_OP_NONE",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines CSR_OP_WRITE",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines CSR_OP_SET",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines CSR_OP_CLEAR",-1,1,0);
	vcdp->declBus  (c+1183,"riscv_defines SP_DVR0",-1,15,0);
	vcdp->declBus  (c+1184,"riscv_defines SP_DCR0",-1,15,0);
	vcdp->declBus  (c+1185,"riscv_defines SP_DMR1",-1,15,0);
	vcdp->declBus  (c+1186,"riscv_defines SP_DMR2",-1,15,0);
	vcdp->declBus  (c+1187,"riscv_defines SP_DVR_MSB",-1,7,0);
	vcdp->declBus  (c+1188,"riscv_defines SP_DCR_MSB",-1,7,0);
	vcdp->declBus  (c+1189,"riscv_defines SP_DMR_MSB",-1,7,0);
	vcdp->declBus  (c+1190,"riscv_defines SP_DSR_MSB",-1,7,0);
	vcdp->declBus  (c+1011,"riscv_defines SEL_REGFILE",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines SEL_FW_EX",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines SEL_FW_WB",-1,1,0);
	vcdp->declBus  (c+1021,"riscv_defines OP_A_REGA_OR_FWD",-1,2,0);
	vcdp->declBus  (c+1118,"riscv_defines OP_A_CURRPC",-1,2,0);
	vcdp->declBus  (c+1119,"riscv_defines OP_A_IMM",-1,2,0);
	vcdp->declBus  (c+1120,"riscv_defines OP_A_REGB_OR_FWD",-1,2,0);
	vcdp->declBus  (c+1121,"riscv_defines OP_A_REGC_OR_FWD",-1,2,0);
	vcdp->declBus  (c+1191,"riscv_defines IMMA_Z",-1,0,0);
	vcdp->declBus  (c+1192,"riscv_defines IMMA_ZERO",-1,0,0);
	vcdp->declBus  (c+1021,"riscv_defines OP_B_REGB_OR_FWD",-1,2,0);
	vcdp->declBus  (c+1118,"riscv_defines OP_B_REGC_OR_FWD",-1,2,0);
	vcdp->declBus  (c+1119,"riscv_defines OP_B_IMM",-1,2,0);
	vcdp->declBus  (c+1120,"riscv_defines OP_B_REGA_OR_FWD",-1,2,0);
	vcdp->declBus  (c+1121,"riscv_defines OP_B_BMASK",-1,2,0);
	vcdp->declBus  (c+1007,"riscv_defines IMMB_I",-1,3,0);
	vcdp->declBus  (c+1193,"riscv_defines IMMB_S",-1,3,0);
	vcdp->declBus  (c+1194,"riscv_defines IMMB_U",-1,3,0);
	vcdp->declBus  (c+1195,"riscv_defines IMMB_PCINCR",-1,3,0);
	vcdp->declBus  (c+1196,"riscv_defines IMMB_S2",-1,3,0);
	vcdp->declBus  (c+1197,"riscv_defines IMMB_S3",-1,3,0);
	vcdp->declBus  (c+1198,"riscv_defines IMMB_VS",-1,3,0);
	vcdp->declBus  (c+1199,"riscv_defines IMMB_VU",-1,3,0);
	vcdp->declBus  (c+1200,"riscv_defines IMMB_SHUF",-1,3,0);
	vcdp->declBus  (c+1201,"riscv_defines IMMB_CLIP",-1,3,0);
	vcdp->declBus  (c+1202,"riscv_defines IMMB_BI",-1,3,0);
	vcdp->declBus  (c+1191,"riscv_defines BMASK_A_ZERO",-1,0,0);
	vcdp->declBus  (c+1192,"riscv_defines BMASK_A_S3",-1,0,0);
	vcdp->declBus  (c+1011,"riscv_defines BMASK_B_S2",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines BMASK_B_S3",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines BMASK_B_ZERO",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines BMASK_B_ONE",-1,1,0);
	vcdp->declBus  (c+1191,"riscv_defines BMASK_A_REG",-1,0,0);
	vcdp->declBus  (c+1192,"riscv_defines BMASK_A_IMM",-1,0,0);
	vcdp->declBus  (c+1191,"riscv_defines BMASK_B_REG",-1,0,0);
	vcdp->declBus  (c+1192,"riscv_defines BMASK_B_IMM",-1,0,0);
	vcdp->declBus  (c+1191,"riscv_defines MIMM_ZERO",-1,0,0);
	vcdp->declBus  (c+1192,"riscv_defines MIMM_S3",-1,0,0);
	vcdp->declBus  (c+1011,"riscv_defines OP_C_REGC_OR_FWD",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines OP_C_REGB_OR_FWD",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines OP_C_JT",-1,1,0);
	vcdp->declBus  (c+1011,"riscv_defines BRANCH_NONE",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines BRANCH_JAL",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines BRANCH_JALR",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines BRANCH_COND",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines JT_JAL",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines JT_JALR",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines JT_COND",-1,1,0);
	vcdp->declBus  (c+1021,"riscv_defines PC_BOOT",-1,2,0);
	vcdp->declBus  (c+1119,"riscv_defines PC_JUMP",-1,2,0);
	vcdp->declBus  (c+1120,"riscv_defines PC_BRANCH",-1,2,0);
	vcdp->declBus  (c+1121,"riscv_defines PC_EXCEPTION",-1,2,0);
	vcdp->declBus  (c+1122,"riscv_defines PC_ERET",-1,2,0);
	vcdp->declBus  (c+1203,"riscv_defines PC_DBG_NPC",-1,2,0);
	vcdp->declBus  (c+1011,"riscv_defines EXC_PC_ILLINSN",-1,1,0);
	vcdp->declBus  (c+1114,"riscv_defines EXC_PC_ECALL",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines EXC_PC_LOAD",-1,1,0);
	vcdp->declBus  (c+1115,"riscv_defines EXC_PC_STORE",-1,1,0);
	vcdp->declBus  (c+1116,"riscv_defines EXC_PC_IRQ",-1,1,0);
	vcdp->declBus  (c+1204,"riscv_defines EXC_CAUSE_ILLEGAL_INSN",-1,5,0);
	vcdp->declBus  (c+1205,"riscv_defines EXC_CAUSE_BREAKPOINT",-1,5,0);
	vcdp->declBus  (c+1206,"riscv_defines EXC_CAUSE_ECALL_UMODE",-1,5,0);
	vcdp->declBus  (c+1207,"riscv_defines EXC_CAUSE_ECALL_MMODE",-1,5,0);
	vcdp->declBus  (c+1191,"riscv_defines TRAP_MACHINE",-1,0,0);
	vcdp->declBus  (c+1192,"riscv_defines TRAP_USER",-1,0,0);
	vcdp->declBus  (c+1208,"riscv_defines EXC_OFF_RST",-1,7,0);
	vcdp->declBus  (c+1209,"riscv_defines EXC_OFF_ILLINSN",-1,7,0);
	vcdp->declBus  (c+1210,"riscv_defines EXC_OFF_ECALL",-1,7,0);
	vcdp->declBus  (c+1211,"riscv_defines EXC_OFF_LSUERR",-1,7,0);
	vcdp->declBus  (c+1002,"riscv_defines DBG_SETS_W",-1,31,0);
	vcdp->declBus  (c+1004,"riscv_defines DBG_SETS_IRQ",-1,31,0);
	vcdp->declBus  (c+1094,"riscv_defines DBG_SETS_ECALL",-1,31,0);
	vcdp->declBus  (c+1001,"riscv_defines DBG_SETS_EILL",-1,31,0);
	vcdp->declBus  (c+1017,"riscv_defines DBG_SETS_ELSU",-1,31,0);
	vcdp->declBus  (c+1000,"riscv_defines DBG_SETS_EBRK",-1,31,0);
	vcdp->declBus  (c+999,"riscv_defines DBG_SETS_SSTE",-1,31,0);
	vcdp->declBus  (c+1212,"riscv_defines DBG_CAUSE_HALT",-1,5,0);
	vcdp->declBus  (c+1094,"riscv_defines C_CMD",-1,31,0);
	vcdp->declBus  (c+1007,"riscv_defines C_FPU_ADD_CMD",-1,3,0);
	vcdp->declBus  (c+1193,"riscv_defines C_FPU_SUB_CMD",-1,3,0);
	vcdp->declBus  (c+1194,"riscv_defines C_FPU_MUL_CMD",-1,3,0);
	vcdp->declBus  (c+1195,"riscv_defines C_FPU_DIV_CMD",-1,3,0);
	vcdp->declBus  (c+1196,"riscv_defines C_FPU_I2F_CMD",-1,3,0);
	vcdp->declBus  (c+1197,"riscv_defines C_FPU_F2I_CMD",-1,3,0);
	vcdp->declBus  (c+1198,"riscv_defines C_FPU_SQRT_CMD",-1,3,0);
	vcdp->declBus  (c+1199,"riscv_defines C_FPU_NOP_CMD",-1,3,0);
	vcdp->declBus  (c+1200,"riscv_defines C_FPU_FMADD_CMD",-1,3,0);
	vcdp->declBus  (c+1201,"riscv_defines C_FPU_FMSUB_CMD",-1,3,0);
	vcdp->declBus  (c+1213,"riscv_defines C_FPU_FNMADD_CMD",-1,3,0);
	vcdp->declBus  (c+1202,"riscv_defines C_FPU_FNMSUB_CMD",-1,3,0);
	vcdp->declBus  (c+1004,"riscv_defines C_FFLAG",-1,31,0);
	vcdp->declBus  (c+1001,"riscv_defines C_RM",-1,31,0);
	vcdp->declBus  (c+1021,"riscv_defines C_RM_NEAREST",-1,2,0);
	vcdp->declBus  (c+1118,"riscv_defines C_RM_TRUNC",-1,2,0);
	vcdp->declBus  (c+1120,"riscv_defines C_RM_PLUSINF",-1,2,0);
	vcdp->declBus  (c+1119,"riscv_defines C_RM_MINUSINF",-1,2,0);
	vcdp->declBus  (c+1004,"riscv_defines C_PC",-1,31,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_operands_o[0]),32);
	vcdp->fullBus  (c+2,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_operands_o[1]),32);
	vcdp->fullBus  (c+3,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_operands_o[2]),32);
	vcdp->fullBus  (c+4,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands[0]),32);
	vcdp->fullBus  (c+5,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands[1]),32);
	vcdp->fullBus  (c+6,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands[2]),32);
	vcdp->fullBus  (c+7,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o[0]),32);
	vcdp->fullBus  (c+8,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o[1]),32);
	vcdp->fullBus  (c+9,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o[2]),32);
	vcdp->fullArray(c+10,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_lut),160);
	vcdp->fullBit  (c+15,(vlSymsp->TOP__top.irq_ack_o));
	vcdp->fullBit  (c+16,(vlSymsp->TOP__top.debug_gnt_o));
	vcdp->fullBus  (c+17,(vlSymsp->TOP__top.debug_rdata_o),32);
	vcdp->fullBit  (c+18,(vlSymsp->TOP__top.debug_halted_o));
	vcdp->fullBit  (c+19,(vlSymsp->TOP__top.core_busy_o));
	vcdp->fullBit  (c+20,(vlSymsp->TOP__top.__PVT__instr_req));
	vcdp->fullBus  (c+21,((0x3ffff0U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int)),22);
	vcdp->fullBus  (c+22,(vlSymsp->TOP__top.__PVT__con_data[0]),32);
	vcdp->fullBus  (c+23,(vlSymsp->TOP__top.__PVT__con_data[1]),32);
	vcdp->fullBus  (c+24,(vlSymsp->TOP__top.__PVT__con_data[2]),32);
	vcdp->fullBus  (c+25,(vlSymsp->TOP__top.__PVT__con_data[3]),32);
	vcdp->fullBus  (c+26,(vlSymsp->TOP__top.__PVT__con_data[4]),32);
	vcdp->fullBus  (c+27,(vlSymsp->TOP__top.__PVT__con_data[5]),32);
	vcdp->fullBus  (c+28,(vlSymsp->TOP__top.__PVT__con_data[6]),32);
	vcdp->fullBus  (c+29,(vlSymsp->TOP__top.__PVT__con_data[7]),32);
	vcdp->fullBus  (c+30,(vlSymsp->TOP__top.__PVT__con_data[8]),32);
	vcdp->fullBus  (c+31,(vlSymsp->TOP__top.__PVT__con_data[9]),32);
	vcdp->fullBus  (c+32,(vlSymsp->TOP__top.__PVT__con_data[10]),32);
	vcdp->fullBus  (c+33,(vlSymsp->TOP__top.__PVT__con_data[11]),32);
	vcdp->fullBus  (c+34,(vlSymsp->TOP__top.__PVT__con_data[12]),32);
	vcdp->fullBus  (c+35,(vlSymsp->TOP__top.__PVT__con_data[13]),32);
	vcdp->fullBus  (c+36,(vlSymsp->TOP__top.__PVT__con_data[14]),32);
	vcdp->fullBus  (c+37,(vlSymsp->TOP__top.__PVT__con_data[15]),32);
	vcdp->fullBit  (c+38,(vlSymsp->TOP__top.__PVT__data_req));
	vcdp->fullArray(c+39,(vlSymsp->TOP__top.__PVT__y0),68);
	vcdp->fullArray(c+42,(vlSymsp->TOP__top.__PVT__y1),68);
	vcdp->fullArray(c+45,(vlSymsp->TOP__top.__PVT__y2),68);
	vcdp->fullArray(c+48,(vlSymsp->TOP__top.__PVT__y3),68);
	vcdp->fullBit  (c+51,(((((6U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
				 | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator))) 
				| (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator))) 
			       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->fullBus  (c+52,(vlSymsp->TOP__top.__PVT__u0__DOT__y1_l),7);
	vcdp->fullBus  (c+53,(vlSymsp->TOP__top.__PVT__u0__DOT__y1_h),7);
	vcdp->fullBus  (c+54,(vlSymsp->TOP__top.__PVT__u0__DOT__y2_l),7);
	vcdp->fullBus  (c+55,(vlSymsp->TOP__top.__PVT__u0__DOT__y2_h),7);
	vcdp->fullBus  (c+56,(vlSymsp->TOP__top.__PVT__u0__DOT__y3_l),7);
	vcdp->fullBus  (c+57,(vlSymsp->TOP__top.__PVT__u0__DOT__y3_h),7);
	vcdp->fullBus  (c+58,(vlSymsp->TOP__top.__PVT__u0__DOT__y4_l),7);
	vcdp->fullBus  (c+59,(vlSymsp->TOP__top.__PVT__u0__DOT__y4_h),7);
	vcdp->fullBus  (c+60,((0xfU & vlSymsp->TOP__top.__PVT__y0[0U])),4);
	vcdp->fullBus  (c+61,((0xfU & ((vlSymsp->TOP__top.__PVT__y0[1U] 
					<< 0x1cU) | 
				       (vlSymsp->TOP__top.__PVT__y0[0U] 
					>> 4U)))),4);
	vcdp->fullBus  (c+62,((0xfU & vlSymsp->TOP__top.__PVT__y1[0U])),4);
	vcdp->fullBus  (c+63,((0xfU & ((vlSymsp->TOP__top.__PVT__y1[1U] 
					<< 0x1cU) | 
				       (vlSymsp->TOP__top.__PVT__y1[0U] 
					>> 4U)))),4);
	vcdp->fullBus  (c+64,((0xfU & vlSymsp->TOP__top.__PVT__y2[0U])),4);
	vcdp->fullBus  (c+65,((0xfU & ((vlSymsp->TOP__top.__PVT__y2[1U] 
					<< 0x1cU) | 
				       (vlSymsp->TOP__top.__PVT__y2[0U] 
					>> 4U)))),4);
	vcdp->fullBus  (c+66,((0xfU & vlSymsp->TOP__top.__PVT__y3[0U])),4);
	vcdp->fullBus  (c+67,((0xfU & ((vlSymsp->TOP__top.__PVT__y3[1U] 
					<< 0x1cU) | 
				       (vlSymsp->TOP__top.__PVT__y3[0U] 
					>> 4U)))),4);
	vcdp->fullBus  (c+68,((0xfffffff0U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int)),32);
	vcdp->fullBus  (c+69,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[0]),32);
	vcdp->fullBus  (c+70,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[1]),32);
	vcdp->fullBus  (c+71,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[2]),32);
	vcdp->fullBus  (c+72,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[3]),32);
	vcdp->fullBus  (c+73,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[4]),32);
	vcdp->fullBus  (c+74,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[5]),32);
	vcdp->fullBus  (c+75,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[6]),32);
	vcdp->fullBus  (c+76,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[7]),32);
	vcdp->fullBus  (c+77,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[8]),32);
	vcdp->fullBus  (c+78,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[9]),32);
	vcdp->fullBus  (c+79,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[10]),32);
	vcdp->fullBus  (c+80,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[11]),32);
	vcdp->fullBus  (c+81,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[12]),32);
	vcdp->fullBus  (c+82,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[13]),32);
	vcdp->fullBus  (c+83,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[14]),32);
	vcdp->fullBus  (c+84,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[15]),32);
	vcdp->fullBus  (c+85,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__str_operator),2);
	vcdp->fullBit  (c+86,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__str_op_en));
	vcdp->fullBus  (c+87,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__str_op_result),32);
	vcdp->fullBus  (c+88,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__str_operand),32);
	vcdp->fullBus  (c+89,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator),3);
	vcdp->fullBit  (c+90,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en));
	vcdp->fullBus  (c+91,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mac_op_result),32);
	vcdp->fullBus  (c+92,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mac_operand1),32);
	vcdp->fullBus  (c+93,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mac_operand2),32);
	vcdp->fullBit  (c+94,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active));
	vcdp->fullBus  (c+95,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mem_wdata),32);
	vcdp->fullBit  (c+96,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active));
	vcdp->fullBit  (c+97,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__clear_instr_valid));
	vcdp->fullBit  (c+98,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_set));
	vcdp->fullBus  (c+99,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id),3);
	vcdp->fullBus  (c+100,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id),2);
	vcdp->fullBus  (c+101,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause),6);
	vcdp->fullBit  (c+102,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__trap_addr_mux));
	vcdp->fullBit  (c+103,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_decoding));
	vcdp->fullBit  (c+104,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_multicycle));
	vcdp->fullBus  (c+105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target),32);
	vcdp->fullBit  (c+106,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy));
	vcdp->fullBit  (c+107,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__busy_L0));
	vcdp->fullBus  (c+108,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_wdata_fw),32);
	vcdp->fullBus  (c+109,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_op),2);
	vcdp->fullBit  (c+110,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__halt_if));
	vcdp->fullBit  (c+111,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready));
	vcdp->fullBit  (c+112,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_ready));
	vcdp->fullBit  (c+113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_valid));
	vcdp->fullBit  (c+114,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_valid));
	vcdp->fullBit  (c+115,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_wb));
	vcdp->fullBit  (c+116,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_ex));
	vcdp->fullBit  (c+117,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_int));
	vcdp->fullBit  (c+118,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_irq_sec));
	vcdp->fullBus  (c+119,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__epc),32);
	vcdp->fullBit  (c+120,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_cause));
	vcdp->fullBit  (c+121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_if));
	vcdp->fullBit  (c+122,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_id));
	vcdp->fullBus  (c+123,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause),6);
	vcdp->fullBit  (c+124,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_mret_id));
	vcdp->fullBit  (c+125,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_uret_id));
	vcdp->fullBus  (c+126,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_regid),1);
	vcdp->fullBus  (c+127,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_we),3);
	vcdp->fullBus  (c+128,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int),32);
	vcdp->fullBit  (c+129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_req));
	vcdp->fullBit  (c+130,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_ack));
	vcdp->fullBit  (c+131,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_stall));
	vcdp->fullBit  (c+132,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_trap));
	vcdp->fullBus  (c+133,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_data_rc_id),32);
	vcdp->fullBit  (c+134,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq));
	vcdp->fullBit  (c+135,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_csr_we));
	vcdp->fullBit  (c+136,((1U & ((~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid)) 
				      | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req)))));
	vcdp->fullBit  (c+137,(((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)) 
				| (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)))));
	vcdp->fullBit  (c+138,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jr_stall));
	vcdp->fullBit  (c+139,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__load_stall));
	vcdp->fullBit  (c+140,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__perf_pipeline_stall));
	vcdp->fullBit  (c+141,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_ctrl_firstfetch));
	vcdp->fullBit  (c+142,(((4U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id)) 
				& (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id)))));
	vcdp->fullBit  (c+143,((1U & (~ (IData)(vlSymsp->TOP__top.core_busy_o)))));
	vcdp->fullBus  (c+144,((0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause))),5);
	vcdp->fullBus  (c+145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_ns),1);
	vcdp->fullBit  (c+146,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__if_valid));
	vcdp->fullBit  (c+147,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready))));
	vcdp->fullBit  (c+148,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid));
	vcdp->fullBit  (c+149,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req));
	vcdp->fullBus  (c+150,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_addr_n),32);
	vcdp->fullBit  (c+151,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid));
	vcdp->fullBit  (c+152,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_ready));
	vcdp->fullBus  (c+153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata),32);
	vcdp->fullBit  (c+154,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_is_hwlp));
	vcdp->fullBus  (c+155,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__exc_pc),32);
	vcdp->fullBus  (c+156,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__trap_base_addr),24);
	vcdp->fullBus  (c+157,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__instr_decompressed),32);
	vcdp->fullBit  (c+158,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__illegal_c_insn));
	vcdp->fullBit  (c+159,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata))));
	vcdp->fullBus  (c+160,((0xfffffffeU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_addr_n)),32);
	vcdp->fullBus  (c+161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__NS),4);
	vcdp->fullBit  (c+162,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__do_fetch));
	vcdp->fullBit  (c+163,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__do_hwlp));
	vcdp->fullBit  (c+164,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__do_hwlp_int));
	vcdp->fullBit  (c+165,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__use_last));
	vcdp->fullBit  (c+166,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__save_rdata_last));
	vcdp->fullBit  (c+167,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__use_hwlp));
	vcdp->fullBit  (c+168,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__save_rdata_hwlp));
	vcdp->fullBit  (c+169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__valid));
	vcdp->fullBit  (c+170,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__next_is_crossword));
	vcdp->fullBit  (c+171,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__next_valid));
	vcdp->fullBit  (c+172,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__next_upper_compressed));
	vcdp->fullBus  (c+173,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_n),32);
	vcdp->fullBus  (c+174,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_int),32);
	vcdp->fullBus  (c+175,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_real_next),32);
	vcdp->fullBit  (c+176,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__is_hwlp_n));
	vcdp->fullBit  (c+177,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__valid) 
				& (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req)))));
	vcdp->fullBit  (c+178,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__fetch_valid));
	vcdp->fullBus  (c+179,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata),32);
	vcdp->fullBit  (c+180,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata))));
	vcdp->fullBit  (c+181,((3U != (3U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata 
					     >> 0x10U)))));
	vcdp->fullBit  (c+182,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellinp__L0_buffer_i__hwlp_i));
	vcdp->fullBus  (c+183,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__NS),3);
	vcdp->fullBus  (c+184,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int),32);
	vcdp->fullBit  (c+185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__valid));
	vcdp->fullBit  (c+186,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we));
	vcdp->fullBit  (c+187,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__illegal_insn_dec));
	vcdp->fullBit  (c+188,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ebrk_insn));
	vcdp->fullBit  (c+189,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mret_insn_dec));
	vcdp->fullBit  (c+190,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__uret_insn_dec));
	vcdp->fullBit  (c+191,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ecall_insn_dec));
	vcdp->fullBit  (c+192,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__pipe_flush_dec));
	vcdp->fullBit  (c+193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__rega_used_dec));
	vcdp->fullBit  (c+194,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec));
	vcdp->fullBit  (c+195,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec));
	vcdp->fullBus  (c+196,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id),2);
	vcdp->fullBus  (c+197,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__jump_in_id),2);
	vcdp->fullBit  (c+198,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__instr_multicycle));
	vcdp->fullBit  (c+199,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__halt_id));
	vcdp->fullBus  (c+200,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_shuffle_type),32);
	vcdp->fullBit  (c+201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_ack));
	vcdp->fullBit  (c+202,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_kill));
	vcdp->fullBus  (c+203,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id),6);
	vcdp->fullBit  (c+204,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_we_id));
	vcdp->fullBit  (c+205,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_en));
	vcdp->fullBus  (c+206,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operator),7);
	vcdp->fullBus  (c+207,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_a_mux_sel),3);
	vcdp->fullBus  (c+208,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_b_mux_sel),3);
	vcdp->fullBus  (c+209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_c_mux_sel),2);
	vcdp->fullBus  (c+210,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_mux),2);
	vcdp->fullBus  (c+211,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel),1);
	vcdp->fullBus  (c+212,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel),4);
	vcdp->fullBus  (c+213,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target_mux_sel),2);
	vcdp->fullBus  (c+214,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_operator),3);
	vcdp->fullBit  (c+215,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en) 
				| (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en))));
	vcdp->fullBit  (c+216,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en));
	vcdp->fullBit  (c+217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_sel_subword));
	vcdp->fullBus  (c+218,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_signed_mode),2);
	vcdp->fullBit  (c+219,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en));
	vcdp->fullBus  (c+220,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_signed),2);
	vcdp->fullBit  (c+221,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_we_id));
	vcdp->fullBit  (c+222,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_we_id));
	vcdp->fullBus  (c+223,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_type_id),2);
	vcdp->fullBit  (c+224,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_sign_ext_id));
	vcdp->fullBit  (c+225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_req_id));
	vcdp->fullBit  (c+226,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_load_event_id));
	vcdp->fullBus  (c+227,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regid),1);
	vcdp->fullBus  (c+228,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we),3);
	vcdp->fullBus  (c+229,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_int),3);
	vcdp->fullBit  (c+230,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target_mux_sel));
	vcdp->fullBit  (c+231,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_mux_sel));
	vcdp->fullBit  (c+232,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_mux_sel));
	vcdp->fullBus  (c+233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target),32);
	vcdp->fullBus  (c+234,(((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_int))
				 ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int
				 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
	vcdp->fullBus  (c+235,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int),32);
	vcdp->fullBus  (c+236,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_int))
				 ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target
				 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
	vcdp->fullBus  (c+237,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt),32);
	vcdp->fullBus  (c+238,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_int),32);
	vcdp->fullBit  (c+239,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_valid));
	vcdp->fullBit  (c+240,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access));
	vcdp->fullBus  (c+241,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we)
				 ? 0U : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op))),2);
	vcdp->fullBit  (c+242,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_status));
	vcdp->fullBit  (c+243,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__prepost_useincr));
	vcdp->fullBus  (c+244,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_mux_sel),2);
	vcdp->fullBus  (c+245,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_mux_sel),2);
	vcdp->fullBus  (c+246,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_mux_sel),2);
	vcdp->fullBus  (c+247,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_id),32);
	vcdp->fullBus  (c+248,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id),32);
	vcdp->fullBus  (c+249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_id),32);
	vcdp->fullBus  (c+250,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b),32);
	vcdp->fullBus  (c+251,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_vec),32);
	vcdp->fullBus  (c+252,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_a),32);
	vcdp->fullBus  (c+253,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_b),32);
	vcdp->fullBus  (c+254,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_c),32);
	vcdp->fullBus  (c+255,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_mux),1);
	vcdp->fullBus  (c+256,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_mux),2);
	vcdp->fullBit  (c+257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel));
	vcdp->fullBit  (c+258,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel));
	vcdp->fullBus  (c+259,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux),1);
	vcdp->fullBus  (c+260,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm),5);
	vcdp->fullBus  (c+261,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm),5);
	vcdp->fullBus  (c+262,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
					  ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
					  : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
					      ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
					      : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id 
						 >> 5U))))),5);
	vcdp->fullBus  (c+263,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
					  ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
					  : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
					      ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
					      : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id)))),5);
	vcdp->fullBus  (c+264,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode),2);
	vcdp->fullBit  (c+265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__scalar_replication));
	vcdp->fullBit  (c+266,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_a_id));
	vcdp->fullBit  (c+267,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_wb_is_reg_a_id));
	vcdp->fullBit  (c+268,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_alu_is_reg_a_id));
	vcdp->fullBus  (c+269,(vlSymsp->TOP__top.riscv_core_i__DOT__id_stage_i__DOT____Vcellinp__registers_i__wdata_b_i),32);
	vcdp->fullBus  (c+270,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_b_dec),32);
	vcdp->fullBit  (c+271,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_mem_we));
	vcdp->fullBit  (c+272,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_alu_we));
	vcdp->fullBit  (c+273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__data_req));
	vcdp->fullBus  (c+274,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__hwloop_we),3);
	vcdp->fullBit  (c+275,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal));
	vcdp->fullBus  (c+276,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op),2);
	vcdp->fullBit  (c+277,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_int_en));
	vcdp->fullBit  (c+278,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_dot_en));
	vcdp->fullBus  (c+279,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns),5);
	vcdp->fullBit  (c+280,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done));
	vcdp->fullBit  (c+281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_in_dec));
	vcdp->fullBit  (c+282,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__branch_in_id));
	vcdp->fullBit  (c+283,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done));
	vcdp->fullBit  (c+284,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__irq_enable_int));
	vcdp->fullBus  (c+285,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[0]),32);
	vcdp->fullBus  (c+286,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[1]),32);
	vcdp->fullBus  (c+287,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[2]),32);
	vcdp->fullBus  (c+288,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[3]),32);
	vcdp->fullBus  (c+289,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[4]),32);
	vcdp->fullBus  (c+290,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[5]),32);
	vcdp->fullBus  (c+291,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[6]),32);
	vcdp->fullBus  (c+292,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[7]),32);
	vcdp->fullBus  (c+293,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[8]),32);
	vcdp->fullBus  (c+294,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[9]),32);
	vcdp->fullBus  (c+295,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[10]),32);
	vcdp->fullBus  (c+296,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[11]),32);
	vcdp->fullBus  (c+297,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[12]),32);
	vcdp->fullBus  (c+298,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[13]),32);
	vcdp->fullBus  (c+299,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[14]),32);
	vcdp->fullBus  (c+300,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[15]),32);
	vcdp->fullBit  (c+301,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_ready));
	vcdp->fullBit  (c+302,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_ready) 
				  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_ready)) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_ready)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_ready))));
	vcdp->fullBus  (c+303,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_result),32);
	vcdp->fullBus  (c+304,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_result),32);
	vcdp->fullBit  (c+305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_ready));
	vcdp->fullBit  (c+306,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_ready));
	vcdp->fullBus  (c+307,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_NS),3);
	vcdp->fullBit  (c+308,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_active));
	vcdp->fullBus  (c+309,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_intermediate),32);
	vcdp->fullBus  (c+310,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__char_),32);
	vcdp->fullBus  (c+311,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[0]),32);
	vcdp->fullBus  (c+312,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[1]),32);
	vcdp->fullBus  (c+313,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[2]),32);
	vcdp->fullBus  (c+314,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[3]),32);
	vcdp->fullBus  (c+315,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[4]),32);
	vcdp->fullBus  (c+316,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[5]),32);
	vcdp->fullBus  (c+317,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[6]),32);
	vcdp->fullBus  (c+318,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[7]),32);
	vcdp->fullBus  (c+319,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[8]),32);
	vcdp->fullBus  (c+320,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[9]),32);
	vcdp->fullBus  (c+321,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[10]),32);
	vcdp->fullBus  (c+322,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[11]),32);
	vcdp->fullBus  (c+323,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[12]),32);
	vcdp->fullBus  (c+324,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[13]),32);
	vcdp->fullBus  (c+325,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[14]),32);
	vcdp->fullBus  (c+326,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[15]),32);
	vcdp->fullBus  (c+327,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_ns),3);
	vcdp->fullBus  (c+328,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_ns),3);
	vcdp->fullBus  (c+329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_ns),3);
	vcdp->fullBit  (c+330,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_ns));
	vcdp->fullBit  (c+331,(((6U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->fullBit  (c+332,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_ready));
	vcdp->fullBit  (c+333,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_ready));
	vcdp->fullBit  (c+334,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_ready));
	vcdp->fullBit  (c+335,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_active));
	vcdp->fullBit  (c+336,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_ready));
	vcdp->fullBit  (c+337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_active));
	vcdp->fullBus  (c+338,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_operand),32);
	vcdp->fullBus  (c+339,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_mult1),16);
	vcdp->fullBus  (c+340,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_mult2),16);
	vcdp->fullBus  (c+341,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_add),32);
	vcdp->fullBus  (c+342,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_operand_1),32);
	vcdp->fullBus  (c+343,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_operand_2),32);
	vcdp->fullBus  (c+344,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult1),16);
	vcdp->fullBus  (c+345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult2),16);
	vcdp->fullBus  (c+346,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult3),16);
	vcdp->fullBus  (c+347,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult4),16);
	vcdp->fullBus  (c+348,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_add),32);
	vcdp->fullBus  (c+349,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__max),32);
	vcdp->fullBus  (c+350,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w0),32);
	vcdp->fullBus  (c+351,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w1),32);
	vcdp->fullBus  (c+352,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w2),32);
	vcdp->fullBus  (c+353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w3),32);
	vcdp->fullBus  (c+354,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w4),32);
	vcdp->fullBus  (c+355,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w5),32);
	vcdp->fullBus  (c+356,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w6),32);
	vcdp->fullBus  (c+357,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w7),32);
	vcdp->fullBus  (c+358,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w8),32);
	vcdp->fullBus  (c+359,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y0),32);
	vcdp->fullBus  (c+360,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y1),32);
	vcdp->fullBus  (c+361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y2),32);
	vcdp->fullBus  (c+362,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y3),32);
	vcdp->fullBus  (c+363,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__ymax),32);
	vcdp->fullArray(c+364,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_0),67);
	vcdp->fullArray(c+367,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_3),67);
	vcdp->fullArray(c+370,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_0),67);
	vcdp->fullArray(c+373,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_3),67);
	vcdp->fullArray(c+376,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_1),68);
	vcdp->fullArray(c+379,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_2),68);
	vcdp->fullArray(c+382,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_1),68);
	vcdp->fullArray(c+385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_2),68);
	vcdp->fullArray(c+388,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_0),69);
	vcdp->fullArray(c+391,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_3),69);
	vcdp->fullArray(c+394,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_0),69);
	vcdp->fullArray(c+397,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_3),69);
	vcdp->fullArray(c+400,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0),71);
	vcdp->fullArray(c+403,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0),71);
	vcdp->fullArray(c+406,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_1),70);
	vcdp->fullArray(c+409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_1),70);
	vcdp->fullArray(c+412,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_1),70);
	vcdp->fullArray(c+415,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_2),70);
	vcdp->fullArray(c+418,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_1),70);
	vcdp->fullArray(c+421,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_2),70);
	vcdp->fullArray(c+424,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_1),72);
	vcdp->fullArray(c+427,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_1),72);
	vcdp->fullArray(c+430,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0),73);
	vcdp->fullArray(c+433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0),73);
	vcdp->fullQuad (c+436,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid0_0),34);
	vcdp->fullQuad (c+438,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid0_1),34);
	vcdp->fullQuad (c+440,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid3_0),34);
	vcdp->fullQuad (c+442,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid3_1),34);
	vcdp->fullQuad (c+444,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid1_0),36);
	vcdp->fullQuad (c+446,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid1_1),36);
	vcdp->fullQuad (c+448,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid2_0),36);
	vcdp->fullQuad (c+450,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid2_1),36);
	vcdp->fullBit  (c+452,(((2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->fullBit  (c+453,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->fullBus  (c+454,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift),6);
	vcdp->fullBus  (c+455,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_left),32);
	vcdp->fullBus  (c+456,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt),32);
	vcdp->fullBus  (c+457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_int),32);
	vcdp->fullBus  (c+458,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result),32);
	vcdp->fullBus  (c+459,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_right_result),32);
	vcdp->fullBus  (c+460,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result),32);
	vcdp->fullBus  (c+461,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bitop_result),6);
	vcdp->fullBus  (c+462,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bextins_result),32);
	vcdp->fullBus  (c+463,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D),32);
	vcdp->fullBus  (c+464,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D),32);
	vcdp->fullBit  (c+465,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S));
	vcdp->fullBit  (c+466,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S));
	vcdp->fullBit  (c+467,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S));
	vcdp->fullBit  (c+468,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S));
	vcdp->fullBus  (c+469,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SN),2);
	vcdp->fullBus  (c+470,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a),17);
	vcdp->fullBus  (c+471,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b),17);
	vcdp->fullQuad (c+472,((VL_ULL(0x3ffffffff) 
				& VL_MULS_QQQ(34,34,34, 
					      (VL_ULL(0x3ffffffff) 
					       & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a)), 
					      (VL_ULL(0x3ffffffff) 
					       & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b))))),34);
	vcdp->fullQuad (c+474,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac),34);
	vcdp->fullQuad (c+476,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_result),34);
	vcdp->fullBit  (c+478,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
				       ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						  >> 0x21U))
				       : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						  >> 0x1fU))))));
	vcdp->fullBit  (c+479,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
				       ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						  >> 0x20U))
				       : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						  >> 0x1fU))))));
	vcdp->fullBus  (c+480,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_subword),2);
	vcdp->fullBus  (c+481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_signed),2);
	vcdp->fullBit  (c+482,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_shift_arith));
	vcdp->fullBus  (c+483,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm),5);
	vcdp->fullBus  (c+484,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_subword),2);
	vcdp->fullBus  (c+485,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_signed),2);
	vcdp->fullBit  (c+486,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_shift_arith));
	vcdp->fullBit  (c+487,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active));
	vcdp->fullBit  (c+488,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_save));
	vcdp->fullBit  (c+489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_clearcarry));
	vcdp->fullBus  (c+490,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_NS),3);
	vcdp->fullBus  (c+491,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__NS),2);
	vcdp->fullBit  (c+492,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_we_int));
	vcdp->fullBus  (c+493,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__frm_n),3);
	vcdp->fullBus  (c+494,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fflags_n),5);
	vcdp->fullBus  (c+495,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fprec_n),5);
	vcdp->fullBus  (c+496,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_n),32);
	vcdp->fullBus  (c+497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__exception_pc),32);
	vcdp->fullBus  (c+498,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_n),6);
	vcdp->fullBus  (c+499,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_n),6);
	vcdp->fullBit  (c+500,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause) 
				      >> 5U))));
	vcdp->fullBus  (c+501,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_n),2);
	vcdp->fullBus  (c+502,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc),12);
	vcdp->fullArray(c+503,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_n),384);
	vcdp->fullBus  (c+515,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_n),2);
	vcdp->fullBus  (c+516,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_n),12);
	vcdp->fullBus  (c+517,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__rdata_sel_n),3);
	vcdp->fullBus  (c+518,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__state_n),1);
	vcdp->fullBus  (c+519,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__settings_n),6);
	vcdp->fullBit  (c+520,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_rreq_n));
	vcdp->fullBit  (c+521,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_n));
	vcdp->fullBit  (c+522,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__jump_req_n));
	vcdp->fullBit  (c+523,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_n));
	vcdp->fullBit  (c+524,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_wr));
	vcdp->fullBus  (c+525,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__stall_ns),2);
	vcdp->fullBus  (c+526,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_rdata),32);
	vcdp->fullBit  (c+527,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_resume));
	vcdp->fullBit  (c+528,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_halt));
	vcdp->fullBus  (c+529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_cause_n),6);
	vcdp->fullBit  (c+530,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_ssth_n));
	vcdp->fullBit  (c+531,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__ssth_clear));
	vcdp->fullBus  (c+532,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__pc_tracking_fsm_ns),2);
	vcdp->fullBus  (c+533,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__ppc_int),32);
	vcdp->fullBus  (c+534,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__npc_int),32);
	vcdp->fullBus  (c+535,((0xffff0U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int)),20);
	vcdp->fullBit  (c+536,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_cs) 
				^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active))));
	vcdp->fullBit  (c+537,(((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
				  | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
				 | (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
				| (IData)(vlSymsp->TOP__top.__PVT__data_req))));
	vcdp->fullBit  (c+538,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
				  == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
				& (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
	vcdp->fullBus  (c+539,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_rreq_q)
				 ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_q) 
				     << 5U) | (0x1fU 
					       & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q) 
						  >> 2U)))
				 : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id))),6);
	vcdp->fullBus  (c+540,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S)
				 ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				     ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
				     : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
					 << 0x1fU) 
					| (0x7fffffffU 
					   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
					      >> 1U))))
				 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP)),32);
	vcdp->fullBus  (c+541,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				 ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
				 : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
				     << 0x1fU) | (0x7fffffffU 
						  & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
						     >> 1U))))),32);
	vcdp->fullBus  (c+542,((0x3fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
					  ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift)
					  : ((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))
					      ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP) 
						 - (IData)(1U))
					      : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))))),6);
	vcdp->fullBit  (c+543,(((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_load_event_ex) 
				       & (IData)(vlSymsp->TOP__top.__PVT__data_req)))
				 ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__busy_L0)
				 : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__busy_L0) 
				     | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy)) 
				    | ((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
					 | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
					| (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
				       | (IData)(vlSymsp->TOP__top.__PVT__data_req))))));
	vcdp->fullBit  (c+544,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
				  == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 0x14U))) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
				& (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x14U))))));
	vcdp->fullBus  (c+545,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				 ? 0U : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S)
					  ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S) 
					      << 0x1fU) 
					     | (0x7fffffffU 
						& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP 
						   >> 1U)))
					  : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP))),32);
	vcdp->fullBus  (c+546,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S)
				 ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
				     & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
					   & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
					       >> 0x1fU) 
					      ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))
				     ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
					+ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D)
				     : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
					- vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D))
				 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AReg_DP)),32);
	vcdp->fullBit  (c+547,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				       ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
					  >> 1U) : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP)))));
	vcdp->fullBit  (c+548,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				 ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)
				 : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP))));
	vcdp->fullBit  (c+549,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				       ? ((((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result)) 
					    | ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
					       >> 1U)) 
					   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
					  & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
					      >> 0x1fU) 
					     ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))
				       : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)))));
	vcdp->fullQuad (c+550,((VL_ULL(0x1ffffffff) 
				& ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
				    ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q)) 
					<< 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))
				    : VL_EXTENDS_QI(33,32, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))),33);
	vcdp->fullBus  (c+552,((0x3fffffU & ((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
					       | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
					      | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
					      ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
					      : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int))),22);
	vcdp->fullBus  (c+553,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
				  | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
				 | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
				 ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
				 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),32);
	vcdp->fullBus  (c+554,((0xfffffU & ((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
					      | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
					     | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
					     ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
					     : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int))),20);
	vcdp->fullBus  (c+555,((0xffffcU & ((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
					      | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
					     | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
					     ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
					     : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int))),20);
	vcdp->fullBus  (c+556,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active)
				 ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mem_wdata
				 : ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
				     ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
					 ? ((0xff000000U 
					     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
						<< 0x18U)) 
					    | (0xffffffU 
					       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
						  >> 8U)))
					 : ((0xffff0000U 
					     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
						<< 0x10U)) 
					    | (0xffffU 
					       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
						  >> 0x10U))))
				     : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
					 ? ((0xffffff00U 
					     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
						<< 8U)) 
					    | (0xffU 
					       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
						  >> 0x18U)))
					 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex)))),32);
	vcdp->fullBus  (c+557,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata_unaligned),32);
	vcdp->fullBit  (c+558,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access) 
				& ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex) 
				   & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex) 
				      >> 1U)))));
	vcdp->fullBus  (c+559,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel)
				 ? 0U : (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						  >> 0xfU)))),32);
	vcdp->fullBus  (c+560,(((8U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
				 ? ((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
				     ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_i_type
				     : ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					 ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					     ? ((0xffffffe0U 
						 & (VL_NEGATE_I((IData)(
									(1U 
									 & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									    >> 0x18U)))) 
						    << 5U)) 
						| (0x1fU 
						   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						      >> 0x14U)))
					     : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_i_type)
					 : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					     ? (0x7fffffffU 
						& ((((IData)(1U) 
						     << 
						     (0x1fU 
						      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
							 >> 0x14U))) 
						    - (IData)(1U)) 
						   >> 1U))
					     : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_shuffle_type)))
				 : ((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
				     ? ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					 ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					     ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type
					     : ((0xffffffc0U 
						 & (VL_NEGATE_I((IData)(
									(1U 
									 & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									    >> 0x18U)))) 
						    << 6U)) 
						| ((0x3eU 
						    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						       >> 0x13U)) 
						   | (1U 
						      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
							 >> 0x19U)))))
					 : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					     ? (0x1fU 
						& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x19U))
					     : (0x1fU 
						& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x14U))))
				     : ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					 ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					     ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_compressed_id) 
						 & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned)))
						 ? 2U
						 : 4U)
					     : (0xfffff000U 
						& vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id))
					 : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
					     ? ((0xfffff000U 
						 & (VL_NEGATE_I((IData)(
									(1U 
									 & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									    >> 0x1fU)))) 
						    << 0xcU)) 
						| ((0xfe0U 
						    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						       >> 0x14U)) 
						   | (0x1fU 
						      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
							 >> 7U))))
					     : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_i_type))))),32);
	vcdp->fullBus  (c+561,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
					  ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
					      ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						 >> 0x19U)
					      : 0U)
					  : 0U))),5);
	vcdp->fullBit  (c+562,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex) 
				  == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 0x14U))) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
				& (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x14U))))));
	vcdp->fullBit  (c+563,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex) 
				  == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
				& (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
	vcdp->fullBit  (c+564,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
				  == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 0x14U))) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
				& (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x14U))))));
	vcdp->fullBit  (c+565,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
				  == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
				& (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
	vcdp->fullBit  (c+566,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq) 
				| (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_fw))));
	vcdp->fullBus  (c+567,((0x3fU & ((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
					 - (IData)(1U)))),6);
	vcdp->fullBus  (c+568,((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U])),5);
	vcdp->fullBit  (c+569,((1U & (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes))));
	vcdp->fullBus  (c+570,((0x1fU & ((IData)(0x1fU) 
					 - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]))),5);
	vcdp->fullBit  (c+571,(((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
				   >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))));
	vcdp->fullBus  (c+572,(((0x2aU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
				 ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex
				 : VL_NEGATE_I((IData)(
						       ((0x28U 
							 == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
							& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
							   >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))))))),32);
	vcdp->fullBus  (c+573,((0x3fU & ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes)
					  ? ((0x1fU 
					      & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
					     - (IData)(1U))
					  : 0x1fU))),6);
	vcdp->fullBus  (c+574,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes),32);
	vcdp->fullArray(c+575,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes),160);
	vcdp->fullBus  (c+580,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
				 & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
				       & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
					   >> 0x1fU) 
					  ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))
				 ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
				    + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D)
				 : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
				    - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D))),32);
	vcdp->fullBit  (c+581,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
				& (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
				      & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
					  >> 0x1fU) 
					 ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))));
	vcdp->fullBus  (c+582,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
				 ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm)
				 : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),5);
	vcdp->fullBit  (c+583,(((IData)(vlSymsp->TOP__top.__PVT__data_req) 
				& (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex)))));
	vcdp->fullBit  (c+584,(((IData)(vlSymsp->TOP__top.__PVT__data_req) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex))));
	vcdp->fullBus  (c+585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_in),12);
	vcdp->fullBit  (c+586,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_wb));
	vcdp->fullBit  (c+587,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__m_irq_enable));
	vcdp->fullBus  (c+588,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_a_dec),32);
	vcdp->fullQuad (c+589,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_n),64);
	vcdp->fullBus  (c+591,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)
				 ? VL_NEGATE_I(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)
				 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)),32);
	vcdp->fullBus  (c+592,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP_rev),32);
	vcdp->fullBus  (c+593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D),32);
	vcdp->fullBus  (c+594,(((0x800U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
				 ? ((0x400U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
				     ? ((0x200U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
					 ? 0U : ((0x100U 
						  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						  ? 0U
						  : 
						 ((0x80U 
						   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						   ? 0U
						   : 
						  ((0x40U 
						    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						    ? 0U
						    : 
						   ((0x20U 
						     & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						     ? 0U
						     : 
						    ((0x10U 
						      & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						      ? 
						     ((8U 
						       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						       ? 0U
						       : 
						      ((4U 
							& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						        ? 0U
						        : 
						       ((2U 
							 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							 ? 0U
							 : 
							((1U 
							  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							  ? 0U
							  : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_q)))))
						      : 0U))))))
				     : 0U) : ((0x400U 
					       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
					       ? ((0x200U 
						   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						   ? 
						  ((0x100U 
						    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						    ? 
						   ((0x80U 
						     & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						     ? 
						    ((0x40U 
						      & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						      ? 0U
						      : 
						     ((0x20U 
						       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						       ? 
						      ((0x10U 
							& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						        ? 
						       ((8U 
							 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							 ? 0U
							 : 
							((4U 
							  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							  ? 
							 ((2U 
							   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							   ? 
							  ((1U 
							    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							    ? 0U
							    : (IData)(
								      (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_q 
								       >> 0x20U)))
							   : 
							  ((1U 
							    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							    ? (IData)(
								      (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_end_q 
								       >> 0x20U))
							    : (IData)(
								      (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_start_q 
								       >> 0x20U))))
							  : 
							 ((2U 
							   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							   ? 
							  ((1U 
							    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							    ? 0U
							    : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_q))
							   : 
							  ((1U 
							    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							    ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_end_q)
							    : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_start_q)))))
						        : 0U)
						       : 0U))
						     : 0U)
						    : 0U)
						   : 0U)
					       : ((0x200U 
						   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						   ? 
						  ((0x100U 
						    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						    ? 
						   ((0x80U 
						     & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						     ? 0U
						     : 
						    ((0x40U 
						      & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						      ? 
						     ((0x20U 
						       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						       ? 0U
						       : 
						      ((0x10U 
							& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						        ? 0U
						        : 
						       ((8U 
							 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							 ? 0U
							 : 
							((4U 
							  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							  ? 0U
							  : 
							 ((2U 
							   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							   ? 
							  ((1U 
							    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							    ? 0U
							    : 
							   ((0x80000000U 
							     & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_q) 
								<< 0x1aU)) 
							    | (0x1fU 
							       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_q))))
							   : 
							  ((1U 
							    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_q
							    : 0U))))))
						      : 
						     ((0x20U 
						       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						       ? 0U
						       : 
						      ((0x10U 
							& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
						        ? 0U
						        : 
						       ((8U 
							 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							 ? 0U
							 : 
							((4U 
							  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							  ? 0U
							  : 
							 ((2U 
							   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							   ? 0U
							   : 
							  ((1U 
							    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
							    ? 0U
							    : 
							   ((0x1800U 
							     & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
								<< 0xbU)) 
							    | ((0x80U 
								& ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
								   << 5U)) 
							       | ((0x10U 
								   & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
								      << 1U)) 
								  | ((8U 
								      & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
									 >> 1U)) 
								     | (1U 
									& ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
									   >> 5U))))))))))))))
						    : 0U)
						   : 0U)))),32);
	vcdp->fullBus  (c+595,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
				 ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
				     ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					 ? 8U : 4U)
				     : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					 ? 2U : 1U))
				 : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
				     ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
					 ? 1U : ((2U 
						  & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						  ? 
						 ((1U 
						   & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						   ? 8U
						   : 0xcU)
						  : 
						 ((1U 
						   & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						   ? 6U
						   : 3U)))
				     : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
					 ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					     ? ((1U 
						 & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						 ? 7U
						 : 3U)
					     : ((1U 
						 & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						 ? 1U
						 : 0U))
					 : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					     ? ((1U 
						 & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						 ? 8U
						 : 0xcU)
					     : ((1U 
						 & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						 ? 0xeU
						 : 0xfU)))))),4);
	vcdp->fullBit  (c+596,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_hwlp_id));
	vcdp->fullBit  (c+597,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned));
	vcdp->fullBit  (c+598,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result) 
				      >> 3U))));
	vcdp->fullBus  (c+599,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_operands_ex[0]),32);
	vcdp->fullBus  (c+600,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_operands_ex[1]),32);
	vcdp->fullBus  (c+601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_operands_ex[2]),32);
	vcdp->fullBus  (c+602,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_rdata),32);
	vcdp->fullBit  (c+603,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_fw));
	vcdp->fullBus  (c+604,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr),12);
	vcdp->fullBus  (c+605,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_rdata),32);
	vcdp->fullBus  (c+606,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_wdata),32);
	vcdp->fullBit  (c+607,((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr))));
	vcdp->fullBus  (c+608,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_target),32);
	vcdp->fullBus  (c+609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt),2);
	vcdp->fullBus  (c+610,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT____Vcellinp__hwloop_controller_i__hwlp_dec_cnt_id_i),2);
	vcdp->fullBus  (c+611,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr),2);
	vcdp->fullBus  (c+612,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__j),32);
	vcdp->fullBit  (c+613,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__hwlp_is_crossword));
	vcdp->fullBit  (c+614,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__is_crossword));
	vcdp->fullBit  (c+615,((3U != (3U & (vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[3U] 
					     >> 0x10U)))));
	vcdp->fullArray(c+616,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o),128);
	vcdp->fullBit  (c+620,((3U != (3U & vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[3U]))));
	vcdp->fullBit  (c+621,((3U != (3U & ((vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[3U] 
					      << 0x10U) 
					     | (vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[2U] 
						>> 0x10U))))));
	vcdp->fullBit  (c+622,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__branch_taken_ex));
	vcdp->fullBus  (c+623,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_i_type),32);
	vcdp->fullBus  (c+624,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type),32);
	vcdp->fullBus  (c+625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_data_ra_id),32);
	vcdp->fullBus  (c+626,((3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type)),2);
	vcdp->fullBus  (c+627,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellinp__ex_stage_i__apu_operands_i[0]),32);
	vcdp->fullBus  (c+628,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellinp__ex_stage_i__apu_operands_i[1]),32);
	vcdp->fullBus  (c+629,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellinp__ex_stage_i__apu_operands_i[2]),32);
	vcdp->fullBus  (c+630,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_rev),32);
	vcdp->fullBus  (c+631,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_neg_rev),32);
	vcdp->fullBit  (c+632,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_valid));
	vcdp->fullBus  (c+633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask),32);
	vcdp->fullBit  (c+634,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b_negate));
	vcdp->fullBus  (c+635,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_a),32);
	vcdp->fullBus  (c+636,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b),32);
	vcdp->fullQuad (c+637,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_a),36);
	vcdp->fullQuad (c+639,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_b),36);
	vcdp->fullBus  (c+641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result),32);
	vcdp->fullQuad (c+642,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded),37);
	vcdp->fullBus  (c+644,((((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				   | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				  | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				 | (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
				 ? (0x7fffffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
						   >> 1U))
				 : 0U)),32);
	vcdp->fullBus  (c+645,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result 
				+ (((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				      | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				     | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				    | (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
				    ? (0x7fffffffU 
				       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
					  >> 1U)) : 0U))),32);
	vcdp->fullBit  (c+646,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left));
	vcdp->fullBit  (c+647,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_use_round));
	vcdp->fullBit  (c+648,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic));
	vcdp->fullBus  (c+649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a),32);
	vcdp->fullQuad (c+650,(((0x26U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
				 ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)) 
				     << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)))
				 : (((QData)((IData)(
						     VL_NEGATE_I((IData)(
									 ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic) 
									  & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a 
									     >> 0x1fU)))))) 
				     << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a))))),64);
	vcdp->fullBus  (c+652,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal),4);
	vcdp->fullBus  (c+653,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater),4);
	vcdp->fullBus  (c+654,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_greater),4);
	vcdp->fullBus  (c+655,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_signed),4);
	vcdp->fullBus  (c+656,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_vec),4);
	vcdp->fullBus  (c+657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater_vec),4);
	vcdp->fullBus  (c+658,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result),4);
	vcdp->fullBus  (c+659,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_nan),4);
	vcdp->fullBus  (c+660,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax),32);
	vcdp->fullBus  (c+661,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__sel_minmax),4);
	vcdp->fullBus  (c+662,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__minmax_b),32);
	vcdp->fullBus  (c+663,(((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater))
				 ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax
				 : (((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
					>> 0x1fU)) ? 0U
				     : ((1U & (IData)(
						      (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded 
						       >> 0x24U)))
					 ? (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)
					 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax)))),32);
	vcdp->fullBit  (c+664,((1U & (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded 
					      >> 0x24U)))));
	vcdp->fullBus  (c+665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_byte_sel),8);
	vcdp->fullBus  (c+666,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg_sel),4);
	vcdp->fullBus  (c+667,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg1_sel),2);
	vcdp->fullBus  (c+668,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg0_sel),2);
	vcdp->fullBus  (c+669,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_through),4);
	vcdp->fullBus  (c+670,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1),32);
	vcdp->fullBus  (c+671,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0),32);
	vcdp->fullBus  (c+672,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1_in),32);
	vcdp->fullBus  (c+673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0_in),32);
	vcdp->fullBus  (c+674,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_result),32);
	vcdp->fullBus  (c+675,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__pack_result),32);
	vcdp->fullBus  (c+676,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__ff_input),32);
	vcdp->fullBus  (c+677,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result),6);
	vcdp->fullBus  (c+678,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
	vcdp->fullBus  (c+679,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
				& (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask))),32);
	vcdp->fullBus  (c+680,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
				| vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
	vcdp->fullBit  (c+681,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed));
	vcdp->fullBus  (c+682,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l1),32);
	vcdp->fullBus  (c+683,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l2),24);
	vcdp->fullBus  (c+684,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l3),16);
	vcdp->fullBus  (c+685,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l4),10);
	vcdp->fullBit  (c+686,((0U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result))));
	vcdp->fullBit  (c+687,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S));
	vcdp->fullBus  (c+688,(((((VL_EXTENDS_II(32,18, 
						 (0x3ffffU 
						  & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[0U])) 
				   + VL_EXTENDS_II(32,18, 
						   (0x3ffffU 
						    & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[1U] 
							<< 0xeU) 
						       | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[0U] 
							  >> 0x12U))))) 
				  + VL_EXTENDS_II(32,18, 
						  (0x3ffffU 
						   & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[2U] 
						       << 0x1cU) 
						      | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[1U] 
							 >> 4U))))) 
				 + VL_EXTENDS_II(32,18, 
						 (0x3ffffU 
						  & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[2U] 
						      << 0xaU) 
						     | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[1U] 
							>> 0x16U))))) 
				+ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex)),32);
	vcdp->fullBus  (c+689,(((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul[0U] 
				 + ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul[2U] 
				     << 0x1eU) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul[1U] 
						  >> 2U))) 
				+ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex)),32);
	vcdp->fullQuad (c+690,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_a),36);
	vcdp->fullQuad (c+692,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_b),36);
	vcdp->fullArray(c+694,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul),72);
	vcdp->fullQuad (c+697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_a),34);
	vcdp->fullQuad (c+699,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b),34);
	vcdp->fullArray(c+701,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul),68);
	vcdp->fullBus  (c+704,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int),32);
	vcdp->fullBus  (c+705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset),2);
	vcdp->fullBus  (c+706,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_rdata_ext),32);
	vcdp->fullBus  (c+707,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__perf_rdata),32);
	vcdp->fullBus  (c+708,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_index),5);
	vcdp->fullBit  (c+709,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_all_sel));
	vcdp->fullBit  (c+710,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pccr));
	vcdp->fullBit  (c+711,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcer));
	vcdp->fullBit  (c+712,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcmr));
	vcdp->fullBus  (c+713,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_id_q),5);
	vcdp->fullBit  (c+714,((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_q))));
	vcdp->fullBit  (c+715,(vlSymsp->TOP__top.debug_rvalid_o));
	vcdp->fullBit  (c+716,((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[0xbU])));
	vcdp->fullBit  (c+717,(vlSymsp->TOP__top.__PVT__u0__DOT__clk_));
	vcdp->fullBus  (c+718,(vlSymsp->TOP__top.__PVT__u0__DOT__divider0__DOT__cnt),16);
	vcdp->fullBus  (c+719,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[0xbU]),32);
	vcdp->fullBus  (c+720,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu),6);
	vcdp->fullBus  (c+721,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_q),2);
	vcdp->fullBit  (c+722,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
				 >> 5U) & (0U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_q)))));
	vcdp->fullQuad (c+723,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_start_q),64);
	vcdp->fullQuad (c+725,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_end_q),64);
	vcdp->fullQuad (c+727,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_q),64);
	vcdp->fullBus  (c+729,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__settings_q),6);
	vcdp->fullBit  (c+730,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_rreq_q));
	vcdp->fullBus  (c+731,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_q) 
				 << 5U) | (0x1fU & 
					   ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q) 
					    >> 2U)))),6);
	vcdp->fullBit  (c+732,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_q));
	vcdp->fullBus  (c+733,((0xfffU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q) 
					  >> 2U))),12);
	vcdp->fullBus  (c+734,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__wdata_q),32);
	vcdp->fullBit  (c+735,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__jump_req_q));
	vcdp->fullBit  (c+736,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_busy_q));
	vcdp->fullBus  (c+737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_cs),1);
	vcdp->fullBus  (c+738,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__addr_q),32);
	vcdp->fullBus  (c+739,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__CS),3);
	vcdp->fullArray(c+740,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__L0_buffer),128);
	vcdp->fullBit  (c+744,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs))));
	vcdp->fullBit  (c+745,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_sec_q));
	vcdp->fullBus  (c+746,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__TestReadAddr_Q),6);
	vcdp->fullArray(c+747,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem),1024);
	vcdp->fullBus  (c+779,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs),5);
	vcdp->fullBit  (c+780,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done_q));
	vcdp->fullBit  (c+781,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done_q));
	vcdp->fullBus  (c+782,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs),2);
	vcdp->fullBus  (c+783,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__i),32);
	vcdp->fullBit  (c+784,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_we_lsu));
	vcdp->fullBus  (c+785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_CS),3);
	vcdp->fullBus  (c+786,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_cs),3);
	vcdp->fullBus  (c+787,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_cs),3);
	vcdp->fullBus  (c+788,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_cs),3);
	vcdp->fullBit  (c+789,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_cs));
	vcdp->fullBit  (c+790,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active_d));
	vcdp->fullBit  (c+791,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__enable_i_d));
	vcdp->fullBus  (c+792,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP),32);
	vcdp->fullBus  (c+793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AReg_DP),32);
	vcdp->fullBus  (c+794,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP),32);
	vcdp->fullBit  (c+795,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP));
	vcdp->fullBit  (c+796,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP));
	vcdp->fullBit  (c+797,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP));
	vcdp->fullBus  (c+798,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP),6);
	vcdp->fullBit  (c+799,((1U & (~ (IData)((0U 
						 != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP)))))));
	vcdp->fullBus  (c+800,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SP),2);
	vcdp->fullBit  (c+801,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q));
	vcdp->fullBus  (c+802,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_CS),3);
	vcdp->fullBus  (c+803,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_type_q),2);
	vcdp->fullBus  (c+804,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q),2);
	vcdp->fullBit  (c+805,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q));
	vcdp->fullBit  (c+806,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_we_q));
	vcdp->fullBus  (c+807,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS),2);
	vcdp->fullBus  (c+808,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q),32);
	vcdp->fullBus  (c+809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_q),32);
	vcdp->fullBus  (c+810,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q),6);
	vcdp->fullBus  (c+811,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_q),6);
	vcdp->fullBit  (c+812,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__id_valid_q));
	vcdp->fullBus  (c+813,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc_q),12);
	vcdp->fullArray(c+814,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_q),384);
	vcdp->fullBus  (c+826,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_q),2);
	vcdp->fullBus  (c+827,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_q),12);
	vcdp->fullBus  (c+828,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk3__DOT__i),32);
	vcdp->fullBus  (c+829,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk2__DOT__i),32);
	vcdp->fullBus  (c+830,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__rdata_sel_q),3);
	vcdp->fullBus  (c+831,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__state_q),1);
	vcdp->fullBus  (c+832,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q),15);
	vcdp->fullBit  (c+833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_q));
	vcdp->fullBus  (c+834,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__stall_cs),2);
	vcdp->fullBus  (c+835,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_cause_q),6);
	vcdp->fullBit  (c+836,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_ssth_q));
	vcdp->fullBus  (c+837,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__pc_tracking_fsm_cs),2);
	vcdp->fullBus  (c+838,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				 ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				     ? ((0xffffff00U 
					 & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					    << 8U)) 
					| (0xffU & 
					   (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
					    >> 0x18U)))
				     : ((0xffff0000U 
					 & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					    << 0x10U)) 
					| (0xffffU 
					   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
					      >> 0x10U))))
				 : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				     ? ((0xff000000U 
					 & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					    << 0x18U)) 
					| (0xffffffU 
					   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
					      >> 8U)))
				     : vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o))),32);
	vcdp->fullBus  (c+839,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				 ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				     ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffff0000U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 7U)))) 
						<< 0x10U)) 
					    | ((0xff00U 
						& (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
						   << 8U)) 
					       | (0xffU 
						  & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
						     >> 0x18U))))
					 : ((0xff00U 
					     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
						<< 8U)) 
					    | (0xffU 
					       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
						  >> 0x18U))))
				     : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffff0000U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 0x1fU)))) 
						<< 0x10U)) 
					    | (0xffffU 
					       & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
						  >> 0x10U)))
					 : (0xffffU 
					    & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					       >> 0x10U))))
				 : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				     ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffff0000U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 0x17U)))) 
						<< 0x10U)) 
					    | (0xffffU 
					       & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
						  >> 8U)))
					 : (0xffffU 
					    & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					       >> 8U)))
				     : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffff0000U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 0xfU)))) 
						<< 0x10U)) 
					    | (0xffffU 
					       & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o))
					 : (0xffffU 
					    & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o))))),32);
	vcdp->fullBus  (c+840,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				 ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				     ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffffff00U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 0x1fU)))) 
						<< 8U)) 
					    | (0xffU 
					       & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
						  >> 0x18U)))
					 : (0xffU & 
					    (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					     >> 0x18U)))
				     : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffffff00U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 0x17U)))) 
						<< 8U)) 
					    | (0xffU 
					       & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
						  >> 0x10U)))
					 : (0xffU & 
					    (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					     >> 0x10U))))
				 : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				     ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffffff00U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 0xfU)))) 
						<< 8U)) 
					    | (0xffU 
					       & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
						  >> 8U)))
					 : (0xffU & 
					    (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					     >> 8U)))
				     : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q)
					 ? ((0xffffff00U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
									>> 7U)))) 
						<< 8U)) 
					    | (0xffU 
					       & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o))
					 : (0xffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o))))),32);
	vcdp->fullBit  (c+841,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_q) 
				| (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex))));
	vcdp->fullBus  (c+842,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[
			       (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0x14U))]),32);
	vcdp->fullBit  (c+843,(vlSymsp->TOP__top__ram_i.__PVT__instr_rvalid_o));
	vcdp->fullArray(c+844,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o),128);
	vcdp->fullBit  (c+848,(vlSymsp->TOP__top__ram_i.__PVT__data_rvalid_o));
	vcdp->fullBus  (c+849,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o),32);
	vcdp->fullBit  (c+850,((1U & vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_cnt)));
	vcdp->fullBus  (c+851,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_cnt),32);
	vcdp->fullBus  (c+852,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con),32);
	vcdp->fullBus  (c+853,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_req_ex_i_d),32);
	vcdp->fullArray(c+854,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_c_o),128);
	vcdp->fullBit  (c+858,((1U & (IData)(vlSymsp->TOP__top.__Vcellout__u0__led))));
	vcdp->fullBit  (c+859,((1U & (IData)(vlSymsp->TOP__top.__Vcellout__u0__cs))));
	vcdp->fullBus  (c+860,(vlSymsp->TOP__top.__Vcellout__u0__led),7);
	vcdp->fullBus  (c+861,(vlSymsp->TOP__top.__Vcellout__u0__cs),8);
	vcdp->fullBus  (c+862,(vlSymsp->TOP__top.__PVT__u0__DOT__cnt),3);
	vcdp->fullBit  (c+863,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex));
	vcdp->fullBus  (c+864,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__hwlp_dec_cnt_id),2);
	vcdp->fullBit  (c+865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_valid_id));
	vcdp->fullBus  (c+866,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id),32);
	vcdp->fullBit  (c+867,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_compressed_id));
	vcdp->fullBit  (c+868,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__illegal_c_insn_id));
	vcdp->fullBus  (c+869,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_q),32);
	vcdp->fullBus  (c+870,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_id),32);
	vcdp->fullBit  (c+871,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__useincr_addr_ex));
	vcdp->fullBus  (c+872,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex),32);
	vcdp->fullBit  (c+873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__branch_in_ex));
	vcdp->fullBus  (c+874,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_ex),32);
	vcdp->fullBit  (c+875,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_en_ex));
	vcdp->fullBus  (c+876,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex),7);
	vcdp->fullBus  (c+877,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex),32);
	vcdp->fullBus  (c+878,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex),32);
	vcdp->fullBus  (c+879,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex),5);
	vcdp->fullBus  (c+880,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex),5);
	vcdp->fullBus  (c+881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__imm_vec_ext_ex),2);
	vcdp->fullBus  (c+882,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_vec_mode_ex),2);
	vcdp->fullBus  (c+883,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex),3);
	vcdp->fullBus  (c+884,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex),32);
	vcdp->fullBus  (c+885,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex),32);
	vcdp->fullBus  (c+886,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex),32);
	vcdp->fullBit  (c+887,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_en_ex));
	vcdp->fullBit  (c+888,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_sel_subword_ex));
	vcdp->fullBus  (c+889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_signed_mode_ex),2);
	vcdp->fullBus  (c+890,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex),5);
	vcdp->fullBus  (c+891,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_a_ex),32);
	vcdp->fullBus  (c+892,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_b_ex),32);
	vcdp->fullBus  (c+893,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex),32);
	vcdp->fullBus  (c+894,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_signed_ex),2);
	vcdp->fullBus  (c+895,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__fpu_op_ex),4);
	vcdp->fullBit  (c+896,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex));
	vcdp->fullBus  (c+897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_type_ex),2);
	vcdp->fullBus  (c+898,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_flags_ex),15);
	vcdp->fullBus  (c+899,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_op_ex),6);
	vcdp->fullBus  (c+900,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex),2);
	vcdp->fullBus  (c+901,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_waddr_ex),6);
	vcdp->fullBus  (c+902,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex),6);
	vcdp->fullBit  (c+903,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_ex));
	vcdp->fullBus  (c+904,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex),6);
	vcdp->fullBit  (c+905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_ex));
	vcdp->fullBit  (c+906,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex));
	vcdp->fullBus  (c+907,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_op_ex),2);
	vcdp->fullBus  (c+908,((0xfffU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex)
					   ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex
					   : 0U))),12);
	vcdp->fullBus  (c+909,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex),2);
	vcdp->fullBit  (c+910,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_sign_ext_ex));
	vcdp->fullBus  (c+911,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_reg_offset_ex),2);
	vcdp->fullBit  (c+912,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_ex));
	vcdp->fullBit  (c+913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_load_event_ex));
	vcdp->fullBit  (c+914,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex));
	vcdp->fullBit  (c+915,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__is_hwlp_id_q));
	vcdp->fullBus  (c+916,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt_if),2);
	vcdp->fullBus  (c+917,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__CS),4);
	vcdp->fullBit  (c+918,((3U == (3U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_q 
					     >> 2U)))));
	vcdp->fullBus  (c+919,(((IData)(4U) + (0xfffffffcU 
					       & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_q))),32);
	vcdp->fullBit  (c+920,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__is_hwlp_q));
	vcdp->fullBus  (c+921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata_last_q),32);
	vcdp->fullBus  (c+922,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o[0]),32);
	vcdp->fullBus  (c+923,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o[1]),32);
	vcdp->fullBus  (c+924,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o[2]),32);
	vcdp->fullBus  (c+925,((0xfffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					  >> 0x14U))),32);
	vcdp->fullBus  (c+926,(((0xfffff000U & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									>> 0x1fU)))) 
						<< 0xcU)) 
				| ((0xfe0U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					      >> 0x14U)) 
				   | (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 7U))))),32);
	vcdp->fullBus  (c+927,(((0xffffe000U & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									>> 0x1fU)))) 
						<< 0xdU)) 
				| ((0x1000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 0x13U)) 
				   | ((0x800U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						 << 4U)) 
				      | ((0x7e0U & 
					  (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					   >> 0x14U)) 
					 | (0x1eU & 
					    (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					     >> 7U))))))),32);
	vcdp->fullBus  (c+928,((0xfffff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id)),32);
	vcdp->fullBus  (c+929,(((0xfff00000U & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									>> 0x1fU)))) 
						<< 0x14U)) 
				| ((0xff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id) 
				   | ((0x800U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						 >> 9U)) 
				      | (0x7feU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x14U)))))),32);
	vcdp->fullBus  (c+930,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0xfU))),32);
	vcdp->fullBus  (c+931,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0x14U))),32);
	vcdp->fullBus  (c+932,(((0xffffffe0U & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									>> 0x18U)))) 
						<< 5U)) 
				| (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					    >> 0x14U)))),32);
	vcdp->fullBus  (c+933,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0x19U))),32);
	vcdp->fullBus  (c+934,(((0xffffffc0U & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
									>> 0x18U)))) 
						<< 6U)) 
				| ((0x3eU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					     >> 0x13U)) 
				   | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					    >> 0x19U))))),32);
	vcdp->fullBus  (c+935,(((0x3000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 3U)) 
				| ((0x30000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						>> 7U)) 
				   | ((0x300U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						 >> 0xdU)) 
				      | ((2U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						>> 0x13U)) 
					 | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						  >> 0x19U))))))),32);
	vcdp->fullBus  (c+936,(((0x10000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					     >> 4U)) 
				| (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0x19U)))),32);
	vcdp->fullBus  (c+937,((((IData)(1U) << (0x1fU 
						 & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						    >> 0x14U))) 
				- (IData)(1U))),32);
	vcdp->fullBus  (c+938,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0xfU))),6);
	vcdp->fullBus  (c+939,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0x14U))),6);
	vcdp->fullBus  (c+940,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 7U))),6);
	vcdp->fullBus  (c+941,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
				      >> 7U))),1);
	vcdp->fullBus  (c+942,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex)),32);
	vcdp->fullBus  (c+943,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)),32);
	vcdp->fullBus  (c+944,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
				 << 0x18U) | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
					       << 0x10U) 
					      | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
						  << 8U) 
						 | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex))))),32);
	vcdp->fullBit  (c+945,((((((0x10U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				   | (0x11U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				  | (0x16U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				 | (0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				| (0x47U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
	vcdp->fullBit  (c+946,(((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
				   >> 0x1fU))));
	vcdp->fullBit  (c+947,((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
	vcdp->fullBus  (c+948,(((IData)(0xfffffffeU) 
				<< (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))),32);
	vcdp->fullBit  (c+949,((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
	vcdp->fullBit  (c+950,((1U & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
				       >> 0x1fU) & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
	vcdp->fullBus  (c+951,((3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))),2);
	vcdp->fullBus  (c+952,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))
				 ? (0x7fffffffU & (
						   ((IData)(1U) 
						    << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex)) 
						   >> 1U))
				 : 0U)),32);
	vcdp->fullBus  (c+953,(((IData)(1U) << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),32);
	vcdp->fullBus  (c+954,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
				^ VL_NEGATE_I((IData)(
						      (1U 
						       == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
	vcdp->fullBus  (c+955,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
				& VL_NEGATE_I((IData)(
						      (1U 
						       == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
	vcdp->fullBus  (c+956,(((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex 
				 + (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
				    & VL_NEGATE_I((IData)(
							  (1U 
							   == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))) 
				+ VL_MULS_III(32,32,32, 
					      (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
					       ^ VL_NEGATE_I((IData)(
								     (1U 
								      == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))))), vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex))),32);
	vcdp->fullBit  (c+957,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))));
	vcdp->fullBit  (c+958,(vlTOPp->clk_i));
	vcdp->fullBit  (c+959,(vlTOPp->rstn_i));
	vcdp->fullBit  (c+960,(vlTOPp->irq_i));
	vcdp->fullBus  (c+961,(vlTOPp->irq_id_i),5);
	vcdp->fullBit  (c+962,(vlTOPp->irq_ack_o));
	vcdp->fullBus  (c+963,(vlTOPp->irq_id_o),5);
	vcdp->fullBit  (c+964,(vlTOPp->irq_sec_i));
	vcdp->fullBit  (c+965,(vlTOPp->sec_lvl_o));
	vcdp->fullBit  (c+966,(vlTOPp->debug_req_i));
	vcdp->fullBit  (c+967,(vlTOPp->debug_gnt_o));
	vcdp->fullBit  (c+968,(vlTOPp->debug_rvalid_o));
	vcdp->fullBus  (c+969,(vlTOPp->debug_addr_i),15);
	vcdp->fullBit  (c+970,(vlTOPp->debug_we_i));
	vcdp->fullBus  (c+971,(vlTOPp->debug_wdata_i),32);
	vcdp->fullBus  (c+972,(vlTOPp->debug_rdata_o),32);
	vcdp->fullBit  (c+973,(vlTOPp->debug_halted_o));
	vcdp->fullBit  (c+974,(vlTOPp->fetch_enable_i));
	vcdp->fullBit  (c+975,(vlTOPp->core_busy_o));
	vcdp->fullBus  (c+976,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_wr) 
				 << 5U) | (0x1fU & 
					   ((IData)(vlTOPp->debug_addr_i) 
					    >> 2U)))),6);
	vcdp->fullBit  (c+977,((((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_req) 
				   | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_q)) 
				  | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__jump_req_q)) 
				 | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq)) 
				| (IData)(vlTOPp->debug_req_i))));
	vcdp->fullBus  (c+978,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq)
				 ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_wr) 
				     << 5U) | (0x1fU 
					       & ((IData)(vlTOPp->debug_addr_i) 
						  >> 2U)))
				 : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex))),6);
	vcdp->fullBus  (c+979,(0x80U),32);
	vcdp->fullBus  (c+980,(0x16U),32);
	vcdp->fullBus  (c+981,(0x80U),32);
	vcdp->fullArray(c+982,(vlSymsp->TOP__top.__PVT__con_data_o),512);
	vcdp->fullBit  (c+998,(vlSymsp->TOP__top.__PVT__clk_o));
	vcdp->fullBus  (c+999,(0U),32);
	vcdp->fullBus  (c+1000,(1U),32);
	vcdp->fullBus  (c+1001,(3U),32);
	vcdp->fullBus  (c+1002,(6U),32);
	vcdp->fullBus  (c+1003,(0xfU),32);
	vcdp->fullBus  (c+1004,(5U),32);
	vcdp->fullBit  (c+1005,(1U));
	vcdp->fullBit  (c+1006,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__fregfile_disable_i));
	vcdp->fullBus  (c+1007,(0U),4);
	vcdp->fullBus  (c+1008,(0U),6);
	vcdp->fullBit  (c+1009,(0U));
	vcdp->fullBit  (c+1010,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_gnt_i));
	vcdp->fullBus  (c+1011,(0U),2);
	vcdp->fullBus  (c+1012,(0U),15);
	vcdp->fullBit  (c+1013,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_valid_i));
	vcdp->fullBus  (c+1014,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_result_i),32);
	vcdp->fullBus  (c+1015,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_flags_i),5);
	vcdp->fullBus  (c+1016,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ext_perf_counters_i),2);
	vcdp->fullBus  (c+1017,(2U),32);
	vcdp->fullBit  (c+1018,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_flag));
	vcdp->fullBit  (c+1019,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active));
	vcdp->fullBus  (c+1020,(0U),5);
	vcdp->fullBus  (c+1021,(0U),3);
	vcdp->fullBus  (c+1022,(0U),18);
	vcdp->fullBus  (c+1023,(0U),12);
	vcdp->fullBus  (c+1024,(0U),24);
	vcdp->fullBus  (c+1025,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__utvec_q),24);
	vcdp->fullBus  (c+1026,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_read_regs),18);
	vcdp->fullBus  (c+1027,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_read_regs_valid),3);
	vcdp->fullBus  (c+1028,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_write_regs),12);
	vcdp->fullBus  (c+1029,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_write_regs_valid),2);
	vcdp->fullBus  (c+1030,(0x20U),32);
	vcdp->fullBit  (c+1031,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__CSN_T));
	vcdp->fullBit  (c+1032,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__WEN_T));
	vcdp->fullBus  (c+1033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__A_T),6);
	vcdp->fullBus  (c+1034,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__D_T),32);
	vcdp->fullArray(c+1035,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem_fp),1024);
	vcdp->fullBus  (c+1067,(0x20U),32);
	vcdp->fullBus  (c+1068,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_ns),2);
	vcdp->fullBit  (c+1069,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__fpu_busy));
	vcdp->fullBus  (c+1070,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_result),32);
	vcdp->fullBit  (c+1071,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_req));
	vcdp->fullBit  (c+1072,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_ready));
	vcdp->fullBit  (c+1073,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_gnt));
	vcdp->fullBit  (c+1074,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w_wb_cs));
	vcdp->fullBit  (c+1075,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w_wb_ns));
	vcdp->fullBus  (c+1076,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w_rank),4);
	vcdp->fullBit  (c+1077,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w_wb_ready));
	vcdp->fullBus  (c+1078,(0U),32);
	vcdp->fullBus  (c+1079,(0xcU),32);
	vcdp->fullBus  (c+1080,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__frm_q),3);
	vcdp->fullBus  (c+1081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fflags_q),5);
	vcdp->fullBus  (c+1082,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fprec_q),5);
	vcdp->fullBus  (c+1083,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__uepc_q),32);
	vcdp->fullBus  (c+1084,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__uepc_n),32);
	vcdp->fullBus  (c+1085,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__ucause_q),6);
	vcdp->fullBus  (c+1086,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__ucause_n),6);
	vcdp->fullBus  (c+1087,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvec_reg_q),24);
	vcdp->fullBus  (c+1088,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__utvec_n),24);
	vcdp->fullBus  (c+1089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_reg_q),2);
	vcdp->fullBus  (c+1090,(0xcU),32);
	vcdp->fullBus  (c+1091,(0x14U),32);
	vcdp->fullBus  (c+1092,(0xfU),4);
	vcdp->fullBus  (c+1093,(0x100000U),32);
	vcdp->fullBus  (c+1094,(4U),32);
	vcdp->fullBus  (c+1095,(0x73U),7);
	vcdp->fullBus  (c+1096,(0xfU),7);
	vcdp->fullBus  (c+1097,(0x33U),7);
	vcdp->fullBus  (c+1098,(0x13U),7);
	vcdp->fullBus  (c+1099,(0x23U),7);
	vcdp->fullBus  (c+1100,(3U),7);
	vcdp->fullBus  (c+1101,(0x63U),7);
	vcdp->fullBus  (c+1102,(0x67U),7);
	vcdp->fullBus  (c+1103,(0x6fU),7);
	vcdp->fullBus  (c+1104,(0x17U),7);
	vcdp->fullBus  (c+1105,(0x37U),7);
	vcdp->fullBus  (c+1106,(0x53U),7);
	vcdp->fullBus  (c+1107,(0x43U),7);
	vcdp->fullBus  (c+1108,(0x4fU),7);
	vcdp->fullBus  (c+1109,(0x47U),7);
	vcdp->fullBus  (c+1110,(0x4bU),7);
	vcdp->fullBus  (c+1111,(0x27U),7);
	vcdp->fullBus  (c+1112,(7U),7);
	vcdp->fullBus  (c+1113,(0xbU),7);
	vcdp->fullBus  (c+1114,(1U),2);
	vcdp->fullBus  (c+1115,(2U),2);
	vcdp->fullBus  (c+1116,(3U),2);
	vcdp->fullBus  (c+1117,(0x2bU),7);
	vcdp->fullBus  (c+1118,(1U),3);
	vcdp->fullBus  (c+1119,(2U),3);
	vcdp->fullBus  (c+1120,(3U),3);
	vcdp->fullBus  (c+1121,(4U),3);
	vcdp->fullBus  (c+1122,(5U),3);
	vcdp->fullBus  (c+1123,(6U),3);
	vcdp->fullBus  (c+1124,(0x5bU),7);
	vcdp->fullBus  (c+1125,(0x57U),7);
	vcdp->fullBus  (c+1126,(0x7bU),7);
	vcdp->fullBus  (c+1127,(7U),32);
	vcdp->fullBus  (c+1128,(0x18U),7);
	vcdp->fullBus  (c+1129,(0x19U),7);
	vcdp->fullBus  (c+1130,(0x1aU),7);
	vcdp->fullBus  (c+1131,(0x1bU),7);
	vcdp->fullBus  (c+1132,(0x1cU),7);
	vcdp->fullBus  (c+1133,(0x1dU),7);
	vcdp->fullBus  (c+1134,(0x1eU),7);
	vcdp->fullBus  (c+1135,(0x1fU),7);
	vcdp->fullBus  (c+1136,(0x2fU),7);
	vcdp->fullBus  (c+1137,(0x2eU),7);
	vcdp->fullBus  (c+1138,(0x15U),7);
	vcdp->fullBus  (c+1139,(0x24U),7);
	vcdp->fullBus  (c+1140,(0x25U),7);
	vcdp->fullBus  (c+1141,(0x26U),7);
	vcdp->fullBus  (c+1142,(0x28U),7);
	vcdp->fullBus  (c+1143,(0x29U),7);
	vcdp->fullBus  (c+1144,(0x2aU),7);
	vcdp->fullBus  (c+1145,(0x2cU),7);
	vcdp->fullBus  (c+1146,(0x36U),7);
	vcdp->fullBus  (c+1147,(0x34U),7);
	vcdp->fullBus  (c+1148,(0x35U),7);
	vcdp->fullBus  (c+1149,(0x3eU),7);
	vcdp->fullBus  (c+1150,(0x3fU),7);
	vcdp->fullBus  (c+1151,(0U),7);
	vcdp->fullBus  (c+1152,(1U),7);
	vcdp->fullBus  (c+1153,(4U),7);
	vcdp->fullBus  (c+1154,(5U),7);
	vcdp->fullBus  (c+1155,(8U),7);
	vcdp->fullBus  (c+1156,(9U),7);
	vcdp->fullBus  (c+1157,(0xaU),7);
	vcdp->fullBus  (c+1158,(0xcU),7);
	vcdp->fullBus  (c+1159,(0xdU),7);
	vcdp->fullBus  (c+1160,(2U),7);
	vcdp->fullBus  (c+1161,(6U),7);
	vcdp->fullBus  (c+1162,(0x14U),7);
	vcdp->fullBus  (c+1163,(0x16U),7);
	vcdp->fullBus  (c+1164,(0x2dU),7);
	vcdp->fullBus  (c+1165,(0x10U),7);
	vcdp->fullBus  (c+1166,(0x11U),7);
	vcdp->fullBus  (c+1167,(0x12U),7);
	vcdp->fullBus  (c+1168,(0x30U),7);
	vcdp->fullBus  (c+1169,(0x31U),7);
	vcdp->fullBus  (c+1170,(0x32U),7);
	vcdp->fullBus  (c+1171,(0x3aU),7);
	vcdp->fullBus  (c+1172,(0x3bU),7);
	vcdp->fullBus  (c+1173,(0x38U),7);
	vcdp->fullBus  (c+1174,(0x39U),7);
	vcdp->fullBus  (c+1175,(0x7fU),7);
	vcdp->fullBus  (c+1176,(0x40U),7);
	vcdp->fullBus  (c+1177,(0x41U),7);
	vcdp->fullBus  (c+1178,(0x42U),7);
	vcdp->fullBus  (c+1179,(0x44U),7);
	vcdp->fullBus  (c+1180,(0x45U),7);
	vcdp->fullBus  (c+1181,(0x46U),7);
	vcdp->fullBus  (c+1182,(0x48U),7);
	vcdp->fullBus  (c+1183,(0x3000U),16);
	vcdp->fullBus  (c+1184,(0x3008U),16);
	vcdp->fullBus  (c+1185,(0x3010U),16);
	vcdp->fullBus  (c+1186,(0x3011U),16);
	vcdp->fullBus  (c+1187,(0U),8);
	vcdp->fullBus  (c+1188,(1U),8);
	vcdp->fullBus  (c+1189,(2U),8);
	vcdp->fullBus  (c+1190,(4U),8);
	vcdp->fullBus  (c+1191,(0U),1);
	vcdp->fullBus  (c+1192,(1U),1);
	vcdp->fullBus  (c+1193,(1U),4);
	vcdp->fullBus  (c+1194,(2U),4);
	vcdp->fullBus  (c+1195,(3U),4);
	vcdp->fullBus  (c+1196,(4U),4);
	vcdp->fullBus  (c+1197,(5U),4);
	vcdp->fullBus  (c+1198,(6U),4);
	vcdp->fullBus  (c+1199,(7U),4);
	vcdp->fullBus  (c+1200,(8U),4);
	vcdp->fullBus  (c+1201,(9U),4);
	vcdp->fullBus  (c+1202,(0xbU),4);
	vcdp->fullBus  (c+1203,(7U),3);
	vcdp->fullBus  (c+1204,(2U),6);
	vcdp->fullBus  (c+1205,(3U),6);
	vcdp->fullBus  (c+1206,(8U),6);
	vcdp->fullBus  (c+1207,(0xbU),6);
	vcdp->fullBus  (c+1208,(0x80U),8);
	vcdp->fullBus  (c+1209,(0x84U),8);
	vcdp->fullBus  (c+1210,(0x88U),8);
	vcdp->fullBus  (c+1211,(0x8cU),8);
	vcdp->fullBus  (c+1212,(0x1fU),6);
	vcdp->fullBus  (c+1213,(0xaU),4);
    }
}
