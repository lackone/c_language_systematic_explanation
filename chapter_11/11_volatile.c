#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

volatile int flag = 0;

//volatile 并非为并发程序设计
//volatile 的目的是禁止编译器优化读写操作
//volatile 不会保证访问的原子性
volatile int a = 0;
int x = 0;

int T1(void *arg) {
    a = 2;
    flag = 1;
    a = a + 3; //这条可能直接优化成 a=5
    return 0;
}

int T2(void *arg) {
    while (!flag) {
    }
    x = a * a;
    return 0;
}

int main() {
    thrd_t t1, t2;
    thrd_create(&t1, T1, NULL);
    thrd_create(&t2, T2, NULL);

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    printf("%d\n", x);

    return 0;
}
