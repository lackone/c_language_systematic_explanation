#include <stdio.h>

int main() {
    //while语句
    int i = 5;
    while (i > 0) {
        printf("%d\n", i);
        i--;
    }

    //for语句
    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }

    //do while语句
    i = 10;
    do {
        printf("%d\n", i);

        i--;
    } while (i > 0);

    //双for循环
    for (int i = 1; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            printf("%d*%d=%d \t", i, j, i * j);
        }
        printf("\n");
    }

    //continue break
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            continue; //跳过当前循环执行下一次
        }
        if (i == 9) {
            break; //跳出循环
        }
    }

    //goto语句
    int b = 0;
BEGIN:
    printf("%d\n", b);
    if (b++ < 5) {
        goto BEGIN;
    }

    return 0;
}
