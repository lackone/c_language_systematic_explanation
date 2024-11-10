#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"
#include <stdatomic.h>

//保证原子操作
atomic_int count = 0;

int thrd_start(void *name) {
    printf("Thread started\n");

    for (int i = 0; i < 1000000; i++) {
        count++;

        //count++ 并非原子操作
        //int tmp = count; count = tmp + 1, tmp;
    }

    return 0;
}

//对共享资源进行非原子的并发访问
//不同线程之间的代码可见性问题
//线程内部代码编译时的重排序问题

int main() {
    thrd_t t1, t2;
    thrd_create(&t1, thrd_start, NULL);
    thrd_create(&t2, thrd_start, NULL);

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    printf("%d\n", count);

    return 0;
}
