/*This file contains all functions regarding the engine making moves and reporting to
	the gui.*/
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check.h"
#include "evaluate.h"
#include "play.h"
#include "bitBoard.h"

#define RANDOM 0

void to_text(int source_square, int dest_square, char *move)
{
	/*convert the source and destination squares to a text move*/
	uint64_t file = 0x101010101010101;
	uint64_t rank = 0x0000000000000ff;
	for(int i = 0;i < 8; i++) {
		if(squares[source_square] & file) {
			move[0] = (char)(i + 97);
		}
		file <<=1;

	}
	for(int i = 0; i < 8; i++) {
		if(squares[source_square] & rank) {
			move[1] = (char)(i + 49);
		}
		rank <<= 8;

	}
	file = 0x101010101010101;
	rank = 0x0000000000000ff;
	for(int i = 0;i < 8; i++) {
		if(squares[dest_square] & file) {
			move[2] = (char)(i + 97);
		}
		file <<=1;

	}
	for(int i = 0; i < 8; i++) {
		if(squares[dest_square] & rank) {
			move[3] = (char)(i + 49);
		}
		rank <<= 8;


	}
}

/*returns the text string of the best move in the board's current arrangement.*/
void get_best_move(char *best_move_string, Bitboard *b_ptr)
{
	/*the value of the move for the array given above*/
	int move_value[6] = {0};

	/*arrays containing the source and destination square for each piece's
	  best move.*/
	int source_square_best[6] = {0};
	int dest_square_best[6] = {0};

	/*temporary bitboard to modify and pass to the value function*/
	Bitboard temp;
	copy_board(*b_ptr, &temp);//copy board to temp

	/*
	for every piece, for every legal move, get the value of making that move by passing
	a modified board to get_state_value*/
	int piece_max = -1000000;
	for(int piece_type = BPAWN; piece_type >= 0; piece_type--) {
		uint64_t pb = get_board(b_ptr,piece_type);//piece type board
		int val = -1000000;
		for(int i = 0; i < 64; i ++) {
			if (squares[i] & pb) {//loop through the pieces
				uint64_t lm = getLegalMoves(b_ptr, piece_type, i);//board containing legal moves for a piece
				getCheck(b_ptr,&lm,i);
				/*exploration*/
				if (lm && RANDOM) {
					int randsquare = rand()%64;
					while (!(squares[randsquare] & lm) && randsquare >= 0) {
						randsquare--;
					}
					if (!(squares[randsquare] & lm)) {
						while (!(squares[randsquare] & lm) && randsquare < 64) {
							randsquare++;
						}
					}
					source_square_best[piece_type] = i;
					dest_square_best[piece_type] = randsquare;

					//see if random move puts you in check
					copy_board(*b_ptr, &temp);
					char tempmove[6];
					to_text(i,randsquare,tempmove);
					update(&temp,tempmove);
					if (temp.bKing & white_moves(&temp)) {
						piece_max = -1000000;
					} else {
						piece_max = 1000+rand();
					}
					break;
				} else if (lm){
					char tempmove[6];
					for(int dst = 0; dst < 64; dst++){
						if (squares[dst] & lm) {
							to_text(i,dst,tempmove);
							update(&temp,tempmove);
							if (white_moves(&temp) & temp.bKing) {
								val = -10000;
							} else {
								val = minimax(&temp,TREE_DEPTH,0);//start with black
								if (val >= piece_max) {
									piece_max = val;
									source_square_best[piece_type] = i;
									dest_square_best[piece_type] = dst;
								}
							}
						}
					}
				}
			} else if (!pb) {//if there aren't pieces of this type left
				piece_max = -1000000;
			}
		}
		move_value[piece_type] = piece_max;//save that piece type's max
	}

	int index_of_max = 0;
	/*select the maximum move of the piece types*/
	for (int i = 0; i < 6; i++) {
		if (move_value[i] >= move_value[index_of_max]) {
			index_of_max = i;
		}
	}

	printf("%d\n", index_of_max);
	to_text(source_square_best[index_of_max],dest_square_best[index_of_max],best_move_string);

	best_move_string[4] = '\n'; //TODO:this position will eventually be used for promotion
	best_move_string[5] = EOF;
	copy_board(*b_ptr, &temp);
	char tempmove[6];
	to_text(source_square_best[index_of_max],dest_square_best[index_of_max],tempmove);
	update(&temp,tempmove);
	if (temp.bKing & white_moves(&temp)) {
		printf("telluser Congrats\n");
	}
	return;
}

void play(Bitboard *b_ptr)
{
	char *best_move = (char *)malloc(7);//5 character move, newline, eof
	best_move[6] = EOF;
	best_move[5] = '\n';

	get_best_move(best_move, b_ptr);
	update(b_ptr,best_move);
	if(!strcmp(best_move,"a1a1")) {
		printf("resign\n");
	} else {
		fprintf(stdout,"move %s\n", best_move);
	}

	fflush(stdout);
	fflush(stdin);
	free(best_move);
	return;
}
