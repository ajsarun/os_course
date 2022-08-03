/* parent.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
  pid_t pid, w;
  int i, status;
  char value[3];            /* place to store index as string */   
  for (i = 0; i < 3; ++i) {		   /* generate 3 child processes	    */
    if ((pid = fork( )) == 0) {
      execl("child", "child", NULL);
    } else                             /* assuming no failures here ...  */
      printf("Forked child %d\n", pid);
  }
/*	Wait for the children				
*/
  while ((w = wait(&status)) && w != -1) {
 	printf("Wait on PID: %d returns status of : %d\n", w, 
			WEXITSTATUS(status));
    /*printf("Wait on PID: %d returns status of : %d\n", w, 
			status);*/
  }
  exit(0);
}

