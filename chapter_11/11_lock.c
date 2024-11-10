#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

int count = 0;
mtx_t mutex;

int thrd_start(void *name) {
    printf("Thread started\n");

    for (int i = 0; i < 1000000; i++) {
        //加锁
        mtx_lock(&mutex);
        count++;
        //解锁
        mtx_unlock(&mutex);
    }

    return 0;
}

int main() {
    mtx_init(&mutex, mtx_plain);

    thrd_t t1, t2;
    thrd_create(&t1, thrd_start, NULL);
    thrd_create(&t2, thrd_start, NULL);

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    printf("%d\n", count);

    //mtx_t;
    //mtx_init();
    //mtx_destroy();
    //mtx_lock();
    //mtx_unlock();
    //mtx_timedlock();
    //mtx_trylock();

    mtx_destroy(&mutex);

    return 0;
}
