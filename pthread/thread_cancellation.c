#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Thread started\n");
    
    // Set cancellation type and state
    //pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    //pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    
    // Simulate work
    int i = 0;
    while(1) {
        //Deferred cancellation will check for cancellation point
        //if this loop does not have cancellation point 
        //and the mode is deferred cancellation it will not terminate.
        //But it will terminate if we use Asynchronous cancellation  
        //printf("Thread working %d\n", i); //printf() is also cancellation point
        //sleep(1);                       //sleep() is cancellation point
        // Periodic cancellation points
        //pthread_testcancel();           //this is also cancellation point
        i++;
    }
    printf("Thread finished work\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;
    int result;

    // Create the thread
    pthread_attr_init(&attr);
    result = pthread_create(&thread, &attr, thread_function, NULL);
    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    // Sleep for 1 seconds and then cancel the thread
    sleep(1);
    pthread_cancel(thread);

    // Wait for the thread to finish
    pthread_join(thread, NULL);
    
    printf("Thread cancelled\n");
    return 0;
}
