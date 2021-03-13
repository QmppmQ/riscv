import riscv_defines::*;
module riscv_str_ops
(
	input logic						 clk,
	input logic						 rst_n,
	input logic						 enable_i,
	input logic [STR_OP_WIDTH-1:0]   operator_i,
	input logic [31:0]				 operand_i,
	input logic						 ex_ready_i,

	output logic [31:0]				 result_o,

	output logic					 ready_o
);
//	always_comb 
//	begin	
//		result_o = enable_i ? operand_i : 32'b0;
//	end

enum logic [2:0] {
	IDLE,
	STEP0,
	STEP1,
	STEP2,
	FINISH
} leet_CS,leet_NS;

logic leet_ready;
logic leet_active;
assign ready_o = leet_ready;
logic [31:0] leet_intermediate;
logic [31:0] char_;
	always_ff @( posedge clk,negedge rst_n)
	begin
		if (~rst_n)
			leet_CS <= IDLE;
		else
			leet_CS <= leet_NS;
	end

	always_comb begin
		leet_ready = 1'b0;
		leet_NS = leet_CS;
		leet_active = 1'b1;
		
		case (leet_CS)
			IDLE: begin
				leet_active = 1'b0;
				leet_ready  = 1'b1;
				if (operator_i == STR_OP_LEET && enable_i) begin
					leet_ready = 1'b0;
					leet_NS = STEP0;
					leet_intermediate <= operand_i;
				end
			end

			STEP0: begin
				leet_NS = STEP1;
				char_ = leet_intermediate;
				if ((char_[7:0] == 69 || char_[7:0] == 101))
					char_[7:0] = 51;
				if ((char_[15:8] == 69 || char_[15:8] == 101))
					char_[15:8] = 51;
				if ((char_[23:16] == 69 || char_[23:16] == 101))
					char_[23:16] = 51;
				if ((char_[31:24] == 69 || char_[31:24] == 101))
					char_[31:24] = 51;

				leet_intermediate <= char_;
			end

			STEP1: begin
				leet_NS = STEP2;
				char_ = leet_intermediate;
				if ((char_[7:0] == 83 || char_[7:0] == 115))
					char_[7:0] = 53;
				if ((char_[15:8] == 83 || char_[15:8] == 115))
					char_[15:8] = 53;
				if ((char_[23:16] == 83 || char_[23:16] == 115))
					char_[23:16] = 53;
				if ((char_[31:24] == 83 || char_[31:24] == 115))
					char_[31:24] = 53;
				leet_intermediate <= char_;
				
			end

			STEP2: begin
				leet_NS = FINISH;
				char_ = leet_intermediate;
				if ((char_[7:0] == 76 || char_[7:0] == 108))
					char_[7:0] = 49;
				if ((char_[15:8] == 76 || char_[15:8] == 108))
					char_[15:8] = 49;
				if ((char_[23:16] == 76 || char_[23:16] == 108))
					char_[23:16] = 49;
				if ((char_[31:24] == 76 || char_[31:24] == 108))
					char_[31:24] = 49;
				leet_intermediate <= char_;
			end

			FINISH: begin
				leet_ready = 1'b1;
				if (ex_ready_i)
					leet_NS = IDLE;
			end
		endcase
	end

	always_comb
	begin
		if (enable_i) begin
			case (operator_i)
				STR_OP_UPPER:begin
				if (operand_i[31:24] >=97 && operand_i[31:24] <=122)
					result_o[31:24] = operand_i[31:24] - 32;
				else 
					result_o[31:24] = operand_i[31:24];

				if (operand_i[23:16] >=97 && operand_i[23:16] <=122)
					result_o[23:16] = operand_i[23:16] - 32;
				else
					result_o[23:16] = operand_i[23:16];

				if (operand_i[15:8] >=97 && operand_i[15:8] <=122)
					result_o[15:8] = operand_i[15:8] - 32;
				else 
					result_o[15:8] = operand_i[15:8];

				if (operand_i[7:0] >=97 && operand_i[7:0] <=122)
					result_o[7:0] = operand_i[7:0] - 32;
				else
					result_o[7:0] = operand_i[7:0];
					$display("%t: Exec Upper instruction", $time);
				end
				STR_OP_LOWER:begin
					$display("%t: Exec Lower instruction", $time);
					result_o = operand_i;
				end
				STR_OP_LEET:begin
					$display("%t: Exec Leet instruction", $time);
					if(leet_CS == FINISH)begin
						result_o = leet_intermediate;
				
					end
				end
				STR_OP_ROT13:begin
					$display("%t: Exec Rot13 instruction", $time);
					result_o = operand_i;
				end
			endcase
		end

//		if (enable_i) begin
//			result_o = 32'hDEADBEEF;
//
//			if(operator_i == STR_OP_UPPER)
//				result_o = result;
//			if(operator_i == STR_OP_LLET && leet_CS == FINISH)
//				result_o = leet_intermediate;
//		end
	end
endmodule
