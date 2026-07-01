/* Prog: dup2.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int pfd[2];
  int pid;

  if (pipe(pfd) == -1)
  {
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
    close(pfd[0]);
    dup2(pfd[1],1 );
    close(pfd[1]);
    execlp("ls", "ls",NULL);
    perror("ls failed");
    exit(3);
  } else {
    close(pfd[1]);
    dup2(pfd[0], 0);
    close(pfd[0]);
    execlp("wc", "wc",NULL);
    perror("wc failed");
    exit(4);
  }
  exit(0);
}
