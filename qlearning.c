#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bitBoard.h"
#include "qlearning.h"


int getValue(uint64_t board, unsigned int piece_type);




int get_state_value(Bitboard *b_ptr){

	int value = 0;

	getFeatures(b_ptr, features);//Getting Features of the current Bitboard
	
	for(int i = 0; i < 4; i++){
		value += weights[i] * features[i]; // Q = w[i] * f[i]
	}

	return value;

}//Q(s, a)


void updateWeights(int weights[NUM_FEATURES], char * move_made, Bitboard *b_ptr){

	getFeatures(b_ptr, features);//Getting Features of the current Bitboard
	
	//diff = (reward + discount*maxAction(b_ptr) ) - get_state_value(b_ptr);


}//Update weights based on the move made

/*
int maxAction(Bitbiard *b_ptr){

	int maxAction = 0;







} //Return the maximum value of Q(s, a)

*/

void getFeatures(Bitboard *b_ptr, int features[NUM_FEATURES]){
	int wValue = 0;

	features[WHITE] = count(allWhite(b_ptr)); //count # of white pieces
	features[BLACK] = count(allBlack(b_ptr)); //count # of black pieces
	
	
	wValue  = getValue(b_ptr->wPawns, WPAWN); //get the total value of white pawns
	wValue += getValue(b_ptr->wKnights, WKNIGHT); //get the total value of white knigts
	wValue += getValue(b_ptr->wBishops, WBISHOP); //get the total value of white bishops
	wValue += getValue(b_ptr->wRooks, WROOK); //get the total value of white rooks
	features[WHITEVALUE] = wValue + getValue(b_ptr->wQueen, WQUEEN); //get the total value of white queen +
																		  //previous pieces, excluding King
	
	int bValue = 0;
	
	bValue  = getValue(b_ptr->bPawns, BPAWN); //get the total value of black pawns
	bValue += getValue(b_ptr->bKnights, BKNIGHT); //get the total value of black knigts
	bValue += getValue(b_ptr->bBishops, BBISHOP); //get the total value of black bishops
	bValue += getValue(b_ptr->bRooks, BROOK); //get the total value of black rooks
	features[BLACKVALUE] = bValue + getValue(b_ptr->bQueen, BQUEEN); //get the total value of black queen +
																		  //previous pieces, excluding King
	

} //Gets features for the board



int count(uint64_t board){

	int count = 0;

	for(int i = 0; i < 64; i++){
			if ((board & 1) == 1){
				count++;
				board>>=1;
			}
			else
				board>>=1;
	} //iterte 64 times

	return count;
}


int getValue(uint64_t board, unsigned int piece_type){

	int value = 0;
	int piece_value = 0;
	

	switch(piece_type){
	case WPAWN:
		piece_value = 100;
	break;

	case WROOK:
		piece_value = 500;
	break;

	case WKNIGHT:
		piece_value = 300;
	break;

	case WBISHOP:
		piece_value = 350;
	break;

	case WQUEEN:
		piece_value = 900;
	break;

	case WKING:
		piece_value = 99999;
	break;

	case BPAWN:
		piece_value = 100;
	break;

	case BROOK:
		piece_value = 500;
	break;

	case BKNIGHT:
		piece_value = 300;
	break;

	case BBISHOP:
		piece_value = 350;
	break;

	case BQUEEN:
		piece_value = 900;
	break;

	case BKING:
		piece_value = 99999;
	break;
	}

	for(int row = 7; row >= 0; row--){
		for(int col = 0; col <= 7; col++){
			if ((board & 1) == 1){
				value += piece_value;
				board>>=1;
			}
			else
				board>>=1;
		}
	}
	return value;
} //get total value for given Pieces









