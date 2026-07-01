#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{
   pid_t pid;
   int i,status;
   for (i =0; i < 3; i++) {
      pid = fork();
      if (pid == 0) {
         printf("I am child %d\n", i);
         exit(i);
      }
   }
   while(wait(&status) != -1) {
      printf("child %d exit\n", WEXITSTATUS(status));
   }
   printf("Goodbye\n");
   return 0;
}