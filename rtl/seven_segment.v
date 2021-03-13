`timescale 1ns / 1ps
////////////////////////////////////////////////////////////////////////////////////
//// Company: 
//// Engineer: 
//// 
//// Create Date: 2020/08/29 13:17:24
//// Design Name: 
//// Module Name: seven_segment
//// Project Name: 
//// Target Devices: 
//// Tool Versions: 
//// Description: 
//// 
//// Dependencies: 
//// 
//// Revision:
//// Revision 0.01 - File Created
//// Additional Comments:
//// 
////////////////////////////////////////////////////////////////////////////////////


(*DONT_TOUCH = "TURE"*) 
module seven_segment(
    clk,reset,y1,y2,y3,y4,led,cs
    );
    input reset,clk;
    input [67:0] y1,y2,y3,y4;
    output reg [6:0] led;
    output reg [7:0] cs;
    reg [2:0] cnt;
    wire clk_;
    //wire [7:0] y1_,y2_,y3_,y4_;
    wire [6:0] y1_l,y1_h,y2_l,y2_h,y3_l,y3_h,y4_l,y4_h;
//    assign y1_ = y1[7:0];
//    assign y2_ = y2[7:0];
//    assign y3_ = y3[7:0];
//    assign y4_ = y4[7:0];
    
    
    divider divider0(
        .reset (reset),
        .clk   (clk),
        .clk_out  (clk_)
    );
    seven_segment_change u0(
        .y_i    (y1[3:0]),
        .y_o    (y1_l)
    );
    seven_segment_change u1(
        .y_i    (y1[7:4]),
        .y_o    (y1_h)
    );
    seven_segment_change u2(
        .y_i    (y2[3:0]),
        .y_o    (y2_l)
    );
    seven_segment_change u3(
        .y_i    (y2[7:4]),
        .y_o    (y2_h)
    );
    seven_segment_change u4(
        .y_i    (y3[3:0]),
        .y_o    (y3_l)
    );
    seven_segment_change u5(
        .y_i    (y3[7:4]),
        .y_o    (y3_h)
    );
    seven_segment_change u6(
        .y_i    (y4[3:0]),
        .y_o    (y4_l)
    );
    seven_segment_change u7(
        .y_i    (y4[7:4]),
        .y_o    (y4_h)
    );
    
    always @(posedge clk_, negedge reset)
    begin
        if(!reset)
            begin
                cnt <= 3'b000;
                led <= 7'b0000000;
                cs <= 8'b11111111;
            end
        else
            begin
                case(cnt)
                    0: begin
                         led <= y1_l;
                         cs <= 8'b11111110;
                         cnt <= 1;
                         end
                    1: begin
                         led <= y1_h;
                         cs <= 8'b11111101;
                         cnt <=2;

                         end
                    2: begin
                         led <= y2_l;
                         cs <= 8'b11111011;
                         cnt <= 3;
                         end
                    3: begin
                         led <= y2_h;  
                         cs <= 8'b11110111;
                         cnt <= 4;
                         end
                    4: begin
                         led <= y3_l;
                         cs <= 8'b11101111;                         
                         cnt <= 5;

                         end
                    5: begin
                         led <= y3_h;
                         cs <= 8'b11011111;                         
                         cnt <= 6;
                         end
                    6: begin
                         led <= y4_l;
                         cs <= 8'b10111111;                         
                         cnt <= 7;
                         end
                    7: begin
                         led <= y4_h;  
                         cs <= 8'b01111111;                         
                         cnt <= 0;
                         end
                endcase        
            end
       end
endmodule

