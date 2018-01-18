#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitBoard.h"
#include "protocol.h"

static Bitboard **boards;//the array of board representations

void play(void);//main control loop for engine

int main(void){
	boards = boardInit();
	play();
	boardDestroy(boards);
	return 0;
}

void play(void)
{
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
