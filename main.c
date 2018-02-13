#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bitBoard.h"
#include "protocol.h"
#include "play.h"
#include "evaluate.h"

static Bitboard previous_state;

void command(Bitboard *b);//main control loop for engine

int main(void){


	uint64_t temp = 1;

	/*the following loop initializes an array of 64 boards with just the square that
	*it refers to set. this allows you to use the array to manipulate a single square
	*on the board.*/

  	for (int i = 0; i < 64; i++) {
			squares[i] = temp;
			temp <<= 1;
		}

   /* Testing the commads for the xboard */


  	char *s = (char *)malloc(MAX_CMD_LEN);
  	fgets(s, MAX_CMD_LEN, stdin);
	if (!strcmp(s, "xboard\n")) {
		printf("\n");
	}
	fgets(s, MAX_CMD_LEN, stdin);
	if (!strcmp(s, "protover 2\n")) {
		printf("feature sigint=0 sigterm=0 usermove=0 done=1\n");
	}
	free(s);

	setbuf(stdout, NULL);//disable buffered output for xboard
	setbuf(stdin, NULL);


	Bitboard  b;
	init(&b);
	init(&previous_state);
	
//	int pos = getPositionValue(b.bPawns, BPAWN);
//	printf("Black Pawns position evaluates to %d", pos);
	command(&b);
	return 0;
}

void command(Bitboard * b)
{
	char * cmd = (char*)malloc(sizeof(char)*MAX_CMD_LEN);//allocate space for
																											// command
	unsigned int action = 0;
	cmd[0] = '\n';
	while(action != QUIT) {
		fgets(cmd, MAX_CMD_LEN, stdin);
		proto_clean(cmd);//clean the command
		action = proto_exec(cmd);//the the action value
		switch (action) {
			case NEW:
			init(b);
			break;

			case FORCE: /*do whatever force requires*/;
			break;

			case SETBOARD:/*receive a fen string and update boards*/;
			break;


			//case TIME:
			case MOVE:
			update(b, cmd);
			play(b);
			break;

			case QUIT:
			default:
			break;
		}
		fflush(stdin);
		fflush(stdout);
	}
	free(cmd);
	return;

}
