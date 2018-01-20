#include <stdint.h>
#include <stdlib.h>
#include "bitBoard.h"



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

    //now check for collisions with other pieces
    moves = ~allPieces(board) & moves;
    //now calculate attacks
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
  b->bPawns | b->bRooks | b->bKnights | b->bBishops | b->bQueen | b->bKing;
}
uint64_t allPieces(Bitboard *b)
{
   return allWhite(b) | allBlack(b);
}
