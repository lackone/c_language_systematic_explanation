#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void swap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void swap2(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap3(void *x, void *y, size_t size) {
    void *tmp = malloc(size);
    if (tmp) {
        memcpy(tmp, x, size);
        memcpy(x, y, size);
        memcpy(y, tmp, size);

        free(tmp);
    }
}

#define SWAP(x, y, type) {type tmp = x; x = y; y = tmp;}

#define SWAP_EXT(x, y, type) do { type tmp = x; x = y; y = tmp; } while(0)

//typeof 获取类型
//c++ decltype(a)
#define SWAP2(x, y) {typeof(x) tmp = x; x = y; y = tmp;}

int main() {
    int a = 3, b = 5;

    swap(a, b);
    printf("a = %d, b = %d\n", a, b);
    swap2(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    swap3(&a, &b, sizeof(int));
    printf("a = %d, b = %d\n", a, b);

    SWAP(a, b, int);
    printf("a = %d, b = %d\n", a, b);

    SWAP2(a, b);
    printf("a = %d, b = %d\n", a, b);

    if (a)
        SWAP_EXT(a, b, int);
    else {
        printf("no swap");
    }

    return 0;
}
