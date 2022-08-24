/* forkExample.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
  pid_t pid;
  int i;
  for (int i = 0; i < 5; i++) {
    pid = fork();
    if (pid == 0) {
        if (i%2 == 0 ) {
            
        }
       printf("child i = %d\n", i);
      //exit(0);
    }  
    
    
  }
  return 0;
}
