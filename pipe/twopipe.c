#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 1024

int main(int argc, char **argv)
{
  int pfd1[2];
  int pfd2[2]; 
  int nread;
  int pid;
   int status;
  char buf[SIZE];

  if (pipe(pfd1) == -1)
  {
    perror("pipe failed");
    exit(1);
  }
  if (pipe(pfd2) == -1) {
	perror("pipe failed");
	exit(1);
  }

  if ((pid = fork()) < 0)
  {
    perror("fork failed");
    exit(2);
  }

  if (pid == 0)
  {
    /* child */
    close(pfd1[1]);
    close(pfd2[0]);
    while ((nread = read(pfd1[0], buf, SIZE)) != 0) {	
    	printf("child read %s\n", buf);
    }
    close(pfd1[0]);
    strcpy(buf, "I am fine thank you");
    write(pfd2[1], buf, strlen(buf) + 1);
    close(pfd2[1]);	
  } else {
    /* parent */
    close(pfd1[0]);
    close(pfd2[1]);
    strcpy(buf, "How are you\0");
    /* include null terminator in write */
    write(pfd1[1], buf,
	  strlen(buf)+1);
    close(pfd1[1]);
    while ((nread = read(pfd2[0], buf, SIZE)) != 0) 
	printf("Parent read %s\n", buf);	 
    close(pfd2[0]);
  }
  exit(0);
}
