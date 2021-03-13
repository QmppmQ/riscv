import riscv_defines::*;
//(*DONT_TOUCH = "TURE"*) 
module riscv_mac_ops
(
	input logic						 clk,
	input logic						 rst_n,
	input logic						 enable_i,
	input logic [MAC_OP_WIDTH-1:0]   operator_i,
	input logic [31:0]				 operand_i1,
	input logic [31:0]				 operand_i2,
	input logic						 ex_ready_i,

	input logic [31:0]				 con_data_cnt,
	input logic [31:0]				 mem_rdata,
	output logic [31:0]				 mem_wdata,
	output logic 					 wb23_active,
	output logic					 wb23_flag,
	output logic [31:0]				 result_o,
	output logic					 con_active_o,
	output logic					 ready_o,
	output logic					 con_data_flag,
	output logic   [67:0]            y0_o,y1_o,y2_o,y3_o,
	output logic   [31:0]        con_data[15:0]
);

enum logic [2:0] {
	IDLE,
	STEP0,
	STEP1,
	FINISH
} mac_cs,mac_ns,con_2x2_cs,con_2x2_ns;

enum logic [2:0] {
	IDLE_CON,
	GET_DATA,
	CAL_1,
	CAL_2,
	CAL_3,
	FINISH_CON
} con_cs,con_ns; 

enum logic {
	IDLE_WB,
	WDATA
  } wb23_cs,wb23_ns;


logic wb23_ready;
logic wb23_active;
logic con_ready;
logic mac_ready;
logic mac_active;
logic con_2x2_ready;
logic con_2x2_active;
assign ready_o = mac_ready & con_2x2_ready & con_ready;
logic [31:0] mac_operand;
logic [15:0] mac_mult1;
logic [15:0] mac_mult2;
logic [31:0] mac_add;
logic [31:0] con_operand_1;
logic [31:0] con_operand_2;
logic [15:0] con_mult1;
logic [15:0] con_mult2;
logic [15:0] con_mult3;
logic [15:0] con_mult4;
logic [31:0] con_add;

//con_logic

logic con_active;
logic con_active_d;
logic enable_i_d;
logic [31:0] max = operand_i2;
parameter nbit = 32;
//logic signed [15:0][nbit-1:0] con_data;
logic signed [nbit-1:0] w0,w1,w2,w3,w4,w5,w6,w7,w8;
logic signed [2*nbit+3:0] y0, y1, y2,y3;

logic signed [2*nbit+2:0] M0_0_0, M0_0_3, M3_0_0, M3_0_3;
logic signed [2*nbit+3:0] M0_0_1, M0_0_2, M3_0_1, M3_0_2;
logic signed [2*nbit+4:0] M1_0_0, M1_0_3, M2_0_0, M2_0_3;
logic signed [2*nbit+6:0] M0_0, M3_0;
logic signed [2*nbit+5:0] M0_1, M3_1, M1_0_1, M1_0_2, M2_0_1, M2_0_2;
logic signed [2*nbit+7:0] M1_1, M2_1;
logic signed [2*nbit+8:0] M1_0, M2_0;
logic signed [nbit+1:0] mid0_0, mid0_1, mid3_0, mid3_1;
logic signed [nbit+3:0] mid1_0, mid1_1, mid2_0, mid2_1; 

assign w0=1;
assign w1=2;
assign w2=3;
assign w3=4;
assign w4=5;
assign w5=6;
assign w6=7;
assign w7=8;
assign w8=9;
assign con_active_o = con_active;
	always_ff @( posedge clk,negedge rst_n)
	begin
		if (~rst_n)
			mac_cs <= IDLE;
		else
			mac_cs <= mac_ns;
	end

	always_comb begin
		mac_ready = 1'b0;
		mac_ns = mac_cs;
		mac_active = 1'b1;
		
		case (mac_cs)
			IDLE: begin
				mac_active = 1'b0;
				mac_ready  = 1'b1;
				if (operator_i == MAC_OP && enable_i) begin
					mac_ready = 1'b0;
					mac_ns = STEP0;
					mac_operand <= operand_i1;
				end
					
			end

			STEP0: begin
				mac_ns = STEP1;
				mac_mult1 = mac_operand[31:24] * mac_operand[23:16];
				mac_mult2 = mac_operand[15:8] * mac_operand[7:0];
				
			end

			STEP1: begin
				mac_ns = FINISH;
				mac_add = mac_mult1 + mac_mult2;
			end


			FINISH: begin
				mac_ready = 1'b1;
				if (ex_ready_i)
					mac_ns = IDLE;
			end
		endcase
	end

	always_ff @( posedge clk,negedge rst_n)
	begin
		if (~rst_n)
			con_2x2_cs <= IDLE;
		else
			con_2x2_cs <= con_2x2_ns;
	end

	always_comb begin
		con_2x2_ready = 1'b0;
		con_2x2_ns = con_2x2_cs;
		con_2x2_active = 1'b1;
		
		case (con_2x2_cs)
			IDLE: begin
				con_2x2_active = 1'b0;
				con_2x2_ready  = 1'b1;
				if (operator_i == CON_2X2_OP && enable_i) begin
					con_2x2_ready = 1'b0;
					con_2x2_ns = STEP0;
					con_operand_1 <= operand_i1;
					con_operand_2 <= operand_i2;
				end
					
			end

			STEP0: begin
				con_2x2_ns = STEP1;
				con_mult1 = con_operand_1[31:24] * con_operand_2[31:24];
				con_mult2 = con_operand_1[23:16] * con_operand_2[23:16];
				con_mult3 = con_operand_1[15:8] * con_operand_2[15:8];
				con_mult4 = con_operand_1[7:0] * con_operand_2[7:0];

				
			end

			STEP1: begin
				con_2x2_ns = FINISH;
				con_add = con_mult1 + con_mult2 + con_mult3 + con_mult4;
			end


			FINISH: begin
				con_2x2_ready = 1'b1;
				if (ex_ready_i)
					con_2x2_ns = IDLE;
			end
		endcase
	end

//con_always
	
	always_ff @( posedge clk, negedge rst_n)
	begin
		if(~rst_n)begin
		end
		else
		con_active_d <= con_active;
		enable_i_d <= enable_i;
	end	
    
	always_comb
	begin
		//ori if( con_active^con_active_d == 1)
	   if( enable_i^enable_i_d == 1)begin
			if( enable_i == 1)
			     con_data_flag = 1;
			end
		else
			con_data_flag = 0;
	end
	
	always_ff @( posedge clk,negedge rst_n)
	begin
		if (~rst_n)begin
			con_cs <= IDLE_CON;
		end
		else
			con_cs <= con_ns;
	end

	always_comb begin
		con_ns = con_cs;
		case (con_cs)
			IDLE_CON: begin
			    con_ready = 1'b1;
			    con_active = 1'b0;
				if (operator_i == CON_OP && enable_i) begin
					max = operand_i2;
					con_ns = GET_DATA;
				end
					
			end

			GET_DATA: begin
				con_ready = 1'b0;
				con_active = 1'b1;
				if(con_data_cnt < max+1)begin
				    if(clk==0)begin //con_data_cnt和mem_rdata不能同时到达造成了赋值两次变化
					   con_data[con_data_cnt-1] = mem_rdata;
					   con_ns = GET_DATA;
				    end
				end
				else
					con_ns = CAL_1;
			end

			CAL_1: begin
				con_ready = 1'b0;
				con_active = 1'b1;
				mid0_0 = w1+w2+w0;
    				mid0_1 = w0-w1+w2;  
    				M0_0_0=(con_data[0]-con_data[8]-con_data[2]+con_data[10])*w0<<<1;
    				M0_0_1=(con_data[1]-con_data[9]+con_data[2]-con_data[10])*mid0_0;
    				M0_0_2=(-con_data[1]+con_data[9]+con_data[2]-con_data[10])*mid0_1;
    				M0_0_3=(con_data[1]-con_data[9]-con_data[3]+con_data[11])*w2<<<1;

				mid1_0 = w0 + w3 + w6 + w1 + w4 + w7 + w2 + w5 + w8;
			     	mid1_1 = w0 + w3 + w6 - w1 - w4 - w7 + w2 + w5 + w8;  
			     	M1_0_0=(con_data[4]+con_data[8]-con_data[6]-con_data[10])*(w0+w3+w6)<<<1;
			     	M1_0_1=(con_data[5]+con_data[9]+con_data[6]+con_data[10])*mid1_0;
			     	M1_0_2=(-con_data[5]-con_data[9]+con_data[6]+con_data[10])*mid1_1;
			     	M1_0_3=(con_data[5]+con_data[9]-con_data[7]-con_data[11])*(w2 + w5 + w8)<<<1;

				mid2_0 = w0 - w3 + w6 + w1 - w4 + w7 + w2 - w5 + w8;
				mid2_1 = w0 - w3 + w6 - w1 + w4 - w7 + w2 - w5 + w8;  
				M2_0_0=(-con_data[4]+con_data[8]+con_data[6]-con_data[10])*(w0-w3+w6)<<<1;
				M2_0_1=(-con_data[5]+con_data[9]-con_data[6]+con_data[10])*mid2_0;
				M2_0_2=(con_data[5]-con_data[9]-con_data[6]+con_data[10])*mid2_1;
				M2_0_3=(-con_data[5]+con_data[9]+con_data[7]-con_data[11])*(w2 - w5 + w8)<<<1;

				mid3_0 = w6+w7+w8;
				mid3_1 = w6-w7+w8;  
				M3_0_0=(con_data[4]-con_data[12]-con_data[6]+con_data[14])*w6<<<1;
				M3_0_1=(con_data[5]-con_data[13]+con_data[6]-con_data[14])*mid3_0;
				M3_0_2=(-con_data[5]+con_data[13]+con_data[6]-con_data[14])*mid3_1;
				M3_0_3=(con_data[5]-con_data[13]-con_data[7]+con_data[15])*w8<<<1;
				//test_tag_oneclk
				M0_0 = (M0_0_0 + M0_0_1 + M0_0_2)<<<1;
				M0_1 = (M0_0_1 - M0_0_2 - M0_0_3)<<<1;
				M1_0 = (M1_0_0 + M1_0_1 + M1_0_2);
				M1_1 = (M1_0_1 - M1_0_2 - M1_0_3);
				M2_0 = (M2_0_0 + M2_0_1 + M2_0_2);
				M2_1 = (M2_0_1 - M2_0_2 - M2_0_3); 
				M3_0 = (M3_0_0 + M3_0_1 + M3_0_2)<<<1;
				M3_1 = (M3_0_1 - M3_0_2 - M3_0_3)<<<1;       
				y0=(M0_0 + M1_0 + M2_0)>>>2;
				y1=(M0_1 + M1_1 + M2_1)>>>2;
				y2=(M1_0 - M2_0 - M3_0)>>>2;
				y3=(M1_1 - M2_1 - M3_1)>>>2;       
				y0_o = y0;
				y1_o = y1;
				y2_o = y2;
				y3_o = y3;
				
				//con_ns = CAL_2;
				con_ns=FINISH_CON;
			end
//			CAL_2:begin
//				con_ready = 1'b0;
//				con_active = 1'b1;
//				M0_0 = (M0_0_0 + M0_0_1 + M0_0_2)<<<1;
//				M0_1 = (M0_0_1 - M0_0_2 - M0_0_3)<<<1;
//				M1_0 = (M1_0_0 + M1_0_1 + M1_0_2);
//				M1_1 = (M1_0_1 - M1_0_2 - M1_0_3);
//				M2_0 = (M2_0_0 + M2_0_1 + M2_0_2);
//				M2_1 = (M2_0_1 - M2_0_2 - M2_0_3); 
//				M3_0 = (M3_0_0 + M3_0_1 + M3_0_2)<<<1;
//				M3_1 = (M3_0_1 - M3_0_2 - M3_0_3)<<<1;       
//				con_ns = CAL_3;
//			end
//			CAL_3:begin
//				con_ready = 1'b0;
//				con_active = 1'b1;
//				y0=(M0_0 + M1_0 + M2_0)>>>2;
//				y1=(M0_1 + M1_1 + M2_1)>>>2;
//				y2=(M1_0 - M2_0 - M3_0)>>>2;
//				y3=(M1_1 - M2_1 - M3_1)>>>2;       
//				y0_o = y0;
//				y1_o = y1;
//				y2_o = y2;
//				y3_o = y3;
//				con_ns = FINISH_CON;    
//			end
			FINISH_CON: begin
				con_ready = 1'b1;
				con_active = 1'b0;
				if (ex_ready_i)
					con_ns = IDLE_CON;
			end
		endcase
	end


//conv23 write back

	always_ff @( posedge clk, negedge rst_n)
	begin
		if (~rst_n) begin
			wb23_cs <= IDLE_WB;
		end
		else
			wb23_cs	<= wb23_ns;
	end

	always_comb
	begin
		wb23_ready = 1'b0;
		wb23_ns = wb23_cs;
		wb23_active = 1'b1;
	
		case(wb23_cs)
			IDLE_WB:begin
				wb23_active = 1'b0;
				wb23_ready = 1'b1;
				if(operator_i == WB23_OP && enable_i) begin
					wb23_active = 1'b1;
					wb23_ready = 1'b0;
					wb23_ns = WDATA;
				end
			endmem_wdata

			WDATA:begin
				wb23_active = 1'b1;
				wb23_ready = 1'b0;
				if (con_data_cnt < 4) begin
					case(con_data_cnt)
						0:	mem_wdata = y0;
						1:	mem_wdata = y1;
						2:	mem_wdata = y2;
						3:	mem_wdata = y3;
					endcase
					wb23_ns = WDATA;
				end

				else
					wb23_ns = IDLE_WB;
			end
	
	end


	always_comb
	begin
		if (enable_i) begin
			case (operator_i)
				MAC_OP:begin
					//$display("%t: Exec MAC instruction", $time);
					if(mac_cs == FINISH)begin
						result_o = mac_add;
				
					end
				end
				CON_2X2_OP:begin
					if(con_2x2_cs == FINISH)begin
						result_o = con_add;
					end
				end
				CON_OP:begin
					if(con_cs == FINISH_CON)begin
					
					end
				end
			endcase
		end

	end
endmodule
