#ifndef Q_LEARN_H
#define Q_LEARN_H
#define NUM_FEATURES 4

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

TODO: castling
**************************************/

int features[NUM_FEATURES];//the feature vector to which weights will be applied
int weights[NUM_FEATURES];//the computer generated weights to apply to features

#endif
