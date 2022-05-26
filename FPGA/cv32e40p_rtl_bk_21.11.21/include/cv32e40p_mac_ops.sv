import cv32e40p_pkg::*;
//(*DONT_TOUCH = "TURE"*) 
module cv32e40p_mac_ops
(
	input logic						 clk,
	input logic						 rst_n,
	input logic						 enable_i,
	input logic [MAC_OP_WIDTH-1:0]   		 operator_i,
	input logic [31:0]				 operand_i1,
	input logic [31:0]				 operand_i2,
	input logic				         ex_ready_i,

	input logic [31:0]				 con_data_cnt,
	input logic [31:0]				 mem_rdata,
	output logic [31:0]				 mem_wdata,
	output logic 					 wb23_active,
	output logic					 wb_finish,
	output logic					 w_wb_active,
	output logic [31:0]				 result_o,
	output logic					 con_active_o,
	output logic					 mp_wb_active_o,
	output logic 					 mp_ri_active_o,
	output logic					 ready_o,
	output logic					 mac_flag,
	output logic   [31:0]            		 y0_o,y1_o,y2_o,y3_o,
	output logic   [31:0]        			 con_data[15:0]
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
	WB23_WDATA
} wb23_cs,wb23_ns;

enum logic {
	IDLE_W_WB,
	W_WDATA
} w_wb_cs,w_wb_ns;

enum logic {
	IDLE_MP_WB,
	MP_WDATA
} mp_wb_cs,mp_wb_ns;

enum logic {
	IDLE_MP_RI,
	MP_RDATA
} mp_ri_cs,mp_ri_ns;

logic [3:0] w_rank;
logic wb_flag;
logic wb23_flag;
logic w_wb_ready;
logic wb23_ready;
logic con_ready;
logic mac_ready;
logic mac_active;
logic con_2x2_ready;
logic con_2x2_active;
logic con_data_flag;
logic mp_wb_ready;
logic mp_wb_active;
logic mp_ri_active;
logic mp_ri_ready;

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


assign wb_finish = wb23_cs ^ wb23_active;
assign mac_flag =  con_data_flag | wb23_flag | mp_wb_flag | mp_ri_flag;
assign ready_o = mac_ready & con_2x2_ready & con_ready & wb23_ready & mp_ri_ready;//mp_wb_op is one cycle inst no need to add mp_wb_ready

//con_logic

logic con_active;
logic con_get_data;
logic con_active_d;
logic enable_i_d;
logic [31:0] max;
parameter nbit = 32;
//logic signed [15:0][nbit-1:0] con_data;
logic signed [nbit-1:0] w0,w1,w2,w3,w4,w5,w6,w7,w8;
logic signed [2*nbit+3:0] y0, y1, y2,y3;
logic signed [31:0] y0_m,y1_m,y2_m,y3_m,ymax;

logic signed [2*nbit+2:0] M0_0_0, M0_0_3, M3_0_0, M3_0_3;
logic signed [2*nbit+3:0] M0_0_1, M0_0_2, M3_0_1, M3_0_2;
logic signed [2*nbit+4:0] M1_0_0, M1_0_3, M2_0_0, M2_0_3;
logic signed [2*nbit+6:0] M0_0, M3_0;
logic signed [2*nbit+5:0] M0_1, M3_1, M1_0_1, M1_0_2, M2_0_1, M2_0_2;
logic signed [2*nbit+7:0] M1_1, M2_1;
logic signed [2*nbit+8:0] M1_0, M2_0;
logic signed [nbit+1:0] mid0_0, mid0_1, mid3_0, mid3_1;
logic signed [nbit+3:0] mid1_0, mid1_1, mid2_0, mid2_1; 
logic signed [nbit+1:0] mid0_2, mid0_3;

assign con_active_o = con_active;
assign mp_wb_active_o = mp_wb_active;
assign mp_ri_active_o = mp_ri_active;


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
			con_active_d <= 0;
			enable_i_d <= 0;
		end
		else begin
			con_active_d <= con_active;
			enable_i_d <= enable_i;
		end
	end	

//flag
assign wb23_flag = (operator_i == WB23_OP) && enable_i;
assign con_data_flag = (operator_i == CON_OP) && enable_i;
assign wb_flag = (operator_i == W_WB_OP) && enable_i;
assign mp_wb_flag = (operator_i == MP_WB_OP) && enable_i;
assign mp_ri_flag = (operator_i == MP_RI_OP) && enable_i;

//con
assign y0_o = y0[31:0];
assign y1_o = y1[31:0];
assign y2_o = y2[31:0];
assign y3_o = y3[31:0];

    always_ff @( posedge clk,negedge rst_n)
    begin
        if(~rst_n)begin
            con_data[0] <= '0;
            con_data[1] <= '0;
            con_data[2] <= '0;
            con_data[3] <= '0;
            con_data[4] <= '0;
            con_data[5] <= '0;
            con_data[6] <= '0;
            con_data[7] <= '0;
            con_data[8] <= '0;
            con_data[9] <= '0;
            con_data[10] <= '0;
            con_data[11] <= '0;
            con_data[12] <= '0;
            con_data[13] <= '0;
            con_data[14] <= '0;
            con_data[15] <= '0;
        end
        else begin
			if(con_get_data == 1'b1)begin
				con_data[con_data_cnt-1] <= mem_rdata;
			end
        end
    end
    
	always_ff @( posedge clk,negedge rst_n ) begin
		if(~rst_n)begin
			y0_m <= '0;
			y1_m <= '0;
			y2_m <= '0;
			y3_m <= '0;
		end
		else begin
			if(mp_ri_active)begin
				case(con_data_cnt)
				1:	y0_m <= mem_rdata;
				2:	y1_m <= mem_rdata;
				3:	y2_m <= mem_rdata;
				4:	y3_m <= mem_rdata;
				endcase
			end	
			else if(operator_i == RELU_OP && enable_i)
			begin
				y0_m <= y0_m[31]?0:y0_m;
				y1_m <= y1_m[31]?0:y1_m;
				y2_m <= y2_m[31]?0:y2_m;
				y3_m <= y3_m[31]?0:y3_m;
				//ymax <= ymax[31]?0:ymax;
			end
			
		end

	end

	always_comb begin
		if(operator_i == RELU_OP && enable_i)
		begin
			ymax = ymax[31]?0:ymax;
		end
		if (operator_i == MAX_POOL_OP && enable_i)begin
			if (y0_m < y1_m) 
				ymax = y1_m;
			else
				ymax = y0_m;
			if (ymax < y2_m)
				ymax = y2_m;
			if (ymax < y3_m)
				ymax = y3_m;
		end	
	end


	always_ff @( posedge clk,negedge rst_n)
	begin
		if (~rst_n)begin
			con_cs <= IDLE_CON;
			mp_ri_cs <= IDLE_MP_RI;
		end
		else begin
			con_cs <= con_ns;
			mp_ri_cs <= mp_ri_ns;
		end
	end

	always_comb begin
		con_ns = con_cs;
		mp_ri_ready = 1'b0;
		mp_ri_ns = mp_ri_cs;
		mp_ri_active = 1'b1;

		case (con_cs)
			IDLE_CON: begin
			    con_ready = 1'b1;
			    con_active = 1'b0;
				con_get_data = 1'b0;
				if (operator_i == CON_OP && enable_i) begin
					max = operand_i2;
					con_ns = GET_DATA;
				end
					
			end

			GET_DATA: begin
				con_ready = 1'b0;
				con_active = 1'b1;
				con_get_data = 1'b1;
				if(con_data_cnt !== max)begin //yao gai cheng ==
//				    if(clk==0)begin
//					   con_data[con_data_cnt-1] = mem_rdata;
					   con_ns = GET_DATA;
//				    end
				end
				else
					con_ns = CAL_1;
			end

			CAL_1: begin
				con_ready = 1'b0;
				con_active = 1'b1;
				con_get_data = 1'b0;
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
//				con_ns=CAL_2;
//				end

//			CAL_2:begin
				M0_0 = (M0_0_0 + M0_0_1 + M0_0_2)<<<1;
				M0_1 = (M0_0_1 - M0_0_2 - M0_0_3)<<<1;
				M1_0 = (M1_0_0 + M1_0_1 + M1_0_2);
				M1_1 = (M1_0_1 - M1_0_2 - M1_0_3);
				M2_0 = (M2_0_0 + M2_0_1 + M2_0_2);
				M2_1 = (M2_0_1 - M2_0_2 - M2_0_3); 
				M3_0 = (M3_0_0 + M3_0_1 + M3_0_2)<<<1;
				M3_1 = (M3_0_1 - M3_0_2 - M3_0_3)<<<1;
//			    con_ns=CAL_3;
//			    end
//			CAL_3:begin       
				y0=(M0_0 + M1_0 + M2_0)>>>2;
				y1=(M0_1 + M1_1 + M2_1)>>>2;
				y2=(M1_0 - M2_0 - M3_0)>>>2;
				y3=(M1_1 - M2_1 - M3_1)>>>2;       
				con_ns=FINISH_CON;
			end
			FINISH_CON: begin
				con_ready = 1'b1;
				con_active = 1'b0;
				con_get_data = 1'b0;
				if (ex_ready_i)
					con_ns = IDLE_CON;
			end
		endcase

		case(mp_ri_cs)
			IDLE_MP_RI:begin
				mp_ri_ready = 1'b1;
				mp_ri_active = 1'b0;
				if(operator_i == MP_RI_OP && enable_i) begin
					mp_ri_ns = MP_RDATA;
				end
			end
			MP_RDATA:begin
				mp_ri_ready = 1'b0;
				mp_ri_active = 1'b1;
				if (con_data_cnt !== 5) begin //yao gai cheng ==
					mp_ri_ns = MP_RDATA;
					// $display("mp_rdata is ok, y0=%d,y1=%d,y2=%d,y3=%d",y0[31:0],y1[31:0],y2[31:0],y3[31:0]);
				end
				else begin
					mp_ri_ready = 1'b1;
					mp_ri_active = 1'b0;
					mp_ri_ns = IDLE_MP_RI;
				end
			end
		endcase


	end


//max pooling ymax write back 

	always_ff @(posedge clk, negedge rst_n ) 
	begin 
		if (~rst_n) begin
			mp_wb_cs <= IDLE_MP_WB;
			wb23_cs <= IDLE_WB;

		end
		else begin
			mp_wb_cs <= mp_wb_ns;
			wb23_cs	<= wb23_ns;
		end
	end

	always_comb
	begin
		mp_wb_ready = 1'b0;
		mp_wb_ns = mp_wb_cs;
		mp_wb_active = 1'b1;

		wb23_ready = 1'b1;
		wb23_ns = wb23_cs;
		wb23_active = 1'b0;

		case(mp_wb_cs)
			IDLE_MP_WB:begin
				mp_wb_ready = 1'b1;
				mp_wb_active = 1'b0;
				if(operator_i == MP_WB_OP && enable_i) begin
					mp_wb_ns = MP_WDATA;
				end
			end
			MP_WDATA:begin
				// $display("mp_wdata is ok, mem_wdata=%d",mem_wdata);
				mp_wb_ready = 1'b0;
				mp_wb_active = 1'b1;
				mem_wdata = ymax[31:0];
				mp_wb_ns = IDLE_MP_WB;
			end
		endcase

		case(wb23_cs)
			IDLE_WB:begin
				wb23_active = 1'b0;
				wb23_ready = 1'b1;
				if(operator_i == WB23_OP && enable_i) begin
					// wb23_active = 1'b1;
					// wb23_ready = 1'b0;
					wb23_ns = WB23_WDATA;
				end
			end

			WB23_WDATA:begin
				wb23_active = 1'b1;
				wb23_ready = 1'b0;
				if (con_data_cnt !== 4) begin
					case(con_data_cnt)
						0:	mem_wdata = y0[31:0];//debuging
						1:	mem_wdata = y1[31:0];
						2:	mem_wdata = y2[31:0];
						3:begin
							mem_wdata = y3[31:0];
							wb23_ready = 1'b1;
						end	
						default:;
					endcase
					wb23_ns = WB23_WDATA;
				end

				else	
				begin
					wb23_ns = IDLE_WB;
					wb23_active = 1'b0;
					wb23_ready = 1'b1;
				end
			end
		endcase

	end


//weight write back
	always_ff @(posedge clk, negedge rst_n)
	begin
		if (~rst_n)begin
			w0 <= 1;
			w1 <= 2;
			w2 <= 3;
			w3 <= 4;
			w4 <= 5;
			w5 <= 6;
			w6 <= 7;
			w7 <= 8;
			w8 <= 9;
		end

		else begin
			if(operator_i == W_WB_OP && enable_i) begin
			case(operand_i1)	//the rank of weight
				1:w0 <= operand_i2;
				2:w1 <= operand_i2;
				3:w2 <= operand_i2;
				4:w3 <= operand_i2;
				5:w4 <= operand_i2;
				6:w5 <= operand_i2;
				7:w6 <= operand_i2;
				8:w7 <= operand_i2;
				9:w8 <= operand_i2;
				default:;
			endcase			
		end
		end	
	end
	
endmodule
