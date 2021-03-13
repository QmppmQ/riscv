`timescale 1ns / 1ps

module divider(reset,clk,clk_out);
    input clk,reset;
    output reg clk_out;



reg [15:0] cnt;
 
 
always @(posedge clk or negedge reset)
begin
    if(!reset)
    begin
        cnt <= 4'b0;
        clk_out <= 1'b0;
    end
    else
    begin
        if(cnt == 1000)
        begin
            clk_out <= ~clk_out;
            cnt <= 16'b0;
        end
        else
        begin
            cnt <= cnt + 16'b1;
        end
    end
end

endmodule

