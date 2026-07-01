/* ---------------------------------------------------------------- */
/* PROGRAM  multiple_sig.c:                                         */
/* This is a simple program that illustrates the way to catch       */
/* more than one signal                                             */
/* ---------------------------------------------------------------- */

#include  <stdio.h>
#include  <signal.h>
void sig_handler(int);              
void main(void)
{
     signal(SIGINT, sig_handler);        /* install Ctrl-C handler   */
     signal(SIGQUIT, sig_handler);	     /* install Ctrl-\ handler */	
     while (1);                          /* loop forever   */
}
void  sig_handler(int sig)
{
     char  c;
     signal(SIGINT, SIG_IGN);               
     signal(SIGQUIT, SIG_IGN);
     switch(sig) {
	case SIGINT:
		printf("Ha! Ha! You cannot interrupt me\n");
		break;
	case SIGQUIT:
		printf("Ha! Ha! you cannot quit me\n");
		break;		
     }		
     signal(SIGINT, sig_handler);
     signal(SIGQUIT, sig_handler);
}