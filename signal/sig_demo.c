/* ---------------------------------------------------------------- */
/* PROGRAM  sig_demo.c:                                             */
/* This is a simple program that illustrates the use of signal      */
/* handler.  It catches Ctrl-C.                                     */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <signal.h>
#include <stdlib.h>
#include <unistd.h>
#define clear_buffer() while(getchar() != '\n') 

void     int_handler(int);               /* Ctrl-C handler           */
/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

void  main(void)
{
     signal(SIGINT, int_handler);         /* install Ctrl-C handler   */
     while (1) {                         /* loop forever and wait    */
          printf("Running...\n");
          sleep(1);                      /* for Ctrl-C to come       */
     }
}

/* ---------------------------------------------------------------- */
/* FUNCTION  int_handler:                                            */
/*    This function handles the SIGINT (Ctrl-C) signal.             */
/* ---------------------------------------------------------------- */

void  int_handler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);   /* disable Ctrl-C           */
     printf("OUCH, did you hit Ctrl-C?\n"    
            "Do you really want to quit? [y/n] ");
     c = getchar();                     /* read an input character  */
	clear_buffer(); 	     
     if (c == 'y' || c == 'Y')          /* if it is y or Y, then    */
          exit(0);                      /* exit.  Otherwise,        */
     else
          signal(SIGINT, int_handler);   /* reinstall the handler    */
}

