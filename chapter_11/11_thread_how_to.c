#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

int thrd_start(void *name) {
    printf("Hello World %s\n", (char *) name);
    return 0;
}

int main() {
    thrd_t new_thread;
    int ret = thrd_create(&new_thread, thrd_start, "test");
    if (ret == thrd_success) {
        printf("main = %#x, new = %#x \n", thrd_current(), new_thread);
    } else {
        printf("main = %#x \n", thrd_current());
    }

    //等待线程
    //thrd_sleep(&(struct timespec){.tv_sec = 0, .tv_nsec = 100000000}, NULL);

    //等待线程，获取结果
    int res;
    thrd_join(new_thread, &res);
    printf("%d\n", res);

    //让出时间片
    //thrd_yield();

    //thrd_detach(new_thread);

    return 0;
}
