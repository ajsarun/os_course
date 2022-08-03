/* forkExample.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
  pid_t pid;
  int i;
  for (int i = 0; i < 3; i++) {
    pid = fork();
    if (pid == 0) {
      printf("child i = %d\n", i);
      //exit(0);
    }  
    else {
      printf("parent i = %d\n", i);
    }
  }
  return 0;
}
