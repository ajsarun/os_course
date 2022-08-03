/* ---------------------------------------------------------------- */
/* PROGRAM  sig-0.c:                                                */
/*    This is a simple program that illustrates the use of signal   */
/* handler.  It catches Ctrl-C.                                     */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <signal.h>
#include <stdlib.h>
#include <unistd.h>
#define clear_buffer() while(getchar() != '\n') 

void     INThandler(int);               /* Ctrl-C handler           */

/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

void  main(void)
{
     signal(SIGINT, INThandler);         /* install Ctrl-C handler   */
     while (1)                          /* loop forever and wait    */
          pause();                      /* for Ctrl-C to come       */
}

/* ---------------------------------------------------------------- */
/* FUNCTION  INThandler:                                            */
/*    This function handles the SIGINT (Ctrl-C) signal.             */
/* ---------------------------------------------------------------- */

void  INThandler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);   /* disable Ctrl-C           */
     printf("OUCH, did you hit Ctrl-C?\n"    /* print something     */
            "Do you really want to quit? [y/n] ");
     c = getchar();                     /* read an input character  */
	  clear_buffer(); 	     
		if (c == 'y' || c == 'Y')          /* if it is y or Y, then    */
          exit(0);                      /* exit.  Otherwise,        */
     else
          signal(SIGINT, INThandler);   /* reinstall the handler    */
}

