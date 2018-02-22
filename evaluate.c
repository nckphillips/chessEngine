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
                                                        temp_value = getTotalMaterial(b_ptr);
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
                                                        temp_value = getTotalMaterial(b_ptr); //getPositionValue(b_ptr, piece_type);
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

int getTotalMaterial(Bitboard *b_ptr)
{
        int value = 0;
	value  = -1 * getValue(b_ptr->wPawns, WPAWN) * count(b_ptr->wPawns); //get the total value of white pawns
	value -= getValue(b_ptr->wKnights, WKNIGHT) * count(b_ptr->wKnights); //get the total value of white knigts
	value -= getValue(b_ptr->wBishops, WBISHOP) * count(b_ptr->wBishops); //get the total value of white bishops
	value -= getValue(b_ptr->wRooks, WROOK) * count(b_ptr->wRooks); //get the total value of white rooks
	value -= getValue(b_ptr->wQueen, WQUEEN) * count(b_ptr->wQueen); //get the total value of white queen +															  //previous pieces, excluding King
        //value -= getValue(b_ptr->wKing, WKING) * count(b_ptr->wKing);


	value += getValue(b_ptr->bPawns, BPAWN) * count(b_ptr->bPawns); //get the total value of black pawns
	value += getValue(b_ptr->bKnights, BKNIGHT) * count(b_ptr->bKnights); //get the total value of black knigts
	value += getValue(b_ptr->bBishops, BBISHOP) * count(b_ptr->bBishops); //get the total value of black bishops
	value += getValue(b_ptr->bRooks, BROOK) * count(b_ptr->bRooks); //get the total value of black rooks
	value += getValue(b_ptr->bQueen, BQUEEN) * count(b_ptr->bQueen); //get the total value of black queen +
	//value += getValue(b_ptr->bKing, BKING) * count(b_ptr->bKing);
        printf("total material value is: %d\n", value);
        return value;
}

/*finds the value of a move for a given piecetype, based on the position value arrays*/
int getPositionValue(Bitboard *b_ptr, int piece_type){

        uint64_t pb;
        int value = 0;
        int it;

        //compare with the given piece type's position value array
        switch(piece_type){
        	case BPAWN:
        		pb = get_board(b_ptr, BPAWN);
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
                        value += evaluate_pawn_structure(b_ptr);
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

        		break;
        }
        value += getTotalMaterial(b_ptr);
        printf("total val of board: \n");
        printChessboard(b_ptr);
        printf("\n%d\n", value);
        return value;

}



int evaluate_pawn_structure(Bitboard *b_ptr){
/*Function for evaluating connected pawns*/


	//This function should encourage our engine to have connected pawns
		//NOT IMPLEMNTED
	
	//Discourage to have single pawns, unprotected by the other pawns
		//NOT IMPLEMENTED
	
	//This function should discourage stacked Pawns too
		//IMPLEMENTED
		
	int value = 0;
	int same_col_penalty = 0;


	same_col_penalty = same_col_pawns(b_ptr) * (-5);

	value = same_col_penalty;


	return value;

}


int same_col_pawns(Bitboard *b_ptr){

	/*Penalizing stacked pawns by (-5)*/

	int value = 0;

	uint64_t	AFILE = 0x0101010101010101;

	uint64_t	BFILE =      squares[b8] | squares[b7] | squares[b6] | squares[b5] |\
				 squares[b4] | squares[b3] | squares[b2] | squares[b1];

	uint64_t	CFILE =      squares[c1] | squares[c2] | squares[c3] | squares[c4] |\
			         squares[c5] | squares[c6] | squares[c7] | squares[c8];

	uint64_t	DFILE =      squares[d1] | squares[d2] | squares[d3] | squares[d4] |\
			         squares[d5] | squares[d6] | squares[d7] | squares[d8];

	uint64_t	EFILE =      squares[e1] | squares[e2] | squares[e3] | squares[e4] |\
			         squares[e5] | squares[e6] | squares[e7] | squares[e8];

	uint64_t	FFILE =      squares[f8] | squares[f7] | squares[f6] | squares[f5] |\
				 squares[f4] | squares[f3] | squares[f2] | squares[f1];

	uint64_t	GFILE =      squares[g1] | squares[g2] | squares[g3] | squares[g4] |\
			         squares[g5] | squares[g6] | squares[g7] | squares[g8];

	uint64_t	HFILE =      squares[h8] | squares[h7] | squares[h6] | squares[h5] |\
				 squares[h4] | squares[h3] | squares[h2] | squares[h1];

	int temp = count(b_ptr->bPawns & AFILE);
	if (temp > 1)
		value += temp;

	temp = count(b_ptr->bPawns & BFILE);
	if (temp > 1)
		value += temp;

	temp = count(b_ptr->bPawns & CFILE);
	if (temp > 1)
		value += temp;

	temp = count(b_ptr->bPawns & DFILE);
	if (temp > 1)
		value += temp;

	temp = count(b_ptr->bPawns & EFILE);
	if (temp > 1)
		value += temp;

	temp = count(b_ptr->bPawns & FFILE);
	if (temp > 1)
		value += temp;

	temp = count(b_ptr->bPawns & GFILE);
	if (temp > 1)
		value += temp;

	temp = count(b_ptr->bPawns & HFILE);
	if (temp > 1)
		value += temp;

	return value;
}





int count(uint64_t board){

	int count = 0;

	for(int i = 0; i < 64; i++){
			if ((board & 1) == 1){
				count++;
				board>>=1;
			}
			else
				board>>=1;
	} //iterate 64 times

	return count;
}

/*get total value for given Pieces excluding Kings*/
int getValue(uint64_t board, unsigned int piece_type){

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
		piece_value = 325;
	break;

	case BQUEEN:
		piece_value = 900 ;
	break;

	case BKING:
		piece_value = 99999;
	break;
	}
return piece_value;
}
