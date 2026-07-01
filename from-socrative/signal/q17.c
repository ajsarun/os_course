#include  <stdio.h>
#include  <signal.h>
void     SIGhandler(int);              
void  main(void)
{
     signal(SIGINT, SIGhandler);        
     signal(SIGQUIT, SIGhandler);	
     signal(SIGKILL, SIGhandler);		
     while (1);                          /* loop forever   */
}
void  SIGhandler(int sig)
{
     char  c;
     signal(SIGINT, SIG_IGN); 
     signal(SIGQUIT, SIG_IGN);
     signal(SIGKILL, SIG_IGN); 	
     switch(sig) {
	case SIGINT:
		printf("Ha! Ha! You cannot interrupt me\n");
		break;
	case SIGQUIT:
		printf("Ha! Ha! you cannot quit me\n");
		break;
	case SIGKILL:
		printf("Ha! Ha! you cannot kill me\n");
		break;		
     }		
     signal(SIGINT, SIGhandler);
     signal(SIGQUIT, SIGhandler);
     signal(SIGKILL, SIGhandler);	         
}