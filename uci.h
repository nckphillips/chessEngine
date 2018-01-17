#ifndef _UCI_H
#define _UCI_H

#define MAX_CMD_LEN 256 //maximum length of one line of input to engine

void uci_clean(char *);
int uci_exec(char *);

#endif
