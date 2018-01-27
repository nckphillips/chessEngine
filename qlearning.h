#ifndef Q_LEARN_H
#define Q_LEARN_H

#include "bitBoard.h"

#define NUM_FEATURES 4
#define ALPHA 0.2 //learning rate
#define GAMMA 0.8 //discount factor
#define EPSILON 0.5 //exploration rate



enum features {WHITE, BLACK, WHITEVALUE, BLACKVALUE};


/***********************************
LIST OF FEATURES IDEAS:

number black-white
number of white
value of black -value of white
value of white
position of king
number of pieces in the middle of the board (black)
number of white pieces in the middle
total number of legal moves for black
total number of legal moves for white
connected pawns
passed pawns
king protection
can you capture a high value pieces
piece support

TODO: draw
TODO: castling
**************************************/

int features[NUM_FEATURES];//the feature vector to which weights will be applied


int weights[NUM_FEATURES];//the computer generated weights to apply to features

int get_value_of_move(Bitboard *b_ptr, char * move);//Q(s, a)
int update_values(char * move_made, Bitboard *b_ptr);//should be called after opponent
						     //makes move the the weights can
						     //be updated
						     
void getFeatures(Bitboard *b_ptr, int features[NUM_FEATURES]);//extracts features from the 
										//current state of the board
										
int count(uint64_t board); //Counts the number of ones in the bitboard				     
						     
						     
						     

#endif
