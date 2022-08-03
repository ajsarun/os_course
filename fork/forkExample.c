/* forkExample.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  pid_t pid;
  int i;
  pid = fork();
  if (pid > 0) {  /* parent */
    i = 1;
    printf("I am parent i = %d\n", i);
  }
  else {   /* child */
    i = 2;
    
    printf("I am child i = %d\n", i);
  }
  return 0;
}
