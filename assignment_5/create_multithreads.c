#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int a_global = 0;

void *myThread(void *x)
{

    int *myid = (int *)x;
    static int a_static = 0;
    int local =0;

    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid, ++a_static, ++a_global, local++);
}

int main()
{

    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    pthread_create(&t1, NULL, myThread, (void *)&t1);
    pthread_create(&t2, NULL, myThread, (void *)&t2);
    pthread_create(&t3, NULL, myThread, (void *)&t3);

    pthread_exit(NULL);
    return 0;
}
