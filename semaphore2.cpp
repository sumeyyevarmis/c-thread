// semaphore sync

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t smp;
int sayi = 5;
void *thread(void *arg){
    sem_wait(&smp);
    sayi++;
    long id = pthread_self();
    printf("thread = %ld, sayi = %d\n",id,sayi);
    sem_post(&smp);
    return NULL;
}
int main() {
    sem_init(&smp,0,1);
    pthread_t th[5];
    for(int i = 0;i<5;i++){
        pthread_create(&th[i],NULL,thread,NULL);
    }
    for(int i = 0;i<5;i++){
        pthread_join(th[i],NULL);
    }
    sem_destroy(&smp);
    puts("Terminated");
    return 0;
}