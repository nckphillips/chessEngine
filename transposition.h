#ifndef TRANSPOSE_H_
#define TRANSPOSE_H_

#define TABLE_SIZE 100000
#include "bitBoard.h"
enum table_indices{KEY,VALUE,DEPTH};

uint64_t t_table[TABLE_SIZE][3];//key,value,depth

uint64_t random_numbers[12][64][2];

void generate_random_numbers();

uint64_t zobrist_hash(Bitboard *b_ptr, char sidetomove);

#endif
