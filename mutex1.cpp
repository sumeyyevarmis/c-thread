/*
 * mutex ile senkronizasyon
 */
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int sayi = 5;
void *thread(void *arg){
    pthread_mutex_lock(&mutex);
    sayi++;
    long id = pthread_self();
    printf("thread = %ld, sayi = %d\n",id,sayi);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
int main() {
    pthread_t th[5];
    pthread_mutex_init(&mutex,0);
    for(int i = 0;i<5;i++){
        pthread_create(&th[i],NULL,thread,NULL);
    }
    for(int i = 0;i<5;i++){
        pthread_join(th[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    puts("Terminated");
    return 0;
}