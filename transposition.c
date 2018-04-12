#include "transposition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bitBoard.h"
void generate_random_numbers()
{

        for(int i = 0; i < 12; i++) {
                for(int j = 0; j < 64; j++){
                                random_numbers[i][j] = random();
                                random_numbers[i][j] <<= 32;
                                random_numbers[i][j] |= random();
                }
        }
}



uint64_t zobrist_hash(Bitboard * b_ptr, char sidetomove)
{
        uint64_t hash = 0;
        int piece_square = 0;
        for(int piecetype = 0; piecetype < 12; piecetype++){
                uint64_t pb = get_board(b_ptr, piecetype);

                while (pb){
                        piece_square = __builtin_ffsll(pb) - 1;
                        hash ^= random_numbers[piecetype][piece_square];
                        pb &= ~squares[piece_square];
                }

                
        }


        return hash;
}//Return zobrist hash
