#include <stdio.h>

// gcc 12_use_static_sum.c 12_static_sum.a -o 12_use_static_sum
// ./12_use_static_sum
// ldd 12_use_static_sum 查看需要用到的动态链接库
int main(void) {
    printf("%d\n", sum2(3, 5));
    return 0;
}