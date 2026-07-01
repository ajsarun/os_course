/* ---------------------------------------------------------------- */
/* PROGRAM  raise.c:                                                */
/* This program demonstrates the use of raise() function            */
/* raise().                                                         */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>
#include  <signal.h>

signed long  prev_fact, i; 

void  sig_handler(int);             /* SIGUSR1 handler */

/* ---------------------------------------------------------------- */
/* FUNCTION  sig_handler:                                           */
/* This function handles the SIGUSR1 signal.                        */
/* It prints out the values of i-1 and prev_fact = (i-1)!           */
/* ---------------------------------------------------------------- */

void  sig_handler(int sig)
{
     printf("\nReceived a SIGUSR1.  The answer is %ld! = %ld\n", 
               i-1, prev_fact);
     exit(0);
}

int  main(void)
{
     signed long  fact;

     printf("Factorial Computation:\n\n");
     signal(SIGUSR1, sig_handler);  /* install SIGUSR1 handler       */
     for (prev_fact = i = 1; ; i++, prev_fact = fact) { 
          fact = prev_fact * i;    /* computing factorial           */
          if (fact < prev_fact)            /* if the results wraps around   */
               raise(SIGUSR1);     /* we have overflow, print the last result */
          else     /* otherwise, print the value    */
               printf("%ld! = %ld (%ld) \n", i, fact, prev_fact);
     }
     return 0;
}