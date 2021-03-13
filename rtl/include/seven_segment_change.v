`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/09/03 20:17:04
// Design Name: 
// Module Name: seven_segment_change
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


module seven_segment_change(
    y_i,y_o
    );
    input [3:0] y_i;
    output reg [6:0] y_o;
    
    always @*
    begin
        case(y_i)
            0:begin
                y_o = 7'b0000001;
              end
            1:begin
                y_o = 7'b1001111;
              end
            2:begin
                y_o = 7'b0010010;
              end
            3:begin
                y_o = 7'b0000110;
              end
            4:begin
                y_o = 7'b1001100;
              end
            5:begin
                y_o = 7'b0100100;
              end
            6:begin
                y_o = 7'b0100000;
              end
            7:begin
                y_o = 7'b0001111;
              end
            8:begin
                y_o = 7'b0000000;
              end
            9:begin
                y_o = 7'b0000100;
              end
            10:begin
                y_o = 7'b0001000;
               end
            11:begin
                y_o = 7'b1100000;
               end
            12:begin
                y_o = 7'b0110001;
               end
            13:begin
                y_o = 7'b1000010;
               end
            14:begin
                y_o = 7'b0110000;
               end
            15:begin
                y_o = 7'b0111000;
               end
            default:;
            endcase
    end
    
endmodule
