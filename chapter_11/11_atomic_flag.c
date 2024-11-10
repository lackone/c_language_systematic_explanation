#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"
#include <stdatomic.h>

atomic_flag resume_flag = ATOMIC_FLAG_INIT;

int PrintNumber(void *arg) {
    int current = 0;
    while (atomic_flag_test_and_set(&resume_flag)) {
        current++;
        printf("%d\n", current);
        thrd_sleep(&(struct timespec){.tv_sec = 1, .tv_nsec = 0}, NULL);
    }
    return current;
}

int main(void) {
    atomic_flag_test_and_set(&resume_flag);

    thrd_t t;
    thrd_create(&t, &PrintNumber, NULL);

    thrd_sleep(&(struct timespec){.tv_sec = 5, .tv_nsec = 0}, NULL);

    atomic_flag_clear(&resume_flag);

    int ret;
    thrd_join(t, &ret);
    printf("%d\n", ret);

    return 0;
}
