#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
  pid_t pid[3], w;		
  int i, status;
  for (i = 0; i < 3; ++i) {		
    if ((pid[i] = fork()) == 0) {	
      printf("I am child %d, my pid is %d\n", i, getpid());
      exit(i);
    }  
  }
  for( i=0; (w = waitpid( pid[i], &status, 0)) && w != -1; ++i ) {
        printf("Wait on PID: %d returns value of  : %d\n", w,
            WEXITSTATUS(status));
  }
  exit(0);
}