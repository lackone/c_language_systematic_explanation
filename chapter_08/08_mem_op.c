#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //memcpy 内存拷贝
    //memchr 内存查找
    //memcmp 内存比较
    //memset 设置内存值
    char *mem = malloc(10);
    memset(mem, 0, 10);
    free(mem);

    //memmove 有内存覆盖用memmove
    char *str = "helloworld";
    char *dst = malloc(11);
    memset(dst, 0, 11);
    memcpy(dst, str, 11); //内存不会重叠，用memcpy
    printf("%s\n", dst);

    memmove(dst + 3, dst + 1, 4);
    printf("%s\n", dst);

    return 0;
}
