/*This file holds all the information pertaining to the bitboard representaion
 *and move calculations (legal moves, positions, etc)*/

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bitBoard.h"
#include "fpga.h"

uint64_t HFILE;
uint64_t AFILE;
uint64_t RANK1;
uint64_t RANK8;
uint64_t rookMove;
//uint64_t bepBoard = 0; //enPassant board
//uint64_t wepBoard = 0;

uint64_t checkBoard;
//int black_check;
//int white_check;
int black_stale;
int white_stale;

/*castling rights*/
/*
int wqCastle = 1;
int wkCastle = 1;
int bqCastle = 1;
int bkCastle = 1;
*/

/*helper functions*/
uint64_t find_moved_black_pawns(uint64_t bPawns);
uint64_t black_pawn_attacks(Bitboard* b, int piece_square);
uint64_t find_moved_white_pawns(uint64_t wPawns);
uint64_t white_pawn_attacks(Bitboard* b, int piece_square);
uint64_t same_file(Bitboard* b, unsigned int piece_type);
uint64_t same_rank(Bitboard* b, unsigned int piece_type);
uint64_t bRookMoves(Bitboard *b,int piece_type, uint64_t direction, int i, int piece_square);
uint64_t wRookMoves(Bitboard *b,int piece_type, uint64_t direction, int i, int piece_square);
uint64_t bishop_moves(Bitboard* b, unsigned int piece_type, int piece_square);
uint64_t get_board(Bitboard *b_ptr, int piece_type);//return the piece's bitboard
uint64_t black_moves(Bitboard *b);
uint64_t white_moves(Bitboard *b);
uint64_t all_moves(Bitboard *b);
//int black_check(Bitboard *b);
//int white_check(Bitboard *b);
int black_mate(Bitboard *b);
int white_mate(Bitboard *b);
//int black_stale(Bitboard *b);
//int white_stale(Bitboard *b);

void bitBoard_print(uint64_t b, int row){
	if (row == 8) {
	return;
	}
	else {
		bitBoard_print(b >> 8, row+1);
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("%d ", (int)(b & 0x0000001));
		b >>= 1;
		printf("\n");
		return;
		}
} //Function that prints the board


void printChessboard(Bitboard *b){

	char board[8][8];

	for(int row = 0; row < 8; row++)
		for(int col = 0; col < 8; col++)
			board[row][col] = '#'; //Initialize all squares to '#'

	loop(b->wPawns, board, WPAWN);
	loop(b->wRooks, board, WROOK);
	loop(b->wKnights, board, WKNIGHT);
	loop(b->wBishops, board, WBISHOP);
	loop(b->wQueen, board, WQUEEN);
	loop(b->wKing, board, WKING);

	loop(b->bPawns, board, BPAWN);
	loop(b->bRooks, board, BROOK);
	loop(b->bKnights, board, BKNIGHT);
	loop(b->bBishops, board, BBISHOP);
	loop(b->bQueen, board, BQUEEN);
	loop(b->bKing, board, BKING);

	printf("\n");

	for(int row = 0; row < 8; row++){
		for(int col = 0; col < 8; col++){
			printf(" %c", (char)board[row][col]);
		}

		printf("\n");
	}
} //Print Chess Pieces


void loop(uint64_t b, char board[8][8], unsigned int piece_type){

	char piece;

	switch(piece_type){
	case WPAWN:
		piece = 'P';
	break;

	case WROOK:
		piece = 'R';
	break;

	case WKNIGHT:
		piece = 'N';
	break;

	case WBISHOP:
		piece = 'B';
	break;

	case WQUEEN:
		piece = 'Q';
	break;

	case WKING:
		piece = 'K';
	break;

	case BPAWN:
		piece = 'p';
	break;

	case BROOK:
		piece = 'r';
	break;

	case BKNIGHT:
		piece = 'n';
	break;

	case BBISHOP:
		piece = 'b';
	break;

	case BQUEEN:
		piece = 'q';
	break;

	case BKING:
		piece = 'k';
	break;
	}

	for(int row = 7; row >= 0; row--){
		for(int col = 0; col <= 7; col++){
			if ((b & 1) == 1){
				board[row][col] = piece;
				b>>=1;
			}
			else
				b>>=1;
		}
	}
} //Assign Letters to squares on the board


/*gets the legal moves for a piece. Pass the bitboard corresponding the piece*/
uint64_t getLegalMoves(Bitboard *board, unsigned int piece_type, int piece_square)
{
	static uint64_t moves;
	moves = 0;
	static uint64_t b;
	b = 0;//this was added to simplify square specificity
	//static int i ;
	//i = 0;


	/*TODO: set mem buf with appropriate data*/

	/*0b11111101 since second bit is done bit*/
	static uint8_t done_mask = 0xfd;
	/*clear buffer*/
	memset((void *)mem_buf, 0, sizeof(fpga_mem));

	mem_buf->command_field = 1;
	mem_buf->piece_type = piece_type;
	mem_buf->piece_square = piece_square;
	mem_buf->occupying_piece_color = allWhite(board);
	mem_buf->is_occupied_wires = allWhite(board) | allBlack(board);
	memcpy((void *)mem_ptr, (void *)mem_buf, sizeof(fpga_mem));
	*(uint8_t *)mem_ptr = 0;//start calculating legal Moves

	/*poll sdram for done signal*/
	while (!(*((uint8_t*)mem_ptr) & done_mask)) {

	}

	/*FPGA is finished, get the results*/
	memcpy((void *)mem_buf, (void *)mem_ptr, sizeof(fpga_mem));
	moves = mem_buf->move_bits;

	switch (piece_type){
		case BPAWN:
		//moves is initialized to one square in front or'ed with two squares
		//as long as the second square is not being blocked be a white
		//piece residing on the first square.
		b = board->bPawns & squares[piece_square];
		moves =  (b >> 8 & ~allPieces(board)) | (b >> 16 & ~allPieces(board)>>8);
		//check which pawns have moved and fix the board
		moves &= ~(find_moved_black_pawns(b) >> 16);//TODO: fix this
		//now check for collisions with other pieces
		// fpga takes care of this moves &= ~allPieces(board);
		//now calculate attacks and add them to moves.
		// FPGA should do thismoves |= black_pawn_attacks(board,piece_square);
		break;

		case WPAWN:
		//philosphy here is same as black pawn but for the opposite side
		//of the board.
		//b = board->wPawns & squares[piece_square];
		//fpga moves = (b << 8 & ~allPieces(board)) | (b << 16 & ~allPieces(board)<<8);
		moves &= ~(find_moved_white_pawns(b) << 16);
		//fpga moves &= ~allPieces(board);
		//fpga moves |= white_pawn_attacks(board,piece_square);
		break;

		case BROOK:
		//b = board->bRooks & squares[piece_square];
		//fire a ray from each rook in every direction
		/*while(b) {
			i = __builtin_ffsll(b) - 1;
			//set moves to the right
			rookMove = bRookMoves(board, BROOK,HFILE, i, piece_square);
			moves |= rookMove;

			//set moves to the left
			rookMove = bRookMoves(board, BROOK,AFILE, i, piece_square);
			moves |= rookMove;

			//set moves down
			rookMove = bRookMoves(board, BROOK,RANK1, i, piece_square);
			moves |= rookMove;

			//set moves up
			rookMove = bRookMoves(board, BROOK,RANK8, i, piece_square);
			moves |= rookMove;
			subtract the rook positions from the moves*/
	/*		if (moves) {
				moves &= ~b;
			}
			b &= ~squares[i];
		}
		break;

		case WROOK:
		b = board->wRooks & squares[piece_square];
		while(b) {
			i = __builtin_ffsll(b) - 1;
			//set moves to the right
			rookMove = wRookMoves(board, WROOK, HFILE, i, piece_square);
			moves |= rookMove;

			//set moves to the left
			rookMove = wRookMoves(board, WROOK, AFILE, i, piece_square);
			moves |= rookMove;

			//set moves down
			rookMove = wRookMoves(board, WROOK,RANK1, i, piece_square);
			moves |= rookMove;

			//set moves up
			rookMove = wRookMoves(board, WROOK,RANK8, i, piece_square);
			moves |= rookMove;

			subtract the rook positions from the moves*/
	/*		if (moves) {
				moves &= ~b;
			}
			b &= ~squares[i];
		}
		break;

		case BBISHOP:
		moves = bishop_moves(board,BBISHOP,piece_square);

		break;

		case WBISHOP:
		moves = bishop_moves(board,WBISHOP,piece_square);
		break;

		case BKNIGHT:
			b = board->bKnights & squares[piece_square];
			//Moves for the Black Knight
			moves = (((b & ~(0xff03030303030303)) << 6) & ~allBlack(board)) |
			(((b & ~(0xffc0c0c0c0c0c0c0)) << 10) & ~allBlack(board)) |
			(((b & ~(0xc0c0c0c0c0c0c0ff)) >> 6) & ~allBlack(board)) |
			(((b & ~(0x3030303030303ff)) >> 10) & ~allBlack(board)) |
			(((b & ~(0xffff010101010101)) << 15 ) & ~allBlack(board)) |
			(((b & ~(0xffff808080808080)) << 17) & ~allBlack(board)) |
			(((b & ~(0x808080808080ffff)) >> 15) & ~allBlack(board)) |
			(((b & ~(0x10101010101ffff)) >> 17) & ~allBlack(board));
		break;

		case WKNIGHT:
			b = board->wKnights & squares[piece_square];
			//Moves for the White Knight
			moves = (((b & ~(0xff03030303030303)) << 6) & ~allWhite(board)) |
			(((b & ~(0xffc0c0c0c0c0c0c0)) << 10) & ~allWhite(board)) |
			(((b & ~(0xc0c0c0c0c0c0c0ff)) >> 6) & ~allWhite(board)) |
			(((b & ~(0x3030303030303ff)) >> 10) & ~allWhite(board)) |
			(((b & ~(0xffff010101010101)) << 15 ) & ~allWhite(board)) |
			(((b & ~(0xffff808080808080)) << 17) & ~allWhite(board)) |
			(((b & ~(0x808080808080ffff)) >> 15) & ~allWhite(board)) |
			(((b & ~(0x10101010101ffff)) >> 17) & ~allWhite(board));
		break;

		case BQUEEN:
		b = board->bQueen & squares[piece_square];
		moves = bishop_moves(board, BQUEEN, piece_square);
		while(b) {
			i = __builtin_ffsll(b) - 1;
			//set moves to the right
			rookMove = bRookMoves(board, BQUEEN,HFILE, i, piece_square);
			moves |= rookMove;

			//set moves to the left
			rookMove = bRookMoves(board, BQUEEN,AFILE, i, piece_square);
			moves |= rookMove;

			//set moves down
			rookMove = bRookMoves(board, BQUEEN,RANK1, i, piece_square);
			moves |= rookMove;

			//set moves up
			rookMove = bRookMoves(board, BQUEEN,RANK8, i, piece_square);
			moves |= rookMove;
			subtract the rook positions from the moves*/
	/*		if (moves) {
				moves &= ~b;
			}
			b &= ~squares[i];
		}
		break;

		case WQUEEN:
		b = board->wQueen & squares[piece_square];
		moves = bishop_moves(board, WQUEEN, piece_square);
		while(b) {
			i = __builtin_ffsll(b) - 1;
			//set moves to the right
			rookMove = wRookMoves(board, WQUEEN,HFILE, i, piece_square);
			moves |= rookMove;

			//set moves to the left
			rookMove = wRookMoves(board, WQUEEN,AFILE, i, piece_square);
			moves |= rookMove;

			//set moves down
			rookMove = wRookMoves(board, WQUEEN,RANK1, i, piece_square);
			moves |= rookMove;

			//set moves up
			rookMove = wRookMoves(board, WQUEEN,RANK8, i, piece_square);
			moves |= rookMove;
			subtract the rook positions from the moves*/
	/*		if (moves) {
				moves &= ~b;
			}
			b &= ~squares[i];
		}
		break;*/

		case BKING:

		//move up, down, right, left, or diagonal by 1 square, but not beyond the edges
	//fpga	moves = (board->bKing & ~HFILE) << 1 | (board->bKing & ~AFILE) <<7 | board->bKing << 8 | (board->bKing & ~HFILE) << 9 |
		//	(board->bKing & ~AFILE) >> 1 | (board->bKing & ~HFILE) >>7 | board->bKing >>8 | (board->bKing & ~AFILE) >>9;
		/*can we castle??*/
		if(board->black_check == 0){
			if(board->bqCastle == 1){
				if( (((board->bKing>>1) & allPieces(board))== 0) && (((board->bKing>>2) & allPieces(board)) == 0) && (((board->bKing>>3) & allPieces(board)) == 0) ){
				//space between bKing and bqRook is empty
					if( (((board->bKing>>1) & white_moves(board))== 0) && (((board->bKing>>2) & white_moves(board)) == 0) && (((board->bKing>>3) & white_moves(board)) == 0) ){
						//space between bKing and bqRook is not in check: Black can castle Queenside
						moves |= board->bKing>>2;
					}
				}
			}

			if(board->bkCastle == 1){
				if( (( (board->bKing<<1) & allPieces(board) )== 0) && (((board->bKing<<2) & allPieces(board))== 0) ){
				//space between bKing and bkRook is empty
					if( (( (board->bKing<<1) & white_moves(board) )== 0) && (((board->bKing<<2) & white_moves(board))== 0) ){
						//space between bKing and bkRook is not in check: Black can castle Kingside
						moves |= board->bKing<<2;
					}
				}
			}
		}
		//don't move where there's another black piece
	//fpga	moves &= ~allBlack(board);
		//TODO: account for check

		break;
		case WKING:
		//move up, down, right, left, or diagonal by 1 square, but not beyond the edges
	//fpga	moves = (board->wKing & ~HFILE) << 1 | (board->wKing & ~AFILE) <<7 | board->wKing << 8 | (board->wKing & ~HFILE) << 9 |
		//	(board->wKing & ~AFILE) >> 1 | (board->wKing & ~HFILE) >>7 | board->wKing >>8 | (board->wKing & ~AFILE) >>9;
		/*can we castle??*/
		if(board->white_check == 0){
			if(board->wqCastle == 1){
				if( (((board->wKing>>1) & allPieces(board)) == 0) && (((board->wKing>>2) & allPieces(board)) == 0) && (((board->wKing>>3) & allPieces(board)) == 0) ){
				//space between wKing and wqRook is empty
					if( (((board->wKing>>1) & black_moves(board)) == 0) && (((board->wKing>>2) & black_moves(board)) == 0) && (((board->wKing>>3) & black_moves(board)) == 0) ){
						//space between wKing and wqRook is not in check: White can castle Queenside
						moves |= board->wKing>>2;
					}
				}
			}
			if(board->wkCastle == 1){
				if( (((board->wKing<<1) & allPieces(board)) == 0) && (((board->wKing<<2) & allPieces(board)) == 0) ){
				//space between wKing and wkRook is empty
					if( (((board->wKing<<1) & black_moves(board)) == 0) && (((board->wKing<<2) & black_moves(board)) == 0) ){
						//space between wKing and wkRook is not in check: White can castle Kingside
						moves |= board->wKing<<2;
					}
				}
			}
		}
		//don't move where there's another white piece
	//fpga	moves &= ~allWhite(board);

		break;
		default: return -1;
	}


	return moves;
}

/*updates the bitboard upon move*/
void update(Bitboard * b_ptr, char * move)
{
	int from_file;
	int from_rank;
	int to_file;
	int to_rank;
	uint64_t source_square;
	uint64_t dest_square;
	char * rookMove;
	move[4] = '\0';
	/*if castling, move the rook first*/
	//if(wqCastle == 1){
		if( (move[0] == 'e') && (move[1] == '1') && (move[2] == 'c') && (move[3] == '1') ){
			rookMove = "a1d1";
			from_file = (int)rookMove[0] - 97;
			from_rank = (int)rookMove[1] - 49;
			to_file = (int)rookMove[2] - 97;
			to_rank = (int)rookMove[3] - 49;
			source_square = squares[(from_rank * 8) + from_file];
			dest_square = squares[(to_rank * 8) + to_file];
			square_move(b_ptr, source_square, dest_square);
		}
	//}
	//if(wkCastle == 1){
		if( (move[0] == 'e') && (move[1] == '1') && (move[2] == 'g') && (move[3] == '1') ){
			rookMove = "h1f1";
			from_file = (int)rookMove[0] - 97;
			from_rank = (int)rookMove[1] - 49;
			to_file = (int)rookMove[2] - 97;
			to_rank = (int)rookMove[3] - 49;
			source_square = squares[(from_rank * 8) + from_file];
			dest_square = squares[(to_rank * 8) + to_file];
			square_move(b_ptr, source_square, dest_square);
		}
	//}
	//if(bqCastle == 1){
		if( (move[0] == 'e') && (move[1] == '8') && (move[2] == 'c') && (move[3] == '8') ){
			rookMove = "a8d8";
			from_file = (int)rookMove[0] - 97;
			from_rank = (int)rookMove[1] - 49;
			to_file = (int)rookMove[2] - 97;
			to_rank = (int)rookMove[3] - 49;
			source_square = squares[(from_rank * 8) + from_file];
			dest_square = squares[(to_rank * 8) + to_file];
			square_move(b_ptr, source_square, dest_square);
		}
	//}
	//if(bkCastle == 1){
		if( (move[0] == 'e') && (move[1] == '8') && (move[2] == 'g') && (move[3] == '8') ){
			rookMove = "h8f8";
			from_file = (int)rookMove[0] - 97;
			from_rank = (int)rookMove[1] - 49;
			to_file = (int)rookMove[2] - 97;
			to_rank = (int)rookMove[3] - 49;
			source_square = squares[(from_rank * 8) + from_file];
			dest_square = squares[(to_rank * 8) + to_file];
			square_move(b_ptr, source_square, dest_square);
		}
	//}

	/*commands are given: "e5e6" so the below lines convert the two parts of
	 *the command to squares.*/
	from_file = (int)move[0] - 97;
	from_rank = (int)move[1] - 49;
	to_file = (int)move[2] - 97;
	to_rank = (int)move[3] - 49;
	source_square = squares[(from_rank * 8) + from_file];
	dest_square = squares[(to_rank * 8) + to_file];
	square_move(b_ptr, source_square, dest_square);

	//if a pawn moves to the last row: promote it
	if( (move[1] == '2') && (move[3] == '1') ){
		if(dest_square & b_ptr->bPawns){
		//a black pawn made it to white's first row; make it a queen
			b_ptr->bPawns &= ~(dest_square);
			b_ptr->bQueen |= (dest_square);
		}
	} else if( (move[1] == '7') && (move[3] == '8') ){
		if(dest_square & b_ptr->wPawns){
		//a white pawn made it to black's first row; make it a queen
			b_ptr->wPawns &= ~(dest_square);
			b_ptr->wQueen |= (dest_square);
		}
	}

	//if a pawn was taken en passant: get rid of it
	if(dest_square & b_ptr->wPawns){
		//printf("white pawn is moving\n");
		if(dest_square & b_ptr->bepBoard){
			//TODO: and b_ptr with squares(bepBoard>>8) = 0??? use a temp bitboard?
			//b_ptr->wPawns &= ~source_square
			//a white pawn is taking a black pawn en passant
			//printf("b en passant\n");
			b_ptr->bPawns &= ~(b_ptr->bepBoard>>8);
		}
	} else if(dest_square & b_ptr->bPawns){
		//printf("black pawn is moving\n");
		if(dest_square & b_ptr->wepBoard){
			//TODO
			//a black pawn is taking a white pawn en passant
			//printf("w en passant\n");
			b_ptr->wPawns &= ~(b_ptr->wepBoard<<8);
		}
	}

	/*see if en passant should apply on the next move*/
	if( (move[1] == '7') && (move[3] == '5') && ( dest_square & b_ptr->bPawns) ){
	//dest_square contains a black pawn which moved forward 2 spaces
		//enPassant board contains the spot behind that pawn
		//printf("black2\n");
		b_ptr->bepBoard = dest_square<<8;
		b_ptr->wepBoard = 0;
	} else if( (move[1] == '2') && (move[3] == '4') && (dest_square & b_ptr->wPawns) ){
	//dest_square contains a white pawn which moved forward 2 spaces
		//en Passant board contains the spot behind that pawn
		//printf("white2\n");
		b_ptr->bepBoard = 0;
		b_ptr->wepBoard = dest_square>>8;
	} else{
		b_ptr->bepBoard = 0;
		b_ptr->wepBoard = 0;
	}


	/*update castling rights*/
	if (move[0] == 'e'){
		//white king has moved
		if(move[1] == '1'){
			b_ptr->wqCastle = 0;
			b_ptr->wkCastle = 0;
		//black king has moved
		} else if(move[1] == '8'){
			b_ptr->bqCastle = 0;
			b_ptr->bkCastle = 0;
		}
	} else if(move[0] == 'a'){
		//white queenside rook has moved
		if(move[1] == '1'){
			b_ptr->wqCastle = 0;
		//black queenside rook has moved
		} else if(move[1] == '8'){
			b_ptr->bqCastle = 0;
		}
	} else if(move[0] == 'h'){
		if(move[1] == '1'){
		//white kingside rook has moved
			b_ptr->wkCastle = 0;
		} else if(move[1] == '8'){
		//black kingside rook has moved
			b_ptr->bkCastle = 0;
		}
	}
	if(move[2] == 'a'){
		if(move[3] == '1'){
		//white queenside rook has been taken, or already moved
			b_ptr->wqCastle = 0;
		} else if(move[3] == '8'){
		//black queenside rook has been taken, or already moved
			b_ptr->bqCastle = 0;
		}
	} else if(move[2] == 'h'){
		if(move[3] == '1'){
		//white kingside rook has been taken, or already moved
			b_ptr->wkCastle = 0;
		} else if(move[3] == '8'){
		//black kingside rook has been taken, or already moved
			b_ptr->bkCastle = 0;
		}
	}

	/*is either side in check?*/
	if((black_moves(b_ptr)) & (b_ptr->wKing)){
		b_ptr->white_check = 1;
	} else{
		b_ptr->white_check = 0;
	}
	if((white_moves(b_ptr)) & (b_ptr->bKing)){
		b_ptr->black_check = 1;
	} else{
		b_ptr->black_check = 0;
	}

	return;



}

void take_black(Bitboard *b_ptr)
{
	b_ptr->bPawns &= ~allWhite(b_ptr);
	b_ptr->bRooks &= ~allWhite(b_ptr);
	b_ptr->bKnights &= ~allWhite(b_ptr);
	b_ptr->bBishops &= ~allWhite(b_ptr);
	b_ptr->bQueen &= ~allWhite(b_ptr);
	b_ptr->bKing &= ~allWhite(b_ptr);
}

void take_white(Bitboard *b_ptr)
{
	b_ptr->wPawns &= ~allBlack(b_ptr);
	b_ptr->wRooks &= ~allBlack(b_ptr);
	b_ptr->wKnights &= ~allBlack(b_ptr);
	b_ptr->wBishops &= ~allBlack(b_ptr);
	b_ptr->wQueen &= ~allBlack(b_ptr);
	b_ptr->wKing &= ~allBlack(b_ptr);

}

void square_move(Bitboard *b_ptr, uint64_t source_square, uint64_t dest_square)
{
	if (source_square & allWhite(b_ptr)) {
		if (source_square & b_ptr->wPawns) {
			b_ptr->wPawns &= ~source_square;
			b_ptr->wPawns |= dest_square;
		} else if (source_square & b_ptr->wRooks) {
			b_ptr->wRooks &= ~source_square;
			b_ptr->wRooks |= dest_square;
		} else if (source_square & b_ptr->wBishops) {
			b_ptr->wBishops &= ~source_square;
			b_ptr->wBishops |= dest_square;
		} else if (source_square & b_ptr->wKing) {
			b_ptr->wKing &= ~source_square;
			b_ptr->wKing |= dest_square;
		} else if (source_square & b_ptr->wQueen) {
			b_ptr->wQueen &= ~source_square;
			b_ptr->wQueen |= dest_square;
		} else if (source_square & b_ptr->wKnights) {
			b_ptr->wKnights &= ~source_square;
			b_ptr->wKnights |= dest_square;
		}
		take_black(b_ptr);
	} else {//it's a black piece
		if (source_square & b_ptr->bPawns) {
			b_ptr->bPawns &= ~source_square;
			b_ptr->bPawns |= dest_square;
		} else if (source_square & b_ptr->bRooks) {
			b_ptr->bRooks &= ~source_square;
			b_ptr->bRooks |= dest_square;
		} else if (source_square & b_ptr->bBishops) {
			b_ptr->bBishops &= ~source_square;
			b_ptr->bBishops |= dest_square;
		} else if (source_square & b_ptr->bKing) {
			b_ptr->bKing &= ~source_square;
			b_ptr->bKing |= dest_square;
		} else if (source_square & b_ptr->bQueen) {
			b_ptr->bQueen &= ~source_square;
			b_ptr->bQueen |= dest_square;
		} else if (source_square & b_ptr->bKnights) {
			b_ptr->bKnights &= ~source_square;
			b_ptr->bKnights |= dest_square;
		}
		take_white(b_ptr);
	}
	//printf("board\n");
	//printChessboard(b_ptr);
	return;
}


void init(struct Bitboard* b){

	//Bit 0 (the least significant bit) represents square A1, Bit 1 = B1 and Bit 63 = H8.
	//If this bit is set to 1, it means a piece of the specify type is located on that square,
	//0 means it is not on that square.

	b->wPawns = 0x000000000000FF00;
	b->wRooks = 0x0000000000000081;
	b->wKnights = 0x0000000000000042;
	b->wBishops = 0x0000000000000024;
	b->wQueen = 0x0000000000000008;
	b->wKing = 0x0000000000000010;

	b->bPawns = 0x00FF000000000000;
	b->bRooks = 0x8100000000000000;
	b->bKnights = 0x4200000000000000;
	b->bBishops = 0x2400000000000000;
	b->bQueen = 0x0800000000000000;
	b->bKing = 0x1000000000000000;

	b->wqCastle = 1;
	b->wkCastle = 1;
	b->bqCastle = 1;
	b->bkCastle = 1;
	b->wepBoard = 0;
	b->bepBoard = 0;
	HFILE =      squares[h8] | squares[h7] | squares[h6] | squares[h5] |\
		     squares[h4] | squares[h3] | squares[h2] | squares[h1];
	AFILE =      squares[a1] | squares[a2] | squares[a3] | squares[a4] |\
	             squares[a5] | squares[a6] | squares[a7] | squares[a8];
	RANK1 =      squares[a1] | squares[b1] | squares[c1] | squares[d1] |\
		     squares[e1] | squares[f1] | squares[g1] | squares[h1];
	RANK8 =      squares[a8] | squares[b8] | squares[c8] | squares[d8] |\
		     squares[e8] | squares[f8] | squares[g8] | squares[h8];

	b->white_check = 0;
	b->black_check = 0;
} //Initialize bitboard

/*Returns a bitboard of all white pieces*/
uint64_t allWhite(Bitboard *b)
{
	 return b->wPawns | b->wRooks | b->wKnights | b->wBishops | b->wQueen | b->wKing;
}
/*Returns a bitboard of all black pieces*/
uint64_t allBlack(Bitboard *b)
{
	return b->bPawns | b->bRooks | b->bKnights | b->bBishops | b->bQueen | b->bKing;
}
/*Returns a bitboard of all pieces*/
uint64_t allPieces(Bitboard *b)
{
	 return (allWhite(b) | allBlack(b));
}

uint64_t find_moved_black_pawns(uint64_t bPawns)
{
	return bPawns & ~(squares[48] | squares[49] | squares[50] | squares[51] | squares[52] | \
										squares[53] | squares[54] | squares[55]);
}


uint64_t black_pawn_attacks(Bitboard* b, int piece_square)
{
	uint64_t attacks = 0;


	uint64_t diag = (((b->bPawns & squares[piece_square] & ~HFILE) >> 7) & ~allBlack(b)) | (((b->bPawns & squares[piece_square] & ~AFILE) >> 9) & ~allBlack(b));
	attacks = (diag & allWhite(b)) | (diag & b->wepBoard);


	return attacks;
}

uint64_t find_moved_white_pawns(uint64_t wPawns)
{
	return wPawns & ~(squares[8] | squares[9] | squares[10] | squares[11] | squares[12] | \
		          squares[13] | squares[14] | squares[15]);
}
uint64_t white_pawn_attacks(Bitboard* b, int piece_square)
{
	uint64_t attacks = 0;
	/*NOTE:there may be a bug here if a pawn is on the edge of the board but not sure*/

	uint64_t diag = (((b->wPawns & squares[piece_square] & ~AFILE) << 7) & ~allWhite(b)) | ((((b->wPawns & squares[piece_square] & ~HFILE))<< 9) & ~allWhite(b));
	attacks = (diag & allBlack(b)) | (diag & b->bepBoard);

	return attacks;
}
/*return a bitboard with all squares on the same diagonals as the piece_type*/
uint64_t bishop_moves(Bitboard* b, unsigned int piece_type, int piece_square)
{
	uint64_t diag = 0;
	uint64_t piece_board = get_board(b, piece_type) & squares[piece_square];
	uint64_t r7,r9,l7,l9;//one board to shift left 7, right 9, etc. for diagonals
	//create bitboard for edge files
	uint64_t edge_files = HFILE | AFILE;
	int j = 0;
	while (piece_board) {
		j = __builtin_ffsll(piece_board) - 1;
		if (squares[piece_square] & HFILE) {
			l9 = 0;
			r7 = 0;
		} else {
			l9 = squares[j];
			r7 = squares[j];
		}
		if (squares[piece_square] & AFILE) {
			l7 = 0;
			r9 = 0;
		} else {
			r9 = squares[j];
			l7 = squares[j];
		}
		//generate diagonals

		for(int i = 0; i < 8; i++) {
			r7 >>= 7;
			r9 >>= 9;
			l7 <<= 7;
			l9 <<= 9;

			diag |= r7 | r9 | l7  | l9 ;
			 switch (piece_type) {
				 case BBISHOP:
				 case BQUEEN:
				 if(r7 & allWhite(b)) {
					 r7 = 0;//it can take the white piece but can't move further
				 } else if (r7 & allBlack(b)) {
					 diag -= r7;//it can move only to the square before the black piece
					 r7 = 0;//move no further
				 }
				 if(r9 & allWhite(b)) {
					 r9 = 0;
				 } else if (r9 & allBlack(b)) {
					 diag -= r9;
					 r9 = 0;
				 }
				 if(l7 & allWhite(b)) {
					 l7 = 0;
				 } else if (l7 & allBlack(b)) {
					 diag -= l7;
					 l7 = 0;
				 }
				 if(l9 & allWhite(b)) {
					 l9 = 0;
				 } else if (l9 & allBlack(b)) {
					 diag -= l9;
					 l9 = 0;
				 }
				 case WBISHOP:
				 case WQUEEN:
				 if(r7 & allBlack(b)) {
					 r7 = 0;
				 } else if (r7 & allWhite(b)) {
					 diag -= r7;
					 r7 = 0;
				 }
				 if(r9 & allBlack(b)) {
					 r9 = 0;
				 } else if (r9 & allWhite(b)) {
					 diag -= r9;
					 r9 = 0;
				 }
				 if(l7 & allBlack(b)) {
					 l7 = 0;
				 } else if (l7 & allWhite(b)) {
					 diag -= l7;
					 l7 = 0;
				 }
				 if(l9 & allBlack(b)) {
					 l9 = 0;
				 } else if (l9 & allWhite(b)) {
					 diag -= l9;
					 l9 = 0;
				 }
				 break;
			 }
			//if a representation is about to loop around, clear that one.
			r7 &= ~edge_files;
			r9 &= ~edge_files;
			l9 &= ~edge_files;
			l7 &= ~edge_files;

		}
		piece_board &= ~squares[j];
	}

	return diag;
}
/*return a bitboard with all squares on the same rank as the piece_type*/
uint64_t same_rank(Bitboard* b, unsigned int piece_type)
{
	uint64_t rank = 0;
	uint64_t piece_board = get_board(b, piece_type);

	uint64_t mask = 0xff;
	for (int i = 0; i < 8 ; i+=1)  {
		if (mask & piece_board) {
			rank += mask;
		}
		mask <<= 8;
	}

	return rank;
}
/*return a bitboard showing all moves a black rook can make*/
uint64_t bRookMoves(Bitboard *b, int piece_type, uint64_t direction, int i, int piece_square)
{
	//uint64_t dir = direction;
	uint64_t piece_board = get_board(b, piece_type) & squares[piece_square];
	uint64_t newMove = 0;
	int a = 0;
	if(direction == HFILE){
		a = 1;
	} else if (direction == AFILE){
		a = -1;
	} else if (direction == RANK1){
		a = -8;
	} else if (direction == RANK8){
		a = 8;
	}
	int j=i;
	for (; (squares[j] & ~direction); j+=a) {
		if (squares[j] & allWhite(b)) {
			newMove |= squares[j];
			break;
		} else if (squares[j] & (allBlack(b)-piece_board)) {
			break;
		} else {
			newMove |= squares[j];
		}
	}
	if(squares[j] & direction) {
		newMove |= squares[j] & ~allBlack(b);
	}
	return newMove;
}

/*return a bitboard showing all moves a white rook can make*/
uint64_t wRookMoves(Bitboard *b, int piece_type,uint64_t direction, int i, int piece_square)
{
	//uint64_t dir = direction;

	uint64_t piece_board = get_board(b, piece_type) & squares[piece_square];
	uint64_t newMove = 0;
	int a = 0;
	if(direction == HFILE){
		a = 1;
	} else if (direction == AFILE){
		a = -1;
	} else if (direction == RANK1){
		a = -8;
	} else if (direction == RANK8){
		a = 8;
	}
	int j = i;
	for (; (squares[j] & ~direction); j+=a) {
		if (squares[j] & allBlack(b)) {
			newMove |= squares[j];
			break;
		} else if (squares[j] & (allWhite(b)-piece_board)) {
			break;
		} else {
			newMove |= squares[j];
		}
	}
	if(squares[j] & direction) {
		newMove |= squares[j] & ~allWhite(b);
	}
	return newMove;
}

/*return a bitboard with all squares on the same file as the piece_type*/
uint64_t same_file(Bitboard* b, unsigned int piece_type)
{

	uint64_t file = 0;
	uint64_t piece_board = get_board(b, piece_type);
	for (int i = 8; i <=64; i+=8) {
		file += piece_board >> i | piece_board << i;
	}

	return file;
}

/*return a board containing all legal moves the black pieces can make*/
uint64_t black_moves(Bitboard *b)
{
	uint64_t bm = 0;
	for(int i = 0; i < 64; i++){
		bm |= getLegalMoves(b, BBISHOP,i) | getLegalMoves(b, BROOK,i) | getLegalMoves(b, BKNIGHT,i) | getLegalMoves(b, BPAWN,i) |
			getLegalMoves(b, BKING,i) | getLegalMoves(b, BQUEEN,i);
	}
	return bm;
}

/*return a board containing all legal moves the white pieces can make*/
uint64_t white_moves(Bitboard *b)
{
	uint64_t wm = 0;
	for(int i = 0; i < 64; i++){
		wm |= getLegalMoves(b, WBISHOP,i) | getLegalMoves(b, WROOK,i) | getLegalMoves(b, WKNIGHT,i) | getLegalMoves(b, WPAWN,i) |
			getLegalMoves(b, WKING,i) | getLegalMoves(b, WQUEEN,i);
	}
	return wm;
}

/*return a board containing the legal moves all pieces can make*/
uint64_t all_moves(Bitboard *b)
{
	uint64_t am = 0;
	am = black_moves(b) | white_moves(b);
	return am;
}


/*indicate whether the Black King is in checkmate*/
int black_mate(Bitboard *b)
{
	Bitboard temp;
	copy_board(*b, &temp);
	if(b->black_check == 0){
		return 0;
	} else{//TODO: update this
		return 1;
	}
}

/*indicate whether the White King is in checkmate*/
int white_mate(Bitboard *b)
{
	Bitboard temp;
	copy_board(*b, &temp);
	if(b->white_check == 0){
		return 0;
	} else{//TODO: update this
		return 1;
	}
}

/*indicate whether black is in stalemate
int black_stale(Bitboard *b)
{
	if((black_moves(b) == 0) && (black_check == 0)){
		return 1;
	} else{
		return 0;
	}
}
indicate whether white is in stalemate
int white_stale(Bitboard *b)
{
	if((white_moves(b) == 0) && (white_mate(b) == 0)){
		return 1;
	} else{
		return 0;
	}
}
*/
/*return the requested bitboard*/
uint64_t get_board(Bitboard *b_ptr, int piece_type)
{
	uint64_t piece_board = 0;
	switch (piece_type) {
		case BPAWN: piece_board = b_ptr->bPawns;
		break;

		case WPAWN: piece_board = b_ptr->wPawns;
		break;

		case BROOK: piece_board = b_ptr->bRooks;
		break;

		case BBISHOP: piece_board = b_ptr->bBishops;
		break;

		case BKNIGHT: piece_board = b_ptr->bKnights;
		break;

		case BQUEEN: piece_board = b_ptr->bQueen;
		break;

		case BKING: piece_board = b_ptr->bKing;
		break;

		case WROOK: piece_board = b_ptr->wRooks;
		break;

		case WBISHOP: piece_board = b_ptr->wBishops;
		break;

		case WKNIGHT: piece_board = b_ptr->wKnights;
		break;

		case WQUEEN: piece_board = b_ptr->wQueen;
		break;

		case WKING: piece_board = b_ptr->wKing;
		default: break;

	}
	return piece_board;
}

void copy_board(const Bitboard source, Bitboard * dest)
{
	dest->wPawns = source.wPawns;
	dest->wRooks = source.wRooks;
	dest->wKnights = source.wKnights;
	dest->wBishops = source.wBishops;
	dest->wQueen = source.wQueen;
	dest->wKing = source.wKing;

	dest->bPawns = source.bPawns;
	dest->bRooks = source.bRooks;
	dest->bKnights = source.bKnights;
	dest->bBishops = source.bBishops;
	dest->bQueen = source.bQueen;
	dest->bKing = source.bKing;
}



void copy_board2(const Bitboard *source, Bitboard *dest)
{
	dest->wPawns = source->wPawns;
	dest->wRooks = source->wRooks;
	dest->wKnights = source->wKnights;
	dest->wBishops = source->wBishops;
	dest->wQueen = source->wQueen;
	dest->wKing = source->wKing;

	dest->bPawns = source->bPawns;
	dest->bRooks = source->bRooks;
	dest->bKnights = source->bKnights;
	dest->bBishops = source->bBishops;
	dest->bQueen = source->bQueen;
	dest->bKing = source->bKing;
}//Same function as copy_board, but takes 2 pointers
