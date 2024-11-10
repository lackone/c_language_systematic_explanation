#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

//每个线程都有一个副本
_Thread_local int count = 0;

int Counter(void *step) {
    for (int i = 0; i < 1000000; i++) {
        count += *(int *) step;
    }
    printf("%d\n", count);
    return 0;
}

int main() {
    thrd_t t1, t2;

    int step_1 = 1, step_2 = 2;
    thrd_create(&t1, Counter, &step_1);
    thrd_create(&t2, Counter, &step_2);

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    //主线程，也有count的副本
    printf("%d\n", count);

    //tss_create()
    //tss_delete()

    return 0;
}
