module reg32_avalon_interface(
	input clock,
	input reset_n,
	input write,
	input[31:0] writedata,
	input read,
	output[31:0] readdata,
	input[3:0] byteenable,
	input chipselect,
	output[31:0] Q_export
);

wire[3:0] local_byteenable;
wire[31:0] to_reg, from_reg;
assign to_reg = writedata;
assign readdata = from_reg;
assign Q_export = from_reg;
assign local_byteenable = (chipselect & write) ? byteenable : 4'd0;
reg32 U1 (
	.clock		(clock),
	.reset_n		(reset_n),
	.dIn				(to_reg),
	.byteenable	(local_byteenable),
	.dOut				(from_reg)
);

endmodule