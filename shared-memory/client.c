/* ----------------------------------------------------------------- */
/* PROGRAM  client.c                                                 */
/*    This is the client program.  It can only be started as the     */
/* server says so.  The client requests the same shared memory the   */
/* server established, attaches it to its own address space, takes   */
/* the data, changes the status to TAKEN, detaches the shared memory,*/
/* and exits.                                                        */
/* ----------------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

#include  "shm_status.h"

void  main(void)
{
     key_t          shm_key;
     int            shm_id;
     struct Memory  *shm_ptr;
     
     shm_key = ftok(".", 'x');
     shm_id = shmget(shm_key, sizeof(struct Memory), 0666);
     if (shm_id < 0) {
          printf("*** shmget error (client) ***\n");
          exit(1);
     }
     printf("   Client has received a shared memory of four integers...\n");
     
     shm_ptr = (struct Memory *) shmat(shm_id, NULL, 0);
     if (shm_ptr == NULL) {
          printf("*** shmat error (client) ***\n");
          exit(1);
     }
     printf("   Client has attached the shared memory...\n");
     
     while (shm_ptr->status != FILLED);
     printf("   Client found the data is ready...\n");
     printf("   Client found %d %d %d %d in shared memory...\n",
                shm_ptr->data[0], shm_ptr->data[1], 
                shm_ptr->data[2], shm_ptr->data[3]);

     shm_ptr->status = TAKEN;
     printf("   Client has informed server data have been taken...\n");
     shmdt((void *) shm_ptr);
     printf("   Client has detached its shared memory...\n");
     printf("   Client exits...\n");
     exit(0);
}
