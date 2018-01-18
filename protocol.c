#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "protocol.h"

void move_next_cmd(char *cmd,int i) {
  int j = i+1;
  i+=1;
  while (!isalpha(cmd[j]) && cmd[j] != '\n' && cmd[j] != '\0') {
    j++;
  }
  if (cmd[j] == '\n' || cmd[j] == '\0')
    cmd[i-1] = '\0';
  else {
    while (isalpha(cmd[j])) {
      cmd[i] = cmd[j];
      cmd[j] = '\n';//once character is copied, replace with newline
      j++;
      i++;
    }
  }
}

/*The following function receives a string and cleans all whitespace and unrecognized commands*/
void proto_clean(char *cmd)
{
  /*Remove whitespace and replace with delimiters (+) until null char is reached*/
  for(int i = 0; i < MAX_CMD_LEN && cmd[i] != '\0'; i++) {
    if(cmd[i] == '\n') {
      cmd[i] = '\0';//end of line becomes end of file
    } else if (isspace(cmd[i])) {
      cmd[i] = '+';
      if (isspace(cmd[i+1])) {
        move_next_cmd(cmd,i);//if there were multiple spaces next to eachother, get rid of them
      }
    }
  }
}

/*The following receives a command and executes the command, and returns a value
 * depending on whether the engine needs to perform an action. This function
 * ignores unrecognized commands per the UCI specs.
 ******************************************************************
*/
int proto_exec(char *cmd)
{
  if (!strcmp(cmd, "xboard")) {
    printf("\n");
  } else if (!strcmp(cmd, "new")) {
    return NEW;
  } else if (!strcmp(cmd, "force")) {
    return FORCE;
  } else if (!strcmp(cmd,"quit")) {
    return QUIT;
  } else if (!strcmp(cmd, "go")) {
    return GO;
  }
  return NONE;
}
