/*This file contains all functions regarding the engine making moves and reporting to
	the gui.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "play.h"
#include "bitBoard.h"
#include "qlearning.h"

/*returns the text string of the best move in the board's current arrangement.*/
void get_best_move(char const *best_move_string, Bitboard *b_ptr)
{

	/*the value of the move for the array given above*/
	int move_value[12] = {0};

	int source_square_best[12] = {0};
	int dest_square_best[12] = {0};

	/*for each piece type, find the best move*/
	for(int piece_type = 0; piece_type < 12; piece_type++) {

	}

	int index_of_max = 0;
	/*select the maximum move of the piece types*/
	for (int i = 0; i < 12; i++) {
		if (move_value[i] > move_value[index_of_max]) {
			index_of_max = i;
		}
	}

	/*convert the source and destination squares to a text move*/
	uint64_t file = 0x101010101010101;
	uint64_t rank = 0x110000000000000;
	for(int i = 0;i < 8; i++) {
		if(source_square & file) {
			best_move[0] = (char)(i + 97);
		}
	}
	for(int i = 0; i < 8; i++) {
		if(source_square & rank) {
			best_move[1] = (char)(i + 49);
		}
	}
	for(int i = 0;i < 8; i++) {
		if(dest_square & file) {
			best_move[2] = (char)(i + 97);
		}
	}
	for(int i = 0; i < 8; i++) {
		if(dest_square & rank) {
			best_move[3] = (char)(i + 49);
		}
	}


	return;
}

void play(Bitboard *b_ptr)
{
	char *best_move = (char *)malloc(7);//5 character move, newline, eof
	best_move[6] = eof;
	best_move[5] = '\n';
	get_best_move(best_move, b_ptr);
	update()
	fprintf(stdout,"move %s",best_move);
	free(best_move);
	return;
}
