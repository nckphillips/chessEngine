#ifndef _EVAL_H
#define _EVAL_H
#include "bitBoard.h"

enum features {WHITE, BLACK, WHITEVALUE, BLACKVALUE, PAWNPOSITION};

#define NUM_FEATURES 4
#define TREE_DEPTH 8

int features[NUM_FEATURES];//the feature vector to which weights will be applied














int eval_state(Bitboard * b_ptr);
void getFeatures(Bitboard *b_ptr, int features[NUM_FEATURES]);
int count(uint64_t board);
int getValue(uint64_t board, unsigned int piece_type);
int evaluate_pawn_structure(int features[NUM_FEATURES]);
int getPositionValue(uint64_t board, unsigned int piece_type); //Evaluates the value for a piece type

#endif
