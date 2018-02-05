#include <stdint.h>
#include <stdio.h>
#include "bitBoard.h"
#include "check.h"
#include "play.h"

void getCheck(Bitboard *b_ptr, uint64_t *legal_moves, int piece_square)
{
        /*if moves are empty or king is not in check.*/
        if (!(*legal_moves)) {
                return;
        } else if (!(white_moves(b_ptr)&b_ptr->bKing)){
                return;
        }

        Bitboard temp;
        char move[6];
        copy_board(*b_ptr, &temp);
        for (int i = 0; i < 64; i++) {
                if (*legal_moves & squares[i]) {
                        to_text(piece_square,i,move);
                        update(&temp, move);
                        
                        if (white_moves(&temp) & temp.bKing) {
                                *legal_moves &= ~squares[i];//remove this move
                        }
                        copy_board(*b_ptr,&temp);
                }
        }

}
