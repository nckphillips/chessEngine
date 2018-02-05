#ifndef _CHECK_H
#define _CHECK_H
#include <stdint.h>
#include "bitBoard.h"
void getCheck(Bitboard *b_ptr, uint64_t *legal_moves, int piece_square);
#endif
