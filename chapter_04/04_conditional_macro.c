#include <stdio.h>

/**
#ifdef 如果定义
#ifndef 如果没有定义
#if 如果
#endif

#if defined(MACRO) ==> #ifdef MACRO
*/

void dump(const char *msg) {
#ifdef DEUBG
      puts(msg);
#endif
}

//c++的宏
#ifdef __cplusplus
extern "C" {
#endif
int add(int a, int b);
#ifdef __cplusplus
};
#endif

int main(void) {
    dump("test");

    //获取当前C版本
    printf("%ld \n", __STDC_VERSION__);

#if __STDC_VERSION__ >= 201112L
    puts("C11");
#elif __STDC_VERSION__ >= 199901L
    puts("C99");
#else
    puts("C89");
#endif

    return 0;
}
