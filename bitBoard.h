#ifndef _BIT_BOARD_H
#define _BIT_BOARD_H

/*Used to initialize a board at the start of a game.*/
void boardInit();

/*Used to destroy a board at the end of a game or on exit.*/
void boardDestroy();

/*Called after move is made to update the boards*/
void update(char * move);
#endif
