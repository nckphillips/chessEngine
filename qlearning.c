#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bitBoard.h"
#include "qlearning.h"


int weights[NUM_FEATURES] = {0};//the computer generated weights to apply to features


int getValue(uint64_t board, unsigned int piece_type);




int get_state_value(Bitboard *b_ptr){

	int value = 0;

	getFeatures(b_ptr, features);//Getting Features of the current Bitboard

	for(int i = 0; i < NUM_FEATURES; i++){
		printf("weight %d: %d\n", i,weights[i]);
		value += weights[i] * features[i]; // Q = w[i] * f[i]
	}
	printf("board was:\n");
	printChessboard(b_ptr);
	printf("value was: %d\n", value);

	return value;

}//Q(s, a)

int getReward(Bitboard *b_ptr, Bitboard *previous) {
	int wValue = 0;
	int bValue = 0;
	int total_curr = 0;
	int total_prev = 0;
	wValue  = getValue(b_ptr->wPawns, WPAWN); //get the total value of white pawns
	wValue += getValue(b_ptr->wKnights, WKNIGHT); //get the total value of white knigts
	wValue += getValue(b_ptr->wBishops, WBISHOP); //get the total value of white bishops
	wValue += getValue(b_ptr->wRooks, WROOK); //get the total value of white rooks

	bValue  = getValue(b_ptr->bPawns, BPAWN); //get the total value of black pawns
	bValue += getValue(b_ptr->bKnights, BKNIGHT); //get the total value of black knigts
	bValue += getValue(b_ptr->bBishops, BBISHOP); //get the total value of black bishops
	bValue += getValue(b_ptr->bRooks, BROOK); //get the total value of black rooks
	total_curr = wValue + bValue;
	wValue  = getValue(previous->wPawns, WPAWN); //get the total value of white pawns
	wValue += getValue(previous->wKnights, WKNIGHT); //get the total value of white knigts
	wValue += getValue(previous->wBishops, WBISHOP); //get the total value of white bishops
	wValue += getValue(previous->wRooks, WROOK); //get the total value of white rooks

	bValue  = getValue(previous->bPawns, BPAWN); //get the total value of black pawns
	bValue += getValue(previous->bKnights, BKNIGHT); //get the total value of black knigts
	bValue += getValue(previous->bBishops, BBISHOP); //get the total value of black bishops
	bValue += getValue(previous->bRooks, BROOK); //get the total value of black rooks
	total_prev = wValue + bValue;
	return total_curr-total_prev;
}

void update_values(Bitboard *b_ptr, Bitboard *previous_state){

	getFeatures(b_ptr, features);//Getting Features of the current Bitboard

	int diff = 0;

	diff = (getReward(b_ptr,previous_state)+DISCOUNT * maxAction(b_ptr) ) - get_state_value(previous_state);
	for(int i = 0; i < NUM_FEATURES; i++){
		weights[i] += ALPHA * diff * features[i]; // W[i] = ALPHA * diff * F[i]
	}
	writeFile();

}//Update weights based on the move made
/**
def computeValueFromQValues(self, state):
	"""
	  Returns max_action Q(state,action)
	  where the max is over legal actions.  Note that if
	  there are no legal actions, which is the case at the
	  terminal state, you should return a value of 0.0.
	"""
	"*** YOUR CODE HERE ***"
	actions = self.getLegalActions(state)

	qprev = 0.0
	if actions == None: return 0.0
	elif len(actions) == 1: return self.getQValue(state,actions[0])
	else:
		for act in actions:
			q = self.getQValue(state,act)
			if q > qprev: qprev = q
	return qprev
*/
int maxAction(Bitboard *b_ptr){


	Bitboard temp;
	copy_board2(b_ptr, &temp);
	int piece_max = 0;

	for(int piece_type = BPAWN; piece_type >= 0; piece_type--) {
		uint64_t pb = get_board(b_ptr,piece_type);//piece type board
		int val = 0;
		for(int i = 0; i < 64; i ++) {
			if (squares[i] & pb){//loop through the pieces
				uint64_t lm = getLegalMoves(b_ptr, piece_type, i);

				for(int j = 0; j < 64; j++) {//loop through the moves
					if(squares[j] & lm) {
						square_move(&temp,squares[i],squares[j]); //square[i] holds current pos
						val = get_state_value(&temp);
						if (val >= piece_max) {
							piece_max = val;
						}
						copy_board2(b_ptr,&temp); //reverse temp to initial state
					}
				}
			}

		} //iterate through all pieces

	} //interate through all piece types



	return piece_max;

} //Return the maximum value of Q(s, a)


void getFeatures(Bitboard *b_ptr, int features[NUM_FEATURES]){
	int wValue = 0;
	features[WHITE] = count(allWhite(b_ptr)); //count # of white pieces
	features[BLACK] = count(allBlack(b_ptr)); //count # of black pieces


	wValue  = getValue(b_ptr->wPawns, WPAWN); //get the total value of white pawns
	wValue += getValue(b_ptr->wKnights, WKNIGHT); //get the total value of white knigts
	wValue += getValue(b_ptr->wBishops, WBISHOP); //get the total value of white bishops
	wValue += getValue(b_ptr->wRooks, WROOK); //get the total value of white rooks
	features[WHITEVALUE] = wValue + getValue(b_ptr->wQueen, WQUEEN); //get the total value of white queen +
	features[WHITEVALUE] *= -1;																  //previous pieces, excluding King

	int bValue = 0;

	bValue  = getValue(b_ptr->bPawns, BPAWN); //get the total value of black pawns
	bValue += getValue(b_ptr->bKnights, BKNIGHT); //get the total value of black knigts
	bValue += getValue(b_ptr->bBishops, BBISHOP); //get the total value of black bishops
	bValue += getValue(b_ptr->bRooks, BROOK); //get the total value of black rooks
	features[BLACKVALUE] = bValue + getValue(b_ptr->bQueen, BQUEEN); //get the total value of black queen +
																		  //previous pieces, excluding King


} //Gets features for the board

/*
int getReward(Bitboard* b_ptr){

	int reward = 0;







}
*/


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
		piece_value = 1 ;
	break;

	case WROOK:
		piece_value = 5 ;
	break;

	case WKNIGHT:
		piece_value = 3 ;
	break;

	case WBISHOP:
		piece_value = 4;
	break;

	case WQUEEN:
		piece_value = 9 ;
	break;

	case WKING:
		piece_value = 99999;
	break;

	case BPAWN:
		piece_value = 1 ;
	break;

	case BROOK:
		piece_value = 5 ;
	break;

	case BKNIGHT:
		piece_value = 3 ;
	break;

	case BBISHOP:
		piece_value = 4;
	break;

	case BQUEEN:
		piece_value = 9 ;
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

void writeFile()
{
   FILE * fp;
   int i;
   /* open the file for writing*/
   fp = fopen ("weights.txt","w");

   /* write 10 lines of text into the file stream*/
   for(i = 0; i < NUM_FEATURES; i++){
       fprintf (fp, "%d\n", weights[i]);
   }

   /* close the file*/
   fclose (fp);
}//write to a weights.txt
