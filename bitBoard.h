/*This file holds all the informationg pertaining to the bitboard representaion
 *and move calculations (legal moves, positions, etc)*/

#ifndef _BIT_BOARD_H
#define _BIT_BOARD_H

#include <stdint.h>

enum pieces {BROOK, BBISHOP, BKNIGHT, BQUEEN, BKING, BPAWN,
	     WROOK, WBISHOP, WKNIGHT, WQUEEN, WKING, WPAWN };

/*use these to refer to squares in the "squares" array*/
enum square_index {a1,b1,c1,d1,e1,f1,g1,h1,
		   a2,b2,c2,d2,e2,f2,g2,h2,
	           a3,b3,c3,d3,e3,f3,g3,h3,
	           a4,b4,c4,d4,e4,f4,g4,h4,
	           a5,b5,c5,d5,e5,f5,g5,h5,
	           a6,b6,c6,d6,e6,f6,g6,h6,
	           a7,b7,c7,d7,e7,f7,g7,h7,
	           a8,b8,c8,d8,e8,f8,g8,h8};

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

/*prints chess board with letters for pieces*/
void printChessboard(Bitboard *b);

/*loops through bitboard, assigning letters to the squares*/
void loop(uint64_t b, char board[8][8], unsigned int piece_type);

/*get all the legal moves on the board for a piece type*/
uint64_t getLegalMoves(Bitboard *board, unsigned int piece_type);

void update(Bitboard * b_ptr, char * move);

/*set up the bitboard structure*/
void init(struct Bitboard* b);

uint64_t allWhite(Bitboard *b);//returns bitboard of all white pieces
uint64_t allBlack(Bitboard *b);//returns bitboard of all black pieces
uint64_t allPieces(Bitboard *b);//returns bitboard of all pieces

#endif
