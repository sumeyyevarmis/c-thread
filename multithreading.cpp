// creating five thread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N 5
void *worker_thread(void *arg)
{
        printf("This is worker_thread #%ld\n", (long)arg);
        return NULL;
}
int main()
{
        pthread_t my_thread[N];
        long id;
   int ret;
        printf("In main: creating thread\n");
        for(id = 1; id <= N; id++) {
                ret =  pthread_create(&my_thread[id], NULL, worker_thread, (void*)id);
                if(ret != 0) {
                        printf("Error: pthread_create() failed\n");
                }
        }
        for(id = 1; id <= N; id++) {
pthread_join(my_thread[id], NULL);
  }
        return 0;
}
