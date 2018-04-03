#include "transposition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bitBoard.h"
void generate_random_numbers()
{
        //srandom(time(0));
        //uint64_t msb = 0;
        for(int i = 0; i < 12; i++) {
                for(int j = 0; j < 64; j++){
                        for(int k = 0; k < 2; k++) {
                                //msb = rand();
                                //random_numbers[i][j][k] = random();
                        }
                }
        }
}
//Return a half size zobrist hash
uint64_t zobrist_hash(Bitboard * b_ptr, char sidetomove)
{
        uint64_t hash = 0;
        for(int piecetype = 0; piecetype < 12; piecetype++){
                uint64_t pb = get_board(b_ptr, piecetype);
                int piece_square = 0;
                while (pb){
                        piece_square = __builtin_ffsll(pb) - 1;
                        hash ^= random_numbers[piecetype][piece_square][(int)sidetomove];
                        pb &= ~squares[piece_square];
                }
        }


        return hash;
}
