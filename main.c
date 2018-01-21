#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitBoard.h"
#include "protocol.h"



void play(Bitboard *b);//main control loop for engine

int main(void){
	//boards = boardInit();
 uint64_t temp = 1;
	for (int i = 0; i < 64; i++) {
		squares[i] = temp;
		temp <<= 1;
	}

	Bitboard  b;
	init(&b);

	////////////////////TODO This is modifying the PAWN board for testing????///////////////
	b.bPawns = b.bPawns - squares[54] + squares[38];
	////modify white for testing
	b.wPawns = b.wPawns - squares[13] + squares[45];
	bitBoard_print(b.bPawns,0);
	play(&b);
	//boardDestroy(boards);
	return 0;
}

void play(Bitboard * b)
{

		char * cmd = (char*)malloc(sizeof(char)*MAX_CMD_LEN);//allocate space for
																												// command
		unsigned int action = 0;//TODO: will be assigned a value depending on action required from engine
		cmd[0] = '\n';
		while(action != 3) {
			fgets(cmd, MAX_CMD_LEN, stdin);
			proto_clean(cmd);//clean the command
			action = proto_exec(cmd);//the the action value
			switch (action) {
				case NEW: /*newgame()*/;
				case FORCE: /*do whatever force requires*/;
				case QUIT: /*quit*/;
				case GO: /*start thinking and make move when done*/;
				case SETBOARD:/*receive a fen string and update boards*/;
				case MOVE:/*receive an algebraic move and update internal boards.*/;
				default:
				if(makeMove(cmd, b)) printf("Error\n");
				break;
			}
			printf("%s\n", cmd);
		}
		free(cmd);

}

int makeMove(char * cmd, Bitboard * b)
{
	getLegalMoves(b, WPAWN);
	return 0;
}
