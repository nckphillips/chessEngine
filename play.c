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

	Bitboard temp;

	readThreadParams* rt;
	readThreadParams bp;
	rt = &bp;
	init_struct_ptr(rt);
	rt->b_ptr = b_ptr;

	readThreadParams* rt2;
	readThreadParams bp2;
	rt2 = &bp2;
	init_struct_ptr(rt2);
	rt2->b_ptr = b_ptr;

	int  iret1, iret2;
    pthread_t tid1, tid2;
    //printf("Before Thread\n");


    iret1 = pthread_create(&tid1, NULL, spawn_thread_1, rt);//Spawn 1st thread
    iret2 = pthread_create(&tid2, NULL, spawn_thread_2, rt2);//Spawn 2nd thread
    //printf("After Thread1\n");
	pthread_join(tid1, NULL);//Wait for 1st thread to return
	pthread_join(tid2, NULL);//Wait for 2nd thread to return

	/*HERE WE ARE BACK TO 1 THREAD*/


    printf("Thread 1 returns: %d\n",iret1);
    printf("Thread 2 returns: %d\n",iret2);
	int move_value[6];
	int source_square_best[6];
	int dest_square_best[6];

	move_value[0] = rt->move_value[0];
	move_value[1] = rt->move_value[1];
	move_value[2] = rt->move_value[2];
	move_value[3] = rt->move_value[3];
	move_value[4] = rt->move_value[4];
	move_value[5] = rt->move_value[5];

	/*arrays containing the source and destination square for last 3 piece's
	  best move.*/
	source_square_best[0] = rt->source_square_best[0];
	source_square_best[1] = rt->source_square_best[1];
	source_square_best[2] = rt->source_square_best[2];
	source_square_best[3] = rt->source_square_best[3];
	source_square_best[4] = rt->source_square_best[4];
	source_square_best[5] = rt->source_square_best[5];

	dest_square_best[0] = rt->dest_square_best[0];
	dest_square_best[1] = rt->dest_square_best[1];
	dest_square_best[2] = rt->dest_square_best[2];
	dest_square_best[3] = rt->dest_square_best[3];
	dest_square_best[4] = rt->dest_square_best[4];
	dest_square_best[5] = rt->dest_square_best[5];

	int move_value1[6];
	int source_square_best1[6];
	int dest_square_best1[6];

	move_value1[0] = rt2->move_value[0];
	move_value1[1] = rt2->move_value[1];
	move_value1[2] = rt2->move_value[2];
	move_value1[3] = rt2->move_value[3];
	move_value1[4] = rt2->move_value[4];
	move_value1[5] = rt2->move_value[5];

	/*arrays containing the source and destination square for first 3 piece's
	  best move.*/
	source_square_best1[0] = rt2->source_square_best[0];
	source_square_best1[1] = rt2->source_square_best[1];
	source_square_best1[2] = rt2->source_square_best[2];
	source_square_best1[3] = rt2->source_square_best[3];
	source_square_best1[4] = rt2->source_square_best[4];
	source_square_best1[5] = rt2->source_square_best[5];

	dest_square_best1[0] = rt2->dest_square_best[0];
	dest_square_best1[1] = rt2->dest_square_best[1];
	dest_square_best1[2] = rt2->dest_square_best[2];
	dest_square_best1[3] = rt2->dest_square_best[3];
	dest_square_best1[4] = rt2->dest_square_best[4];
	dest_square_best1[5] = rt2->dest_square_best[5];


	int index_of_max1 = 0;

	for (int i = 0; i < 3; i++) {
		printf("Val1:%d\n", move_value1[i]);
		if (source_square_best1[i] != dest_square_best1[i] && move_value1[i] >= move_value1[index_of_max1] && move_value1[i] >= -1000000) {
			index_of_max1 = i;
		}
	}
	/*
	printf("index_of_max1:%d\n", index_of_max1);
	printf("source1: %d\n", source_square_best1[index_of_max1]);
	printf("dest1: %d\n", dest_square_best1[index_of_max1]);
	*/

	int index_of_max = 3;
	/*select the maximum move of the piece types*/
	for (int i = 3; i < 6; i++) {
		printf("Val:%d\n", move_value[i]);
		if (source_square_best[i] != dest_square_best[i] && move_value[i] >= move_value[index_of_max] && move_value[i] >= -1000000) {
			index_of_max = i;
		}
	}

	/*
	printf("index_of_max:%d\n", index_of_max);
	printf("source: %d\n", source_square_best[index_of_max]);
	printf("dest: %d\n", dest_square_best[index_of_max]);
	//to_text(source_square_best[index_of_max],dest_square_best[index_of_max],best_move_string);
	*/

	if(move_value[index_of_max] > move_value1[index_of_max1]){
		to_text(source_square_best[index_of_max],dest_square_best[index_of_max],best_move_string);
	}
	else{
		to_text(source_square_best1[index_of_max1],dest_square_best1[index_of_max1],best_move_string);
	}//Pick a better move


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
