#include <stdint.h>
#include <stdlib.h>
#include "bitBoard.h"

Bitboard **boardInit()
{
  Bitboard **b = (Bitboard **)malloc(sizeof(Bitboard)*33*NUM_BOARDS_PP);
  return b;
}

void bitBoard_print(struct Bitboard* b) {
  uint64_t total = b->allWhite | b->allBlack;
  for(int i = 0; i < 64; i++) {
    if(!(i%8)) {//print a return at the end of every row.
      printf("\n");
    }
    printf("%d \n", (total & 0x0000001));
    total >>= 1;
  }
}

void boardDestroy(Bitboard** b)
{
  free(b);
}

void update(char * move)
{

}
