module verif
(
    input logic [127:0]  y_i,
    input logic [1023:0] registers_i,
    input logic [16:0] ins_addr_i,
    input logic [31:0] ins_data_i,
    input logic [16:0] data_addr_i,
    input logic [31:0] data_data_i,
    input logic sleep_i,
    output logic y_ok,
    output logic registers_ok,
    output logic ins_ok,
    output logic data_ok
);

logic [127:0] y_c = 128'h000000b0_00000105_000000ed_0000015f;
logic [31:0] x0 = '0;
logic [31:0] x1 = 32'h00001168;
logic [31:0] x2 = 32'h00007ff0;
logic [31:0] x3 = 32'h00003c50;
logic [31:0] x4 = '0;
logic [31:0] x5 = 32'h000017e8;
logic [31:0] x6 = 32'h00003ab8;
logic [31:0] x7 = '0;
logic [31:0] x8 = '0;
logic [31:0] x9 = '0;
logic [31:0] x10 = '0;
logic [31:0] x11 = '0;
logic [31:0] x12 = 32'h00000012;
logic [31:0] x13 = 32'h00001168;
logic [31:0] x14 = '0;
logic [31:0] x15 = 32'h20000000;
logic [31:0] x16 = 32'h00003ac0;
logic [31:0] x17 = 32'h00003ab8;
logic [31:0] x18 = '0;
logic [31:0] x19 = '0;
logic [31:0] x20 = '0;
logic [31:0] x21 = '0;
logic [31:0] x22 = '0;
logic [31:0] x23 = '0;
logic [31:0] x24 = '0;
logic [31:0] x25 = '0;
logic [31:0] x26 = '0;
logic [31:0] x27 = '0;
logic [31:0] x28 = '0;
logic [31:0] x29 = '0;
logic [31:0] x30 = '0;
logic [31:0] x31 = '0;

logic [16:0] ins_addr_c = 17'h003d5;
logic [31:0] ins_data_c = 32'ha8230580;
logic [16:0] data_addr_c= 17'h005fa;
logic [31:0] data_data_c= '0;


always_comb begin
    if((y_i==y_c)&sleep_i)begin
        y_ok = 1'b1;
    end
    else begin
        y_ok = 1'b0;
    end
end


always_comb begin
    if( (registers_i[31:0]		==	x0)&
        (registers_i[63:32]		==	x1)&
        (registers_i[95:64]		==	x2)&
        (registers_i[127:96]		==	x3)&
        (registers_i[159:128]		==	x4)&
        (registers_i[191:160]		==	x5)&
        (registers_i[223:192]		==	x6)&
        (registers_i[255:224]		==	x7)&
        (registers_i[287:256]		==	x8)&
        (registers_i[319:288]		==	x9)&
        (registers_i[351:320]		==	x10)&
        (registers_i[383:352]		==	x11)&
        (registers_i[415:384]		==	x12)&
        (registers_i[447:416]		==	x13)&
        (registers_i[479:448]		==	x14)&
        (registers_i[511:480]		==	x15)&
        (registers_i[543:512]		==	x16)&
        (registers_i[575:544]		==	x17)&
        (registers_i[607:576]		==	x18)&
        (registers_i[639:608]		==	x19)&
        (registers_i[671:640]		==	x20)&
        (registers_i[703:672]		==	x21)&
        (registers_i[735:704]		==	x22)&
        (registers_i[767:736]		==	x23)&
        (registers_i[799:768]		==	x24)&
        (registers_i[831:800]		==	x25)&
        (registers_i[863:832]		==	x26)&
        (registers_i[895:864]		==	x27)&
        (registers_i[927:896]		==	x28)&
        (registers_i[959:928]		==	x29)&
        (registers_i[991:960]		==	x30)&
        (registers_i[1023:992]		==	x31)&sleep_i
    )begin
        registers_ok = 1'b1;
    end
    else begin
        registers_ok = 1'b0;
    end
end

always_comb begin
    if((ins_addr_i==ins_addr_c)&(ins_data_i==ins_data_c)&sleep_i)begin
        ins_ok = 1'b1;
    end
    else begin
        ins_ok = 1'b0;
    end
end

always_comb begin
    if((data_addr_i==data_addr_c)&(data_data_i==data_data_c)&sleep_i)begin
        data_ok = 1'b1;
    end
    else begin
        data_ok = 1'b0;
    end
end

endmodule