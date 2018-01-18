#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitBoard.h"
#include "protocol.h"

//static Bitboard **boards; //the array of board representations

void play(void);//main control loop for engine

int main(void){
  //boards = boardInit();
  
  struct Bitboard  b;
  init(&b);

  uint64_t allWhite = b.wPawns | b.wRooks | b.wKnights | b.wBishops | b.wQueen | b.wKing;
  uint64_t allBlack = b.bPawns | b.bRooks | b.bKnights | b.bBishops | b.bQueen | b.bKing;
  uint64_t allPieces = allWhite | allBlack;
  // play();
  bitBoard_print(allPieces, 0);
  //boardDestroy(boards);
  return 0;
}

void play(void)
{

  char * cmd = (char*)malloc(sizeof(char)*MAX_CMD_LEN);//allocate space for command
  unsigned int action = 0;//TODO: will be assigned a value depending on action required from engine
  cmd[0] = '\n';
  while(action != 3) {
    fgets(cmd, MAX_CMD_LEN, stdin);
    proto_clean(cmd);
    action = proto_exec(cmd);
    printf("%s\n", cmd);
  }
  free(cmd);
=======
		char * cmd = (char*)malloc(sizeof(char)*MAX_CMD_LEN);//allocate space for
																												// command
	  unsigned int action = 0;//TODO: will be assigned a value depending on action required from engine
		cmd[0] = '\n';
		while(action != 3) {
			fgets(cmd, MAX_CMD_LEN, stdin);
			proto_clean(cmd);
			action = proto_exec(cmd);
			switch (action) {
				case NEW: /*newgame()*/;
				case FORCE: /*do whatever force requires*/;
				case QUIT: /*quit*/;
				case GO: /*start thinking and make move when done*/;
				case SETBOARD:/*receive a fen string and update boards*/;
				case MOVE:/*receive an algebraic move and update internal boards.*/;
			}
			printf("%s\n", cmd);
		}
		free(cmd);

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
} //Initialize bitboard





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
