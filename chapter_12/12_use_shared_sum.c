#include <stdio.h>

// gcc 12_use_shared_sum.c -L. -l12_shared_sum -o 12_use_shared_sum
// -L.: 告诉编译器在当前目录查找库文件
// -lexample: 指定链接的库，GCC 默认会加上 lib 前缀和 .so 后缀。
int main() {
    printf("%d\n", sum2(3, 5));
    return 0;
}