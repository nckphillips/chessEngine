#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitBoard.h"
#include "uci.h"

static Bitboard *boards;//the array of board representations

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
	  //unsigned int action = 0;//TODO: will be assigned a value depending on action required from engine
		cmd[0] = '\n';
		while(cmd[0] != EOF) {
			fgets(cmd, MAX_CMD_LEN, stdin);
			uci_clean(cmd);
			//action = uci_exec(cmd);//TODO: im thinking uci exec can return here if this is a go command or something.
			printf("%s\n", cmd);
		}
		free(cmd);
}
