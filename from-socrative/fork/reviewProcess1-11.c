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
	for (i =0; i < 2; i++) {
		pid = fork();
		if (pid == 0) {
			printf("child %d\n", i+1);
			
		}
	}	
	while(wait(NULL) != -1);
	printf("goodbye\n");
  	return 0;
}