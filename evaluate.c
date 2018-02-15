#include <stdlib.h>
#include <stdio.h>

#include "bitBoard.h"
#include "evaluate.h"
#include "play.h"

static const int whitePawnValues[64] =  {0,  0,  0,  0,  0,  0,  0,  0,
                                	50, 50, 50, 50, 50, 50, 50, 50,
                                	10, 10, 20, 30, 30, 20, 10, 10,
                                	 5,  5, 10, 25, 25, 10,  5,  5,
                                	 0,  0,  0, 20, 20,  0,  0,  0,
                                	 5, -5,-10,  0,  0,-10, -5,  5,
                                	 5, 10, 10,-20,-20, 10, 10,  5,
                                	 0,  0,  0,  0,  0,  0,  0,  0 };

static const int blackPawnValues[64] =      {0,  0,  0,  0,  0,  0,  0,  0,
                                	     5, 10, 10,-20,-20, 10, 10,  5,
                                	     5, -5,-10,  0,  0,-10, -5,  5,
                                	     0,  0,  0, 20, 20,  0,  0,  0,
                                	     5,  5, 10, 25, 25, 10,  5,  5,
                                	    10, 10, 20, 30, 30, 20, 10, 10,
                                	    50, 50, 50, 50, 50, 50, 50, 50,
                                	     0,  0,  0,  0,  0,  0,  0,  0 };

static const int whiteBishopValues[64] ={-20,-10,-10,-10,-10,-10,-10,-20,
                                         -10,  0,  0,  0,  0,  0,  0,-10,
                                         -10,  0,  5, 10, 10,  5,  0,-10,
                                         -10,  5,  5, 10, 10,  5,  5,-10,
                                         -10,  0, 10, 10, 10, 10,  0,-10,
                                         -10, 10, 10, 10, 10, 10, 10,-10,
                                         -10,  5,  0,  0,  0,  0,  5,-10,
                                         -20,-10,-10,-10,-10,-10,-10,-20};

static const int blackBishopValues[64] = {-20,-10,-10,-10,-10,-10,-10,-20,
                                          -10,  5,  0,  0,  0,  0,  5,-10,
                                          -10, 10, 10, 10, 10, 10, 10,-10,
                                          -10,  0, 10, 10, 10, 10,  0,-10,
                                          -10,  5,  5, 10, 10,  5,  5,-10,
                                          -10,  0,  5, 10, 10,  5,  0,-10,
                                          -10,  0,  0,  0,  0,  0,  0,-10,
                                          -20,-10,-10,-10,-10,-10,-10,-20};

static const int whiteRookValues[64] =  {0,  0,  0,  0,  0,  0,  0,  0,
                                	 5, 10, 10, 10, 10, 10, 10,  5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	 0,  0,  0,  5,  5,  0,  0,  0 };

static const int blackRookValues[64] =  {0,  0,  0,  5,  5,  0,  0,  0,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	-5,  0,  0,  0,  0,  0,  0, -5,
                                	 5, 10, 10, 10, 10, 10, 10,  5,
                                	 0,  0,  0,  0,  0,  0,  0,  0 };

static const int whiteKnightValues[64] =  {-50, -40, -30, -30, -30, -30, -40, -50,
                                	   -40, -20,   0,   0,   0,   0, -20, -40,
                                	   -30,   0,  10,  15,  15,  10,   0, -30,
                                      	   -30,   5,  15,  20,  20,  15,   5, -30,
                                	   -30,   5,  15,  20,  20,  15,   5, -30,
                                	   -30,   0,  10,  15,  15,  10,   0, -30,
                                	   -40, -20,   0,   5,   5,   0, -20, -40,
                                	   -50, -40, -30, -30, -30, -30, -40, -50};

static const int blackKnightValues[64] =  {-50, -40, -30, -30, -30, -30, -40, -50,
                                	   -40, -20,   0,   5,   5,   0, -20, -40,
                                	   -30,   0,  10,  15,  15,  10,   0, -30,
                                      	   -30,   5,  15,  20,  20,  15,   5, -30,
                                	   -30,   5,  15,  20,  20,  15,   5, -30,
                                	   -30,   0,  10,  15,  15,  10,   0, -30,
                                	   -40, -20,   0,   0,   0,   0, -20, -40,
                                	   -50, -40, -30, -30, -30, -30, -40, -50};



static const int whiteQueenValues[64] ={-20,-10,-10, -5, -5,-10,-10,-20,
                                        -10,  0,  0,  0,  0,  0,  0,-10,
                                        -10,  0,  5,  5,  5,  5,  0,-10,
                                         -5,  0,  5,  5,  5,  5,  0, -5,
                                          0,  0,  5,  5,  5,  5,  0, -5,
                                        -10,  5,  5,  5,  5,  5,  0,-10,
                                        -10,  0,  5,  0,  0,  0,  0,-10,
                                        -20,-10,-10, -5, -5,-10,-10,-20};

static const int blackQueenValues[64] = {-20,-10,-10, -5, -5,-10,-10,-20,
                                         -10,  0,  5,  0,  0,  0,  0,-10,
                                           0,  0,  5,  5,  5,  5,  0, -5,
                                           0,  0,  5,  5,  5,  5,  0, -5,
                                          -5,  0,  5,  5,  5,  5,  0, -5,
                                         -10,  0,  5,  5,  5,  5,  0,-10,
                                         -10,  0,  5,  0,  0,  0,  0,-10,
                                         -20,-10,-10, -5, -5,-10,-10,-20};

static const int whiteKingMidgameValues[64]={-30,-40,-40,-50,-50,-40,-40,-30,
                                             -30,-40,-40,-50,-50,-40,-40,-30,
                                             -30,-40,-40,-50,-50,-40,-40,-30,
                                             -30,-40,-40,-50,-50,-40,-40,-30,
                                             -20,-30,-30,-40,-40,-30,-30,-20,
                                             -10,-20,-20,-20,-20,-20,-20,-10,
                                              20, 20,  0,  0,  0,  0, 20, 20,
                                              20, 30, 10,  0,  0, 10, 30, 20};

/*
static const int whiteKingEndgameValues[64]={-50,-40,-30,-20,-20,-30,-40, 50,
                                             -30,-20,-10,  0,  0,-10,-20,-30,
                                             -30,-10, 20, 30, 30, 20,-10,-30,
                                             -30,-10, 30, 40, 40, 30,-10,-30,
                                             -30,-10, 30, 40, 40, 30,-10,-30,
                                             -30,-10, 20, 30, 30, 20,-10,-30,
                                             -30,-30,  0,  0,  0,  0,-30,-30,
                                             -50,-30,-30,-30,-30,-30,-30,-50};

*/

static const int blackKingMidgameValues[64]={20, 30, 10,  0,  0, 10, 30, 20,
                                             20, 20,  0,  0,  0,  0, 20, 20,
                                            -10,-20,-20,-20,-20,-20,-20,-10,
                                            -10,-20,-20,-20,-20,-20,-20,-10,
                                            -20,-30,-30,-40,-40,-30,-30,-20,
                                            -30,-40,-40,-50,-50,-40,-40,-30,
                                            -30,-40,-40,-50,-50,-40,-40,-30
                                            -30,-40,-40,-50,-50,-40,-40,-30};
/*
static const int blackKingEndgameValues[64]={-50,-30,-30,-30,-30,-30,-30,-50,
                                             -30,-30,  0,  0,  0,  0,-30,-30,
                                             -30,-10, 20, 30, 30, 20,-10,-30,
                                             -30,-10, 30, 40, 40, 30,-10,-30,
                                             -30,-10, 30, 40, 40, 30,-10,-30,
                                             -30,-10, 20, 30, 30, 20,-10,-30,
                                             -30,-20,-10,  0,  0,-10,-20,-30,
                                             -50,-40,-30,-20,-20,-30,-40, 50};
*/

int minimax(Bitboard * b_ptr, unsigned const int depth, const int color)

{
        static Bitboard* backup = 0;
        if (depth == TREE_DEPTH && backup == 0) {
                backup = (Bitboard *)malloc(sizeof(Bitboard));
                copy_board(*b_ptr, backup);
        }
	int value = 0;
        int temp_value = 0;
        int new_color = 0;
        if (color == 0) new_color = 1;
        int src_best = 0;
        int dst_best = 0;
        int max = 0;
        uint64_t lm = 0;
        uint64_t pb = 0;
        char tmpmove[6];
	//TODO:value = getValue(b_ptr);//Getting Features of the current Bitboard
        if (depth > 0 && value > -999) {//TODO: the idea here is to stop when the branch is very negative
                /*PSEUDOCODE: for every white legal move, try the move and get the Features
                save the move that gives you the most negative feautres. outside of the loop make t
                the move and undo when minimax returns*/
                if (color == 0) {
                        for (int piece_type = BPAWN; piece_type >=0; piece_type--) {
                                pb = get_board(b_ptr,piece_type);
                                for (int src = 0; src < 64; src++) {
                                        lm = getLegalMoves(b_ptr, piece_type, src);
                                        for(int dst = 0; dst < 64; dst++) {
                                                if(squares[dst] & lm && pb & squares[src]) {
                                                        to_text(src,dst,tmpmove);
                                                        update(b_ptr,tmpmove);
                                                        temp_value = getPositionValue(b_ptr, piece_type);
                                                        copy_board(*backup,b_ptr);
                                                        if (temp_value >= max) {
                                                                max = temp_value;
                                                                src_best = src;
                                                                dst_best = dst;
                                                        }
                                                }
                                        }
                                }
                        }
                } else {
                        for (int piece_type = WPAWN; piece_type < 12; piece_type++) {
                                pb = get_board(b_ptr,piece_type);
                                for (int src = 0; src < 64; src++) {
                                lm = getLegalMoves(b_ptr, piece_type, src);
                                        for(int dst = 0; dst < 64; dst++) {
                                                if(squares[dst] & lm && pb & squares[src]) {
                                                        to_text(src,dst,tmpmove);
                                                        update(b_ptr,tmpmove);
                                                        temp_value = getPositionValue(b_ptr, piece_type);
                                                        copy_board(*backup,b_ptr);
                                                        if (temp_value <= max) {
                                                                max = temp_value;
                                                                src_best = src;
                                                                dst_best = dst;
                                                        }
                                                }
                                        }
                                }
                        }
                }
                if (src_best != dst_best) {
                        to_text(src_best,dst_best,tmpmove);
                        update(b_ptr,tmpmove);
                        max += minimax(b_ptr, depth-1, new_color);
                } else {
                        max = -100000;
                }
        }
	return max;

}


/*






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


	features[PAWNPOSITION] = getPositionValue(b_ptr->bPawns, 	BPAWN); //Get position value for pawns







} //Gets features for the board
*/


int getPositionValue(Bitboard *b_ptr, int piece_type){

	uint64_t pb;
	int value = 0;
	int it;
//NEEDS SWITCH STATEMENT FOR A
switch(piece_type){
	case BPAWN:
		pb = get_board(b_ptr, BPAWN);
		//value = 0;
		it = 56;


		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value += blackPawnValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case WPAWN:

		pb = get_board(b_ptr, WPAWN);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value -= whitePawnValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case WBISHOP:

		pb = get_board(b_ptr, WBISHOP);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value -= whiteBishopValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case BBISHOP:

		pb = get_board(b_ptr, BBISHOP);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value += blackBishopValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case WROOK:

		pb = get_board(b_ptr, WROOK);
		value = 0;
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value -= whiteRookValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case BROOK:

		pb = get_board(b_ptr, BROOK);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value += blackRookValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case WKNIGHT:

		pb = get_board(b_ptr, WKNIGHT);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value -= whiteKnightValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case BKNIGHT:

		pb = get_board(b_ptr, BKNIGHT);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value += blackKnightValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case BQUEEN:

		pb = get_board(b_ptr, BQUEEN);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value += blackQueenValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case WQUEEN:

		pb = get_board(b_ptr, WQUEEN);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value -= whiteQueenValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case BKING:

		//NOTE: not yet accounting for mid/endgame scenario

		pb = get_board(b_ptr, BKING);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value += blackKingMidgameValues[it + col];//TODO: switch which values we use
				                                                  //depending on where we are in the game
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
	case WKING:

		pb = get_board(b_ptr, WKING);
		it = 56;
		for(int row = 7; row >= 0; row--){
			for(int col = 0; col <= 7; col++){
				if ((pb & 1) == 1){
					value -= whiteKingMidgameValues[it + col];
					pb>>=1;
				}
				else
					pb>>=1;
			}
			it = it -8;
		}
		return value;
		break;
}
return value;

} //NEEDS WORK





int evaluate_pawn_structure(int features[NUM_FEATURES]){

	int value = 0;





	return value;

} //Function for evaluating connected pawns


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
		piece_value = 100 ;
	break;

	case WROOK:
		piece_value = 500 ;
	break;

	case WKNIGHT:
		piece_value = 300 ;
	break;

	case WBISHOP:
		piece_value = 325;
	break;

	case WQUEEN:
		piece_value = 900 ;
	break;

	case WKING:
		piece_value = 99999;
	break;

	case BPAWN:
		piece_value = 100 ;
	break;

	case BROOK:
		piece_value = 500 ;
	break;

	case BKNIGHT:
		piece_value = 300 ;
	break;

	case BBISHOP:
		piece_value = 350;
	break;

	case BQUEEN:
		piece_value = 900 ;
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
} //get total value for given Pieces excluding Kings
