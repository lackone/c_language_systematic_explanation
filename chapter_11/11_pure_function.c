#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

int Counter(void *arg) {
    int local_count = 0;
    for (int i = 0; i < 1000000; i++) {
        local_count++;
    }
    return local_count;
}

int main() {
    thrd_t t1, t2;
    thrd_create(&t1, Counter, NULL);
    thrd_create(&t2, Counter, NULL);

    int count = 0;
    int result = 0;

    thrd_join(t1, &count);
    result += count;
    thrd_join(t2, &count);
    result += count;

    printf("%d\n", result);

    return 0;
}
