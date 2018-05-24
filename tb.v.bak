module tb;

reg clock;
reg initialize;
wire [63:0] move_wires;
reg [63:0] occupying_piece_color, is_occupied_wires;
reg [5:0] square_currently_calculating;
reg [3:0] pt_calc;



chessEngine c(
.clock(clock),
.initialize(initialize),
.pt_calc(pt_calc),
.occupying_piece_color(occupying_piece_color),
.is_occupied_wires(is_occupied_wires),
.square_currently_calculating(square_currently_calculating),
.move_wires(move_wires)
);

initial begin
clock = 1'b0;
end

always begin
#5 
clock = ~clock;
end

initial begin
occupying_piece_color = 63'd0;
is_occupied_wires = 63'd0;
square_currently_calculating = 6'd0;
pt_calc = 4'd0;
initialize = 1'b1;
#20

initialize = 1'b0; 
end



endmodule