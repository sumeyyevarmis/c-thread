// semaphore sync

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t tek;
sem_t cift;

// tekleri yazan thread
void* thread1(void* arg){
    int i;
    for(i=0;i<10000;i++){
        sem_wait(&tek);
        if(i%2 != 0){
            printf("Bu thread calisti %ld tek sayi = %d\n",(long)arg, i);
        }
        sem_post(&cift);
    }
    return NULL;
}
// çiftleri yazan thread
void* thread2(void* arg){

    int i;
    for(i=0;i<10000;i++){
        sem_wait(&cift);
        if(i%2 == 0){

            printf("Bu thread calisti %ld cift sayi = %d\n",(long)arg, i);
        }
        sem_post(&tek);
    }

    return NULL;
}
int main() {
    sem_init(&tek,0,1);
    sem_init(&cift,0,1);
    pthread_t t1,t2;
    long one =1;
    long two = 2;
    pthread_create(&t1,NULL,thread1,(void*)one);
    pthread_create(&t2,NULL,thread2,(void*)two);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&tek);
    sem_destroy(&cift);
    puts("Terminated");
    return 0;
}