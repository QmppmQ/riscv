// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (((vlTOPp->__Vm_traceActivity 
				 | (vlTOPp->__Vm_traceActivity 
				    >> 1U)) | (vlTOPp->__Vm_traceActivity 
					       >> 2U)) 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (((vlTOPp->__Vm_traceActivity 
				 | (vlTOPp->__Vm_traceActivity 
				    >> 1U)) | (vlTOPp->__Vm_traceActivity 
					       >> 3U)) 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 5U))))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 2U)) | (vlTOPp->__Vm_traceActivity 
					      >> 5U))))) {
	    vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__11(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				>> 2U) | (vlTOPp->__Vm_traceActivity 
					  >> 3U))))) {
	    vlTOPp->traceChgThis__12(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				>> 2U) | (vlTOPp->__Vm_traceActivity 
					  >> 5U))))) {
	    vlTOPp->traceChgThis__13(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__14(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__15(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x20U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__16(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__17(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_operands_o[0]),32);
	vcdp->chgBus  (c+2,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_operands_o[1]),32);
	vcdp->chgBus  (c+3,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_master_operands_o[2]),32);
	vcdp->chgBus  (c+4,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands[0]),32);
	vcdp->chgBus  (c+5,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands[1]),32);
	vcdp->chgBus  (c+6,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands[2]),32);
	vcdp->chgBus  (c+7,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o[0]),32);
	vcdp->chgBus  (c+8,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o[1]),32);
	vcdp->chgBus  (c+9,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o[2]),32);
	vcdp->chgArray(c+10,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_lut),160);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+15,(vlSymsp->TOP__top.irq_ack_o));
	vcdp->chgBit  (c+16,(vlSymsp->TOP__top.debug_gnt_o));
	vcdp->chgBus  (c+17,(vlSymsp->TOP__top.debug_rdata_o),32);
	vcdp->chgBit  (c+18,(vlSymsp->TOP__top.debug_halted_o));
	vcdp->chgBit  (c+19,(vlSymsp->TOP__top.core_busy_o));
	vcdp->chgBit  (c+20,(vlSymsp->TOP__top.__PVT__instr_req));
	vcdp->chgBus  (c+21,((0x3ffff0U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int)),22);
	vcdp->chgBus  (c+22,(vlSymsp->TOP__top.__PVT__con_data[0]),32);
	vcdp->chgBus  (c+23,(vlSymsp->TOP__top.__PVT__con_data[1]),32);
	vcdp->chgBus  (c+24,(vlSymsp->TOP__top.__PVT__con_data[2]),32);
	vcdp->chgBus  (c+25,(vlSymsp->TOP__top.__PVT__con_data[3]),32);
	vcdp->chgBus  (c+26,(vlSymsp->TOP__top.__PVT__con_data[4]),32);
	vcdp->chgBus  (c+27,(vlSymsp->TOP__top.__PVT__con_data[5]),32);
	vcdp->chgBus  (c+28,(vlSymsp->TOP__top.__PVT__con_data[6]),32);
	vcdp->chgBus  (c+29,(vlSymsp->TOP__top.__PVT__con_data[7]),32);
	vcdp->chgBus  (c+30,(vlSymsp->TOP__top.__PVT__con_data[8]),32);
	vcdp->chgBus  (c+31,(vlSymsp->TOP__top.__PVT__con_data[9]),32);
	vcdp->chgBus  (c+32,(vlSymsp->TOP__top.__PVT__con_data[10]),32);
	vcdp->chgBus  (c+33,(vlSymsp->TOP__top.__PVT__con_data[11]),32);
	vcdp->chgBus  (c+34,(vlSymsp->TOP__top.__PVT__con_data[12]),32);
	vcdp->chgBus  (c+35,(vlSymsp->TOP__top.__PVT__con_data[13]),32);
	vcdp->chgBus  (c+36,(vlSymsp->TOP__top.__PVT__con_data[14]),32);
	vcdp->chgBus  (c+37,(vlSymsp->TOP__top.__PVT__con_data[15]),32);
	vcdp->chgBit  (c+38,(vlSymsp->TOP__top.__PVT__data_req));
	vcdp->chgArray(c+39,(vlSymsp->TOP__top.__PVT__y0),68);
	vcdp->chgArray(c+42,(vlSymsp->TOP__top.__PVT__y1),68);
	vcdp->chgArray(c+45,(vlSymsp->TOP__top.__PVT__y2),68);
	vcdp->chgArray(c+48,(vlSymsp->TOP__top.__PVT__y3),68);
	vcdp->chgBit  (c+51,(((((6U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
				| (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator))) 
			       | (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator))) 
			      & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->chgBus  (c+52,(vlSymsp->TOP__top.__PVT__u0__DOT__y1_l),7);
	vcdp->chgBus  (c+53,(vlSymsp->TOP__top.__PVT__u0__DOT__y1_h),7);
	vcdp->chgBus  (c+54,(vlSymsp->TOP__top.__PVT__u0__DOT__y2_l),7);
	vcdp->chgBus  (c+55,(vlSymsp->TOP__top.__PVT__u0__DOT__y2_h),7);
	vcdp->chgBus  (c+56,(vlSymsp->TOP__top.__PVT__u0__DOT__y3_l),7);
	vcdp->chgBus  (c+57,(vlSymsp->TOP__top.__PVT__u0__DOT__y3_h),7);
	vcdp->chgBus  (c+58,(vlSymsp->TOP__top.__PVT__u0__DOT__y4_l),7);
	vcdp->chgBus  (c+59,(vlSymsp->TOP__top.__PVT__u0__DOT__y4_h),7);
	vcdp->chgBus  (c+60,((0xfU & vlSymsp->TOP__top.__PVT__y0[0U])),4);
	vcdp->chgBus  (c+61,((0xfU & ((vlSymsp->TOP__top.__PVT__y0[1U] 
				       << 0x1cU) | 
				      (vlSymsp->TOP__top.__PVT__y0[0U] 
				       >> 4U)))),4);
	vcdp->chgBus  (c+62,((0xfU & vlSymsp->TOP__top.__PVT__y1[0U])),4);
	vcdp->chgBus  (c+63,((0xfU & ((vlSymsp->TOP__top.__PVT__y1[1U] 
				       << 0x1cU) | 
				      (vlSymsp->TOP__top.__PVT__y1[0U] 
				       >> 4U)))),4);
	vcdp->chgBus  (c+64,((0xfU & vlSymsp->TOP__top.__PVT__y2[0U])),4);
	vcdp->chgBus  (c+65,((0xfU & ((vlSymsp->TOP__top.__PVT__y2[1U] 
				       << 0x1cU) | 
				      (vlSymsp->TOP__top.__PVT__y2[0U] 
				       >> 4U)))),4);
	vcdp->chgBus  (c+66,((0xfU & vlSymsp->TOP__top.__PVT__y3[0U])),4);
	vcdp->chgBus  (c+67,((0xfU & ((vlSymsp->TOP__top.__PVT__y3[1U] 
				       << 0x1cU) | 
				      (vlSymsp->TOP__top.__PVT__y3[0U] 
				       >> 4U)))),4);
	vcdp->chgBus  (c+68,((0xfffffff0U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int)),32);
	vcdp->chgBus  (c+69,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[0]),32);
	vcdp->chgBus  (c+70,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[1]),32);
	vcdp->chgBus  (c+71,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[2]),32);
	vcdp->chgBus  (c+72,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[3]),32);
	vcdp->chgBus  (c+73,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[4]),32);
	vcdp->chgBus  (c+74,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[5]),32);
	vcdp->chgBus  (c+75,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[6]),32);
	vcdp->chgBus  (c+76,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[7]),32);
	vcdp->chgBus  (c+77,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[8]),32);
	vcdp->chgBus  (c+78,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[9]),32);
	vcdp->chgBus  (c+79,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[10]),32);
	vcdp->chgBus  (c+80,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[11]),32);
	vcdp->chgBus  (c+81,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[12]),32);
	vcdp->chgBus  (c+82,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[13]),32);
	vcdp->chgBus  (c+83,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[14]),32);
	vcdp->chgBus  (c+84,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_data[15]),32);
	vcdp->chgBus  (c+85,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__str_operator),2);
	vcdp->chgBit  (c+86,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__str_op_en));
	vcdp->chgBus  (c+87,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__str_op_result),32);
	vcdp->chgBus  (c+88,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__str_operand),32);
	vcdp->chgBus  (c+89,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator),3);
	vcdp->chgBit  (c+90,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en));
	vcdp->chgBus  (c+91,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mac_op_result),32);
	vcdp->chgBus  (c+92,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mac_operand1),32);
	vcdp->chgBus  (c+93,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mac_operand2),32);
	vcdp->chgBit  (c+94,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active));
	vcdp->chgBus  (c+95,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mem_wdata),32);
	vcdp->chgBit  (c+96,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active));
	vcdp->chgBit  (c+97,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__clear_instr_valid));
	vcdp->chgBit  (c+98,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_set));
	vcdp->chgBus  (c+99,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id),3);
	vcdp->chgBus  (c+100,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id),2);
	vcdp->chgBus  (c+101,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause),6);
	vcdp->chgBit  (c+102,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__trap_addr_mux));
	vcdp->chgBit  (c+103,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_decoding));
	vcdp->chgBit  (c+104,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_multicycle));
	vcdp->chgBus  (c+105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target),32);
	vcdp->chgBit  (c+106,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy));
	vcdp->chgBit  (c+107,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__busy_L0));
	vcdp->chgBus  (c+108,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_wdata_fw),32);
	vcdp->chgBus  (c+109,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_op),2);
	vcdp->chgBit  (c+110,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__halt_if));
	vcdp->chgBit  (c+111,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready));
	vcdp->chgBit  (c+112,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_ready));
	vcdp->chgBit  (c+113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_valid));
	vcdp->chgBit  (c+114,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_valid));
	vcdp->chgBit  (c+115,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_wb));
	vcdp->chgBit  (c+116,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_ex));
	vcdp->chgBit  (c+117,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_int));
	vcdp->chgBit  (c+118,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_irq_sec));
	vcdp->chgBus  (c+119,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__epc),32);
	vcdp->chgBit  (c+120,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_cause));
	vcdp->chgBit  (c+121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_if));
	vcdp->chgBit  (c+122,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_id));
	vcdp->chgBus  (c+123,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause),6);
	vcdp->chgBit  (c+124,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_mret_id));
	vcdp->chgBit  (c+125,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_uret_id));
	vcdp->chgBus  (c+126,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_regid),1);
	vcdp->chgBus  (c+127,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_we),3);
	vcdp->chgBus  (c+128,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int),32);
	vcdp->chgBit  (c+129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_req));
	vcdp->chgBit  (c+130,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_ack));
	vcdp->chgBit  (c+131,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_stall));
	vcdp->chgBit  (c+132,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_trap));
	vcdp->chgBus  (c+133,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_data_rc_id),32);
	vcdp->chgBit  (c+134,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq));
	vcdp->chgBit  (c+135,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_csr_we));
	vcdp->chgBit  (c+136,((1U & ((~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid)) 
				     | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req)))));
	vcdp->chgBit  (c+137,(((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)) 
			       | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)))));
	vcdp->chgBit  (c+138,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jr_stall));
	vcdp->chgBit  (c+139,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__load_stall));
	vcdp->chgBit  (c+140,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__perf_pipeline_stall));
	vcdp->chgBit  (c+141,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_ctrl_firstfetch));
	vcdp->chgBit  (c+142,(((4U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id)) 
			       & (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id)))));
	vcdp->chgBit  (c+143,((1U & (~ (IData)(vlSymsp->TOP__top.core_busy_o)))));
	vcdp->chgBus  (c+144,((0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause))),5);
	vcdp->chgBus  (c+145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_ns),1);
	vcdp->chgBit  (c+146,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__if_valid));
	vcdp->chgBit  (c+147,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid) 
			       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready))));
	vcdp->chgBit  (c+148,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid));
	vcdp->chgBit  (c+149,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req));
	vcdp->chgBus  (c+150,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_addr_n),32);
	vcdp->chgBit  (c+151,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid));
	vcdp->chgBit  (c+152,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_ready));
	vcdp->chgBus  (c+153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata),32);
	vcdp->chgBit  (c+154,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_is_hwlp));
	vcdp->chgBus  (c+155,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__exc_pc),32);
	vcdp->chgBus  (c+156,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__trap_base_addr),24);
	vcdp->chgBus  (c+157,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__instr_decompressed),32);
	vcdp->chgBit  (c+158,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__illegal_c_insn));
	vcdp->chgBit  (c+159,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata))));
	vcdp->chgBus  (c+160,((0xfffffffeU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_addr_n)),32);
	vcdp->chgBus  (c+161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__NS),4);
	vcdp->chgBit  (c+162,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__do_fetch));
	vcdp->chgBit  (c+163,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__do_hwlp));
	vcdp->chgBit  (c+164,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__do_hwlp_int));
	vcdp->chgBit  (c+165,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__use_last));
	vcdp->chgBit  (c+166,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__save_rdata_last));
	vcdp->chgBit  (c+167,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__use_hwlp));
	vcdp->chgBit  (c+168,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__save_rdata_hwlp));
	vcdp->chgBit  (c+169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__valid));
	vcdp->chgBit  (c+170,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__next_is_crossword));
	vcdp->chgBit  (c+171,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__next_valid));
	vcdp->chgBit  (c+172,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__next_upper_compressed));
	vcdp->chgBus  (c+173,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_n),32);
	vcdp->chgBus  (c+174,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_int),32);
	vcdp->chgBus  (c+175,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_real_next),32);
	vcdp->chgBit  (c+176,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__is_hwlp_n));
	vcdp->chgBit  (c+177,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__valid) 
			       & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req)))));
	vcdp->chgBit  (c+178,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__fetch_valid));
	vcdp->chgBus  (c+179,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata),32);
	vcdp->chgBit  (c+180,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata))));
	vcdp->chgBit  (c+181,((3U != (3U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata 
					    >> 0x10U)))));
	vcdp->chgBit  (c+182,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellinp__L0_buffer_i__hwlp_i));
	vcdp->chgBus  (c+183,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__NS),3);
	vcdp->chgBus  (c+184,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int),32);
	vcdp->chgBit  (c+185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__valid));
	vcdp->chgBit  (c+186,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we));
	vcdp->chgBit  (c+187,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__illegal_insn_dec));
	vcdp->chgBit  (c+188,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ebrk_insn));
	vcdp->chgBit  (c+189,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mret_insn_dec));
	vcdp->chgBit  (c+190,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__uret_insn_dec));
	vcdp->chgBit  (c+191,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ecall_insn_dec));
	vcdp->chgBit  (c+192,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__pipe_flush_dec));
	vcdp->chgBit  (c+193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__rega_used_dec));
	vcdp->chgBit  (c+194,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec));
	vcdp->chgBit  (c+195,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec));
	vcdp->chgBus  (c+196,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id),2);
	vcdp->chgBus  (c+197,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__jump_in_id),2);
	vcdp->chgBit  (c+198,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__instr_multicycle));
	vcdp->chgBit  (c+199,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__halt_id));
	vcdp->chgBus  (c+200,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_shuffle_type),32);
	vcdp->chgBit  (c+201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_ack));
	vcdp->chgBit  (c+202,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_kill));
	vcdp->chgBus  (c+203,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id),6);
	vcdp->chgBit  (c+204,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_we_id));
	vcdp->chgBit  (c+205,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_en));
	vcdp->chgBus  (c+206,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operator),7);
	vcdp->chgBus  (c+207,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_a_mux_sel),3);
	vcdp->chgBus  (c+208,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_b_mux_sel),3);
	vcdp->chgBus  (c+209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_c_mux_sel),2);
	vcdp->chgBus  (c+210,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_mux),2);
	vcdp->chgBus  (c+211,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel),1);
	vcdp->chgBus  (c+212,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel),4);
	vcdp->chgBus  (c+213,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target_mux_sel),2);
	vcdp->chgBus  (c+214,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_operator),3);
	vcdp->chgBit  (c+215,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en) 
			       | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en))));
	vcdp->chgBit  (c+216,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en));
	vcdp->chgBit  (c+217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_sel_subword));
	vcdp->chgBus  (c+218,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_signed_mode),2);
	vcdp->chgBit  (c+219,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en));
	vcdp->chgBus  (c+220,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_signed),2);
	vcdp->chgBit  (c+221,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_we_id));
	vcdp->chgBit  (c+222,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_we_id));
	vcdp->chgBus  (c+223,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_type_id),2);
	vcdp->chgBit  (c+224,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_sign_ext_id));
	vcdp->chgBit  (c+225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_req_id));
	vcdp->chgBit  (c+226,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_load_event_id));
	vcdp->chgBus  (c+227,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regid),1);
	vcdp->chgBus  (c+228,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we),3);
	vcdp->chgBus  (c+229,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_int),3);
	vcdp->chgBit  (c+230,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target_mux_sel));
	vcdp->chgBit  (c+231,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_mux_sel));
	vcdp->chgBit  (c+232,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_mux_sel));
	vcdp->chgBus  (c+233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target),32);
	vcdp->chgBus  (c+234,(((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_int))
			        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int
			        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
	vcdp->chgBus  (c+235,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int),32);
	vcdp->chgBus  (c+236,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_int))
			        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target
			        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
	vcdp->chgBus  (c+237,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt),32);
	vcdp->chgBus  (c+238,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_int),32);
	vcdp->chgBit  (c+239,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_valid));
	vcdp->chgBit  (c+240,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access));
	vcdp->chgBus  (c+241,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we)
			        ? 0U : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op))),2);
	vcdp->chgBit  (c+242,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_status));
	vcdp->chgBit  (c+243,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__prepost_useincr));
	vcdp->chgBus  (c+244,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_mux_sel),2);
	vcdp->chgBus  (c+245,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_mux_sel),2);
	vcdp->chgBus  (c+246,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_mux_sel),2);
	vcdp->chgBus  (c+247,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_id),32);
	vcdp->chgBus  (c+248,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id),32);
	vcdp->chgBus  (c+249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_id),32);
	vcdp->chgBus  (c+250,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b),32);
	vcdp->chgBus  (c+251,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_vec),32);
	vcdp->chgBus  (c+252,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_a),32);
	vcdp->chgBus  (c+253,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_b),32);
	vcdp->chgBus  (c+254,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_c),32);
	vcdp->chgBus  (c+255,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_mux),1);
	vcdp->chgBus  (c+256,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_mux),2);
	vcdp->chgBit  (c+257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel));
	vcdp->chgBit  (c+258,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel));
	vcdp->chgBus  (c+259,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux),1);
	vcdp->chgBus  (c+260,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm),5);
	vcdp->chgBus  (c+261,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm),5);
	vcdp->chgBus  (c+262,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
					 ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
					 : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
					     ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
					     : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id 
						>> 5U))))),5);
	vcdp->chgBus  (c+263,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
					 ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
					 : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
					     ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
					     : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id)))),5);
	vcdp->chgBus  (c+264,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode),2);
	vcdp->chgBit  (c+265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__scalar_replication));
	vcdp->chgBit  (c+266,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_a_id));
	vcdp->chgBit  (c+267,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_wb_is_reg_a_id));
	vcdp->chgBit  (c+268,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_alu_is_reg_a_id));
	vcdp->chgBus  (c+269,(vlSymsp->TOP__top.riscv_core_i__DOT__id_stage_i__DOT____Vcellinp__registers_i__wdata_b_i),32);
	vcdp->chgBus  (c+270,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_b_dec),32);
	vcdp->chgBit  (c+271,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_mem_we));
	vcdp->chgBit  (c+272,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_alu_we));
	vcdp->chgBit  (c+273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__data_req));
	vcdp->chgBus  (c+274,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__hwloop_we),3);
	vcdp->chgBit  (c+275,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal));
	vcdp->chgBus  (c+276,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op),2);
	vcdp->chgBit  (c+277,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_int_en));
	vcdp->chgBit  (c+278,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_dot_en));
	vcdp->chgBus  (c+279,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns),5);
	vcdp->chgBit  (c+280,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done));
	vcdp->chgBit  (c+281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_in_dec));
	vcdp->chgBit  (c+282,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__branch_in_id));
	vcdp->chgBit  (c+283,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done));
	vcdp->chgBit  (c+284,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__irq_enable_int));
	vcdp->chgBus  (c+285,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[0]),32);
	vcdp->chgBus  (c+286,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[1]),32);
	vcdp->chgBus  (c+287,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[2]),32);
	vcdp->chgBus  (c+288,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[3]),32);
	vcdp->chgBus  (c+289,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[4]),32);
	vcdp->chgBus  (c+290,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[5]),32);
	vcdp->chgBus  (c+291,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[6]),32);
	vcdp->chgBus  (c+292,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[7]),32);
	vcdp->chgBus  (c+293,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[8]),32);
	vcdp->chgBus  (c+294,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[9]),32);
	vcdp->chgBus  (c+295,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[10]),32);
	vcdp->chgBus  (c+296,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[11]),32);
	vcdp->chgBus  (c+297,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[12]),32);
	vcdp->chgBus  (c+298,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[13]),32);
	vcdp->chgBus  (c+299,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[14]),32);
	vcdp->chgBus  (c+300,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__con_data[15]),32);
	vcdp->chgBit  (c+301,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_ready));
	vcdp->chgBit  (c+302,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_ready) 
				 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_ready)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_ready)) 
			       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_ready))));
	vcdp->chgBus  (c+303,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_result),32);
	vcdp->chgBus  (c+304,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_result),32);
	vcdp->chgBit  (c+305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_ready));
	vcdp->chgBit  (c+306,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_ready));
	vcdp->chgBus  (c+307,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_NS),3);
	vcdp->chgBit  (c+308,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_active));
	vcdp->chgBus  (c+309,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_intermediate),32);
	vcdp->chgBus  (c+310,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__char_),32);
	vcdp->chgBus  (c+311,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[0]),32);
	vcdp->chgBus  (c+312,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[1]),32);
	vcdp->chgBus  (c+313,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[2]),32);
	vcdp->chgBus  (c+314,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[3]),32);
	vcdp->chgBus  (c+315,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[4]),32);
	vcdp->chgBus  (c+316,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[5]),32);
	vcdp->chgBus  (c+317,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[6]),32);
	vcdp->chgBus  (c+318,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[7]),32);
	vcdp->chgBus  (c+319,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[8]),32);
	vcdp->chgBus  (c+320,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[9]),32);
	vcdp->chgBus  (c+321,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[10]),32);
	vcdp->chgBus  (c+322,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[11]),32);
	vcdp->chgBus  (c+323,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[12]),32);
	vcdp->chgBus  (c+324,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[13]),32);
	vcdp->chgBus  (c+325,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[14]),32);
	vcdp->chgBus  (c+326,(vlSymsp->TOP__top.riscv_core_i__DOT__ex_stage_i__DOT____Vcellout__riscv_mac_ops_i__con_data[15]),32);
	vcdp->chgBus  (c+327,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_ns),3);
	vcdp->chgBus  (c+328,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_ns),3);
	vcdp->chgBus  (c+329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_ns),3);
	vcdp->chgBit  (c+330,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_ns));
	vcdp->chgBit  (c+331,(((6U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
			       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->chgBit  (c+332,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_ready));
	vcdp->chgBit  (c+333,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_ready));
	vcdp->chgBit  (c+334,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_ready));
	vcdp->chgBit  (c+335,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_active));
	vcdp->chgBit  (c+336,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_ready));
	vcdp->chgBit  (c+337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_active));
	vcdp->chgBus  (c+338,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_operand),32);
	vcdp->chgBus  (c+339,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_mult1),16);
	vcdp->chgBus  (c+340,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_mult2),16);
	vcdp->chgBus  (c+341,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_add),32);
	vcdp->chgBus  (c+342,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_operand_1),32);
	vcdp->chgBus  (c+343,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_operand_2),32);
	vcdp->chgBus  (c+344,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult1),16);
	vcdp->chgBus  (c+345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult2),16);
	vcdp->chgBus  (c+346,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult3),16);
	vcdp->chgBus  (c+347,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_mult4),16);
	vcdp->chgBus  (c+348,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_add),32);
	vcdp->chgBus  (c+349,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__max),32);
	vcdp->chgBus  (c+350,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w0),32);
	vcdp->chgBus  (c+351,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w1),32);
	vcdp->chgBus  (c+352,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w2),32);
	vcdp->chgBus  (c+353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w3),32);
	vcdp->chgBus  (c+354,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w4),32);
	vcdp->chgBus  (c+355,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w5),32);
	vcdp->chgBus  (c+356,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w6),32);
	vcdp->chgBus  (c+357,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w7),32);
	vcdp->chgBus  (c+358,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__w8),32);
	vcdp->chgBus  (c+359,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y0),32);
	vcdp->chgBus  (c+360,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y1),32);
	vcdp->chgBus  (c+361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y2),32);
	vcdp->chgBus  (c+362,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__y3),32);
	vcdp->chgBus  (c+363,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__ymax),32);
	vcdp->chgArray(c+364,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_0),67);
	vcdp->chgArray(c+367,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_3),67);
	vcdp->chgArray(c+370,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_0),67);
	vcdp->chgArray(c+373,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_3),67);
	vcdp->chgArray(c+376,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_1),68);
	vcdp->chgArray(c+379,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0_2),68);
	vcdp->chgArray(c+382,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_1),68);
	vcdp->chgArray(c+385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0_2),68);
	vcdp->chgArray(c+388,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_0),69);
	vcdp->chgArray(c+391,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_3),69);
	vcdp->chgArray(c+394,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_0),69);
	vcdp->chgArray(c+397,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_3),69);
	vcdp->chgArray(c+400,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_0),71);
	vcdp->chgArray(c+403,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_0),71);
	vcdp->chgArray(c+406,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M0_1),70);
	vcdp->chgArray(c+409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M3_1),70);
	vcdp->chgArray(c+412,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_1),70);
	vcdp->chgArray(c+415,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0_2),70);
	vcdp->chgArray(c+418,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_1),70);
	vcdp->chgArray(c+421,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0_2),70);
	vcdp->chgArray(c+424,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_1),72);
	vcdp->chgArray(c+427,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_1),72);
	vcdp->chgArray(c+430,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M1_0),73);
	vcdp->chgArray(c+433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__M2_0),73);
	vcdp->chgQuad (c+436,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid0_0),34);
	vcdp->chgQuad (c+438,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid0_1),34);
	vcdp->chgQuad (c+440,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid3_0),34);
	vcdp->chgQuad (c+442,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid3_1),34);
	vcdp->chgQuad (c+444,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid1_0),36);
	vcdp->chgQuad (c+446,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid1_1),36);
	vcdp->chgQuad (c+448,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid2_0),36);
	vcdp->chgQuad (c+450,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mid2_1),36);
	vcdp->chgBit  (c+452,(((2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
			       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->chgBit  (c+453,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_operator)) 
			       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mac_op_en))));
	vcdp->chgBus  (c+454,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift),6);
	vcdp->chgBus  (c+455,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_left),32);
	vcdp->chgBus  (c+456,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt),32);
	vcdp->chgBus  (c+457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_int),32);
	vcdp->chgBus  (c+458,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result),32);
	vcdp->chgBus  (c+459,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_right_result),32);
	vcdp->chgBus  (c+460,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result),32);
	vcdp->chgBus  (c+461,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bitop_result),6);
	vcdp->chgBus  (c+462,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bextins_result),32);
	vcdp->chgBus  (c+463,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D),32);
	vcdp->chgBus  (c+464,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D),32);
	vcdp->chgBit  (c+465,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S));
	vcdp->chgBit  (c+466,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S));
	vcdp->chgBit  (c+467,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S));
	vcdp->chgBit  (c+468,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S));
	vcdp->chgBus  (c+469,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SN),2);
	vcdp->chgBus  (c+470,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a),17);
	vcdp->chgBus  (c+471,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b),17);
	vcdp->chgQuad (c+472,((VL_ULL(0x3ffffffff) 
			       & VL_MULS_QQQ(34,34,34, 
					     (VL_ULL(0x3ffffffff) 
					      & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a)), 
					     (VL_ULL(0x3ffffffff) 
					      & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b))))),34);
	vcdp->chgQuad (c+474,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac),34);
	vcdp->chgQuad (c+476,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_result),34);
	vcdp->chgBit  (c+478,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
				      ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						 >> 0x21U))
				      : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						 >> 0x1fU))))));
	vcdp->chgBit  (c+479,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
				      ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						 >> 0x20U))
				      : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
						 >> 0x1fU))))));
	vcdp->chgBus  (c+480,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_subword),2);
	vcdp->chgBus  (c+481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_signed),2);
	vcdp->chgBit  (c+482,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_shift_arith));
	vcdp->chgBus  (c+483,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm),5);
	vcdp->chgBus  (c+484,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_subword),2);
	vcdp->chgBus  (c+485,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_signed),2);
	vcdp->chgBit  (c+486,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_shift_arith));
	vcdp->chgBit  (c+487,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active));
	vcdp->chgBit  (c+488,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_save));
	vcdp->chgBit  (c+489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_clearcarry));
	vcdp->chgBus  (c+490,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_NS),3);
	vcdp->chgBus  (c+491,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__NS),2);
	vcdp->chgBit  (c+492,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_we_int));
	vcdp->chgBus  (c+493,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__frm_n),3);
	vcdp->chgBus  (c+494,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fflags_n),5);
	vcdp->chgBus  (c+495,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fprec_n),5);
	vcdp->chgBus  (c+496,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_n),32);
	vcdp->chgBus  (c+497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__exception_pc),32);
	vcdp->chgBus  (c+498,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_n),6);
	vcdp->chgBus  (c+499,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_n),6);
	vcdp->chgBit  (c+500,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause) 
				     >> 5U))));
	vcdp->chgBus  (c+501,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_n),2);
	vcdp->chgBus  (c+502,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc),12);
	vcdp->chgArray(c+503,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_n),384);
	vcdp->chgBus  (c+515,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_n),2);
	vcdp->chgBus  (c+516,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_n),12);
	vcdp->chgBus  (c+517,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__rdata_sel_n),3);
	vcdp->chgBus  (c+518,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__state_n),1);
	vcdp->chgBus  (c+519,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__settings_n),6);
	vcdp->chgBit  (c+520,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_rreq_n));
	vcdp->chgBit  (c+521,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_n));
	vcdp->chgBit  (c+522,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__jump_req_n));
	vcdp->chgBit  (c+523,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_n));
	vcdp->chgBit  (c+524,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_wr));
	vcdp->chgBus  (c+525,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__stall_ns),2);
	vcdp->chgBus  (c+526,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_rdata),32);
	vcdp->chgBit  (c+527,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_resume));
	vcdp->chgBit  (c+528,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_halt));
	vcdp->chgBus  (c+529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_cause_n),6);
	vcdp->chgBit  (c+530,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_ssth_n));
	vcdp->chgBit  (c+531,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__ssth_clear));
	vcdp->chgBus  (c+532,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__pc_tracking_fsm_ns),2);
	vcdp->chgBus  (c+533,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__ppc_int),32);
	vcdp->chgBus  (c+534,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__npc_int),32);
	vcdp->chgBus  (c+535,((0xffff0U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__instr_addr_int)),20);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+536,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_cs) 
			       ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active))));
	vcdp->chgBit  (c+537,(((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
				 | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
				| (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
			       | (IData)(vlSymsp->TOP__top.__PVT__data_req))));
	vcdp->chgBit  (c+538,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
				 == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
			       & (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
	vcdp->chgBus  (c+539,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_rreq_q)
			        ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_q) 
				    << 5U) | (0x1fU 
					      & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q) 
						 >> 2U)))
			        : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id))),6);
	vcdp->chgBus  (c+540,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S)
			        ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
				    : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
					<< 0x1fU) | 
				       (0x7fffffffU 
					& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
					   >> 1U))))
			        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP)),32);
	vcdp->chgBus  (c+541,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
			        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
			        : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
				    << 0x1fU) | (0x7fffffffU 
						 & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
						    >> 1U))))),32);
	vcdp->chgBus  (c+542,((0x3fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
					 ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift)
					 : ((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))
					     ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP) 
						- (IData)(1U))
					     : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))))),6);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+543,(((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_load_event_ex) 
				      & (IData)(vlSymsp->TOP__top.__PVT__data_req)))
			        ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__busy_L0)
			        : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__busy_L0) 
				    | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy)) 
				   | ((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
					| (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
				       | (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
				      | (IData)(vlSymsp->TOP__top.__PVT__data_req))))));
	vcdp->chgBit  (c+544,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
				 == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					      >> 0x14U))) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
			       & (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						  >> 0x14U))))));
	vcdp->chgBus  (c+545,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
			        ? 0U : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S)
					 ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S) 
					     << 0x1fU) 
					    | (0x7fffffffU 
					       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP 
						  >> 1U)))
					 : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP))),32);
	vcdp->chgBus  (c+546,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S)
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
	vcdp->chgBit  (c+547,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				      ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
					 >> 1U) : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP)))));
	vcdp->chgBit  (c+548,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
			        ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)
			        : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP))));
	vcdp->chgBit  (c+549,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
				      ? ((((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result)) 
					   | ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
					      >> 1U)) 
					  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
					 & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
					     >> 0x1fU) 
					    ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))
				      : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)))));
	vcdp->chgQuad (c+550,((VL_ULL(0x1ffffffff) 
			       & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
				   ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q)) 
				       << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))
				   : VL_EXTENDS_QI(33,32, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))),33);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+552,((0x3fffffU & ((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
					      | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
					     | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
					     ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
					     : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int))),22);
	vcdp->chgBus  (c+553,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
				 | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
				| (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
			        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
			        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),32);
	vcdp->chgBus  (c+554,((0xfffffU & ((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
					     | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
					    | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
					    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
					    : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int))),20);
	vcdp->chgBus  (c+555,((0xffffcU & ((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active) 
					     | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active)) 
					    | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__w_wb_active))
					    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con
					    : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int))),20);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+556,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__wb23_active)
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
	vcdp->chgBus  (c+557,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata_unaligned),32);
	vcdp->chgBit  (c+558,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access) 
			       & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex) 
				  & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex) 
				     >> 1U)))));
	vcdp->chgBus  (c+559,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel)
			        ? 0U : (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						 >> 0xfU)))),32);
	vcdp->chgBus  (c+560,(((8U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel))
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
	vcdp->chgBus  (c+561,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
					 ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
					     ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						>> 0x19U)
					     : 0U) : 0U))),5);
	vcdp->chgBit  (c+562,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex) 
				 == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					      >> 0x14U))) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
			       & (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						  >> 0x14U))))));
	vcdp->chgBit  (c+563,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex) 
				 == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
			       & (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
	vcdp->chgBit  (c+564,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
				 == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					      >> 0x14U))) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
			       & (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						  >> 0x14U))))));
	vcdp->chgBit  (c+565,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
				 == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
				& (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
			       & (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
	vcdp->chgBit  (c+566,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq) 
			       | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_fw))));
	vcdp->chgBus  (c+567,((0x3fU & ((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
					- (IData)(1U)))),6);
	vcdp->chgBus  (c+568,((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U])),5);
	vcdp->chgBit  (c+569,((1U & (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes))));
	vcdp->chgBus  (c+570,((0x1fU & ((IData)(0x1fU) 
					- vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]))),5);
	vcdp->chgBit  (c+571,(((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
			       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
				  >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))));
	vcdp->chgBus  (c+572,(((0x2aU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
			        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex
			        : VL_NEGATE_I((IData)(
						      ((0x28U 
							== (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
						       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
							  >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))))))),32);
	vcdp->chgBus  (c+573,((0x3fU & ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes)
					 ? ((0x1fU 
					     & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
					    - (IData)(1U))
					 : 0x1fU))),6);
	vcdp->chgBus  (c+574,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes),32);
	vcdp->chgArray(c+575,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes),160);
	vcdp->chgBus  (c+580,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
				& (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
				      & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
					  >> 0x1fU) 
					 ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))
			        ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
				   + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D)
			        : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
				   - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D))),32);
	vcdp->chgBit  (c+581,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
			       & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
				     & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
					 >> 0x1fU) 
					^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))));
	vcdp->chgBus  (c+582,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
			        ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm)
			        : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),5);
	vcdp->chgBit  (c+583,(((IData)(vlSymsp->TOP__top.__PVT__data_req) 
			       & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex)))));
	vcdp->chgBit  (c+584,(((IData)(vlSymsp->TOP__top.__PVT__data_req) 
			       & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex))));
	vcdp->chgBus  (c+585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_in),12);
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+586,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_wb));
	vcdp->chgBit  (c+587,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__m_irq_enable));
	vcdp->chgBus  (c+588,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_a_dec),32);
	vcdp->chgQuad (c+589,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_n),64);
	vcdp->chgBus  (c+591,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)
			        ? VL_NEGATE_I(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)
			        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)),32);
	vcdp->chgBus  (c+592,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP_rev),32);
	vcdp->chgBus  (c+593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D),32);
    }
}

void Vtop::traceChgThis__9(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+594,(((0x800U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr))
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
    }
}

void Vtop::traceChgThis__10(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+595,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
			        ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
				    ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
				        ? 8U : 4U) : 
				   ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
				     ? 2U : 1U)) : 
			       ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
				 ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
				     ? 1U : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					      ? ((1U 
						  & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						  ? 8U
						  : 0xcU)
					      : ((1U 
						  & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
						  ? 6U
						  : 3U)))
				 : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
				     ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					 ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					     ? 7U : 3U)
					 : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					     ? 1U : 0U))
				     : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					 ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					     ? 8U : 0xcU)
					 : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
					     ? 0xeU
					     : 0xfU)))))),4);
	vcdp->chgBit  (c+596,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_hwlp_id));
	vcdp->chgBit  (c+597,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned));
	vcdp->chgBit  (c+598,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result) 
				     >> 3U))));
	vcdp->chgBus  (c+599,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_operands_ex[0]),32);
	vcdp->chgBus  (c+600,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_operands_ex[1]),32);
	vcdp->chgBus  (c+601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_operands_ex[2]),32);
	vcdp->chgBus  (c+602,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_rdata),32);
	vcdp->chgBit  (c+603,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_fw));
	vcdp->chgBus  (c+604,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr),12);
	vcdp->chgBus  (c+605,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_rdata),32);
	vcdp->chgBus  (c+606,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_wdata),32);
	vcdp->chgBit  (c+607,((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr))));
	vcdp->chgBus  (c+608,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_target),32);
	vcdp->chgBus  (c+609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt),2);
	vcdp->chgBus  (c+610,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT____Vcellinp__hwloop_controller_i__hwlp_dec_cnt_id_i),2);
	vcdp->chgBus  (c+611,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr),2);
	vcdp->chgBus  (c+612,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__j),32);
	vcdp->chgBit  (c+613,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__hwlp_is_crossword));
	vcdp->chgBit  (c+614,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__is_crossword));
	vcdp->chgBit  (c+615,((3U != (3U & (vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[3U] 
					    >> 0x10U)))));
	vcdp->chgArray(c+616,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o),128);
	vcdp->chgBit  (c+620,((3U != (3U & vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[3U]))));
	vcdp->chgBit  (c+621,((3U != (3U & ((vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[3U] 
					     << 0x10U) 
					    | (vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT____Vcellout__L0_buffer_i__rdata_o[2U] 
					       >> 0x10U))))));
	vcdp->chgBit  (c+622,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__branch_taken_ex));
	vcdp->chgBus  (c+623,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_i_type),32);
	vcdp->chgBus  (c+624,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type),32);
	vcdp->chgBus  (c+625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_data_ra_id),32);
	vcdp->chgBus  (c+626,((3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type)),2);
	vcdp->chgBus  (c+627,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellinp__ex_stage_i__apu_operands_i[0]),32);
	vcdp->chgBus  (c+628,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellinp__ex_stage_i__apu_operands_i[1]),32);
	vcdp->chgBus  (c+629,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellinp__ex_stage_i__apu_operands_i[2]),32);
	vcdp->chgBus  (c+630,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_rev),32);
	vcdp->chgBus  (c+631,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_neg_rev),32);
	vcdp->chgBit  (c+632,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_valid));
	vcdp->chgBus  (c+633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask),32);
	vcdp->chgBit  (c+634,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b_negate));
	vcdp->chgBus  (c+635,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_a),32);
	vcdp->chgBus  (c+636,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b),32);
	vcdp->chgQuad (c+637,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_a),36);
	vcdp->chgQuad (c+639,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_b),36);
	vcdp->chgBus  (c+641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result),32);
	vcdp->chgQuad (c+642,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded),37);
	vcdp->chgBus  (c+644,((((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				  | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				 | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				| (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
			        ? (0x7fffffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
						  >> 1U))
			        : 0U)),32);
	vcdp->chgBus  (c+645,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result 
			       + (((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				     | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				    | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				   | (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
				   ? (0x7fffffffU & 
				      (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
				       >> 1U)) : 0U))),32);
	vcdp->chgBit  (c+646,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left));
	vcdp->chgBit  (c+647,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_use_round));
	vcdp->chgBit  (c+648,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic));
	vcdp->chgBus  (c+649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a),32);
	vcdp->chgQuad (c+650,(((0x26U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
			        ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)) 
				    << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)))
			        : (((QData)((IData)(
						    VL_NEGATE_I((IData)(
									((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic) 
									 & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a 
									    >> 0x1fU)))))) 
				    << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a))))),64);
	vcdp->chgBus  (c+652,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal),4);
	vcdp->chgBus  (c+653,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater),4);
	vcdp->chgBus  (c+654,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_greater),4);
	vcdp->chgBus  (c+655,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_signed),4);
	vcdp->chgBus  (c+656,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_vec),4);
	vcdp->chgBus  (c+657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater_vec),4);
	vcdp->chgBus  (c+658,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result),4);
	vcdp->chgBus  (c+659,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_nan),4);
	vcdp->chgBus  (c+660,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax),32);
	vcdp->chgBus  (c+661,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__sel_minmax),4);
	vcdp->chgBus  (c+662,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__minmax_b),32);
	vcdp->chgBus  (c+663,(((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater))
			        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax
			        : (((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
				       >> 0x1fU)) ? 0U
				    : ((1U & (IData)(
						     (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded 
						      >> 0x24U)))
				        ? (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)
				        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax)))),32);
	vcdp->chgBit  (c+664,((1U & (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded 
					     >> 0x24U)))));
	vcdp->chgBus  (c+665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_byte_sel),8);
	vcdp->chgBus  (c+666,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg_sel),4);
	vcdp->chgBus  (c+667,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg1_sel),2);
	vcdp->chgBus  (c+668,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg0_sel),2);
	vcdp->chgBus  (c+669,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_through),4);
	vcdp->chgBus  (c+670,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1),32);
	vcdp->chgBus  (c+671,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0),32);
	vcdp->chgBus  (c+672,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1_in),32);
	vcdp->chgBus  (c+673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0_in),32);
	vcdp->chgBus  (c+674,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_result),32);
	vcdp->chgBus  (c+675,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__pack_result),32);
	vcdp->chgBus  (c+676,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__ff_input),32);
	vcdp->chgBus  (c+677,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result),6);
	vcdp->chgBus  (c+678,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
	vcdp->chgBus  (c+679,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
			       & (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask))),32);
	vcdp->chgBus  (c+680,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
			       | vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
	vcdp->chgBit  (c+681,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed));
	vcdp->chgBus  (c+682,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l1),32);
	vcdp->chgBus  (c+683,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l2),24);
	vcdp->chgBus  (c+684,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l3),16);
	vcdp->chgBus  (c+685,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l4),10);
	vcdp->chgBit  (c+686,((0U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result))));
	vcdp->chgBit  (c+687,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S));
	vcdp->chgBus  (c+688,(((((VL_EXTENDS_II(32,18, 
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
	vcdp->chgBus  (c+689,(((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul[0U] 
				+ ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul[2U] 
				    << 0x1eU) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul[1U] 
						 >> 2U))) 
			       + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex)),32);
	vcdp->chgQuad (c+690,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_a),36);
	vcdp->chgQuad (c+692,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_b),36);
	vcdp->chgArray(c+694,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul),72);
	vcdp->chgQuad (c+697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_a),34);
	vcdp->chgQuad (c+699,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b),34);
	vcdp->chgArray(c+701,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul),68);
	vcdp->chgBus  (c+704,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int),32);
	vcdp->chgBus  (c+705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset),2);
	vcdp->chgBus  (c+706,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_rdata_ext),32);
	vcdp->chgBus  (c+707,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__perf_rdata),32);
	vcdp->chgBus  (c+708,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_index),5);
	vcdp->chgBit  (c+709,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_all_sel));
	vcdp->chgBit  (c+710,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pccr));
	vcdp->chgBit  (c+711,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcer));
	vcdp->chgBit  (c+712,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcmr));
    }
}

void Vtop::traceChgThis__11(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+713,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_id_q),5);
	vcdp->chgBit  (c+714,((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_q))));
	vcdp->chgBit  (c+715,(vlSymsp->TOP__top.debug_rvalid_o));
	vcdp->chgBit  (c+716,((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[0xbU])));
	vcdp->chgBit  (c+717,(vlSymsp->TOP__top.__PVT__u0__DOT__clk_));
	vcdp->chgBus  (c+718,(vlSymsp->TOP__top.__PVT__u0__DOT__divider0__DOT__cnt),16);
	vcdp->chgBus  (c+719,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[0xbU]),32);
	vcdp->chgBus  (c+720,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu),6);
	vcdp->chgBus  (c+721,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_q),2);
	vcdp->chgBit  (c+722,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
				>> 5U) & (0U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_q)))));
	vcdp->chgQuad (c+723,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_start_q),64);
	vcdp->chgQuad (c+725,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_end_q),64);
	vcdp->chgQuad (c+727,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_q),64);
	vcdp->chgBus  (c+729,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__settings_q),6);
	vcdp->chgBit  (c+730,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_rreq_q));
	vcdp->chgBus  (c+731,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_q) 
				<< 5U) | (0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q) 
						   >> 2U)))),6);
	vcdp->chgBit  (c+732,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_q));
	vcdp->chgBus  (c+733,((0xfffU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q) 
					 >> 2U))),12);
	vcdp->chgBus  (c+734,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__wdata_q),32);
	vcdp->chgBit  (c+735,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__jump_req_q));
	vcdp->chgBit  (c+736,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_busy_q));
	vcdp->chgBus  (c+737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_cs),1);
	vcdp->chgBus  (c+738,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__addr_q),32);
	vcdp->chgBus  (c+739,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__CS),3);
	vcdp->chgArray(c+740,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__L0_buffer_i__DOT__L0_buffer),128);
	vcdp->chgBit  (c+744,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs))));
	vcdp->chgBit  (c+745,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_sec_q));
	vcdp->chgBus  (c+746,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__TestReadAddr_Q),6);
	vcdp->chgArray(c+747,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem),1024);
	vcdp->chgBus  (c+779,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs),5);
	vcdp->chgBit  (c+780,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done_q));
	vcdp->chgBit  (c+781,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done_q));
	vcdp->chgBus  (c+782,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs),2);
	vcdp->chgBus  (c+783,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__i),32);
	vcdp->chgBit  (c+784,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_we_lsu));
	vcdp->chgBus  (c+785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_str_ops_i__DOT__leet_CS),3);
	vcdp->chgBus  (c+786,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__mac_cs),3);
	vcdp->chgBus  (c+787,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_2x2_cs),3);
	vcdp->chgBus  (c+788,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_cs),3);
	vcdp->chgBit  (c+789,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__wb23_cs));
	vcdp->chgBit  (c+790,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__con_active_d));
	vcdp->chgBit  (c+791,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__riscv_mac_ops_i__DOT__enable_i_d));
	vcdp->chgBus  (c+792,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP),32);
	vcdp->chgBus  (c+793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AReg_DP),32);
	vcdp->chgBus  (c+794,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP),32);
	vcdp->chgBit  (c+795,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP));
	vcdp->chgBit  (c+796,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP));
	vcdp->chgBit  (c+797,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP));
	vcdp->chgBus  (c+798,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP),6);
	vcdp->chgBit  (c+799,((1U & (~ (IData)((0U 
						!= (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP)))))));
	vcdp->chgBus  (c+800,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SP),2);
	vcdp->chgBit  (c+801,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q));
	vcdp->chgBus  (c+802,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_CS),3);
	vcdp->chgBus  (c+803,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_type_q),2);
	vcdp->chgBus  (c+804,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q),2);
	vcdp->chgBit  (c+805,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q));
	vcdp->chgBit  (c+806,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_we_q));
	vcdp->chgBus  (c+807,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS),2);
	vcdp->chgBus  (c+808,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q),32);
	vcdp->chgBus  (c+809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_q),32);
	vcdp->chgBus  (c+810,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q),6);
	vcdp->chgBus  (c+811,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_q),6);
	vcdp->chgBit  (c+812,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__id_valid_q));
	vcdp->chgBus  (c+813,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc_q),12);
	vcdp->chgArray(c+814,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_q),384);
	vcdp->chgBus  (c+826,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_q),2);
	vcdp->chgBus  (c+827,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_q),12);
	vcdp->chgBus  (c+828,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk3__DOT__i),32);
	vcdp->chgBus  (c+829,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk2__DOT__i),32);
	vcdp->chgBus  (c+830,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__rdata_sel_q),3);
	vcdp->chgBus  (c+831,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__state_q),1);
	vcdp->chgBus  (c+832,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__addr_q),15);
	vcdp->chgBit  (c+833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_sel_q));
	vcdp->chgBus  (c+834,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__stall_cs),2);
	vcdp->chgBus  (c+835,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_cause_q),6);
	vcdp->chgBit  (c+836,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__dbg_ssth_q));
	vcdp->chgBus  (c+837,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__pc_tracking_fsm_cs),2);
    }
}

void Vtop::traceChgThis__12(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+838,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
			        ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				    ? ((0xffffff00U 
					& (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					   << 8U)) 
				       | (0xffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
						   >> 0x18U)))
				    : ((0xffff0000U 
					& (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					   << 0x10U)) 
				       | (0xffffU & 
					  (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
					   >> 0x10U))))
			        : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
				    ? ((0xff000000U 
					& (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
					   << 0x18U)) 
				       | (0xffffffU 
					  & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
					     >> 8U)))
				    : vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o))),32);
	vcdp->chgBus  (c+839,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
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
	vcdp->chgBus  (c+840,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
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
    }
}

void Vtop::traceChgThis__13(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+841,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_q) 
			       | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex))));
	vcdp->chgBus  (c+842,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[
			      (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 0x14U))]),32);
    }
}

void Vtop::traceChgThis__14(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+843,(vlSymsp->TOP__top__ram_i.__PVT__instr_rvalid_o));
	vcdp->chgArray(c+844,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o),128);
	vcdp->chgBit  (c+848,(vlSymsp->TOP__top__ram_i.__PVT__data_rvalid_o));
	vcdp->chgBus  (c+849,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o),32);
	vcdp->chgBit  (c+850,((1U & vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_cnt)));
	vcdp->chgBus  (c+851,(vlSymsp->TOP__top.__Vcellout__riscv_core_i__con_cnt),32);
	vcdp->chgBus  (c+852,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_con),32);
	vcdp->chgBus  (c+853,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_req_ex_i_d),32);
	vcdp->chgArray(c+854,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_c_o),128);
    }
}

void Vtop::traceChgThis__15(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+858,((1U & (IData)(vlSymsp->TOP__top.__Vcellout__u0__led))));
	vcdp->chgBit  (c+859,((1U & (IData)(vlSymsp->TOP__top.__Vcellout__u0__cs))));
	vcdp->chgBus  (c+860,(vlSymsp->TOP__top.__Vcellout__u0__led),7);
	vcdp->chgBus  (c+861,(vlSymsp->TOP__top.__Vcellout__u0__cs),8);
	vcdp->chgBus  (c+862,(vlSymsp->TOP__top.__PVT__u0__DOT__cnt),3);
    }
}

void Vtop::traceChgThis__16(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+863,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex));
	vcdp->chgBus  (c+864,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__hwlp_dec_cnt_id),2);
	vcdp->chgBit  (c+865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_valid_id));
	vcdp->chgBus  (c+866,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id),32);
	vcdp->chgBit  (c+867,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_compressed_id));
	vcdp->chgBit  (c+868,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__illegal_c_insn_id));
	vcdp->chgBus  (c+869,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_q),32);
	vcdp->chgBus  (c+870,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_id),32);
	vcdp->chgBit  (c+871,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__useincr_addr_ex));
	vcdp->chgBus  (c+872,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex),32);
	vcdp->chgBit  (c+873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__branch_in_ex));
	vcdp->chgBus  (c+874,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_ex),32);
	vcdp->chgBit  (c+875,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_en_ex));
	vcdp->chgBus  (c+876,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex),7);
	vcdp->chgBus  (c+877,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex),32);
	vcdp->chgBus  (c+878,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex),32);
	vcdp->chgBus  (c+879,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex),5);
	vcdp->chgBus  (c+880,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex),5);
	vcdp->chgBus  (c+881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__imm_vec_ext_ex),2);
	vcdp->chgBus  (c+882,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_vec_mode_ex),2);
	vcdp->chgBus  (c+883,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex),3);
	vcdp->chgBus  (c+884,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex),32);
	vcdp->chgBus  (c+885,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex),32);
	vcdp->chgBus  (c+886,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex),32);
	vcdp->chgBit  (c+887,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_en_ex));
	vcdp->chgBit  (c+888,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_sel_subword_ex));
	vcdp->chgBus  (c+889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_signed_mode_ex),2);
	vcdp->chgBus  (c+890,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex),5);
	vcdp->chgBus  (c+891,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_a_ex),32);
	vcdp->chgBus  (c+892,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_b_ex),32);
	vcdp->chgBus  (c+893,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex),32);
	vcdp->chgBus  (c+894,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_signed_ex),2);
	vcdp->chgBus  (c+895,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__fpu_op_ex),4);
	vcdp->chgBit  (c+896,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex));
	vcdp->chgBus  (c+897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_type_ex),2);
	vcdp->chgBus  (c+898,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_flags_ex),15);
	vcdp->chgBus  (c+899,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_op_ex),6);
	vcdp->chgBus  (c+900,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex),2);
	vcdp->chgBus  (c+901,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_waddr_ex),6);
	vcdp->chgBus  (c+902,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex),6);
	vcdp->chgBit  (c+903,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_ex));
	vcdp->chgBus  (c+904,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex),6);
	vcdp->chgBit  (c+905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_ex));
	vcdp->chgBit  (c+906,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex));
	vcdp->chgBus  (c+907,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_op_ex),2);
	vcdp->chgBus  (c+908,((0xfffU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex)
					  ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex
					  : 0U))),12);
	vcdp->chgBus  (c+909,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex),2);
	vcdp->chgBit  (c+910,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_sign_ext_ex));
	vcdp->chgBus  (c+911,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_reg_offset_ex),2);
	vcdp->chgBit  (c+912,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_ex));
	vcdp->chgBit  (c+913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_load_event_ex));
	vcdp->chgBit  (c+914,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex));
	vcdp->chgBit  (c+915,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__is_hwlp_id_q));
	vcdp->chgBus  (c+916,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt_if),2);
	vcdp->chgBus  (c+917,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__CS),4);
	vcdp->chgBit  (c+918,((3U == (3U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_q 
					    >> 2U)))));
	vcdp->chgBus  (c+919,(((IData)(4U) + (0xfffffffcU 
					      & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__addr_q))),32);
	vcdp->chgBit  (c+920,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__is_hwlp_q));
	vcdp->chgBus  (c+921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__genblk1__DOT__prefetch_128__DOT__prefetch_buffer_i__DOT__rdata_last_q),32);
	vcdp->chgBus  (c+922,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o[0]),32);
	vcdp->chgBus  (c+923,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o[1]),32);
	vcdp->chgBus  (c+924,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o[2]),32);
	vcdp->chgBus  (c+925,((0xfffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					 >> 0x14U))),32);
	vcdp->chgBus  (c+926,(((0xfffff000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
								       >> 0x1fU)))) 
					       << 0xcU)) 
			       | ((0xfe0U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					     >> 0x14U)) 
				  | (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					      >> 7U))))),32);
	vcdp->chgBus  (c+927,(((0xffffe000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
								       >> 0x1fU)))) 
					       << 0xdU)) 
			       | ((0x1000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					      >> 0x13U)) 
				  | ((0x800U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						<< 4U)) 
				     | ((0x7e0U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x14U)) 
					| (0x1eU & 
					   (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					    >> 7U))))))),32);
	vcdp->chgBus  (c+928,((0xfffff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id)),32);
	vcdp->chgBus  (c+929,(((0xfff00000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
								       >> 0x1fU)))) 
					       << 0x14U)) 
			       | ((0xff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id) 
				  | ((0x800U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						>> 9U)) 
				     | (0x7feU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						  >> 0x14U)))))),32);
	vcdp->chgBus  (c+930,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 0xfU))),32);
	vcdp->chgBus  (c+931,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 0x14U))),32);
	vcdp->chgBus  (c+932,(((0xffffffe0U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
								       >> 0x18U)))) 
					       << 5U)) 
			       | (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					   >> 0x14U)))),32);
	vcdp->chgBus  (c+933,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 0x19U))),32);
	vcdp->chgBus  (c+934,(((0xffffffc0U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
								       >> 0x18U)))) 
					       << 6U)) 
			       | ((0x3eU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					    >> 0x13U)) 
				  | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					   >> 0x19U))))),32);
	vcdp->chgBus  (c+935,(((0x3000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					      >> 3U)) 
			       | ((0x30000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 7U)) 
				  | ((0x300U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						>> 0xdU)) 
				     | ((2U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					       >> 0x13U)) 
					| (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						 >> 0x19U))))))),32);
	vcdp->chgBus  (c+936,(((0x10000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					    >> 4U)) 
			       | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 0x19U)))),32);
	vcdp->chgBus  (c+937,((((IData)(1U) << (0x1fU 
						& (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
						   >> 0x14U))) 
			       - (IData)(1U))),32);
	vcdp->chgBus  (c+938,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 0xfU))),6);
	vcdp->chgBus  (c+939,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 0x14U))),6);
	vcdp->chgBus  (c+940,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
					>> 7U))),6);
	vcdp->chgBus  (c+941,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
				     >> 7U))),1);
	vcdp->chgBus  (c+942,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex)),32);
	vcdp->chgBus  (c+943,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)),32);
	vcdp->chgBus  (c+944,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
				<< 0x18U) | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
					      << 0x10U) 
					     | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
						 << 8U) 
						| (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex))))),32);
	vcdp->chgBit  (c+945,((((((0x10U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
				  | (0x11U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				 | (0x16U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
				| (0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
			       | (0x47U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
	vcdp->chgBit  (c+946,(((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
			       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
				  >> 0x1fU))));
	vcdp->chgBit  (c+947,((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
	vcdp->chgBus  (c+948,(((IData)(0xfffffffeU) 
			       << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))),32);
	vcdp->chgBit  (c+949,((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
	vcdp->chgBit  (c+950,((1U & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
				      >> 0x1fU) & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
	vcdp->chgBus  (c+951,((3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))),2);
	vcdp->chgBus  (c+952,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))
			        ? (0x7fffffffU & (((IData)(1U) 
						   << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex)) 
						  >> 1U))
			        : 0U)),32);
	vcdp->chgBus  (c+953,(((IData)(1U) << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),32);
	vcdp->chgBus  (c+954,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
			       ^ VL_NEGATE_I((IData)(
						     (1U 
						      == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
	vcdp->chgBus  (c+955,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
			       & VL_NEGATE_I((IData)(
						     (1U 
						      == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
	vcdp->chgBus  (c+956,(((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex 
				+ (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
				   & VL_NEGATE_I((IData)(
							 (1U 
							  == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))) 
			       + VL_MULS_III(32,32,32, 
					     (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
					      ^ VL_NEGATE_I((IData)(
								    (1U 
								     == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))))), vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex))),32);
	vcdp->chgBit  (c+957,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))));
    }
}

void Vtop::traceChgThis__17(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+958,(vlTOPp->clk_i));
	vcdp->chgBit  (c+959,(vlTOPp->rstn_i));
	vcdp->chgBit  (c+960,(vlTOPp->irq_i));
	vcdp->chgBus  (c+961,(vlTOPp->irq_id_i),5);
	vcdp->chgBit  (c+962,(vlTOPp->irq_ack_o));
	vcdp->chgBus  (c+963,(vlTOPp->irq_id_o),5);
	vcdp->chgBit  (c+964,(vlTOPp->irq_sec_i));
	vcdp->chgBit  (c+965,(vlTOPp->sec_lvl_o));
	vcdp->chgBit  (c+966,(vlTOPp->debug_req_i));
	vcdp->chgBit  (c+967,(vlTOPp->debug_gnt_o));
	vcdp->chgBit  (c+968,(vlTOPp->debug_rvalid_o));
	vcdp->chgBus  (c+969,(vlTOPp->debug_addr_i),15);
	vcdp->chgBit  (c+970,(vlTOPp->debug_we_i));
	vcdp->chgBus  (c+971,(vlTOPp->debug_wdata_i),32);
	vcdp->chgBus  (c+972,(vlTOPp->debug_rdata_o),32);
	vcdp->chgBit  (c+973,(vlTOPp->debug_halted_o));
	vcdp->chgBit  (c+974,(vlTOPp->fetch_enable_i));
	vcdp->chgBit  (c+975,(vlTOPp->core_busy_o));
	vcdp->chgBus  (c+976,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_wr) 
				<< 5U) | (0x1fU & ((IData)(vlTOPp->debug_addr_i) 
						   >> 2U)))),6);
	vcdp->chgBit  (c+977,((((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__dbg_req) 
				  | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__csr_req_q)) 
				 | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__jump_req_q)) 
				| (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq)) 
			       | (IData)(vlTOPp->debug_req_i))));
	vcdp->chgBus  (c+978,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_wreq)
			        ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_unit_i__DOT__regfile_fp_wr) 
				    << 5U) | (0x1fU 
					      & ((IData)(vlTOPp->debug_addr_i) 
						 >> 2U)))
			        : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex))),6);
    }
}
