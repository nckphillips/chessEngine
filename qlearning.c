#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bitBoard.h"






void getFeatures(Bitboard *b_ptr, int features[NUM_FEATURES]){

	features[WHITE] = count(allWhite(b_ptr)); //count # of white pieces
	features[BLACK] = count(callBlack(b_ptr)); //count # of black pieces
	features[WHITEVALUE] = getWhiteValue(b_ptr); //get the total value of white pieces
	features[BLACKVALUE] = getBlackValue(b_ptr); //get the total value of black pieces

} //Gets features for the board



int count(uint64_t board){
	
	int count;
	

	return count;
}


int getWhiteValue(Bitboard* b_ptr){

	int value;
	
	
	



	return value;
} //get total value for white pieces


int getBlackValue(Bitboard* b_ptr){

	int value;
	
	
	



	return value;
} //get total value for black pieces
