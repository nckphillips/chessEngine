#ifndef _BIT_BOARD_H
#define _BIT_BOARD_H

#include <stdint.h>

#define NUM_BOARDS_PP 3 //number of boards per piece


struct Bitboard{

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

}; //Bitboard Structure





//typedef uint64_t Bitboard;

/*Used to initialize a board at the start of a game. Return a reference to the
 * array of all newly initialized boards. Boards [1-16][] are white [17-32][]
 * are black. Board[0][] is the board containing positions of all pieces.*/
//Bitboard** boardInit();

/*Used to destroy all boards at the end of a game or on exit.*/
//void boardDestroy(Bitboard **b);

/*Called after move is made to update the boards*/
//void update(char * move);


#endif
