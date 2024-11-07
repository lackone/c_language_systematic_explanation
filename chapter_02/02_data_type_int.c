#include <stdio.h>
#include <limits.h>

int main() {
    //有符号
    short a = 0; //16位
    int b = 0; //32位
    long int c = 0; //32位
    long long int d = 0; //64位

    //无符号
    unsigned short e = 0;
    unsigned int f = 0;
    unsigned long g = 0;
    unsigned long long h = 4294967296;

    //size_t 64系统下是64位，32位下32位
    size_t t = 1;
    printf("sizeof(size_t) = %ld\n", sizeof(size_t));

    //sizeof获取类型占用字节大小
    printf("sizeof(short) = %ld\n", sizeof(short));
    printf("sizeof(int) = %ld\n", sizeof(int));
    printf("sizeof(long) = %ld\n", sizeof(long));
    printf("sizeof(long long) = %ld\n", sizeof(long long));

    //%hd short
    //%hu unsigned short
    //%d 整型 int
    //%ld 打印长整型  long
    //%lld 打印长长整型 long long
    printf("%llu \n", h);

    //%x 十六进制
    //%o 八进制
    //%d 十进制
    printf("%x \n", 123);

    //%d打印有符号，%u打印无符号
    printf("int min = %d max = %d \n", INT_MIN, INT_MAX);
    printf("unsigned int min = 0 max = %u \n", UINT_MAX);

    return 0;
}
