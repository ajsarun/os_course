#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/* waitpid.c */

int main(){
  pid_t           pid[3], w;		/* pid is now an array of PIDs   */
  int             i, status;
  char            value[3]; 		/* place to store index as string */
  for (i = 0; i < 3; ++i) {		/* generate 3 child processes     */
    if ((pid[i] = fork()) == 0) {	/* store each PID in the array    */
      execl("child", "child", NULL);
    } else
      printf("Forked child %d\n", pid[i]);
  }

/*	Wait for the children ... in order of generation			
*/
  for( i=0; (w = waitpid( pid[i], &status, 0)) && w != -1; ++i ) {
        printf("Wait on PID: %d returns value of  : %d\n", w,
                WEXITSTATUS(status));
  }
  exit(0);
}

