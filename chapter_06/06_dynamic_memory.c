#include <stdio.h>
#include <stdlib.h>

void initMem(int **ptr, int len, int value) {
    *ptr = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        (*ptr)[i] = value;
    }
}

int main() {
    //从堆中申请内存
    int *p = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        p[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }

    free(p);

    int *p2 = NULL;
    initMem(&p2, 10, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p2[i]);
    }
    free(p2);

    //calloc会设置分配的内存为零
    int *p3 = calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p3[i]);
    }
    free(p3);

    return 0;
}
