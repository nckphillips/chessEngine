#include <stdint.h>
#include <stdlib.h>
#include "bitBoard.h"

uint64_t get_collisions(uint64_t moves, Bitboard* board);
uint64_t find_moved_black_pawns(uint64_t bPawns);
uint64_t black_pawn_attacks(Bitboard* board);

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
	uint64_t moves;
	switch (piece_type){
		case BPAWN:
		moves = board->bPawns >> 8 | board->bPawns >> 16;
		//check which pawns have moved and fix the board
		moves = moves - (find_moved_black_pawns(board->bPawns) >> 16);
		//now check for collisions with other pieces
		moves = get_collisions(moves, board);
		//now calculate attacks
		moves += black_pawn_attacks(board);
		bitBoard_print(moves,0);
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

/*Returns a bitboard of all pieces*/
uint64_t allWhite(Bitboard *b)
{
	 return b->wPawns | b->wRooks | b->wKnights | b->wBishops | b->wQueen | b->wKing;
}
uint64_t allBlack(Bitboard *b)
{
	return b->bPawns | b->bRooks | b->bKnights | b->bBishops | b->bQueen | b->bKing;
}
uint64_t allPieces(Bitboard *b)
{
	 return (allWhite(b) | allBlack(b));
}

uint64_t find_moved_black_pawns(uint64_t bPawns)
{
	return bPawns & ~(squares[48] | squares[49] | squares[50] | squares[51] | squares[52] | \
										squares[53] | squares[54] | squares[55]);
}

uint64_t get_collisions(uint64_t moves, Bitboard* board)
{
	return (~allPieces(board)) & moves;
}

uint64_t black_pawn_attacks(Bitboard* b)
{
	uint64_t attacks = 0;
	uint64_t diag = ((b->bPawns >> 7) & (~b->bPawns)) | ((b->bPawns >> 9) & (~b->bPawns));
	attacks = diag & allWhite(b);

	return attacks;
}
