#include "bitBoard.h"
#include "evaluate.h"

static const int whitePawnValues[64] =  {0,  0,  0,  0,  0,  0,  0,  0,
                                	50, 50, 50, 50, 50, 50, 50, 50,
                                	10, 10, 20, 30, 30, 20, 10, 10,
                                	 5,  5, 10, 25, 25, 10,  5,  5,
                                	 0,  0,  0, 20, 20,  0,  0,  0,
                                	 5, -5,-10,  0,  0,-10, -5,  5,
                                	 5, 10, 10,-20,-20, 10, 10,  5,
                                	 0,  0,  0,  0,  0,  0,  0,  0 };

static const int whiteBishopValues[64] ={-20,-10,-10,-10,-10,-10,-10,-20,
                                         -10,  0,  0,  0,  0,  0,  0,-10,
                                         -10,  0,  5, 10, 10,  5,  0,-10,
                                         -10,  5,  5, 10, 10,  5,  5,-10,
                                         -10,  0, 10, 10, 10, 10,  0,-10,
                                         -10, 10, 10, 10, 10, 10, 10,-10,
                                         -10,  5,  0,  0,  0,  0,  5,-10,
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

static const int whiteKingMidgameValues[64]={-30,-40,-40,-50,-50,-40,-40,-30,
                                             -30,-40,-40,-50,-50,-40,-40,-30,
                                             -30,-40,-40,-50,-50,-40,-40,-30,
                                             -30,-40,-40,-50,-50,-40,-40,-30,
                                             -20,-30,-30,-40,-40,-30,-30,-20,
                                             -10,-20,-20,-20,-20,-20,-20,-10,
                                              20, 20,  0,  0,  0,  0, 20, 20,
                                              20, 30, 10,  0,  0, 10, 30, 20};

static const int whiteKingMidgameValues[64]={-50,-40,-30,-20,-20,-30,-40,50,
                                             -30,-20,-10,  0,  0,-10,-20,-30,
                                             -30,-10, 20, 30, 30, 20,-10,-30,
                                             -30,-10, 30, 40, 40, 30,-10,-30,
                                             -30,-10, 30, 40, 40, 30,-10,-30,
                                             -30,-10, 20, 30, 30, 20,-10,-30,
                                             -30,-30,  0,  0,  0,  0,-30,-30,
                                             -50,-30,-30,-30,-30,-30,-30,-50};

static const int blackPawnValues[64] =      {0,  0,  0,  0,  0,  0,  0,  0,
                                	5, 10, 10,-20,-20, 10, 10,  5,
                                	5, -5,-10,  0,  0,-10, -5,  5,
                                	 0,  0,  0, 20, 20,  0,  0,  0,
                                	 5,  5, 10, 25, 25, 10,  5,  5,
                                	 10, 10, 20, 30, 30, 20, 10, 10,
                                	 50, 50, 50, 50, 50, 50, 50, 50,
                                	 0,  0,  0,  0,  0,  0,  0,  0 };

static const int blackBishopValues[64] =    {-20,-10,-10,-10,-10,-10,-10,-20,
                                        -10,  5,  0,  0,  0,  0,  5,-10,
                                        -10, 10, 10, 10, 10, 10, 10,-10,
                                        -10,  0, 10, 10, 10, 10,  0,-10,
                                        -10,  5,  5, 10, 10,  5,  5,-10,
                                        -10,  0,  5, 10, 10,  5,  0,-10,
                                        -10,  0,  0,  0,  0,  0,  0,-10,
                                        -20,-10,-10,-10,-10,-10,-10,-20};

static const int blackQueenValues[64] =      {-20,-10,-10, -5, -5,-10,-10,-20
                                        -10,  0,  5,  0,  0,  0,  0,-10,
                                        0,  0,  5,  5,  5,  5,  0, -5,
                                        0,  0,  5,  5,  5,  5,  0, -5,
                                          -5,  0,  5,  5,  5,  5,  0, -5,
                                        -10,  0,  5,  5,  5,  5,  0,-10,
                                        -10,  0,  5,  0,  0,  0,  0,-10,
                                        -20,-10,-10,-5,-5,-10,-10,-20};

static const int blackKingMidgameValues[64]={20, 30, 10,  0,  0, 10, 30, 20
                                        20, 20,  0,  0,  0,  0, 20, 20,
                                        -10,-20,-20,-20,-20,-20,-20,-10,
                                        -10,-20,-20,-20,-20,-20,-20,-10,
                                        -20,-30,-30,-40,-40,-30,-30,-20,
                                        -30,-40,-40,-50,-50,-40,-40,-30,
                                         -30,-40,-40,-50,-50,-40,-40,-30
                                         -30,-40,-40,-50,-50,-40,-40,-30};

static const int blackKingMidgameValues[64]={-50,-30,-30,-30,-30,-30,-30,-50
                                                -30,-30,  0,  0,  0,  0,-30,-30,
                                                -30,-10, 20, 30, 30, 20,-10,-30,
                                                -30,-10, 30, 40, 40, 30,-10,-30,
                                                -30,-10, 30, 40, 40, 30,-10,-30,
                                                -30,-10, 20, 30, 30, 20,-10,-30,
                                                -30,-20,-10,  0,  0,-10,-20,-30,
                                                -50,-40,-30,-20,-20,-30,-40,50};



int minimax(const Bitboard * const b_ptr, unsigned const int depth, const int color)
{

	int value = 0;
	int black_value_Advantage = 0; //Can be negative

	getFeatures(b_ptr, features);//Getting Features of the current Bitboard

	value = minimax();

	return value;
}





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



int getPositionValue(uint64_t board, unsigned int piece_type){

//NEEDS SWITCH STATEMENT FOR A PIECE TYPE

int value = 0;

	for(int row = 7; row >= 0; row--){
		for(int col = 0; col <= 7; col++){
			if ((board & 1) == 1){
				value += pawnValues[col]; //INCORRECT, NEEDS SOME SORT OF CALCULATION
				board>>=1;
			}
			else
				board>>=1;
		}
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
} //get total value for given Pieces excluding Kings
