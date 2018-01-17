#ifndef _BIT_BOARD_H
#define _BIT_BOARD_H

#include <stdint.h>

#define NUM_BOARDS_PP 3 //number of boards per piece

typedef uint64_t Bitboard;

/*Used to initialize a board at the start of a game. Return a reference to the
 * array of all newly initialized boards.*/
Bitboard** boardInit();

/*Used to destroy a board at the end of a game or on exit.*/
void boardDestroy(Bitboard **b);

/*Called after move is made to update the boards*/
void update(char * move);
#endif
