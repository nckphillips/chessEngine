module chessEngine(
input initialize,
input clock,
input [3:0] pt_calc,
input [63:0] is_occupied wires,
input [63:0][3:0] occupying_piece_type_wires,
output [63:0] move_wires
);

wire init;
wire clk;
wire [3:0] piece_type_calc; 

assign init = initialize;
assign clk = clock;
assign piece_type_calc = pt_calc;





/*************Generated interconnections for squares*************/
wire b1a1;
wire b2a1;
wire a2a1;
wire c2a1;
wire a1b2;
wire a2b1;
wire a1b1;
wire c1b1;
wire c2b1;
wire b2b1;
wire d2b1;
wire b1a2;
wire b1c2;
wire b2c1;
wire b1c1;
wire d1c1;
wire d2c1;
wire c2c1;
wire a2c1;
wire e2c1;
wire c1b2;
wire c1d2;
wire c2d1;
wire c1d1;
wire e1d1;
wire e2d1;
wire d2d1;
wire b2d1;
wire f2d1;
wire d1c2;
wire d1e2;
wire d2e1;
wire d1e1;
wire f1e1;
wire f2e1;
wire e2e1;
wire c2e1;
wire g2e1;
wire e1d2;
wire e1f2;
wire e2f1;
wire e1f1;
wire g1f1;
wire g2f1;
wire f2f1;
wire d2f1;
wire h2f1;
wire f1e2;
wire f1g2;
wire f2g1;
wire f1g1;
wire h1g1;
wire h2g1;
wire g2g1;
wire e2g1;
wire g1f2;
wire g1h2;
wire g2h1;
wire g1h1;
wire h2h1;
wire f2h1;
wire h1g2;
wire a1a2;
wire b2a2;
wire b3a2;
wire a3a2;
wire g8a2;
wire c3a2;
wire a2b3;
wire a3b2;
wire a2b2;
wire b1b2;
wire c2b2;
wire c3b2;
wire b3b2;
wire h8b2;
wire d3b2;
wire b2a3;
wire b2c3;
wire b3c2;
wire b2c2;
wire c1c2;
wire d2c2;
wire d3c2;
wire c3c2;
wire a3c2;
wire e1c2;
wire a1c2;
wire e3c2;
wire c2b3;
wire c2d3;
wire c3d2;
wire c2d2;
wire d1d2;
wire e2d2;
wire e3d2;
wire d3d2;
wire b3d2;
wire f1d2;
wire b1d2;
wire f3d2;
wire d2c3;
wire d2e3;
wire d3e2;
wire d2e2;
wire e1e2;
wire f2e2;
wire f3e2;
wire e3e2;
wire c3e2;
wire g1e2;
wire c1e2;
wire g3e2;
wire e2d3;
wire e2f3;
wire e3f2;
wire e2f2;
wire f1f2;
wire g2f2;
wire g3f2;
wire f3f2;
wire d3f2;
wire h1f2;
wire d1f2;
wire h3f2;
wire f2e3;
wire f2g3;
wire f3g2;
wire f2g2;
wire g1g2;
wire h2g2;
wire h3g2;
wire g3g2;
wire e3g2;
wire a2g2;
wire g2f3;
wire g2h3;
wire g3h2;
wire g2h2;
wire h1h2;
wire h3h2;
wire f3h2;
wire b2h2;
wire h2g3;
wire a2a3;
wire b3a3;
wire b4a3;
wire a4a3;
wire g1a3;
wire c4a3;
wire a3b4;
wire a4b3;
wire a3b3;
wire b2b3;
wire c3b3;
wire c4b3;
wire b4b3;
wire h1b3;
wire d4b3;
wire b3a4;
wire b3c4;
wire b4c3;
wire b3c3;
wire c2c3;
wire d3c3;
wire d4c3;
wire c4c3;
wire a4c3;
wire e2c3;
wire a2c3;
wire e4c3;
wire c3b4;
wire c3d4;
wire c4d3;
wire c3d3;
wire d2d3;
wire e3d3;
wire e4d3;
wire d4d3;
wire b4d3;
wire f2d3;
wire b2d3;
wire f4d3;
wire d3c4;
wire d3e4;
wire d4e3;
wire d3e3;
wire e2e3;
wire f3e3;
wire f4e3;
wire e4e3;
wire c4e3;
wire g2e3;
wire c2e3;
wire g4e3;
wire e3d4;
wire e3f4;
wire e4f3;
wire e3f3;
wire f2f3;
wire g3f3;
wire g4f3;
wire f4f3;
wire d4f3;
wire h2f3;
wire d2f3;
wire h4f3;
wire f3e4;
wire f3g4;
wire f4g3;
wire f3g3;
wire g2g3;
wire h3g3;
wire h4g3;
wire g4g3;
wire e4g3;
wire a3g3;
wire g3f4;
wire g3h4;
wire g4h3;
wire g3h3;
wire h2h3;
wire h4h3;
wire f4h3;
wire b3h3;
wire h3g4;
wire a3a4;
wire b4a4;
wire b5a4;
wire a5a4;
wire g2a4;
wire c5a4;
wire a4b5;
wire a5b4;
wire a4b4;
wire b3b4;
wire c4b4;
wire c5b4;
wire b5b4;
wire h2b4;
wire d5b4;
wire b4a5;
wire b4c5;
wire b5c4;
wire b4c4;
wire c3c4;
wire d4c4;
wire d5c4;
wire c5c4;
wire a5c4;
wire e3c4;
wire a3c4;
wire e5c4;
wire c4b5;
wire c4d5;
wire c5d4;
wire c4d4;
wire d3d4;
wire e4d4;
wire e5d4;
wire d5d4;
wire b5d4;
wire f3d4;
wire b3d4;
wire f5d4;
wire d4c5;
wire d4e5;
wire d5e4;
wire d4e4;
wire e3e4;
wire f4e4;
wire f5e4;
wire e5e4;
wire c5e4;
wire g3e4;
wire c3e4;
wire g5e4;
wire e4d5;
wire e4f5;
wire e5f4;
wire e4f4;
wire f3f4;
wire g4f4;
wire g5f4;
wire f5f4;
wire d5f4;
wire h3f4;
wire d3f4;
wire h5f4;
wire f4e5;
wire f4g5;
wire f5g4;
wire f4g4;
wire g3g4;
wire h4g4;
wire h5g4;
wire g5g4;
wire e5g4;
wire a4g4;
wire g4f5;
wire g4h5;
wire g5h4;
wire g4h4;
wire h3h4;
wire h5h4;
wire f5h4;
wire b4h4;
wire h4g5;
wire a4a5;
wire b5a5;
wire b6a5;
wire a6a5;
wire g3a5;
wire c6a5;
wire a5b6;
wire a6b5;
wire a5b5;
wire b4b5;
wire c5b5;
wire c6b5;
wire b6b5;
wire h3b5;
wire d6b5;
wire b5a6;
wire b5c6;
wire b6c5;
wire b5c5;
wire c4c5;
wire d5c5;
wire d6c5;
wire c6c5;
wire a6c5;
wire e4c5;
wire a4c5;
wire e6c5;
wire c5b6;
wire c5d6;
wire c6d5;
wire c5d5;
wire d4d5;
wire e5d5;
wire e6d5;
wire d6d5;
wire b6d5;
wire f4d5;
wire b4d5;
wire f6d5;
wire d5c6;
wire d5e6;
wire d6e5;
wire d5e5;
wire e4e5;
wire f5e5;
wire f6e5;
wire e6e5;
wire c6e5;
wire g4e5;
wire c4e5;
wire g6e5;
wire e5d6;
wire e5f6;
wire e6f5;
wire e5f5;
wire f4f5;
wire g5f5;
wire g6f5;
wire f6f5;
wire d6f5;
wire h4f5;
wire d4f5;
wire h6f5;
wire f5e6;
wire f5g6;
wire f6g5;
wire f5g5;
wire g4g5;
wire h5g5;
wire h6g5;
wire g6g5;
wire e6g5;
wire a5g5;
wire g5f6;
wire g5h6;
wire g6h5;
wire g5h5;
wire h4h5;
wire h6h5;
wire f6h5;
wire b5h5;
wire h5g6;
wire a5a6;
wire b6a6;
wire b7a6;
wire a7a6;
wire g4a6;
wire c7a6;
wire a6b7;
wire a7b6;
wire a6b6;
wire b5b6;
wire c6b6;
wire c7b6;
wire b7b6;
wire h4b6;
wire d7b6;
wire b6a7;
wire b6c7;
wire b7c6;
wire b6c6;
wire c5c6;
wire d6c6;
wire d7c6;
wire c7c6;
wire a7c6;
wire e5c6;
wire a5c6;
wire e7c6;
wire c6b7;
wire c6d7;
wire c7d6;
wire c6d6;
wire d5d6;
wire e6d6;
wire e7d6;
wire d7d6;
wire b7d6;
wire f5d6;
wire b5d6;
wire f7d6;
wire d6c7;
wire d6e7;
wire d7e6;
wire d6e6;
wire e5e6;
wire f6e6;
wire f7e6;
wire e7e6;
wire c7e6;
wire g5e6;
wire c5e6;
wire g7e6;
wire e6d7;
wire e6f7;
wire e7f6;
wire e6f6;
wire f5f6;
wire g6f6;
wire g7f6;
wire f7f6;
wire d7f6;
wire h5f6;
wire d5f6;
wire h7f6;
wire f6e7;
wire f6g7;
wire f7g6;
wire f6g6;
wire g5g6;
wire h6g6;
wire h7g6;
wire g7g6;
wire e7g6;
wire a6g6;
wire g6f7;
wire g6h7;
wire g7h6;
wire g6h6;
wire h5h6;
wire h7h6;
wire f7h6;
wire b6h6;
wire h6g7;
wire a6a7;
wire b7a7;
wire b8a7;
wire a8a7;
wire g5a7;
wire c8a7;
wire a7b8;
wire a8b7;
wire a7b7;
wire b6b7;
wire c7b7;
wire c8b7;
wire b8b7;
wire h5b7;
wire d8b7;
wire b7a8;
wire b7c8;
wire b8c7;
wire b7c7;
wire c6c7;
wire d7c7;
wire d8c7;
wire c8c7;
wire a8c7;
wire e6c7;
wire a6c7;
wire e8c7;
wire c7b8;
wire c7d8;
wire c8d7;
wire c7d7;
wire d6d7;
wire e7d7;
wire e8d7;
wire d8d7;
wire b8d7;
wire f6d7;
wire b6d7;
wire f8d7;
wire d7c8;
wire d7e8;
wire d8e7;
wire d7e7;
wire e6e7;
wire f7e7;
wire f8e7;
wire e8e7;
wire c8e7;
wire g6e7;
wire c6e7;
wire g8e7;
wire e7d8;
wire e7f8;
wire e8f7;
wire e7f7;
wire f6f7;
wire g7f7;
wire g8f7;
wire f8f7;
wire d8f7;
wire h6f7;
wire d6f7;
wire h8f7;
wire f7e8;
wire f7g8;
wire f8g7;
wire f7g7;
wire g6g7;
wire h7g7;
wire h8g7;
wire g8g7;
wire e8g7;
wire a7g7;
wire g7f8;
wire g7h8;
wire g8h7;
wire g7h7;
wire h6h7;
wire h8h7;
wire f8h7;
wire b7h7;
wire h7g8;
wire a7a8;
wire b8a8;
wire g6a8;
wire a8b8;
wire b7b8;
wire c8b8;
wire h6b8;
wire b8c8;
wire c7c8;
wire d8c8;
wire e7c8;
wire a7c8;
wire c8d8;
wire d7d8;
wire e8d8;
wire f7d8;
wire b7d8;
wire d8e8;
wire e7e8;
wire f8e8;
wire g7e8;
wire c7e8;
wire e8f8;
wire f7f8;
wire g8f8;
wire h7f8;
wire d7f8;
wire f8g8;
wire g7g8;
wire h8g8;
wire a8g8;
wire g8h8;
wire h7h8;
wire b8h8;


/*************Generated modules*************/


square a1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[0]), 
          .square_id(5'd0), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[0]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(b1a1), 
          .in_tr(b2a1), 
          .in_midt(a2a1), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(c2a1), 
          .in_ktl(0), 
          .in_ktr(b2a1), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(a1b1), 
          .out_tr(a1b2), 
          .out_midt(a1a2), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(a1c2), 
          .out_ktl(), 
          .out_ktr(a1b2), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[0])

square b1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[1]), 
          .square_id(5'd1), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[1]), 
          .in_tl(a2b1), 
          .in_midl(a1b1), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(c1b1), 
          .in_tr(c2b1), 
          .in_midt(b2b1), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(d2b1), 
          .in_ktl(a2b1), 
          .in_ktr(c2b1), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(b1a2), 
          .out_midl(b1a1), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(b1c1), 
          .out_tr(b1c2), 
          .out_midt(b1b2), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(b1d2), 
          .out_ktl(b1a2), 
          .out_ktr(b1c2), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[1])

square c1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[2]), 
          .square_id(5'd2), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[2]), 
          .in_tl(b2c1), 
          .in_midl(b1c1), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(d1c1), 
          .in_tr(d2c1), 
          .in_midt(c2c1), 
          .in_klt(a2c1), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(e2c1), 
          .in_ktl(b2c1), 
          .in_ktr(d2c1), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(c1b2), 
          .out_midl(c1b1), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(c1d1), 
          .out_tr(c1d2), 
          .out_midt(c1c2), 
          .out_klt(c1a2), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(c1e2), 
          .out_ktl(c1b2), 
          .out_ktr(c1d2), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[2])

square d1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[3]), 
          .square_id(5'd3), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[3]), 
          .in_tl(c2d1), 
          .in_midl(c1d1), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(e1d1), 
          .in_tr(e2d1), 
          .in_midt(d2d1), 
          .in_klt(b2d1), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(f2d1), 
          .in_ktl(c2d1), 
          .in_ktr(e2d1), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(d1c2), 
          .out_midl(d1c1), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(d1e1), 
          .out_tr(d1e2), 
          .out_midt(d1d2), 
          .out_klt(d1b2), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(d1f2), 
          .out_ktl(d1c2), 
          .out_ktr(d1e2), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[3])

square e1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[4]), 
          .square_id(5'd4), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[4]), 
          .in_tl(d2e1), 
          .in_midl(d1e1), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(f1e1), 
          .in_tr(f2e1), 
          .in_midt(e2e1), 
          .in_klt(c2e1), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(g2e1), 
          .in_ktl(d2e1), 
          .in_ktr(f2e1), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(e1d2), 
          .out_midl(e1d1), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(e1f1), 
          .out_tr(e1f2), 
          .out_midt(e1e2), 
          .out_klt(e1c2), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(e1g2), 
          .out_ktl(e1d2), 
          .out_ktr(e1f2), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[4])

square f1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[5]), 
          .square_id(5'd5), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[5]), 
          .in_tl(e2f1), 
          .in_midl(e1f1), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(g1f1), 
          .in_tr(g2f1), 
          .in_midt(f2f1), 
          .in_klt(d2f1), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(h2f1), 
          .in_ktl(e2f1), 
          .in_ktr(g2f1), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(f1e2), 
          .out_midl(f1e1), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(f1g1), 
          .out_tr(f1g2), 
          .out_midt(f1f2), 
          .out_klt(f1d2), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(f1h2), 
          .out_ktl(f1e2), 
          .out_ktr(f1g2), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[5])

square g1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[6]), 
          .square_id(5'd6), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[6]), 
          .in_tl(f2g1), 
          .in_midl(f1g1), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(h1g1), 
          .in_tr(h2g1), 
          .in_midt(g2g1), 
          .in_klt(e2g1), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(f2g1), 
          .in_ktr(h2g1), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(g1f2), 
          .out_midl(g1f1), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(g1h1), 
          .out_tr(g1h2), 
          .out_midt(g1g2), 
          .out_klt(g1e2), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(g1f2), 
          .out_ktr(g1h2), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[6])

square h1(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[7]), 
          .square_id(5'd7), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[7]), 
          .in_tl(g2h1), 
          .in_midl(g1h1), 
          .in_bl(0), 
          .in_midb(0), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(h2h1), 
          .in_klt(f2h1), 
          .in_klb(0), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(g2h1), 
          .in_ktr(0), 
          .in_kbl(0), 
          .in_kbr(0)
          .out_tl(h1g2), 
          .out_midl(h1g1), 
          .out_bl(), 
          .out_midb(), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(h1h2), 
          .out_klt(h1f2), 
          .out_klb(), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(h1g2), 
          .out_ktr(), 
          .out_kbl(), 
          .out_kbr(), 
          .movebit(move_wires[7])

square a2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[8]), 
          .square_id(5'd8), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[8]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(a1a2), 
          .in_br(b1a2), 
          .in_midr(b2a2), 
          .in_tr(b3a2), 
          .in_midt(a3a2), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(g8a2), 
          .in_krt(c3a2), 
          .in_ktl(0), 
          .in_ktr(b3a2), 
          .in_kbl(0), 
          .in_kbr(b1a2)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(a2a1), 
          .out_br(a2b1), 
          .out_midr(a2b2), 
          .out_tr(a2b3), 
          .out_midt(a2a3), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(a2g8), 
          .out_krt(a2c3), 
          .out_ktl(), 
          .out_ktr(a2b3), 
          .out_kbl(), 
          .out_kbr(a2b1), 
          .movebit(move_wires[8])

square b2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[9]), 
          .square_id(5'd9), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[9]), 
          .in_tl(a3b2), 
          .in_midl(a2b2), 
          .in_bl(a1b2), 
          .in_midb(b1b2), 
          .in_br(c1b2), 
          .in_midr(c2b2), 
          .in_tr(c3b2), 
          .in_midt(b3b2), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(h8b2), 
          .in_krt(d3b2), 
          .in_ktl(a3b2), 
          .in_ktr(c3b2), 
          .in_kbl(a1b2), 
          .in_kbr(c1b2)
          .out_tl(b2a3), 
          .out_midl(b2a2), 
          .out_bl(b2a1), 
          .out_midb(b2b1), 
          .out_br(b2c1), 
          .out_midr(b2c2), 
          .out_tr(b2c3), 
          .out_midt(b2b3), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(b2h8), 
          .out_krt(b2d3), 
          .out_ktl(b2a3), 
          .out_ktr(b2c3), 
          .out_kbl(b2a1), 
          .out_kbr(b2c1), 
          .movebit(move_wires[9])

square c2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[10]), 
          .square_id(5'd10), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[10]), 
          .in_tl(b3c2), 
          .in_midl(b2c2), 
          .in_bl(b1c2), 
          .in_midb(c1c2), 
          .in_br(d1c2), 
          .in_midr(d2c2), 
          .in_tr(d3c2), 
          .in_midt(c3c2), 
          .in_klt(a3c2), 
          .in_klb(e1c2), 
          .in_krb(a1c2), 
          .in_krt(e3c2), 
          .in_ktl(b3c2), 
          .in_ktr(d3c2), 
          .in_kbl(b1c2), 
          .in_kbr(d1c2)
          .out_tl(c2b3), 
          .out_midl(c2b2), 
          .out_bl(c2b1), 
          .out_midb(c2c1), 
          .out_br(c2d1), 
          .out_midr(c2d2), 
          .out_tr(c2d3), 
          .out_midt(c2c3), 
          .out_klt(c2a3), 
          .out_klb(c2e1), 
          .out_krb(c2a1), 
          .out_krt(c2e3), 
          .out_ktl(c2b3), 
          .out_ktr(c2d3), 
          .out_kbl(c2b1), 
          .out_kbr(c2d1), 
          .movebit(move_wires[10])

square d2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[11]), 
          .square_id(5'd11), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[11]), 
          .in_tl(c3d2), 
          .in_midl(c2d2), 
          .in_bl(c1d2), 
          .in_midb(d1d2), 
          .in_br(e1d2), 
          .in_midr(e2d2), 
          .in_tr(e3d2), 
          .in_midt(d3d2), 
          .in_klt(b3d2), 
          .in_klb(f1d2), 
          .in_krb(b1d2), 
          .in_krt(f3d2), 
          .in_ktl(c3d2), 
          .in_ktr(e3d2), 
          .in_kbl(c1d2), 
          .in_kbr(e1d2)
          .out_tl(d2c3), 
          .out_midl(d2c2), 
          .out_bl(d2c1), 
          .out_midb(d2d1), 
          .out_br(d2e1), 
          .out_midr(d2e2), 
          .out_tr(d2e3), 
          .out_midt(d2d3), 
          .out_klt(d2b3), 
          .out_klb(d2f1), 
          .out_krb(d2b1), 
          .out_krt(d2f3), 
          .out_ktl(d2c3), 
          .out_ktr(d2e3), 
          .out_kbl(d2c1), 
          .out_kbr(d2e1), 
          .movebit(move_wires[11])

square e2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[12]), 
          .square_id(5'd12), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[12]), 
          .in_tl(d3e2), 
          .in_midl(d2e2), 
          .in_bl(d1e2), 
          .in_midb(e1e2), 
          .in_br(f1e2), 
          .in_midr(f2e2), 
          .in_tr(f3e2), 
          .in_midt(e3e2), 
          .in_klt(c3e2), 
          .in_klb(g1e2), 
          .in_krb(c1e2), 
          .in_krt(g3e2), 
          .in_ktl(d3e2), 
          .in_ktr(f3e2), 
          .in_kbl(d1e2), 
          .in_kbr(f1e2)
          .out_tl(e2d3), 
          .out_midl(e2d2), 
          .out_bl(e2d1), 
          .out_midb(e2e1), 
          .out_br(e2f1), 
          .out_midr(e2f2), 
          .out_tr(e2f3), 
          .out_midt(e2e3), 
          .out_klt(e2c3), 
          .out_klb(e2g1), 
          .out_krb(e2c1), 
          .out_krt(e2g3), 
          .out_ktl(e2d3), 
          .out_ktr(e2f3), 
          .out_kbl(e2d1), 
          .out_kbr(e2f1), 
          .movebit(move_wires[12])

square f2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[13]), 
          .square_id(5'd13), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[13]), 
          .in_tl(e3f2), 
          .in_midl(e2f2), 
          .in_bl(e1f2), 
          .in_midb(f1f2), 
          .in_br(g1f2), 
          .in_midr(g2f2), 
          .in_tr(g3f2), 
          .in_midt(f3f2), 
          .in_klt(d3f2), 
          .in_klb(h1f2), 
          .in_krb(d1f2), 
          .in_krt(h3f2), 
          .in_ktl(e3f2), 
          .in_ktr(g3f2), 
          .in_kbl(e1f2), 
          .in_kbr(g1f2)
          .out_tl(f2e3), 
          .out_midl(f2e2), 
          .out_bl(f2e1), 
          .out_midb(f2f1), 
          .out_br(f2g1), 
          .out_midr(f2g2), 
          .out_tr(f2g3), 
          .out_midt(f2f3), 
          .out_klt(f2d3), 
          .out_klb(f2h1), 
          .out_krb(f2d1), 
          .out_krt(f2h3), 
          .out_ktl(f2e3), 
          .out_ktr(f2g3), 
          .out_kbl(f2e1), 
          .out_kbr(f2g1), 
          .movebit(move_wires[13])

square g2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[14]), 
          .square_id(5'd14), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[14]), 
          .in_tl(f3g2), 
          .in_midl(f2g2), 
          .in_bl(f1g2), 
          .in_midb(g1g2), 
          .in_br(h1g2), 
          .in_midr(h2g2), 
          .in_tr(h3g2), 
          .in_midt(g3g2), 
          .in_klt(e3g2), 
          .in_klb(a2g2), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(f3g2), 
          .in_ktr(h3g2), 
          .in_kbl(f1g2), 
          .in_kbr(h1g2)
          .out_tl(g2f3), 
          .out_midl(g2f2), 
          .out_bl(g2f1), 
          .out_midb(g2g1), 
          .out_br(g2h1), 
          .out_midr(g2h2), 
          .out_tr(g2h3), 
          .out_midt(g2g3), 
          .out_klt(g2e3), 
          .out_klb(g2a2), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(g2f3), 
          .out_ktr(g2h3), 
          .out_kbl(g2f1), 
          .out_kbr(g2h1), 
          .movebit(move_wires[14])

square h2(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[15]), 
          .square_id(5'd15), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[15]), 
          .in_tl(g3h2), 
          .in_midl(g2h2), 
          .in_bl(g1h2), 
          .in_midb(h1h2), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(h3h2), 
          .in_klt(f3h2), 
          .in_klb(b2h2), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(g3h2), 
          .in_ktr(0), 
          .in_kbl(g1h2), 
          .in_kbr(0)
          .out_tl(h2g3), 
          .out_midl(h2g2), 
          .out_bl(h2g1), 
          .out_midb(h2h1), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(h2h3), 
          .out_klt(h2f3), 
          .out_klb(h2b2), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(h2g3), 
          .out_ktr(), 
          .out_kbl(h2g1), 
          .out_kbr(), 
          .movebit(move_wires[15])

square a3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[16]), 
          .square_id(5'd16), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[16]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(a2a3), 
          .in_br(b2a3), 
          .in_midr(b3a3), 
          .in_tr(b4a3), 
          .in_midt(a4a3), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(g1a3), 
          .in_krt(c4a3), 
          .in_ktl(0), 
          .in_ktr(b4a3), 
          .in_kbl(0), 
          .in_kbr(b2a3)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(a3a2), 
          .out_br(a3b2), 
          .out_midr(a3b3), 
          .out_tr(a3b4), 
          .out_midt(a3a4), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(a3g1), 
          .out_krt(a3c4), 
          .out_ktl(), 
          .out_ktr(a3b4), 
          .out_kbl(), 
          .out_kbr(a3b2), 
          .movebit(move_wires[16])

square b3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[17]), 
          .square_id(5'd17), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[17]), 
          .in_tl(a4b3), 
          .in_midl(a3b3), 
          .in_bl(a2b3), 
          .in_midb(b2b3), 
          .in_br(c2b3), 
          .in_midr(c3b3), 
          .in_tr(c4b3), 
          .in_midt(b4b3), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(h1b3), 
          .in_krt(d4b3), 
          .in_ktl(a4b3), 
          .in_ktr(c4b3), 
          .in_kbl(a2b3), 
          .in_kbr(c2b3)
          .out_tl(b3a4), 
          .out_midl(b3a3), 
          .out_bl(b3a2), 
          .out_midb(b3b2), 
          .out_br(b3c2), 
          .out_midr(b3c3), 
          .out_tr(b3c4), 
          .out_midt(b3b4), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(b3h1), 
          .out_krt(b3d4), 
          .out_ktl(b3a4), 
          .out_ktr(b3c4), 
          .out_kbl(b3a2), 
          .out_kbr(b3c2), 
          .movebit(move_wires[17])

square c3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[18]), 
          .square_id(5'd18), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[18]), 
          .in_tl(b4c3), 
          .in_midl(b3c3), 
          .in_bl(b2c3), 
          .in_midb(c2c3), 
          .in_br(d2c3), 
          .in_midr(d3c3), 
          .in_tr(d4c3), 
          .in_midt(c4c3), 
          .in_klt(a4c3), 
          .in_klb(e2c3), 
          .in_krb(a2c3), 
          .in_krt(e4c3), 
          .in_ktl(b4c3), 
          .in_ktr(d4c3), 
          .in_kbl(b2c3), 
          .in_kbr(d2c3)
          .out_tl(c3b4), 
          .out_midl(c3b3), 
          .out_bl(c3b2), 
          .out_midb(c3c2), 
          .out_br(c3d2), 
          .out_midr(c3d3), 
          .out_tr(c3d4), 
          .out_midt(c3c4), 
          .out_klt(c3a4), 
          .out_klb(c3e2), 
          .out_krb(c3a2), 
          .out_krt(c3e4), 
          .out_ktl(c3b4), 
          .out_ktr(c3d4), 
          .out_kbl(c3b2), 
          .out_kbr(c3d2), 
          .movebit(move_wires[18])

square d3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[19]), 
          .square_id(5'd19), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[19]), 
          .in_tl(c4d3), 
          .in_midl(c3d3), 
          .in_bl(c2d3), 
          .in_midb(d2d3), 
          .in_br(e2d3), 
          .in_midr(e3d3), 
          .in_tr(e4d3), 
          .in_midt(d4d3), 
          .in_klt(b4d3), 
          .in_klb(f2d3), 
          .in_krb(b2d3), 
          .in_krt(f4d3), 
          .in_ktl(c4d3), 
          .in_ktr(e4d3), 
          .in_kbl(c2d3), 
          .in_kbr(e2d3)
          .out_tl(d3c4), 
          .out_midl(d3c3), 
          .out_bl(d3c2), 
          .out_midb(d3d2), 
          .out_br(d3e2), 
          .out_midr(d3e3), 
          .out_tr(d3e4), 
          .out_midt(d3d4), 
          .out_klt(d3b4), 
          .out_klb(d3f2), 
          .out_krb(d3b2), 
          .out_krt(d3f4), 
          .out_ktl(d3c4), 
          .out_ktr(d3e4), 
          .out_kbl(d3c2), 
          .out_kbr(d3e2), 
          .movebit(move_wires[19])

square e3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[20]), 
          .square_id(5'd20), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[20]), 
          .in_tl(d4e3), 
          .in_midl(d3e3), 
          .in_bl(d2e3), 
          .in_midb(e2e3), 
          .in_br(f2e3), 
          .in_midr(f3e3), 
          .in_tr(f4e3), 
          .in_midt(e4e3), 
          .in_klt(c4e3), 
          .in_klb(g2e3), 
          .in_krb(c2e3), 
          .in_krt(g4e3), 
          .in_ktl(d4e3), 
          .in_ktr(f4e3), 
          .in_kbl(d2e3), 
          .in_kbr(f2e3)
          .out_tl(e3d4), 
          .out_midl(e3d3), 
          .out_bl(e3d2), 
          .out_midb(e3e2), 
          .out_br(e3f2), 
          .out_midr(e3f3), 
          .out_tr(e3f4), 
          .out_midt(e3e4), 
          .out_klt(e3c4), 
          .out_klb(e3g2), 
          .out_krb(e3c2), 
          .out_krt(e3g4), 
          .out_ktl(e3d4), 
          .out_ktr(e3f4), 
          .out_kbl(e3d2), 
          .out_kbr(e3f2), 
          .movebit(move_wires[20])

square f3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[21]), 
          .square_id(5'd21), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[21]), 
          .in_tl(e4f3), 
          .in_midl(e3f3), 
          .in_bl(e2f3), 
          .in_midb(f2f3), 
          .in_br(g2f3), 
          .in_midr(g3f3), 
          .in_tr(g4f3), 
          .in_midt(f4f3), 
          .in_klt(d4f3), 
          .in_klb(h2f3), 
          .in_krb(d2f3), 
          .in_krt(h4f3), 
          .in_ktl(e4f3), 
          .in_ktr(g4f3), 
          .in_kbl(e2f3), 
          .in_kbr(g2f3)
          .out_tl(f3e4), 
          .out_midl(f3e3), 
          .out_bl(f3e2), 
          .out_midb(f3f2), 
          .out_br(f3g2), 
          .out_midr(f3g3), 
          .out_tr(f3g4), 
          .out_midt(f3f4), 
          .out_klt(f3d4), 
          .out_klb(f3h2), 
          .out_krb(f3d2), 
          .out_krt(f3h4), 
          .out_ktl(f3e4), 
          .out_ktr(f3g4), 
          .out_kbl(f3e2), 
          .out_kbr(f3g2), 
          .movebit(move_wires[21])

square g3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[22]), 
          .square_id(5'd22), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[22]), 
          .in_tl(f4g3), 
          .in_midl(f3g3), 
          .in_bl(f2g3), 
          .in_midb(g2g3), 
          .in_br(h2g3), 
          .in_midr(h3g3), 
          .in_tr(h4g3), 
          .in_midt(g4g3), 
          .in_klt(e4g3), 
          .in_klb(a3g3), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(f4g3), 
          .in_ktr(h4g3), 
          .in_kbl(f2g3), 
          .in_kbr(h2g3)
          .out_tl(g3f4), 
          .out_midl(g3f3), 
          .out_bl(g3f2), 
          .out_midb(g3g2), 
          .out_br(g3h2), 
          .out_midr(g3h3), 
          .out_tr(g3h4), 
          .out_midt(g3g4), 
          .out_klt(g3e4), 
          .out_klb(g3a3), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(g3f4), 
          .out_ktr(g3h4), 
          .out_kbl(g3f2), 
          .out_kbr(g3h2), 
          .movebit(move_wires[22])

square h3(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[23]), 
          .square_id(5'd23), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[23]), 
          .in_tl(g4h3), 
          .in_midl(g3h3), 
          .in_bl(g2h3), 
          .in_midb(h2h3), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(h4h3), 
          .in_klt(f4h3), 
          .in_klb(b3h3), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(g4h3), 
          .in_ktr(0), 
          .in_kbl(g2h3), 
          .in_kbr(0)
          .out_tl(h3g4), 
          .out_midl(h3g3), 
          .out_bl(h3g2), 
          .out_midb(h3h2), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(h3h4), 
          .out_klt(h3f4), 
          .out_klb(h3b3), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(h3g4), 
          .out_ktr(), 
          .out_kbl(h3g2), 
          .out_kbr(), 
          .movebit(move_wires[23])

square a4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[24]), 
          .square_id(5'd24), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[24]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(a3a4), 
          .in_br(b3a4), 
          .in_midr(b4a4), 
          .in_tr(b5a4), 
          .in_midt(a5a4), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(g2a4), 
          .in_krt(c5a4), 
          .in_ktl(0), 
          .in_ktr(b5a4), 
          .in_kbl(0), 
          .in_kbr(b3a4)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(a4a3), 
          .out_br(a4b3), 
          .out_midr(a4b4), 
          .out_tr(a4b5), 
          .out_midt(a4a5), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(a4g2), 
          .out_krt(a4c5), 
          .out_ktl(), 
          .out_ktr(a4b5), 
          .out_kbl(), 
          .out_kbr(a4b3), 
          .movebit(move_wires[24])

square b4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[25]), 
          .square_id(5'd25), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[25]), 
          .in_tl(a5b4), 
          .in_midl(a4b4), 
          .in_bl(a3b4), 
          .in_midb(b3b4), 
          .in_br(c3b4), 
          .in_midr(c4b4), 
          .in_tr(c5b4), 
          .in_midt(b5b4), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(h2b4), 
          .in_krt(d5b4), 
          .in_ktl(a5b4), 
          .in_ktr(c5b4), 
          .in_kbl(a3b4), 
          .in_kbr(c3b4)
          .out_tl(b4a5), 
          .out_midl(b4a4), 
          .out_bl(b4a3), 
          .out_midb(b4b3), 
          .out_br(b4c3), 
          .out_midr(b4c4), 
          .out_tr(b4c5), 
          .out_midt(b4b5), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(b4h2), 
          .out_krt(b4d5), 
          .out_ktl(b4a5), 
          .out_ktr(b4c5), 
          .out_kbl(b4a3), 
          .out_kbr(b4c3), 
          .movebit(move_wires[25])

square c4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[26]), 
          .square_id(5'd26), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[26]), 
          .in_tl(b5c4), 
          .in_midl(b4c4), 
          .in_bl(b3c4), 
          .in_midb(c3c4), 
          .in_br(d3c4), 
          .in_midr(d4c4), 
          .in_tr(d5c4), 
          .in_midt(c5c4), 
          .in_klt(a5c4), 
          .in_klb(e3c4), 
          .in_krb(a3c4), 
          .in_krt(e5c4), 
          .in_ktl(b5c4), 
          .in_ktr(d5c4), 
          .in_kbl(b3c4), 
          .in_kbr(d3c4)
          .out_tl(c4b5), 
          .out_midl(c4b4), 
          .out_bl(c4b3), 
          .out_midb(c4c3), 
          .out_br(c4d3), 
          .out_midr(c4d4), 
          .out_tr(c4d5), 
          .out_midt(c4c5), 
          .out_klt(c4a5), 
          .out_klb(c4e3), 
          .out_krb(c4a3), 
          .out_krt(c4e5), 
          .out_ktl(c4b5), 
          .out_ktr(c4d5), 
          .out_kbl(c4b3), 
          .out_kbr(c4d3), 
          .movebit(move_wires[26])

square d4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[27]), 
          .square_id(5'd27), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[27]), 
          .in_tl(c5d4), 
          .in_midl(c4d4), 
          .in_bl(c3d4), 
          .in_midb(d3d4), 
          .in_br(e3d4), 
          .in_midr(e4d4), 
          .in_tr(e5d4), 
          .in_midt(d5d4), 
          .in_klt(b5d4), 
          .in_klb(f3d4), 
          .in_krb(b3d4), 
          .in_krt(f5d4), 
          .in_ktl(c5d4), 
          .in_ktr(e5d4), 
          .in_kbl(c3d4), 
          .in_kbr(e3d4)
          .out_tl(d4c5), 
          .out_midl(d4c4), 
          .out_bl(d4c3), 
          .out_midb(d4d3), 
          .out_br(d4e3), 
          .out_midr(d4e4), 
          .out_tr(d4e5), 
          .out_midt(d4d5), 
          .out_klt(d4b5), 
          .out_klb(d4f3), 
          .out_krb(d4b3), 
          .out_krt(d4f5), 
          .out_ktl(d4c5), 
          .out_ktr(d4e5), 
          .out_kbl(d4c3), 
          .out_kbr(d4e3), 
          .movebit(move_wires[27])

square e4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[28]), 
          .square_id(5'd28), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[28]), 
          .in_tl(d5e4), 
          .in_midl(d4e4), 
          .in_bl(d3e4), 
          .in_midb(e3e4), 
          .in_br(f3e4), 
          .in_midr(f4e4), 
          .in_tr(f5e4), 
          .in_midt(e5e4), 
          .in_klt(c5e4), 
          .in_klb(g3e4), 
          .in_krb(c3e4), 
          .in_krt(g5e4), 
          .in_ktl(d5e4), 
          .in_ktr(f5e4), 
          .in_kbl(d3e4), 
          .in_kbr(f3e4)
          .out_tl(e4d5), 
          .out_midl(e4d4), 
          .out_bl(e4d3), 
          .out_midb(e4e3), 
          .out_br(e4f3), 
          .out_midr(e4f4), 
          .out_tr(e4f5), 
          .out_midt(e4e5), 
          .out_klt(e4c5), 
          .out_klb(e4g3), 
          .out_krb(e4c3), 
          .out_krt(e4g5), 
          .out_ktl(e4d5), 
          .out_ktr(e4f5), 
          .out_kbl(e4d3), 
          .out_kbr(e4f3), 
          .movebit(move_wires[28])

square f4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[29]), 
          .square_id(5'd29), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[29]), 
          .in_tl(e5f4), 
          .in_midl(e4f4), 
          .in_bl(e3f4), 
          .in_midb(f3f4), 
          .in_br(g3f4), 
          .in_midr(g4f4), 
          .in_tr(g5f4), 
          .in_midt(f5f4), 
          .in_klt(d5f4), 
          .in_klb(h3f4), 
          .in_krb(d3f4), 
          .in_krt(h5f4), 
          .in_ktl(e5f4), 
          .in_ktr(g5f4), 
          .in_kbl(e3f4), 
          .in_kbr(g3f4)
          .out_tl(f4e5), 
          .out_midl(f4e4), 
          .out_bl(f4e3), 
          .out_midb(f4f3), 
          .out_br(f4g3), 
          .out_midr(f4g4), 
          .out_tr(f4g5), 
          .out_midt(f4f5), 
          .out_klt(f4d5), 
          .out_klb(f4h3), 
          .out_krb(f4d3), 
          .out_krt(f4h5), 
          .out_ktl(f4e5), 
          .out_ktr(f4g5), 
          .out_kbl(f4e3), 
          .out_kbr(f4g3), 
          .movebit(move_wires[29])

square g4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[30]), 
          .square_id(5'd30), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[30]), 
          .in_tl(f5g4), 
          .in_midl(f4g4), 
          .in_bl(f3g4), 
          .in_midb(g3g4), 
          .in_br(h3g4), 
          .in_midr(h4g4), 
          .in_tr(h5g4), 
          .in_midt(g5g4), 
          .in_klt(e5g4), 
          .in_klb(a4g4), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(f5g4), 
          .in_ktr(h5g4), 
          .in_kbl(f3g4), 
          .in_kbr(h3g4)
          .out_tl(g4f5), 
          .out_midl(g4f4), 
          .out_bl(g4f3), 
          .out_midb(g4g3), 
          .out_br(g4h3), 
          .out_midr(g4h4), 
          .out_tr(g4h5), 
          .out_midt(g4g5), 
          .out_klt(g4e5), 
          .out_klb(g4a4), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(g4f5), 
          .out_ktr(g4h5), 
          .out_kbl(g4f3), 
          .out_kbr(g4h3), 
          .movebit(move_wires[30])

square h4(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[31]), 
          .square_id(5'd31), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[31]), 
          .in_tl(g5h4), 
          .in_midl(g4h4), 
          .in_bl(g3h4), 
          .in_midb(h3h4), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(h5h4), 
          .in_klt(f5h4), 
          .in_klb(b4h4), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(g5h4), 
          .in_ktr(0), 
          .in_kbl(g3h4), 
          .in_kbr(0)
          .out_tl(h4g5), 
          .out_midl(h4g4), 
          .out_bl(h4g3), 
          .out_midb(h4h3), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(h4h5), 
          .out_klt(h4f5), 
          .out_klb(h4b4), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(h4g5), 
          .out_ktr(), 
          .out_kbl(h4g3), 
          .out_kbr(), 
          .movebit(move_wires[31])

square a5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[32]), 
          .square_id(5'd32), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[32]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(a4a5), 
          .in_br(b4a5), 
          .in_midr(b5a5), 
          .in_tr(b6a5), 
          .in_midt(a6a5), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(g3a5), 
          .in_krt(c6a5), 
          .in_ktl(0), 
          .in_ktr(b6a5), 
          .in_kbl(0), 
          .in_kbr(b4a5)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(a5a4), 
          .out_br(a5b4), 
          .out_midr(a5b5), 
          .out_tr(a5b6), 
          .out_midt(a5a6), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(a5g3), 
          .out_krt(a5c6), 
          .out_ktl(), 
          .out_ktr(a5b6), 
          .out_kbl(), 
          .out_kbr(a5b4), 
          .movebit(move_wires[32])

square b5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[33]), 
          .square_id(5'd33), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[33]), 
          .in_tl(a6b5), 
          .in_midl(a5b5), 
          .in_bl(a4b5), 
          .in_midb(b4b5), 
          .in_br(c4b5), 
          .in_midr(c5b5), 
          .in_tr(c6b5), 
          .in_midt(b6b5), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(h3b5), 
          .in_krt(d6b5), 
          .in_ktl(a6b5), 
          .in_ktr(c6b5), 
          .in_kbl(a4b5), 
          .in_kbr(c4b5)
          .out_tl(b5a6), 
          .out_midl(b5a5), 
          .out_bl(b5a4), 
          .out_midb(b5b4), 
          .out_br(b5c4), 
          .out_midr(b5c5), 
          .out_tr(b5c6), 
          .out_midt(b5b6), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(b5h3), 
          .out_krt(b5d6), 
          .out_ktl(b5a6), 
          .out_ktr(b5c6), 
          .out_kbl(b5a4), 
          .out_kbr(b5c4), 
          .movebit(move_wires[33])

square c5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[34]), 
          .square_id(5'd34), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[34]), 
          .in_tl(b6c5), 
          .in_midl(b5c5), 
          .in_bl(b4c5), 
          .in_midb(c4c5), 
          .in_br(d4c5), 
          .in_midr(d5c5), 
          .in_tr(d6c5), 
          .in_midt(c6c5), 
          .in_klt(a6c5), 
          .in_klb(e4c5), 
          .in_krb(a4c5), 
          .in_krt(e6c5), 
          .in_ktl(b6c5), 
          .in_ktr(d6c5), 
          .in_kbl(b4c5), 
          .in_kbr(d4c5)
          .out_tl(c5b6), 
          .out_midl(c5b5), 
          .out_bl(c5b4), 
          .out_midb(c5c4), 
          .out_br(c5d4), 
          .out_midr(c5d5), 
          .out_tr(c5d6), 
          .out_midt(c5c6), 
          .out_klt(c5a6), 
          .out_klb(c5e4), 
          .out_krb(c5a4), 
          .out_krt(c5e6), 
          .out_ktl(c5b6), 
          .out_ktr(c5d6), 
          .out_kbl(c5b4), 
          .out_kbr(c5d4), 
          .movebit(move_wires[34])

square d5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[35]), 
          .square_id(5'd35), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[35]), 
          .in_tl(c6d5), 
          .in_midl(c5d5), 
          .in_bl(c4d5), 
          .in_midb(d4d5), 
          .in_br(e4d5), 
          .in_midr(e5d5), 
          .in_tr(e6d5), 
          .in_midt(d6d5), 
          .in_klt(b6d5), 
          .in_klb(f4d5), 
          .in_krb(b4d5), 
          .in_krt(f6d5), 
          .in_ktl(c6d5), 
          .in_ktr(e6d5), 
          .in_kbl(c4d5), 
          .in_kbr(e4d5)
          .out_tl(d5c6), 
          .out_midl(d5c5), 
          .out_bl(d5c4), 
          .out_midb(d5d4), 
          .out_br(d5e4), 
          .out_midr(d5e5), 
          .out_tr(d5e6), 
          .out_midt(d5d6), 
          .out_klt(d5b6), 
          .out_klb(d5f4), 
          .out_krb(d5b4), 
          .out_krt(d5f6), 
          .out_ktl(d5c6), 
          .out_ktr(d5e6), 
          .out_kbl(d5c4), 
          .out_kbr(d5e4), 
          .movebit(move_wires[35])

square e5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[36]), 
          .square_id(5'd36), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[36]), 
          .in_tl(d6e5), 
          .in_midl(d5e5), 
          .in_bl(d4e5), 
          .in_midb(e4e5), 
          .in_br(f4e5), 
          .in_midr(f5e5), 
          .in_tr(f6e5), 
          .in_midt(e6e5), 
          .in_klt(c6e5), 
          .in_klb(g4e5), 
          .in_krb(c4e5), 
          .in_krt(g6e5), 
          .in_ktl(d6e5), 
          .in_ktr(f6e5), 
          .in_kbl(d4e5), 
          .in_kbr(f4e5)
          .out_tl(e5d6), 
          .out_midl(e5d5), 
          .out_bl(e5d4), 
          .out_midb(e5e4), 
          .out_br(e5f4), 
          .out_midr(e5f5), 
          .out_tr(e5f6), 
          .out_midt(e5e6), 
          .out_klt(e5c6), 
          .out_klb(e5g4), 
          .out_krb(e5c4), 
          .out_krt(e5g6), 
          .out_ktl(e5d6), 
          .out_ktr(e5f6), 
          .out_kbl(e5d4), 
          .out_kbr(e5f4), 
          .movebit(move_wires[36])

square f5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[37]), 
          .square_id(5'd37), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[37]), 
          .in_tl(e6f5), 
          .in_midl(e5f5), 
          .in_bl(e4f5), 
          .in_midb(f4f5), 
          .in_br(g4f5), 
          .in_midr(g5f5), 
          .in_tr(g6f5), 
          .in_midt(f6f5), 
          .in_klt(d6f5), 
          .in_klb(h4f5), 
          .in_krb(d4f5), 
          .in_krt(h6f5), 
          .in_ktl(e6f5), 
          .in_ktr(g6f5), 
          .in_kbl(e4f5), 
          .in_kbr(g4f5)
          .out_tl(f5e6), 
          .out_midl(f5e5), 
          .out_bl(f5e4), 
          .out_midb(f5f4), 
          .out_br(f5g4), 
          .out_midr(f5g5), 
          .out_tr(f5g6), 
          .out_midt(f5f6), 
          .out_klt(f5d6), 
          .out_klb(f5h4), 
          .out_krb(f5d4), 
          .out_krt(f5h6), 
          .out_ktl(f5e6), 
          .out_ktr(f5g6), 
          .out_kbl(f5e4), 
          .out_kbr(f5g4), 
          .movebit(move_wires[37])

square g5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[38]), 
          .square_id(5'd38), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[38]), 
          .in_tl(f6g5), 
          .in_midl(f5g5), 
          .in_bl(f4g5), 
          .in_midb(g4g5), 
          .in_br(h4g5), 
          .in_midr(h5g5), 
          .in_tr(h6g5), 
          .in_midt(g6g5), 
          .in_klt(e6g5), 
          .in_klb(a5g5), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(f6g5), 
          .in_ktr(h6g5), 
          .in_kbl(f4g5), 
          .in_kbr(h4g5)
          .out_tl(g5f6), 
          .out_midl(g5f5), 
          .out_bl(g5f4), 
          .out_midb(g5g4), 
          .out_br(g5h4), 
          .out_midr(g5h5), 
          .out_tr(g5h6), 
          .out_midt(g5g6), 
          .out_klt(g5e6), 
          .out_klb(g5a5), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(g5f6), 
          .out_ktr(g5h6), 
          .out_kbl(g5f4), 
          .out_kbr(g5h4), 
          .movebit(move_wires[38])

square h5(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[39]), 
          .square_id(5'd39), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[39]), 
          .in_tl(g6h5), 
          .in_midl(g5h5), 
          .in_bl(g4h5), 
          .in_midb(h4h5), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(h6h5), 
          .in_klt(f6h5), 
          .in_klb(b5h5), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(g6h5), 
          .in_ktr(0), 
          .in_kbl(g4h5), 
          .in_kbr(0)
          .out_tl(h5g6), 
          .out_midl(h5g5), 
          .out_bl(h5g4), 
          .out_midb(h5h4), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(h5h6), 
          .out_klt(h5f6), 
          .out_klb(h5b5), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(h5g6), 
          .out_ktr(), 
          .out_kbl(h5g4), 
          .out_kbr(), 
          .movebit(move_wires[39])

square a6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[40]), 
          .square_id(5'd40), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[40]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(a5a6), 
          .in_br(b5a6), 
          .in_midr(b6a6), 
          .in_tr(b7a6), 
          .in_midt(a7a6), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(g4a6), 
          .in_krt(c7a6), 
          .in_ktl(0), 
          .in_ktr(b7a6), 
          .in_kbl(0), 
          .in_kbr(b5a6)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(a6a5), 
          .out_br(a6b5), 
          .out_midr(a6b6), 
          .out_tr(a6b7), 
          .out_midt(a6a7), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(a6g4), 
          .out_krt(a6c7), 
          .out_ktl(), 
          .out_ktr(a6b7), 
          .out_kbl(), 
          .out_kbr(a6b5), 
          .movebit(move_wires[40])

square b6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[41]), 
          .square_id(5'd41), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[41]), 
          .in_tl(a7b6), 
          .in_midl(a6b6), 
          .in_bl(a5b6), 
          .in_midb(b5b6), 
          .in_br(c5b6), 
          .in_midr(c6b6), 
          .in_tr(c7b6), 
          .in_midt(b7b6), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(h4b6), 
          .in_krt(d7b6), 
          .in_ktl(a7b6), 
          .in_ktr(c7b6), 
          .in_kbl(a5b6), 
          .in_kbr(c5b6)
          .out_tl(b6a7), 
          .out_midl(b6a6), 
          .out_bl(b6a5), 
          .out_midb(b6b5), 
          .out_br(b6c5), 
          .out_midr(b6c6), 
          .out_tr(b6c7), 
          .out_midt(b6b7), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(b6h4), 
          .out_krt(b6d7), 
          .out_ktl(b6a7), 
          .out_ktr(b6c7), 
          .out_kbl(b6a5), 
          .out_kbr(b6c5), 
          .movebit(move_wires[41])

square c6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[42]), 
          .square_id(5'd42), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[42]), 
          .in_tl(b7c6), 
          .in_midl(b6c6), 
          .in_bl(b5c6), 
          .in_midb(c5c6), 
          .in_br(d5c6), 
          .in_midr(d6c6), 
          .in_tr(d7c6), 
          .in_midt(c7c6), 
          .in_klt(a7c6), 
          .in_klb(e5c6), 
          .in_krb(a5c6), 
          .in_krt(e7c6), 
          .in_ktl(b7c6), 
          .in_ktr(d7c6), 
          .in_kbl(b5c6), 
          .in_kbr(d5c6)
          .out_tl(c6b7), 
          .out_midl(c6b6), 
          .out_bl(c6b5), 
          .out_midb(c6c5), 
          .out_br(c6d5), 
          .out_midr(c6d6), 
          .out_tr(c6d7), 
          .out_midt(c6c7), 
          .out_klt(c6a7), 
          .out_klb(c6e5), 
          .out_krb(c6a5), 
          .out_krt(c6e7), 
          .out_ktl(c6b7), 
          .out_ktr(c6d7), 
          .out_kbl(c6b5), 
          .out_kbr(c6d5), 
          .movebit(move_wires[42])

square d6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[43]), 
          .square_id(5'd43), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[43]), 
          .in_tl(c7d6), 
          .in_midl(c6d6), 
          .in_bl(c5d6), 
          .in_midb(d5d6), 
          .in_br(e5d6), 
          .in_midr(e6d6), 
          .in_tr(e7d6), 
          .in_midt(d7d6), 
          .in_klt(b7d6), 
          .in_klb(f5d6), 
          .in_krb(b5d6), 
          .in_krt(f7d6), 
          .in_ktl(c7d6), 
          .in_ktr(e7d6), 
          .in_kbl(c5d6), 
          .in_kbr(e5d6)
          .out_tl(d6c7), 
          .out_midl(d6c6), 
          .out_bl(d6c5), 
          .out_midb(d6d5), 
          .out_br(d6e5), 
          .out_midr(d6e6), 
          .out_tr(d6e7), 
          .out_midt(d6d7), 
          .out_klt(d6b7), 
          .out_klb(d6f5), 
          .out_krb(d6b5), 
          .out_krt(d6f7), 
          .out_ktl(d6c7), 
          .out_ktr(d6e7), 
          .out_kbl(d6c5), 
          .out_kbr(d6e5), 
          .movebit(move_wires[43])

square e6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[44]), 
          .square_id(5'd44), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[44]), 
          .in_tl(d7e6), 
          .in_midl(d6e6), 
          .in_bl(d5e6), 
          .in_midb(e5e6), 
          .in_br(f5e6), 
          .in_midr(f6e6), 
          .in_tr(f7e6), 
          .in_midt(e7e6), 
          .in_klt(c7e6), 
          .in_klb(g5e6), 
          .in_krb(c5e6), 
          .in_krt(g7e6), 
          .in_ktl(d7e6), 
          .in_ktr(f7e6), 
          .in_kbl(d5e6), 
          .in_kbr(f5e6)
          .out_tl(e6d7), 
          .out_midl(e6d6), 
          .out_bl(e6d5), 
          .out_midb(e6e5), 
          .out_br(e6f5), 
          .out_midr(e6f6), 
          .out_tr(e6f7), 
          .out_midt(e6e7), 
          .out_klt(e6c7), 
          .out_klb(e6g5), 
          .out_krb(e6c5), 
          .out_krt(e6g7), 
          .out_ktl(e6d7), 
          .out_ktr(e6f7), 
          .out_kbl(e6d5), 
          .out_kbr(e6f5), 
          .movebit(move_wires[44])

square f6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[45]), 
          .square_id(5'd45), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[45]), 
          .in_tl(e7f6), 
          .in_midl(e6f6), 
          .in_bl(e5f6), 
          .in_midb(f5f6), 
          .in_br(g5f6), 
          .in_midr(g6f6), 
          .in_tr(g7f6), 
          .in_midt(f7f6), 
          .in_klt(d7f6), 
          .in_klb(h5f6), 
          .in_krb(d5f6), 
          .in_krt(h7f6), 
          .in_ktl(e7f6), 
          .in_ktr(g7f6), 
          .in_kbl(e5f6), 
          .in_kbr(g5f6)
          .out_tl(f6e7), 
          .out_midl(f6e6), 
          .out_bl(f6e5), 
          .out_midb(f6f5), 
          .out_br(f6g5), 
          .out_midr(f6g6), 
          .out_tr(f6g7), 
          .out_midt(f6f7), 
          .out_klt(f6d7), 
          .out_klb(f6h5), 
          .out_krb(f6d5), 
          .out_krt(f6h7), 
          .out_ktl(f6e7), 
          .out_ktr(f6g7), 
          .out_kbl(f6e5), 
          .out_kbr(f6g5), 
          .movebit(move_wires[45])

square g6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[46]), 
          .square_id(5'd46), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[46]), 
          .in_tl(f7g6), 
          .in_midl(f6g6), 
          .in_bl(f5g6), 
          .in_midb(g5g6), 
          .in_br(h5g6), 
          .in_midr(h6g6), 
          .in_tr(h7g6), 
          .in_midt(g7g6), 
          .in_klt(e7g6), 
          .in_klb(a6g6), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(f7g6), 
          .in_ktr(h7g6), 
          .in_kbl(f5g6), 
          .in_kbr(h5g6)
          .out_tl(g6f7), 
          .out_midl(g6f6), 
          .out_bl(g6f5), 
          .out_midb(g6g5), 
          .out_br(g6h5), 
          .out_midr(g6h6), 
          .out_tr(g6h7), 
          .out_midt(g6g7), 
          .out_klt(g6e7), 
          .out_klb(g6a6), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(g6f7), 
          .out_ktr(g6h7), 
          .out_kbl(g6f5), 
          .out_kbr(g6h5), 
          .movebit(move_wires[46])

square h6(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[47]), 
          .square_id(5'd47), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[47]), 
          .in_tl(g7h6), 
          .in_midl(g6h6), 
          .in_bl(g5h6), 
          .in_midb(h5h6), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(h7h6), 
          .in_klt(f7h6), 
          .in_klb(b6h6), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(g7h6), 
          .in_ktr(0), 
          .in_kbl(g5h6), 
          .in_kbr(0)
          .out_tl(h6g7), 
          .out_midl(h6g6), 
          .out_bl(h6g5), 
          .out_midb(h6h5), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(h6h7), 
          .out_klt(h6f7), 
          .out_klb(h6b6), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(h6g7), 
          .out_ktr(), 
          .out_kbl(h6g5), 
          .out_kbr(), 
          .movebit(move_wires[47])

square a7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[48]), 
          .square_id(5'd48), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[48]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(a6a7), 
          .in_br(b6a7), 
          .in_midr(b7a7), 
          .in_tr(b8a7), 
          .in_midt(a8a7), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(g5a7), 
          .in_krt(c8a7), 
          .in_ktl(0), 
          .in_ktr(b8a7), 
          .in_kbl(0), 
          .in_kbr(b6a7)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(a7a6), 
          .out_br(a7b6), 
          .out_midr(a7b7), 
          .out_tr(a7b8), 
          .out_midt(a7a8), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(a7g5), 
          .out_krt(a7c8), 
          .out_ktl(), 
          .out_ktr(a7b8), 
          .out_kbl(), 
          .out_kbr(a7b6), 
          .movebit(move_wires[48])

square b7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[49]), 
          .square_id(5'd49), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[49]), 
          .in_tl(a8b7), 
          .in_midl(a7b7), 
          .in_bl(a6b7), 
          .in_midb(b6b7), 
          .in_br(c6b7), 
          .in_midr(c7b7), 
          .in_tr(c8b7), 
          .in_midt(b8b7), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(h5b7), 
          .in_krt(d8b7), 
          .in_ktl(a8b7), 
          .in_ktr(c8b7), 
          .in_kbl(a6b7), 
          .in_kbr(c6b7)
          .out_tl(b7a8), 
          .out_midl(b7a7), 
          .out_bl(b7a6), 
          .out_midb(b7b6), 
          .out_br(b7c6), 
          .out_midr(b7c7), 
          .out_tr(b7c8), 
          .out_midt(b7b8), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(b7h5), 
          .out_krt(b7d8), 
          .out_ktl(b7a8), 
          .out_ktr(b7c8), 
          .out_kbl(b7a6), 
          .out_kbr(b7c6), 
          .movebit(move_wires[49])

square c7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[50]), 
          .square_id(5'd50), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[50]), 
          .in_tl(b8c7), 
          .in_midl(b7c7), 
          .in_bl(b6c7), 
          .in_midb(c6c7), 
          .in_br(d6c7), 
          .in_midr(d7c7), 
          .in_tr(d8c7), 
          .in_midt(c8c7), 
          .in_klt(a8c7), 
          .in_klb(e6c7), 
          .in_krb(a6c7), 
          .in_krt(e8c7), 
          .in_ktl(b8c7), 
          .in_ktr(d8c7), 
          .in_kbl(b6c7), 
          .in_kbr(d6c7)
          .out_tl(c7b8), 
          .out_midl(c7b7), 
          .out_bl(c7b6), 
          .out_midb(c7c6), 
          .out_br(c7d6), 
          .out_midr(c7d7), 
          .out_tr(c7d8), 
          .out_midt(c7c8), 
          .out_klt(c7a8), 
          .out_klb(c7e6), 
          .out_krb(c7a6), 
          .out_krt(c7e8), 
          .out_ktl(c7b8), 
          .out_ktr(c7d8), 
          .out_kbl(c7b6), 
          .out_kbr(c7d6), 
          .movebit(move_wires[50])

square d7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[51]), 
          .square_id(5'd51), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[51]), 
          .in_tl(c8d7), 
          .in_midl(c7d7), 
          .in_bl(c6d7), 
          .in_midb(d6d7), 
          .in_br(e6d7), 
          .in_midr(e7d7), 
          .in_tr(e8d7), 
          .in_midt(d8d7), 
          .in_klt(b8d7), 
          .in_klb(f6d7), 
          .in_krb(b6d7), 
          .in_krt(f8d7), 
          .in_ktl(c8d7), 
          .in_ktr(e8d7), 
          .in_kbl(c6d7), 
          .in_kbr(e6d7)
          .out_tl(d7c8), 
          .out_midl(d7c7), 
          .out_bl(d7c6), 
          .out_midb(d7d6), 
          .out_br(d7e6), 
          .out_midr(d7e7), 
          .out_tr(d7e8), 
          .out_midt(d7d8), 
          .out_klt(d7b8), 
          .out_klb(d7f6), 
          .out_krb(d7b6), 
          .out_krt(d7f8), 
          .out_ktl(d7c8), 
          .out_ktr(d7e8), 
          .out_kbl(d7c6), 
          .out_kbr(d7e6), 
          .movebit(move_wires[51])

square e7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[52]), 
          .square_id(5'd52), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[52]), 
          .in_tl(d8e7), 
          .in_midl(d7e7), 
          .in_bl(d6e7), 
          .in_midb(e6e7), 
          .in_br(f6e7), 
          .in_midr(f7e7), 
          .in_tr(f8e7), 
          .in_midt(e8e7), 
          .in_klt(c8e7), 
          .in_klb(g6e7), 
          .in_krb(c6e7), 
          .in_krt(g8e7), 
          .in_ktl(d8e7), 
          .in_ktr(f8e7), 
          .in_kbl(d6e7), 
          .in_kbr(f6e7)
          .out_tl(e7d8), 
          .out_midl(e7d7), 
          .out_bl(e7d6), 
          .out_midb(e7e6), 
          .out_br(e7f6), 
          .out_midr(e7f7), 
          .out_tr(e7f8), 
          .out_midt(e7e8), 
          .out_klt(e7c8), 
          .out_klb(e7g6), 
          .out_krb(e7c6), 
          .out_krt(e7g8), 
          .out_ktl(e7d8), 
          .out_ktr(e7f8), 
          .out_kbl(e7d6), 
          .out_kbr(e7f6), 
          .movebit(move_wires[52])

square f7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[53]), 
          .square_id(5'd53), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[53]), 
          .in_tl(e8f7), 
          .in_midl(e7f7), 
          .in_bl(e6f7), 
          .in_midb(f6f7), 
          .in_br(g6f7), 
          .in_midr(g7f7), 
          .in_tr(g8f7), 
          .in_midt(f8f7), 
          .in_klt(d8f7), 
          .in_klb(h6f7), 
          .in_krb(d6f7), 
          .in_krt(h8f7), 
          .in_ktl(e8f7), 
          .in_ktr(g8f7), 
          .in_kbl(e6f7), 
          .in_kbr(g6f7)
          .out_tl(f7e8), 
          .out_midl(f7e7), 
          .out_bl(f7e6), 
          .out_midb(f7f6), 
          .out_br(f7g6), 
          .out_midr(f7g7), 
          .out_tr(f7g8), 
          .out_midt(f7f8), 
          .out_klt(f7d8), 
          .out_klb(f7h6), 
          .out_krb(f7d6), 
          .out_krt(f7h8), 
          .out_ktl(f7e8), 
          .out_ktr(f7g8), 
          .out_kbl(f7e6), 
          .out_kbr(f7g6), 
          .movebit(move_wires[53])

square g7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[54]), 
          .square_id(5'd54), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[54]), 
          .in_tl(f8g7), 
          .in_midl(f7g7), 
          .in_bl(f6g7), 
          .in_midb(g6g7), 
          .in_br(h6g7), 
          .in_midr(h7g7), 
          .in_tr(h8g7), 
          .in_midt(g8g7), 
          .in_klt(e8g7), 
          .in_klb(a7g7), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(f8g7), 
          .in_ktr(h8g7), 
          .in_kbl(f6g7), 
          .in_kbr(h6g7)
          .out_tl(g7f8), 
          .out_midl(g7f7), 
          .out_bl(g7f6), 
          .out_midb(g7g6), 
          .out_br(g7h6), 
          .out_midr(g7h7), 
          .out_tr(g7h8), 
          .out_midt(g7g8), 
          .out_klt(g7e8), 
          .out_klb(g7a7), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(g7f8), 
          .out_ktr(g7h8), 
          .out_kbl(g7f6), 
          .out_kbr(g7h6), 
          .movebit(move_wires[54])

square h7(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[55]), 
          .square_id(5'd55), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[55]), 
          .in_tl(g8h7), 
          .in_midl(g7h7), 
          .in_bl(g6h7), 
          .in_midb(h6h7), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(h8h7), 
          .in_klt(f8h7), 
          .in_klb(b7h7), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(g8h7), 
          .in_ktr(0), 
          .in_kbl(g6h7), 
          .in_kbr(0)
          .out_tl(h7g8), 
          .out_midl(h7g7), 
          .out_bl(h7g6), 
          .out_midb(h7h6), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(h7h8), 
          .out_klt(h7f8), 
          .out_klb(h7b7), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(h7g8), 
          .out_ktr(), 
          .out_kbl(h7g6), 
          .out_kbr(), 
          .movebit(move_wires[55])

square a8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[56]), 
          .square_id(5'd56), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[56]), 
          .in_tl(0), 
          .in_midl(0), 
          .in_bl(0), 
          .in_midb(a7a8), 
          .in_br(b7a8), 
          .in_midr(b8a8), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(g6a8), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(0), 
          .in_kbr(b7a8)
          .out_tl(), 
          .out_midl(), 
          .out_bl(), 
          .out_midb(a8a7), 
          .out_br(a8b7), 
          .out_midr(a8b8), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(a8g6), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(), 
          .out_kbr(a8b7), 
          .movebit(move_wires[56])

square b8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[57]), 
          .square_id(5'd57), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[57]), 
          .in_tl(0), 
          .in_midl(a8b8), 
          .in_bl(a7b8), 
          .in_midb(b7b8), 
          .in_br(c7b8), 
          .in_midr(c8b8), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(0), 
          .in_krb(h6b8), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(a7b8), 
          .in_kbr(c7b8)
          .out_tl(), 
          .out_midl(b8a8), 
          .out_bl(b8a7), 
          .out_midb(b8b7), 
          .out_br(b8c7), 
          .out_midr(b8c8), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(), 
          .out_krb(b8h6), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(b8a7), 
          .out_kbr(b8c7), 
          .movebit(move_wires[57])

square c8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[58]), 
          .square_id(5'd58), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[58]), 
          .in_tl(0), 
          .in_midl(b8c8), 
          .in_bl(b7c8), 
          .in_midb(c7c8), 
          .in_br(d7c8), 
          .in_midr(d8c8), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(e7c8), 
          .in_krb(a7c8), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(b7c8), 
          .in_kbr(d7c8)
          .out_tl(), 
          .out_midl(c8b8), 
          .out_bl(c8b7), 
          .out_midb(c8c7), 
          .out_br(c8d7), 
          .out_midr(c8d8), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(c8e7), 
          .out_krb(c8a7), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(c8b7), 
          .out_kbr(c8d7), 
          .movebit(move_wires[58])

square d8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[59]), 
          .square_id(5'd59), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[59]), 
          .in_tl(0), 
          .in_midl(c8d8), 
          .in_bl(c7d8), 
          .in_midb(d7d8), 
          .in_br(e7d8), 
          .in_midr(e8d8), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(f7d8), 
          .in_krb(b7d8), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(c7d8), 
          .in_kbr(e7d8)
          .out_tl(), 
          .out_midl(d8c8), 
          .out_bl(d8c7), 
          .out_midb(d8d7), 
          .out_br(d8e7), 
          .out_midr(d8e8), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(d8f7), 
          .out_krb(d8b7), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(d8c7), 
          .out_kbr(d8e7), 
          .movebit(move_wires[59])

square e8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[60]), 
          .square_id(5'd60), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[60]), 
          .in_tl(0), 
          .in_midl(d8e8), 
          .in_bl(d7e8), 
          .in_midb(e7e8), 
          .in_br(f7e8), 
          .in_midr(f8e8), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(g7e8), 
          .in_krb(c7e8), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(d7e8), 
          .in_kbr(f7e8)
          .out_tl(), 
          .out_midl(e8d8), 
          .out_bl(e8d7), 
          .out_midb(e8e7), 
          .out_br(e8f7), 
          .out_midr(e8f8), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(e8g7), 
          .out_krb(e8c7), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(e8d7), 
          .out_kbr(e8f7), 
          .movebit(move_wires[60])

square f8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[61]), 
          .square_id(5'd61), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[61]), 
          .in_tl(0), 
          .in_midl(e8f8), 
          .in_bl(e7f8), 
          .in_midb(f7f8), 
          .in_br(g7f8), 
          .in_midr(g8f8), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(h7f8), 
          .in_krb(d7f8), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(e7f8), 
          .in_kbr(g7f8)
          .out_tl(), 
          .out_midl(f8e8), 
          .out_bl(f8e7), 
          .out_midb(f8f7), 
          .out_br(f8g7), 
          .out_midr(f8g8), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(f8h7), 
          .out_krb(f8d7), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(f8e7), 
          .out_kbr(f8g7), 
          .movebit(move_wires[61])

square g8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[62]), 
          .square_id(5'd62), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[62]), 
          .in_tl(0), 
          .in_midl(f8g8), 
          .in_bl(f7g8), 
          .in_midb(g7g8), 
          .in_br(h7g8), 
          .in_midr(h8g8), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(a8g8), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(f7g8), 
          .in_kbr(h7g8)
          .out_tl(), 
          .out_midl(g8f8), 
          .out_bl(g8f7), 
          .out_midb(g8g7), 
          .out_br(g8h7), 
          .out_midr(g8h8), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(g8a8), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(g8f7), 
          .out_kbr(g8h7), 
          .movebit(move_wires[62])

square h8(
          .clock(clk), 
          .init(init), 
          .occupied(is_occupied_wires[63]), 
          .square_id(5'd63), 
          .piece_type_calc(piece_type_calc), 
          .occupying_piece(occupying_piece_type_wires[63]), 
          .in_tl(0), 
          .in_midl(g8h8), 
          .in_bl(g7h8), 
          .in_midb(h7h8), 
          .in_br(0), 
          .in_midr(0), 
          .in_tr(0), 
          .in_midt(0), 
          .in_klt(0), 
          .in_klb(b8h8), 
          .in_krb(0), 
          .in_krt(0), 
          .in_ktl(0), 
          .in_ktr(0), 
          .in_kbl(g7h8), 
          .in_kbr(0)
          .out_tl(), 
          .out_midl(h8g8), 
          .out_bl(h8g7), 
          .out_midb(h8h7), 
          .out_br(), 
          .out_midr(), 
          .out_tr(), 
          .out_midt(), 
          .out_klt(), 
          .out_klb(h8b8), 
          .out_krb(), 
          .out_krt(), 
          .out_ktl(), 
          .out_ktr(), 
          .out_kbl(h8g7), 
          .out_kbr(), 
          .movebit(move_wires[63])



endmodule
