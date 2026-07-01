#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define SIZE 1024
#define READ_SIZE 5
int main(int argc, char **argv)
{
  int pfd[2];
  int nread;
  pid_t pid;
  char buf[SIZE];
  char buf_read[READ_SIZE+1];
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
    /* child */
    close(pfd[1]);
    while ((nread = read(pfd[0], buf_read, READ_SIZE)) != 0) {
      printf("child read %s\n", buf_read);
    }
    close(pfd[0]);
  } else {
    /* parent */
      close(pfd[0]);
      strcpy(buf, "hello world, hello mars, hello universe");
      sleep(2);
      /* include null terminator in write */
      //write(pfd[1], buf, strlen(buf)+1);
      write(pfd[1], buf, strlen(buf));
      close(pfd[1]);
      wait(NULL);
  }
  exit(0);
}
