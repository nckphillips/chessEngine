/*This file contains all functions regarding the engine making moves and reporting to
	the gui.*/
#include <pthread.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check.h"
#include "evaluate.h"
#include "play.h"
#include "bitBoard.h"


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#define RANDOM 0

void *spawn_thread_1(void* ptr);
void *spawn_thread_2(void* ptr);
void init_struct_ptr(readThreadParams* rt);
int move_count = 0;

void init_struct_ptr(readThreadParams* rt){

	rt->move_value[0] = 0;
	rt->move_value[1] = 0;
	rt->move_value[2] = 0;
	rt->move_value[3] = 0;
	rt->move_value[4] = 0;
	rt->move_value[5] = 0;
	rt->source_square_best[0] = 0;
	rt->source_square_best[1] = 0;
	rt->source_square_best[2] = 0;
	rt->source_square_best[3] = 0;
	rt->source_square_best[4] = 0;
	rt->source_square_best[5] = 0;
	rt->dest_square_best[0] = 0;
	rt->dest_square_best[1] = 0;
	rt->dest_square_best[2] = 0;
	rt->dest_square_best[3] = 0;
	rt->dest_square_best[4] = 0;
	rt->dest_square_best[5] = 0;
	rt->b_ptr = NULL;

}//Initialize readThreadParams struct


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


void* spawn_thread_1(void* ptr)
{
	Bitboard temp;
	int piece_type = 0;
	int piece_max = -1000000;
	int deep = TREE_DEPTH - 1;
	readThreadParams *rt = ptr;

	//printf("Started\n");

	for(piece_type = 5; piece_type >= 3; piece_type--) {
		uint64_t pb = get_board(rt->b_ptr,piece_type);//piece type board
		int val = -1000000;
		piece_max = -1000000;
		for(int i = 0; i < 64; i ++) {
			if (squares[i] & pb) {//loop through the pieces
				uint64_t lm = getLegalMoves(rt->b_ptr, piece_type, i);//board containing legal moves for a piece
				getCheck(rt->b_ptr,&lm,i);//remove moves that leave the king in check
				if (lm){
					char tempmove[6];
					for(int dst = 0; dst < 64; dst++){
						if (squares[dst] & lm) {
							copy_board(*(rt->b_ptr), &temp);//copy board to temp
							to_text(i,dst,tempmove);
							tempmove[4] = '\0';
							update(&temp,tempmove);
							if (white_moves(&temp) & temp.bKing) {
								val = -1000000;
								piece_max = -1000000;
								rt->source_square_best[piece_type] = 0;
								rt->dest_square_best[piece_type] = 0;
							} else {
								if (move_count == 0) {
									val = minimax(&temp, deep+1, 1, -999999,999999);
								}
								if (move_count > 10){
									val = minimax(&temp, deep+1, 1, -999999,999999);//start with white response to this move
								} else {
									val = minimax(&temp, deep, 1, -999999,999999);
								}
								///the Following statement assigns the max and also should prevent the a1a1 case
								if (val >= piece_max || rt->source_square_best[piece_type] == rt->dest_square_best[piece_type]) {
									piece_max = val;
									rt->source_square_best[piece_type] = i;
									rt->dest_square_best[piece_type] = dst;
								}
							}
						}
					}
				}
			}
		}
		rt->move_value[piece_type] = piece_max;//save that piece type's max
	}

	//printf("Ended\n");

    return NULL;
} //Find values for moves of the first 3 pieces



void* spawn_thread_2(void* ptr)
{
	Bitboard temp;
	int piece_type = 0;
	int piece_max = -1000000;
	int deep = TREE_DEPTH - 1;
	readThreadParams *rt = ptr;

	//printf("Started\n");

	for(piece_type = 2; piece_type >= 0; piece_type--) {
		uint64_t pb = get_board(rt->b_ptr,piece_type);//piece type board
		int val = -1000000;
		piece_max = -1000000;
		for(int i = 0; i < 64; i ++) {
			if (squares[i] & pb) {//loop through the pieces
				uint64_t lm = getLegalMoves(rt->b_ptr, piece_type, i);//board containing legal moves for a piece
				getCheck(rt->b_ptr,&lm,i);//remove moves that leave the king in check
				if (lm){
					char tempmove[6];
					for(int dst = 0; dst < 64; dst++){
						if (squares[dst] & lm) {
							copy_board(*(rt->b_ptr), &temp);//copy board to temp
							to_text(i,dst,tempmove);
							tempmove[4] = '\0';
							update(&temp,tempmove);
							if (white_moves(&temp) & temp.bKing) {
								val = -1000000;
								piece_max = -1000000;
								rt->source_square_best[piece_type] = 0;
								rt->dest_square_best[piece_type] = 0;
							} else {
								if (move_count > 10){
									val = minimax(&temp, deep+1, 1, -999999,999999);//start with white response to this move
								} else {
									val = minimax(&temp, deep, 1, -999999,999999);
								}
								///the Following statement assigns the max and also should prevent the a1a1 case
								if (val >= piece_max || rt->source_square_best[piece_type] == rt->dest_square_best[piece_type]) {
									piece_max = val;
									rt->source_square_best[piece_type] = i;
									rt->dest_square_best[piece_type] = dst;
								}
							}
						}
					}
				}
			}
		}
		rt->move_value[piece_type] = piece_max;//save that piece type's max
	}

	//printf("Ended\n");

    return NULL;
}//Find values for moves of the last 3 pieces




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

	/*
	for every piece, for every legal move, get the value of making that move by passing
	a modified board to get_state_value*/
	int piece_max = -1000000;
	for(int piece_type = BPAWN; piece_type >= 0; piece_type--) {
		uint64_t pb = get_board(b_ptr,piece_type);//piece type board
		int val = -1000000;
		piece_max = -1000000;
		for(int i = 0; i < 64; i ++) {
			if (squares[i] & pb) {//loop through the pieces
				uint64_t lm = getLegalMoves(b_ptr, piece_type, i);//board containing legal moves for a piece
				getCheck(b_ptr,&lm,i);//remove moves that leave the king in check
				if (lm){
					char tempmove[6];
					for(int dst = 0; dst < 64; dst++){
						if (squares[dst] & lm) {
							copy_board(*b_ptr, &temp);//copy board to temp
							to_text(i,dst,tempmove);
							tempmove[4] = '\0';
							update(&temp,tempmove);
							if (white_moves(&temp) & temp.bKing) {
								val = -1000000;
							} else {
								val = minimax(&temp,TREE_DEPTH,1,-999999,999999);//start with white response to this move

								///the Following statement assigns the max and also should prevent the a1a1 case
								if (val >= piece_max || source_square_best[piece_type] == dest_square_best[piece_type]) {
									piece_max = val;
									source_square_best[piece_type] = i;
									dest_square_best[piece_type] = dst;
									if (white_moves(&temp) & temp.bKing) {
										piece_max = -1000000;
										source_square_best[piece_type] = 0;
										dest_square_best[piece_type] = 0;
									}
								}
							}
						}
					}
				}
			}
		}
		move_value[piece_type] = piece_max;//save that piece type's max
	}

	int index_of_max = 0;
	/*select the maximum move of the piece types*/
	for (int i = 0; i < 6; i++) {
		if (source_square_best[i] != dest_square_best[i] && move_value[i] >= move_value[index_of_max] && move_value[i] >= -1000000) {
			index_of_max = i;
		}
	}

	printf("index_of_max:%d\n", index_of_max);
	printf("source: %d\n", source_square_best[index_of_max]);
	printf("dest: %d\n", dest_square_best[index_of_max]);
	to_text(source_square_best[index_of_max],dest_square_best[index_of_max],best_move_string);




	best_move_string[4] = '\n'; //TODO:this position will eventually be used for promotion
	best_move_string[5] = EOF;
	copy_board(*b_ptr, &temp);
	char tempmove[6];
	to_text(source_square_best[index_of_max],dest_square_best[index_of_max],tempmove);
	update(&temp,tempmove);
	/*if (temp.bKing & white_moves(&temp)) {
		printf("resign\n");c
	}*/
	return;
}

void play(Bitboard *b_ptr)
{
	char *best_move = (char *)malloc(7);//5 character move, newline, eof
	best_move[6] = EOF;
	best_move[5] = '\n';

	get_best_move(best_move, b_ptr);
	update(b_ptr,best_move);
	if(!strcmp(best_move,"a1a1\n")) {
		printf("resign\n");
	} else {
		fprintf(stdout,"move %s\n", best_move);
		move_count ++;
	}

	fflush(stdout);
	fflush(stdin);
	free(best_move);
	return;
}
