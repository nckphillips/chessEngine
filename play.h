/*This file contains all functions regarding the engine making moves and reporting to
  the gui.*/
#ifndef PLAY_CHESS_H
#define PLAY_CHESS_H
#include "bitBoard.h"

typedef struct readThreadParams {                                                   
    int move_value[6];
	int source_square_best[6];                                                           
	int dest_square_best[6];
	Bitboard* b_ptr;                                                         
} readThreadParams;



void play(Bitboard *b_ptr);
void to_text(int source_square, int dest_square, char *move);

#endif
