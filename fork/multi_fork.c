/* multi_fork.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  pid_t pid;
  int i;
  for (int i =0; i < 5; i++) {
    pid = fork();
    if (pid == 0) {
        if (i%2) {
            printf("%d: I am happy\n", i);
            exit(0);
        }
        else {
            printf("%d: I am sad\n", i);
            exit(0);
        }
    }  
  }
  while(wait(NULL) != -1); 
  printf("I am parent, goodbye\n");
  
  return 0;
}
