#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

tss_t count_key;

void MyFree(void *p) {
    printf("Freeing %p\n", p);
    free(p);
}

int Counter(void *step) {
    int *count = malloc(sizeof(int));
    *count = 0;

    if (tss_set(count_key, count) == thrd_success) {
        for (int i = 0; i < 1000000; i++) {
            *count += *(int *) step;
        }
    }

    printf("%d\n", *count);
    printf("%d\n", *(int *) tss_get(count_key));
    return 0;
}

int main() {
    if (tss_create(&count_key, MyFree) == thrd_success) {
        thrd_t t1, t2;

        int step_1 = 1, step_2 = 2;
        thrd_create(&t1, Counter, &step_1);
        thrd_create(&t2, Counter, &step_2);

        //tss_delete提前删除key，则MyFree不会调用

        thrd_join(t1, NULL);
        thrd_join(t2, NULL);

        tss_delete(count_key);
    }

    return 0;
}
