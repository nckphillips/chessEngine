#include <stdint.h>
#include <stdlib.h>
#include "bitBoard.h"

Bitboard **boardInit()
{
  Bitboard **b = (Bitboard **)malloc(sizeof(Bitboard));
  return b;
}

void boardDestroy(Bitboard** b)
{
  free(b);
}

void update(char * move)
{

}
