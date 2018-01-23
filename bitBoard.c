/*This file holds all the informationg pertaining to the bitboard representaion
 *and move calculations (legal moves, positions, etc)*/

#include <stdint.h>
#include <stdlib.h>
#include "bitBoard.h"

uint64_t HFILE;
uint64_t AFILE;
uint64_t RANK1;
uint64_t RANK8;
uint64_t rookMove;

/*helper functions*/
uint64_t find_moved_black_pawns(uint64_t bPawns);
uint64_t black_pawn_attacks(Bitboard* b);
uint64_t find_moved_white_pawns(uint64_t wPawns);
uint64_t white_pawn_attacks(Bitboard* b);
uint64_t same_file(Bitboard* b, unsigned int piece_type);
uint64_t same_rank(Bitboard* b, unsigned int piece_type);
uint64_t translate(Bitboard *bb, uint64_t direction, int i);
uint64_t same_diagonal(Bitboard* b, unsigned int piece_type);
uint64_t get_board(Bitboard *b_ptr, int piece_type);//return the piece's bitboard

void bitBoard_print(uint64_t b, int row){
	if (row == 8) {
	return;
	}
	else {
		bitBoard_print(b >> 8, row+1);
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("%d ", (b & 0x0000001));
		b >>= 1;
		printf("\n");
		return;
		}
} //Function that prints the board

/*gets the legal moves for a piece. Pass the bitboard corresponding the piece*/
uint64_t getLegalMoves(Bitboard *board, unsigned int piece_type)
{
	uint64_t temp = 0;
	uint64_t moves = 0;
	switch (piece_type){
		case BPAWN:
		//moves is initialized to one square in front or'ed with two squares
		//as long as the second square is not being blocked be a white
		//piece residing on the first square.
		moves = board->bPawns >> 8 | (board->bPawns >> 16 & ~allPieces(board)>>8);
		//check which pawns have moved and fix the board
		moves = moves - (find_moved_black_pawns(board->bPawns) >> 16);
		//now check for collisions with other pieces
		moves = moves & ~allPieces(board);
		//now calculate attacks and add them to moves.
		moves += black_pawn_attacks(board);
		break;

		case WPAWN:
		//philosphy here is same as black pawn but for the opposite side
		//of the board.
		moves = board->wPawns << 8 | (board->wPawns << 16 & ~allPieces(board)<<8);
		moves = moves - (find_moved_white_pawns(board->wPawns) << 16);
		moves = moves & ~allPieces(board);
		moves += white_pawn_attacks(board);
		break;

		case BROOK:
		//fire a ray from each rook in every direction
		for(int i = 0; i < 64; i++) {
			if(squares[i] & board->bRooks) {
				//set moves to the right
				rookMove = translate(board, HFILE, i);
				moves |= rookMove;
				
				//set moves to the left
				rookMove = translate(board, AFILE, i);
				moves |= rookMove;
				
				//set moves down
				rookMove = translate(board, RANK1, i);
				moves |= rookMove;
				
				//set moves up
				rookMove = translate(board, RANK8, i);
				moves |= rookMove;
			}
			/*subtract the rook positions from the moves*/
			if (moves) {
				moves &= ~board->bRooks;
			}
		}
<<<<<<< HEAD

=======
>>>>>>> 2124ab3f07a6b7672178e2c8232f538c0db2dd96
		break;

		case WROOK:
		for(int i = 0; i < 64; i++) {
			if(squares[i] & board->wRooks) {
				//set moves to the right
				for (int j = i; (squares[j] & ~HFILE); j++) {
					if (squares[j] & allBlack(board)) {
						moves |= squares[j];
						break;
					} else if (squares[j] & (allWhite(board)-board->wRooks)) {
						break;
					} else {
						moves |= squares[j];
					}
				}
				//set moves to the left
				for (int j = i; (squares[j] & ~AFILE); j--) {
					if (squares[j] & allBlack(board)) {
						moves |= squares[j];
						break;
					} else if (squares[j] & (allWhite(board)-board->wRooks)) {
						break;
					} else {
						moves |= squares[j];
					}
				}
				//set moves down
				for (int j = i; (squares[j] & ~RANK1); j-=8) {
					if (squares[j] & allBlack(board)) {
						moves |= squares[j];
						break;
					} else if (squares[j] & (allWhite(board)-board->wRooks)) {
						break;
					} else {
						moves |= squares[j];
					}
				}
				//set moves up
				for (int j = i; (squares[j] & ~RANK8); j+=8) {
					if (squares[j] & allBlack(board)) {
						moves |= squares[j];
						break;
					} else if (squares[j] & (allWhite(board)-board->wRooks)) {
						break;
					} else {
						moves |= squares[j];
					}
				}
			}
			/*subtract the rook positions from the moves*/
			if (moves) {
				moves &= ~board->wRooks;
			}
		}
		break;

		case BBISHOP:
		moves = same_diagonal(board,BBISHOP);
		moves &= ~allPieces(board);

		break;

		case WBISHOP:

		break;

		case BKNIGHT:

		break;

		case WKNIGHT:

		break;

		case BQUEEN:

		break;

		case WQUEEN:

		break;

		case BKING:

		break;

		case WKING:

		break;

		default: return -1;
	}
	return moves;
}

/*updates the bitboard upon move*/
void update(Bitboard * b_ptr, char * move)
{
	if (strlen(move) < 4) return;
	/*commands are given: "e5e6" so the below lines convert the two part of
	 *the command to squares.*/
	int from_file = (int)move[0] - 97;
	int from_rank = (int)move[1] - 48;
	int to_file = (int)move[2] - 97;
	int to_rank = (int)move[3] - 48;
	uint64_t source_square = squares[(from_rank * 8) + from_file];
	uint64_t dest_square = squares[(to_rank * 8) + to_file];

	if (source_square & allWhite(b_ptr)) {
		if (source_square & b_ptr->wPawns) {
			b_ptr->wPawns -= source_square;
			b_ptr->wPawns += dest_square;
		} else if (source_square & b_ptr->wRooks) {
			b_ptr->wRooks -= source_square;
			b_ptr->wRooks += dest_square;
		} else if (source_square & b_ptr->wBishops) {
			b_ptr->wBishops -= source_square;
			b_ptr->wBishops += dest_square;
		} else if (source_square & b_ptr->wKing) {
			b_ptr->wKing -= source_square;
			b_ptr->wKing += dest_square;
		} else if (source_square & b_ptr->wQueen) {
			b_ptr->wQueen -= source_square;
			b_ptr->wQueen += dest_square;
		} else if (source_square & b_ptr->wKnights) {
			b_ptr->wKnights -= source_square;
			b_ptr->wKnights += dest_square;
		}
	} else {//its a black piece
		if (source_square & b_ptr->bPawns) {
			b_ptr->bPawns -= source_square;
			b_ptr->bPawns += dest_square;
		} else if (source_square & b_ptr->bRooks) {
			b_ptr->bRooks -= source_square;
			b_ptr->bRooks += dest_square;
		} else if (source_square & b_ptr->bBishops) {
			b_ptr->bBishops -= source_square;
			b_ptr->bBishops += dest_square;
		} else if (source_square & b_ptr->bKing) {
			b_ptr->bKing -= source_square;
			b_ptr->bKing += dest_square;
		} else if (source_square & b_ptr->bQueen) {
			b_ptr->bQueen -= source_square;
			b_ptr->bQueen += dest_square;
		} else if (source_square & b_ptr->bKnights) {
			b_ptr->bKnights -= source_square;
			b_ptr->bKnights += dest_square;
		}
	}


}


void init(struct Bitboard* b){

	//Bit 0 (the least significant bit) represents square A1, Bit 1 = B1 and Bit 63 = H8.
	//If this bit is set to 1, it means a piece of the specify type is located on that square,
	//0 means it is not on that square.

	b->wPawns = 0x000000000000FF00;
	b->wRooks = 0x0000000000000081;
	b->wKnights = 0x0000000000000042;
	b->wBishops = 0x0000000000000024;
	b->wQueen = 0x0000000000000008;
	b->wKing = 0x0000000000000010;

	b->bPawns = 0x00FF000000000000;
	b->bRooks = 0x8100000000000000;
	b->bKnights = 0x4200000000000000;
	b->bBishops = 0x2400000000000000;
	b->bQueen = 0x0800000000000000;
	b->bKing = 0x1000000000000000;
	HFILE =      squares[h8] | squares[h7] | squares[h6] | squares[h5] |\
		     squares[h4] | squares[h3] | squares[h2] | squares[h1];
	AFILE =      squares[a1] | squares[a2] | squares[a3] | squares[a4] |\
	             squares[a5] | squares[a6] | squares[a7] | squares[a8];
	RANK1 =      squares[a1] | squares[b1] | squares[c1] | squares[d1] |\
		     squares[e1] | squares[f1] | squares[g1] | squares[h1];
	RANK8 =      squares[a8] | squares[b8] | squares[c8] | squares[d8] |\
		     squares[e8] | squares[f8] | squares[g8] | squares[h8];
} //Initialize bitboard

/*Returns a bitboard of all white pieces*/
uint64_t allWhite(Bitboard *b)
{
	 return b->wPawns | b->wRooks | b->wKnights | b->wBishops | b->wQueen | b->wKing;
}
/*Returns a bitboard of all black pieces*/
uint64_t allBlack(Bitboard *b)
{
	return b->bPawns | b->bRooks | b->bKnights | b->bBishops | b->bQueen | b->bKing;
}
/*Returns a bitboard of all pieces*/
uint64_t allPieces(Bitboard *b)
{
	 return (allWhite(b) | allBlack(b));
}

uint64_t find_moved_black_pawns(uint64_t bPawns)
{
	return bPawns & ~(squares[48] | squares[49] | squares[50] | squares[51] | squares[52] | \
										squares[53] | squares[54] | squares[55]);
}


uint64_t black_pawn_attacks(Bitboard* b)
{
	uint64_t attacks = 0;
	uint64_t diag = (((b->bPawns & ~HFILE) >> 7) & ~allBlack(b)) | (((b->bPawns & ~AFILE) >> 9) & ~allBlack(b));
	attacks = diag & allWhite(b);

	return attacks;
}

uint64_t find_moved_white_pawns(uint64_t wPawns)
{
	return wPawns & ~(squares[8] | squares[9] | squares[10] | squares[11] | squares[12] | \
		          squares[13] | squares[14] | squares[15]);
}
uint64_t white_pawn_attacks(Bitboard* b)
{
	uint64_t attacks = 0;
	/*NOTE:there may be a bug here if a pawn is on the edge of the board but not sure*/

	uint64_t diag = (((b->wPawns & ~AFILE) << 7) & ~allWhite(b)) | (((b->wPawns & ~HFILE))<< 9) & ~allWhite(b);
	attacks = diag & allBlack(b);
	return attacks;
}
/*return a bitboard with all squares on the same diagonals as the piece_type*/
uint64_t same_diagonal(Bitboard* b, unsigned int piece_type)
{
	uint64_t diag = 0;
	uint64_t piece_board = get_board(b, piece_type);
	uint64_t r7,r9,l7,l9;//one board to shift left 7, right 9, etc. for diagonals
	//create bitboard for edge files
	uint64_t edge_files = HFILE | AFILE;
	r7 = piece_board;
	r9 = piece_board;
	l7 = piece_board;
	l9 = piece_board;
	//generate diagonals
	for(int i = 0; i < 8; i++) {
		r7 >>= 7;
		r9 >>= 9;
		l7 <<= 7;
		l9 <<= 9;
		diag |= r7 | r9 | l7 | l9;
		//if a representation is about to loop around, clear that one.
		r7 &= ~edge_files;
		r9 &= ~edge_files;
		l9 &= ~edge_files;
		l7 &= ~edge_files;
	}

	return diag;
}
/*return a bitboard with all squares on the same rank as the piece_type*/
uint64_t same_rank(Bitboard* b, unsigned int piece_type)
{
	uint64_t rank = 0;
	uint64_t piece_board = get_board(b, piece_type);

	uint64_t mask = 0xff;
	for (int i = 0; i < 8 ; i+=1)  {
		if (mask & piece_board) {
			rank += mask;
		}
		mask <<= 8;
	}

	return rank;
}

uint64_t translate(Bitboard *bb, uint64_t direction, int i)
{
	//uint64_t dir = direction;
	uint64_t newMove = 0;
	int a = 0;
	if(direction == HFILE){ 
		a = 1;
	} else if (direction == AFILE){ 
		a = -1;
	} else if (direction == RANK1){
		a = -8;
	} else if (direction == RANK8){
		a = 8;
	}

	for (int j = i; (squares[j] & ~direction); j+=a) {
		if (squares[j] & allWhite(bb)) {
			newMove |= squares[j];
			break;
		} else if (squares[j] & (allBlack(bb)-bb->bRooks)) {
			break;
		} else {
			newMove |= squares[j];
		}
	}
	return newMove;
}

/*return a bitboard with all squares on the same file as the piece_type*/
uint64_t same_file(Bitboard* b, unsigned int piece_type)
{

	uint64_t file = 0;
	uint64_t piece_board = get_board(b, piece_type);
	for (int i = 8; i <=64; i+=8) {
		file += piece_board >> i | piece_board << i;
	}

	return file;
}

/*return the requested bitboard*/
uint64_t get_board(Bitboard *b_ptr, int piece_type)
{
	uint64_t piece_board = 0;
	switch (piece_type) {
		case BROOK: piece_board = b_ptr->bRooks;
		break;

		case BBISHOP: piece_board = b_ptr->bBishops;
		break;

		case BKNIGHT: piece_board = b_ptr->bKnights;
		break;

		case BQUEEN: piece_board = b_ptr->bQueen;
		break;

		case BKING: piece_board = b_ptr->bKing;
		break;

		case WROOK: piece_board = b_ptr->wRooks;
		break;

		case WBISHOP: piece_board = b_ptr->wBishops;
		break;

		case WKNIGHT: piece_board = b_ptr->wKnights;
		break;

		case WQUEEN: piece_board = b_ptr->wQueen;
		break;

		case WKING: piece_board = b_ptr->wKing;
		default: break;

	}
	return piece_board;
}
