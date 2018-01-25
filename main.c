#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitBoard.h"
#include "protocol.h"



void command(Bitboard *b);//main control loop for engine
int makeMove(char *cmd, Bitboard *b);

int main(void){
	uint64_t temp = 1;
 /*the following loop initializes an array of 64 boards with just the square that
  *it refers to set. this allows you to use the array to manipulate a single square
  *on the board.*/
	for (int i = 0; i < 64; i++) {
		squares[i] = temp;
		temp <<= 1;
	}

	setbuf(stdout, NULL);//disable buffered output for xboard
	setbuf(stdin, NULL);

	Bitboard  b;
	init(&b);

	play(&b);
	return 0;
}

void command(Bitboard * b)
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
				case NEW:
				init(b);
				break;
				case FORCE: /*do whatever force requires*/;
				case GO:
				play(b);
				break;
				case SETBOARD:/*receive a fen string and update boards*/;
				case MOVE:
				for (int i = 0; i < MAX_CMD_LEN; i++) {
					if(cmd[i] == '+' ) {
						update(b, cmd+i+1);//pass the start of the move.
						printChessboard(b);
						break;
					}
				}
				break;
				case QUIT:
				default:
				break;
			}
		}
		free(cmd);

}

int makeMove(char * cmd, Bitboard * b)
{
	uint64_t legal_moves = 0;
	legal_moves = getLegalMoves(b, WQUEEN);
	printChessboard(b);
	bitBoard_print(legal_moves,0);
	return 0;
}
