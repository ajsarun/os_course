/* child.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[ ]){
  	pid_t pid;
  	int ret_value;
  	pid = getpid( );
  	ret_value = (int) (pid % 256);
  	srand((unsigned) pid);
  	sleep(rand() % 5);
	printf("Child %d is terminating with exit(%d)\n", pid, ret_value);
    	exit(ret_value);
}

