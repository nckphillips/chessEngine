#ifndef _UCI_H
#define _UCI_H

#define MAX_CMD_LEN 256 //maximum length of one line of input to engine

enum action {NONE, NEW, FORCE, QUIT, GO, SETBOARD, MOVE};

void proto_clean(char *);
int proto_exec(char *);

#endif
