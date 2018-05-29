module chessEngineMemoryWrapper(
        input clk,
	input reset_n,	
	output [255:0] readdata, 
	input write, 
	input [255:0] writedata,
	input chipselect);

reg [255:0] data;

always@(posedge clk) 
begin
	if (~reset_n)
	begin
		data <= 256'b0;
	end
	else begin
		if (chipselect & write) begin
			data <= writedata;
		end
	end
end
  wire initialize;
  wire [3:0] pt_calc;
  wire [63:0] occupying_piece_color;
  wire [63:0] is_occupied_wires;
  wire [5:0] square_currently_calculating;
  wire [63:0] move_wires;

	assign initialize = data[255];
	assign pt_calc[3:0] = data[254:251];
	assign square_currently_calculating = data[247:241];
	assign occupying_piece_color = data[239:176];
	assign is_occupied_wires = data[175:112];

	assign readdata[63:0] = move_wires;

	 chessEngine c(
        .initialize(initialize),
        .pt_calc(pt_calc),
        .occupying_piece_color(occupying_piece_color),
        .is_occupied_wires(is_occupied_wires),
        .square_currently_calculating(square_currently_calculating),
        .move_wires(move_wires)
        );
endmodule
