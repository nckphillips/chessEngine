#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bitBoard.h"
#include "qlearning.h"



int getWhiteValue(Bitboard* b_ptr);
int getBlackValue(Bitboard* b_ptr);



int get_state_value(Bitboard *b_ptr){

	int value = 0;

	//getFeatures(b_ptr, features);//Most likely we gonna call this function here

	return value;

}//Q(s, a)



void getFeatures(Bitboard *b_ptr, int features[NUM_FEATURES]){

	features[WHITE] = count(allWhite(b_ptr)); //count # of white pieces
	features[BLACK] = count(allBlack(b_ptr)); //count # of black pieces
	features[WHITEVALUE] = getWhiteValue(b_ptr); //get the total value of white pieces
	features[BLACKVALUE] = getBlackValue(b_ptr); //get the total value of black pieces

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


int getWhiteValue(Bitboard* b_ptr){

	int value = 0;






	return value;
} //get total value for white pieces


int getBlackValue(Bitboard* b_ptr){

	int value = 0;






	return value;
} //get total value for black pieces
