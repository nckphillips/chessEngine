/*This file holds all the informationg pertaining to the bitboard representaion
 *and move calculations (legal moves, positions, etc)*/

#ifndef _BIT_BOARD_H
#define _BIT_BOARD_H

#include <stdint.h>

enum pieces {BROOK, BBISHOP, BKNIGHT, BQUEEN, BKING, BPAWN,
	     WROOK, WBISHOP, WKNIGHT, WQUEEN, WKING, WPAWN };

uint64_t squares[64];//array of masks. example: e5 is squares[36] which corresponds to 0x0000001000000000

typedef struct Bitboard{

	uint64_t wPawns;
	uint64_t wRooks;
	uint64_t wKnights;
	uint64_t wBishops;
	uint64_t wQueen;
	uint64_t wKing;

	uint64_t bPawns;
	uint64_t bRooks;
	uint64_t bKnights;
	uint64_t bBishops;
	uint64_t bQueen;
	uint64_t bKing;

	//Following 2 lines are just for possible future use
	//const Bitboard WhiteSquares = 0x55AA55AA55AA55AAULL;
	//const Bitboard BlackSquares = 0xAA55AA55AA55AA55ULL;

	//OR the same color type pieces to get all same color type pieces on the board

}Bitboard; //Bitboard Structure

/*print a bitboard. starting with row*/
void bitBoard_print(uint64_t b, int row);

/*get all the legal moves on the board for a piece type*/
uint64_t getLegalMoves(Bitboard *board, unsigned int piece_type);

void update(char * move);

/*set up the bitboard structure*/
void init(struct Bitboard* b);

uint64_t allWhite(Bitboard *b);//returns bitboard of all white pieces
uint64_t allBlack(Bitboard *b);//returns bitboard of all black pieces
uint64_t allPieces(Bitboard *b);//returns bitboard of all pieces

#endif
