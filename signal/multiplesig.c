/* ---------------------------------------------------------------- */
/* PROGRAM  multiplesig.c:                                                
*/

#include  <stdio.h>
#include  <signal.h>

void     SIGhandler(int);              

/* ---------------------------------------------------------------- */
/*                   main program starts here                       */
/* ---------------------------------------------------------------- */

void  main(void)
{
     signal(SIGINT, SIGhandler);        /* install Ctrl-C handler   */
     signal(SIGQUIT, SIGhandler);	/* install Ctrl-\ handler */	
     while (1);                          /* loop forever   */
     
}

/* ---------------------------------------------------------------- */
/* FUNCTION  SIGhandler:                                            */
/*    This function handles the SIGINT (Ctrl-C) signal.             */
/* ---------------------------------------------------------------- */

void  SIGhandler(int sig)
{
     char  c;

     signal(SIGINT, SIG_IGN);              /* disable Ctrl-C       */ 
     signal(SIGQUIT, SIG_IGN);
     switch(sig) {
	case SIGINT:
		printf("Ha! Ha! You cannot interrupt me\n");
		break;
	case SIGQUIT:
		printf("Ha! Ha! you cannot quit me\n");
		break;		
     }		
     signal(SIGINT, SIGhandler);
     signal(SIGQUIT, SIGhandler);
           
    
}

