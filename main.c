#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include "bitBoard.h"
#include "protocol.h"
#include "play.h"
#include "transposition.h"
#include "evaluate.h"
#include "fpga.h"
//static Bitboard previous_state;

void command(Bitboard *b);//main control loop for engine
#include <unistd.h>
int main(void){
	int memfd = open("/dev/mem", O_RDWR | O_SYNC);
	uint64_t temp = 1;
	/*the following loop initializes an array of 64 boards with just the square that
	*it refers to set. this allows you to use the array to manipulate a single square
	*on the board.*/

  	for (int i = 0; i < 64; i++) {
			squares[i] = temp;
			temp <<= 1;
	}

	t_table = (uint64_t**)malloc(TABLE_SIZE * sizeof(uint64_t*));
	for (int i = 0; i < TABLE_SIZE; i++) {
		t_table[i] = (uint64_t *)malloc(3 * sizeof(uint64_t));
	}

	generate_random_numbers();
	//initialize transposition table to zero
	for(int i = 0; i < TABLE_SIZE; i++) {
		for (int j = 0; j < 3; j++) {
			t_table[i][j] = 0;
		}
	}

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

	/*Allocate FPGA buffer*/
	mem_buf = (volatile fpga_mem *)malloc(sizeof(fpga_mem));

	/* Map HPS into our address space. */
	void *virtual_base = 0;
	virtual_base = mmap(0, 0x04000000, PROT_READ | PROT_WRITE, MAP_SHARED,
                  memfd, 0xfc000000);
	mem_ptr  =  virtual_base  +  ((unsigned  long)(0xff200000)  &  (unsigned long)(0x04000000 - 1));
	int tj = *(int*)mem_ptr;
	printf("%d\n", tj);

	Bitboard b;
	init(&b);


	command(&b);
	for (int i = 0; i < TABLE_SIZE; i++) {
		free(t_table[i]);
	}
 close(memfd);
	munmap((void *)mem_ptr, 256);
	free((void *)mem_buf);
	free(t_table);
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
