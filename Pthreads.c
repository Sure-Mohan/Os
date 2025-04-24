#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *mythread1(void *vargp) {
    int i;
    printf("Thread 1\n");
    for (i = 1; i <= 10; i++) {
        printf("i = %d\n", i);
    }
    printf("Exit from thread 1\n");
    return NULL;
}

void *mythread2(void *vargp) {
    int j;
    printf("Thread 2\n");
    for (j = 1; j <= 10; j++) {
        printf("j = %d\n", j);
    }
    printf("Exit from thread 2\n");
    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    printf("Before threads\n");

    pthread_create(&tid1, NULL, mythread1, NULL);
    pthread_create(&tid2, NULL, mythread2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("After threads\n");

    return 0;
}
