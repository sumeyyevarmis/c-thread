/*
 * pthread_self() => threadin id numarasýný verir.
 * pthread_equal(id,id) => ile id leri verilmiþ olan threadlerin ayný olup olmadýklarýný kontrol eder.
 * threadler ayný ise 1, farklý ise 0 döndürür.
 */


#include <stdio.h>
#include <pthread.h>
#define N 5

void *thread(void *arg){
    long id = pthread_self();
    printf("this is thread\n");
    printf("thread id = %ld\n",id);
    return NULL;
}

int main() {
    pthread_t my_thread[N];
    int ret;
    for(int i = 0;i<N;i++){
        ret = pthread_create(&my_thread[i], NULL, thread, NULL);
        if(ret != 0){
            printf("hata\n");
        }
    }
    printf("%d\n",pthread_equal(140359365760768, 140359357368064));

    for(int i = 0;i<N;i++){
        pthread_join(my_thread[i],NULL);
    }

    puts("Terminated");
    return 0;
}
