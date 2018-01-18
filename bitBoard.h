#ifndef _BIT_BOARD_H
#define _BIT_BOARD_H

#include <stdint.h>

#define NUM_BOARDS_PP 3 //number of boards per piece

typedef uint64_t Bitboard;

/*Used to initialize a board at the start of a game. Return a reference to the
 * array of all newly initialized boards. Boards [1-16][] are white [17-32][]
 * are black. Board[0][] is the board containing positions of all pieces.*/
Bitboard** boardInit();

/*Used to destroy all boards at the end of a game or on exit.*/
void boardDestroy(Bitboard **b);

/*Called after move is made to update the boards*/
void update(char * move);

/*print a bitboard to the terminal*/
void bitBoard_print(struct Bitboard* b);
#endif
