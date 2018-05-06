module square( 
input clock, 
input init, 		     //init wire
input occupied, 	     //whether this square is occupied or not
input [5:0] square_id,       //number of the square, should be assigned a const when instantiated in top level module
input [5:0] square_calc,     //number of the square we want to calc moves for, parameter received from software
input [3:0] piece_type_calc, //piecetype we are calculating for
input [1:0] occupying_piece_color, //color of piece on the square, true for white
input in_tl, in_midl, in_bl, in_midb, in_br, in_midr, in_tr, in_midt, in_klt, in_klb, in_krb, in_krt, in_ktl, in_ktr, in_kbl, in_kbr, //in directions
output reg out_tl, out_midl, out_bl, out_midb, out_br, out_midr, out_tr, out_midt, out_klt, out_klb, out_krb, out_krt, out_ktl, out_ktr, out_kbl, out_kbr,  //out directions
output reg movebit);

reg [3:0] piece_on_square;
reg occed;

/*These values come from the enum statement in bitBoard.h*/
localparam BROOK = 4'd0;
localparam BBISHOP = 4'd1;
localparam BKNIGHT = 4'd2;
localparam BQUEEN = 4'd3;
localparam BKING = 4'd4;
localparam BPAWN = 4'd5;
localparam WROOK = 4'd6;
localparam WBISHOP = 4'd7;
localparam WKNIGHT = 4'd8;
localparam WQUEEN = 4'd9;
localparam WKING = 4'd10;
localparam WPAWN = 4'd11;

/*Sequential block for internal registers*/
always @(posedge clock)
begin
	if (init) begin
		piece_on_square <= occupying_piece;
		occed <= occupied;
	end
	else begin
		piece_on_square <= piece_on_square;
		occed <= occed;
	end
//////////////////////ADD STATE FOR DONE? no, this is an upper level  function
end

/*Combinational logic*/
always @(*)
begin
	if(init) begin
		movebit = 0;
		out_tl = 0;	//top left to bottom right (reverse these comments...)
		out_midt = 0;	//top to bottom
		out_tr = 0;	//top right to bottom left
		out_midr = 0;	//right to left
		out_br = 0;	//bottom right to top left
		out_midb = 0;	//bottom to top
		out_bl = 0;	//bottom left to top right
		out_midl = 0;	//left to right	
		out_klt = 0;
		out_klb = 0;
		out_krb = 0;
		out_krt = 0;
		out_ktl = 0;
		out_ktr = 0;
		out_kbl = 0;
		out_kbr = 0; 
	end

	/*Logic for the square we are calculating for*/
	else if (square_id == square_calc) begin
		if (piece_type_calc == BPAWN) begin
			movebit = 0;
			out_tl = 0;	//top left to bottom right (reverse these comments...)
			out_midt = 0;	//top to bottom
			out_tr = 0;	//top right to bottom left
			out_midr = 0;	//right to left
			out_br = 1;	//bottom right to top left
			out_midb = 1;	//bottom to top
			out_bl = 1;	//bottom left to top right
			out_midl = 0;	//left to right	
			out_klt = 0;
			out_klb = 0;
			out_krb = 0;
			out_krt = 0;
			out_ktl = 0;
			out_ktr = 0;
			out_kbl = 0;
			out_kbr = 0;  
		end

		else if (piece_type_calc == WPAWN) begin
			movebit = 0;
			out_tl = 1;	//top left to bottom right (reverse these comments...)
			out_midt = 1;	//top to bottom
			out_tr = 1;	//top right to bottom left
			out_midr = 0;	//right to left
			out_br = 0;	//bottom right to top left
			out_midb = 0;	//bottom to top
			out_bl = 0;	//bottom left to top right
			out_midl = 0;	//left to right	
			out_klt = 0;
			out_klb = 0;
			out_krb = 0;
			out_krt = 0;
			out_ktl = 0;
			out_ktr = 0;
			out_kbl = 0;
			out_kbr = 0; 
		end

		else if ((piece_type_calc == BKNIGHT) | (piece_type_calc == WKNIGHT)) begin
			movebit = 0;
			out_tl = 0;	//top left to bottom right (reverse these comments...)
			out_midt = 0;	//top to bottom
			out_tr = 0;	//top right to bottom left
			out_midr = 0;	//right to left
			out_br = 0;	//bottom right to top left
			out_midb = 0;	//bottom to top
			out_bl = 0;	//bottom left to top right
			out_midl = 0;	//left to right	
			out_klt = 1;
			out_klb = 1;
			out_krb = 1;
			out_krt = 1;
			out_ktl = 1;
			out_ktr = 1;
			out_kbl = 1;
			out_kbr = 1; 
		end

		else if ((piece_type_calc == BBISHOP) | (piece_type_calc == WBISHOP)) begin
			movebit = 0;
			out_tl = 1;	//top left to bottom right (reverse these comments...)
			out_midt = 0;	//top to bottom
			out_tr = 1;	//top right to bottom left
			out_midr = 0;	//right to left
			out_br = 1;	//bottom right to top left
			out_midb = 0;	//bottom to top
			out_bl = 1;	//bottom left to top right
			out_midl = 0;	//left to right	
			out_klt = 0;
			out_klb = 0;
			out_krb = 0;
			out_krt = 0;
			out_ktl = 0;
			out_ktr = 0;
			out_kbl = 0;
			out_kbr = 0; 
		end

		else if ((piece_type_calc == BROOK) | (piece_type_calc == WROOK)) begin
			movebit = 0;
			out_tl = 0;	//top left to bottom right (reverse these comments...)
			out_midt = 1;	//top to bottom
			out_tr = 0;	//top right to bottom left
			out_midr = 1;	//right to left
			out_br = 0;	//bottom right to top left
			out_midb = 1;	//bottom to top
			out_bl = 0;	//bottom left to top right
			out_midl = 1;	//left to right	
			out_klt = 0;
			out_klb = 0;
			out_krb = 0;
			out_krt = 0;
			out_ktl = 0;
			out_ktr = 0;
			out_kbl = 0;
			out_kbr = 0; 
		end

		else if ((piece_type_calc == BQUEEN) | (piece_type_calc == WQUEEN) | (piece_type_calc == BKING) | (piece_type_calc == BKING)) begin
			movebit = 0;
			out_tl = 1;	//top left to bottom right (reverse these comments...)
			out_midt = 1;	//top to bottom
			out_tr = 1;	//top right to bottom left
			out_midr = 1;	//right to left
			out_br = 1;	//bottom right to top left
			out_midb = 1;	//bottom to top
			out_bl = 1;	//bottom left to top right
			out_midl = 1;	//left to right	
			out_klt = 0;
			out_klb = 0;
			out_krb = 0;
			out_krt = 0;
			out_ktl = 0;
			out_ktr = 0;
			out_kbl = 0;
			out_kbr = 0; 
		end

	end

	/*Propogation logic*/
	else begin 
		if(~occed) begin //If not occupied
			//square is not occupied, if we get an input this square is a legal move.
			movebit = in_tl | in_midl | in_bl | in_midb | in_br | in_midr | in_tr | 
				  in_midt | in_klt | in_klb | in_krb | in_krt | in_ktl | in_ktr | in_kbl | in_kbr;
			
			//piece is not a pawn or king, propagate signal
			if (~((piece_type_calc == BPAWN) | (piece_type_calc == WPAWN)) | ~((piece_type_calc == BKING) | (piece_type_calc == WKING))) begin 
				out_tl = in_br;		//top left to bottom right (reverse these comments...)
				out_midt = in_midb;	//top to bottom
				out_tr = in_bl;		//top right to bottom left
				out_midr = in_midl;	//right to left
				out_br = in_tl;		//bottom right to top left
				out_midb = in_midt;	//bottom to top
				out_bl = in_tr;		//bottom left to top right
				out_midl = in_midr;	//left to right
			end

			//is piece king?
			else if ((piece_type_calc == BKING) | (piece_type_calc == WKING)) begin 
				
				//king can only move one square, so dont pass signals
				out_tl = 0;	//top left to bottom right (reverse these comments...)
				out_midt = 0;	//top to bottom
				out_tr = 0;	//top right to bottom left
				out_midr = 0;	//right to left
				out_br = 0;	//bottom right to top left
				out_midb = 0;	//bottom to top
				out_bl = 0;	//bottom left to top right
				out_midl = 0;	//left to right	

			end

			//piece is a pawn
			else begin
				//pawn can only move one square, so dont pass signals
				//(We add the second square move for appropriate pawns in the top level module)
				out_tl = 0;	//top left to bottom right (reverse these comments...)
				out_midt = 0;	//top to bottom
				out_tr = 0;	//top right to bottom left
				out_midr = 0;	//right to left
				out_br = 0;	//bottom right to top left
				out_midb = 0;	//bottom to top
				out_bl = 0;	//bottom left to top right
				out_midl = 0;	//left to right	
			end
			
		end


		else begin //square is occupied
			/*pieces are same color*/
			if (((piece_type_calc < 6) & ~occupying_piece_color) | ((piece_type_calc > 6) & occupying_piece_color)) begin
				movebit = 0;
				out_tl = 0;	//top left to bottom right (reverse these comments...)
				out_midt = 0;	//top to bottom
				out_tr = 0;	//top right to bottom left
				out_midr = 0;	//right to left
				out_br = 0;	//bottom right to top left
				out_midb = 0;	//bottom to top
				out_bl = 0;	//bottom left to top right
				out_midl = 0;	//left to right	
				out_klt = 0;
				out_klb = 0;
				out_krb = 0;
				out_krt = 0;
				out_ktl = 0;
				out_ktr = 0;
				out_kbl = 0;
				out_kbr = 0; 
			end
			/*pieces are different color*/
			else begin
				movebit = 1;
				out_tl = 0;	//top left to bottom right (reverse these comments...)
				out_midt = 0;	//top to bottom
				out_tr = 0;	//top right to bottom left
				out_midr = 0;	//right to left
				out_br = 0;	//bottom right to top left
				out_midb = 0;	//bottom to top
				out_bl = 0;	//bottom left to top right
				out_midl = 0;	//left to right	
				out_klt = 0;
				out_klb = 0;
				out_krb = 0;
				out_krt = 0;
				out_ktl = 0;
				out_ktr = 0;
				out_kbl = 0;
				out_kbr = 0; 
			end
		end 
		out_klt = 0;//knights always only get one move per turn
		out_klb = 0;
		out_krb = 0;
		out_krt = 0;
		out_ktl = 0;
		out_ktr = 0;
		out_kbl = 0;
		out_kbr = 0;  
	end
end

endmodule
