`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/01 15:57:33
// Design Name: 
// Module Name: top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

import cv32e40p_apu_core_pkg::*;
module top
#(parameter // Parameters used by TB
                INSTR_RDATA_WIDTH = 32,
                RAM_ADDR_WIDTH    = 19,
                BOOT_ADDR         = 'h80,
                DM_HALTADDRESS    = 32'h1A11_0800,
                HART_ID           = 32'h0000_0000,
                // Parameters used by DUT
                PULP_XPULP        = 0,
                PULP_CLUSTER      = 0,
                FPU               = 0,
                PULP_ZFINX        = 0,
                NUM_MHPMCOUNTERS  = 1
)
(
    input logic clk_i,
    input logic rst_ni,
    input  logic        fetch_enable_i,
    //output logic [7:0]      cs,
    //output logic [6:0]      led
    //output logic [6:0]      led_
    output logic y_ok_o,
    //output logic registers_ok_o,
    output logic ins_ok_o,
    output logic data_ok_o
);
  // signals connecting core to memory
  logic                               instr_req;
  logic                               instr_gnt;
  logic                               instr_rvalid;
  logic [                 31:0]       instr_addr;
  logic [INSTR_RDATA_WIDTH-1:0]       instr_rdata;

  logic                               data_req;
  logic                               data_gnt;
  logic                               data_rvalid;
  logic [                 31:0]       data_addr;
  logic                               data_we;
  logic [                  3:0]       data_be;
  logic [                 31:0]       data_rdata;
  logic [                 31:0]       data_wdata;
  logic [                  5:0]       data_atop = 6'b0;

  // signals to debug unit
  logic                               debug_req_i;

  // irq signals
  logic                               irq_ack;
  logic [                  4:0]       irq_id_out;
  logic                               irq_software;
  logic                               irq_timer;
  logic                               irq_external;
  logic [                 15:0]       irq_fast;

  //logic                               core_sleep_o;

  // APU Core to FP Wrapper
  logic                               apu_req;
  logic [    APU_NARGS_CPU-1:0][31:0] apu_operands;
  logic [      APU_WOP_CPU-1:0]       apu_op;
  logic [ APU_NDSFLAGS_CPU-1:0]       apu_flags;


  // APU FP Wrapper to Core
  logic                               apu_gnt;
  logic                               apu_rvalid;
  logic [                 31:0]       apu_rdata;
  logic [ APU_NUSFLAGS_CPU-1:0]       apu_rflags;
  
  logic [31:0] y0,y1,y2,y3;
  logic [31:0] pc_id;
  
  assign debug_req_i = 1'b0;

//  seven_segment u0(
//            .clk(clk_o),
//            .reset(rst_ni),
//            .y1(y0),
//            .y2(y1),
//            .y3(y2),
//            .y4(y3),
//            .led(led),
//            .led_(led_),
//            .cs(cs)
//   );

  clk_wiz_0 cpuclk_0(
          .clk_in1(clk_i),    //125MHz
          .clk_out1(clk_o),    //25MHz
          .reset(~rst_ni)
  );

  verif verif(
        .y_i            ({y3,y2,y1,y0}),
        .ins_addr_i     (instr_addr[RAM_ADDR_WIDTH-1:2]),
        .ins_data_i     (instr_rdata),
        .data_addr_i    (data_addr[RAM_ADDR_WIDTH-1:2]),
        .data_data_i    (data_rdata),
        .sleep_i        (core_sleep_o),
        //.registers_i    ({x31,x30,x29,x28,x27,x26,x25,x24,x23,x22,x21,x20,x19,x18,x17,x16,x15,x14,x13,x12,x11,x10,x9,x8,x7,x6,x5,x4,x3,x2,x1,x0}),
        .y_ok           (y_ok_o),
        //.registers_ok   (registers_ok_o),
        .ins_ok         (ins_ok_o),
        .data_ok        (data_ok_o)
  
  );


  cv32e40p_core #(
      .PULP_XPULP      (PULP_XPULP),
      .PULP_CLUSTER    (PULP_CLUSTER),
      .FPU             (FPU),
      .PULP_ZFINX      (PULP_ZFINX),
      .NUM_MHPMCOUNTERS(NUM_MHPMCOUNTERS)
  ) core_i (
      .clk_i (clk_o),
      .rst_ni(rst_ni),

      .pulp_clock_en_i(1'b1),
      .scan_cg_en_i   (1'b0),

      .boot_addr_i        (BOOT_ADDR),
      .mtvec_addr_i       (32'h0),
      .dm_halt_addr_i     (DM_HALTADDRESS),
      .hart_id_i          (32'h0),
      .dm_exception_addr_i(32'h0),

      .instr_addr_o  (instr_addr),
      .instr_req_o   (instr_req),
      .instr_rdata_i (instr_rdata),
      .instr_gnt_i   (instr_gnt),
      .instr_rvalid_i(instr_rvalid),

      .data_addr_o  (data_addr),
      .data_wdata_o (data_wdata),
      .data_we_o    (data_we),
      .data_req_o   (data_req),
      .data_be_o    (data_be),
      .data_rdata_i (data_rdata),
      .data_gnt_i   (data_gnt),
      .data_rvalid_i(data_rvalid),

      .apu_req_o     (apu_req),
      .apu_gnt_i     (apu_gnt),
      .apu_operands_o(apu_operands),
      .apu_op_o      (apu_op),
      .apu_flags_o   (apu_flags),
      .apu_rvalid_i  (apu_rvalid),
      .apu_result_i  (apu_rdata),
      .apu_flags_i   (apu_rflags),

      .irq_i    ({irq_fast, 4'b0, irq_external, 3'b0, irq_timer, 3'b0, irq_software, 3'b0}),
      .irq_ack_o(irq_ack),
      .irq_id_o (irq_id_out),

      .debug_req_i      (debug_req_i),
      .debug_havereset_o(),
      .debug_running_o  (),
      .debug_halted_o   (),

      .fetch_enable_i(fetch_enable_i),
      .core_sleep_o  (core_sleep_o),
      
      //test_debug
      .y0            (y0),
      .y1            (y1),
      .y2            (y2),
      .y3            (y3),
      .pc_id         (pc_id)
  );



    
//mm_ram
//        #(.RAM_ADDR_WIDTH (RAM_ADDR_WIDTH),
//          .INSTR_RDATA_WIDTH (INSTR_RDATA_WIDTH))
//    ram_i
//        (.clk_i          ( clk_o                                     ),
//         .rst_ni         ( rst_ni                                    ),
//         .dm_halt_addr_i ( DM_HALTADDRESS                            ),

//         .instr_req_i    ( instr_req                                 ),
//         .instr_addr_i   ( { {13{1'b0}},
//                             instr_addr[RAM_ADDR_WIDTH-1:0]
//                           }                                         ),
//         .instr_rdata_o  ( instr_rdata                               ),
//         .instr_rvalid_o ( instr_rvalid                              ),
//         .instr_gnt_o    ( instr_gnt                                 ),

//         .data_req_i     ( data_req                                  ),
//         .data_addr_i    ( { {13{1'b0}},
//                             data_addr[RAM_ADDR_WIDTH-1:0]
//                           }                                 ),
//         .data_we_i      ( data_we                                   ),
//         .data_be_i      ( data_be                                   ),
//         .data_wdata_i   ( data_wdata                                ),
//         .data_rdata_o   ( data_rdata                                ),
//         .data_rvalid_o  ( data_rvalid                               ),
//         .data_gnt_o     ( data_gnt                                  ),

//         .irq_id_i       ( irq_id_out                                ),
//         .irq_ack_i      ( irq_ack                                   ),
//         .irq_o          ( irq                                       ),

//         .debug_req_o    ( debug_req                                 ),

//         .pc_core_id_i   ( pc_id                     ));


mm_ram_test #(.ADDR_WIDTH (RAM_ADDR_WIDTH))
ram
(
         .clk            ( clk_o                                     ),
         .instr_req_i    ( instr_req                                 ),
         .instr_addr_i   ( { {13{1'b0}},
                             instr_addr[RAM_ADDR_WIDTH-1:0]
                           }
                                                                    ),
         .instr_rdata_o  ( instr_rdata                               ),
         .instr_rvalid_o ( instr_rvalid                              ),
         .instr_gnt_o    ( instr_gnt                                 ),

         .data_req_i     ( data_req                                  ),
         .data_addr_i    ( { {13{1'b0}},
                             data_addr[RAM_ADDR_WIDTH-1:0]
                           }                                         ),
         .data_we_i      ( data_we                                   ),
         .data_be_i      ( data_be                                   ),
         .data_wdata_i   ( data_wdata                                ),
         .data_rdata_o   ( data_rdata                                ),
         .data_rvalid_o  ( data_rvalid                               ),
         .data_gnt_o     ( data_gnt                                  )

);

    
    
endmodule
