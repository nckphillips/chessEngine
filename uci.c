#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "uci.h"

/*The following function receives a string and cleans all whitespace and unrecognized commands*/
void uci_clean(char *cmd)
{
  /*Remove whitespace and replace with delimiters (+) until null char is reached*/
  for(int i = 0; i < MAX_CMD_LEN && cmd[i] != EOF; i++) {
    if(cmd[i] == '\n') {
      cmd[i] = EOF;//end of line becomes end of file
    } else if (isspace(cmd[i])) {
      cmd[i] = '+';
    }
  }

  /*now that whitespace is removed we can further clean the command by removing
   *junk or unsupported commands*/
}

/*The following receives a command and executes the command, and returns a value
 * depending on whether the engine needs to perform an action*/
int uci_exec(char *cmd)
{
  return 0;
}

/*checks string of characters up to newline to see if it is supported by the engine.*/
int checkCommand(char *cmd)
{
  /*uci
  isready
  ucinewgame
  go
  stop
  quit*/
  return 0;
}
