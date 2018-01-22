/*This file holds all the informationg pertaining to the bitboard representaion
 *and move calculations (legal moves, positions, etc)*/

#include <stdint.h>
#include <stdlib.h>
#include "bitBoard.h"


/*helper functions*/
uint64_t get_collisions(Bitboard* board);
uint64_t find_moved_black_pawns(uint64_t bPawns);
uint64_t black_pawn_attacks(Bitboard* b);
uint64_t find_moved_white_pawns(uint64_t wPawns);
uint64_t white_pawn_attacks(Bitboard* b);
uint64_t same_file(Bitboard* b, unsigned int piece_type);
uint64_t same_rank(Bitboard* b, unsigned int piece_type);
uint64_t same_diagonal(Bitboard* b, unsigned int piece_type);
uint64_t get_board(Bitboard *b_ptr, int piece_type);//return the piece's bitboard

void bitBoard_print(uint64_t b, int row){
	if (row == 8) {
	return;
	}
	else {
		bitBoard_print(b >> 8, row+1);
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("\n");
		return;
		}
} //Function that prints the board

/*gets the legal moves for a piece. Pass the bitboard corresponding the piece*/
uint64_t getLegalMoves(Bitboard *board, unsigned int piece_type)
{
	uint64_t temp = 0;
	uint64_t moves = 0;
	switch (piece_type){
		case BPAWN:
		//moves is initialized to one square in front or'ed with two squares
		//as long as the second square is not being blocked be a white
		//piece residing on the first square.
		moves = board->bPawns >> 8 | (board->bPawns >> 16 & ~allPieces(board)>>8);
		//check which pawns have moved and fix the board
		moves = moves - (find_moved_black_pawns(board->bPawns) >> 16);
		//now check for collisions with other pieces
		moves = moves & get_collisions(board);
		//now calculate attacks and add them to moves.
		moves += black_pawn_attacks(board);
		break;

		case WPAWN:
		//philosphy here is same as black pawn but for the opposite side
		//of the board.
		moves = board->wPawns << 8 | (board->wPawns << 16 & ~allPieces(board)<<8);
		moves = moves - (find_moved_white_pawns(board->wPawns) << 16);
		moves = moves & get_collisions(board);
		moves += white_pawn_attacks(board);
		break;

		case BROOK:
		//initialize move to all squares along the same file or rank as
		//the rook
		moves = same_file(board, BROOK) | same_rank(board, BROOK);
		moves &= ~(allWhite(board) >> 8);//rook can only move to attack white, not past
		moves &= ~allBlack(board);//black rook cannot move to square occupied by black.
		/*remove squares past pieces*/
		temp = moves | board->bRooks;
		for (int i = 0; i < 8; i++) {
			temp >>= 8;
			temp |= board->bRooks;
			moves &= temp;

		}

		//TODO:leave the squares if there is a clear path to a white piece for an attack
		break;

		case WROOK:
		//initialize move to all squares along the same file or rank as
		//the rook
		moves = same_file(board, WROOK) | same_rank(board, WROOK);
		moves &= ~(allWhite(board) >> 8);//rook can only move to attack black, not past
		moves &= ~allBlack(board);//white rook cannot move to square occupied by white.
		/*remove squares past pieces*/
		temp = moves | board->wRooks;
		for (int i = 0; i < 8; i++) {
			temp <<= 8;
			temp |= board->wRooks;
			moves &= temp;
		}
		break;

		case BBISHOP:
		moves = same_diagonal(board,BBISHOP);

		break;

		case WBISHOP:

		break;

		default:
		break;
	}
	return moves;
}

/*updates the bitboard upon move*/
void update(char * move)
{

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
/*returns free squares on the board*/
uint64_t get_collisions(Bitboard* board)
{
	return (~allPieces(board));
}

uint64_t black_pawn_attacks(Bitboard* b)
{
	uint64_t attacks = 0;
	uint64_t diag = ((b->bPawns >> 7) & (~b->bPawns)) | ((b->bPawns >> 9) & (~b->bPawns));
	attacks = diag & allWhite(b);

	return attacks;
}

uint64_t find_moved_white_pawns(uint64_t wPawns)
{
	return wPawns & ~(squares[8] | squares[9] | squares[10] | squares[11] | squares[12] | \
		          squares[13] | squares[14] | squares[15]);
}
uint64_t white_pawn_attacks(Bitboard* b)
{
	uint64_t attacks = 0;
	uint64_t diag = ((b->wPawns << 7) & (~b->wPawns)) | ((b->wPawns << 9) & (~b->wPawns));
	attacks = diag & allBlack(b);
	return attacks;
}
/*return a bitboard with all squares on the same diagonals as the piece_type*/
uint64_t same_diagonal(Bitboard* b, unsigned int piece_type)
{
	uint64_t diag = 0;
	uint64_t piece_board = get_board(b, piece_type);
	uint64_t r7,r9,l7,l9;//one board to shift left 7, right 9, etc. for diagonals
	r7 = piece_board;
	r9 = piece_board;
	l7 = piece_board;
	l9 = piece_board;
	for(int i = 1; i < 8; i++) {
		r7 >>= 7;
		//r9 >>= 9;
		//l7 <<= 7;
	//	l9 <<= 9;
		diag |= r7 ;//| r9 | l7 | l9;
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

/*return the requested bitboard*/
uint64_t get_board(Bitboard *b_ptr, int piece_type)
{
	uint64_t piece_board = 0;
	switch (piece_type) {
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
