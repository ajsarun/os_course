/* ----------------------------------------------------------------- */
/* PROGRAM  server.c                                                 */
/*    This program serves as the server similar to the one in shm.c. */
/* The difference is that the client is no more a child process.     */
/* Thus, some mechanism must be established between the server and   */
/* the client.  This program uses a naive one.  The shared memory    */
/* has an indicator whose possible values are NOT_READY, FILLED and  */
/* TAKEN.  Before the server completes filling data, the status is   */
/* NOT_READY, after filling data it is FILLED.  Then, the server just*/
/* wait (busy waiting) until the status becomes TAKEN.               */
/*    Note that the server must be started first.  The client can    */
/* only be started as the server says so.  Otherwise, the client may */
/* not be able to use the shared memory of the data therein.         */
/* ----------------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include  "shm_status.h"

void  main(int  argc, char *argv[])
{
     key_t          shm_key;
     int            shm_id;
     struct Memory  *shm_ptr;
     
     if (argc != 5) {
          printf("Use: %s #1 #2 #3 #4\n", argv[0]);
          exit(1);
     }
     
     shm_key = ftok(".", 'x');
     shm_id = shmget(shm_key, sizeof(struct Memory), IPC_CREAT | 0666);
     if (shm_id < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }
     printf("Server has received a shared memory of four integers...\n");
     
     shm_ptr = (struct Memory *) shmat(shm_id, NULL, 0);
     if ( shm_ptr == NULL) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     printf("Server has attached the shared memory...\n");
     shm_ptr->status  = NOT_READY;
     shm_ptr->data[0] = atoi(argv[1]);
     shm_ptr->data[1] = atoi(argv[2]);
     shm_ptr->data[2] = atoi(argv[3]);
     shm_ptr->data[3] = atoi(argv[4]);
     printf("Server has filled %d %d %d %d to shared memory...\n",
            shm_ptr->data[0], shm_ptr->data[1], 
            shm_ptr->data[2], shm_ptr->data[3]);
     shm_ptr->status = FILLED;
     
     printf("Please start the client in another window...\n");
                 
     while (shm_ptr->status != TAKEN)
          sleep(1);
          
     printf("Server has detected the completion of its child...\n");
     shmdt((void *) shm_ptr);
     printf("Server has detached its shared memory...\n");
     shmctl(shm_id, IPC_RMID, NULL);
     printf("Server has removed its shared memory...\n");
     printf("Server exits...\n");
     exit(0);
}
