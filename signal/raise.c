/* ---------------------------------------------------------------- */
/* PROGRAM  raise.c:                                                */
/*   This program demonstrates the use of ANSI C library function   */
/* raise().                                                         */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>
#include  <signal.h>

signed long  prev_fact, i;                /* global variables              */

void  SIGhandler(int);             /* SIGUSR1 handler               */

/* ---------------------------------------------------------------- */
/* FUNCTION  SIGhandler:                                            */
/*    This function handles the SIGUSR1 signal.  It prints out the  */
/* values of i and prev_fact = (i-1)!                               */
/* ---------------------------------------------------------------- */


void  SIGhandler(int sig)
{
     printf("\nReceived a SIGUSR1.  The answer is %ld! = %ld\n", 
               i-1, prev_fact);
     exit(0);
}
     
/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

int  main(void)
{
     signed long  fact;

     printf("Factorial Computation:\n\n");
     signal(SIGUSR1, SIGhandler);  /* install SIGUSR1 handler       */
     for (prev_fact = i = 1; ; i++, prev_fact = fact) { 
          fact = prev_fact * i;    /* computing factorial           */
          if (fact < prev_fact)            /* if the results wraps around   */
               raise(SIGUSR1);     /* we have overflow, print it    */
          else     /* otherwise, print the value    */
               printf("     %ld! = %ld (%ld) \n", i, fact, prev_fact);
     }
     return 0;
}
     
