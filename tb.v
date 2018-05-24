module tb;

reg clock;
reg initialize;
wire [63:0] move_wires;
wire [63:0] occupying_piece_color, is_occupied_wires;
wire [5:0] square_currently_calculating;
wire [3:0] pt_calc;

assign occupying_piece_color = 63'h0000000000000001;
assign is_occupied_wires = 63'h0000000000000001;
assign square_currently_calculating = 6'd32;
assign pt_calc = 4'd9;



chessEngine c(
.initialize(initialize),
.pt_calc(pt_calc),
.occupying_piece_color(occupying_piece_color),
.is_occupied_wires(is_occupied_wires),
.square_currently_calculating(square_currently_calculating),
.move_wires(move_wires)
);


always begin
#5 
clock = ~clock;
end

initial begin
clock = 1'b0;
initialize = 1'b1;
#5
initialize = 1'b0;
 
end



endmodule