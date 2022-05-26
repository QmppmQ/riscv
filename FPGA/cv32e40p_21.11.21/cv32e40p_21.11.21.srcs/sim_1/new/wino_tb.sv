`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/09/09 10:27:11
// Design Name: 
// Module Name: wino_tb
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


module wino_tb_sv(

    );
reg clk,rst,fetch_enable;
wire [7:0] cs;
wire [6:0] led;
wire sleep_o;
wire y_ok;
wire ins_ok;
wire data_ok;
    top u0(
    .clk_i      (clk),
    .rst_ni     (rst),
    .fetch_enable_i(fetch_enable),
    .y_ok_o     (y_ok),
    .ins_ok_o     (ins_ok),
    .data_ok_o    (data_ok)
//    .led        (led),
//    .cs         (cs)
    );
initial begin
//clk,rst,irq,irq_sec,debug_req,debug_we,fetch_enable
    clk = 0;
    rst = 1;
    fetch_enable = 0;
    #1000
    rst = 0;
    #1000
    rst = 1;
    #20000
    fetch_enable = 1;

end

always begin
    #5
    clk = ~clk;
end

endmodule
