#include <stdio.h>

//定义宏
#define COLOR_RED 0xFF0000

int main() {
    //常量，不可修改
    const int RED = 0xFF0000;

    //通过指针，仍然是可以修改的
    int *pRED = &RED;
    *pRED = 0xCCCCCC;

    printf("%x \n", *pRED);
    printf("%x \n", RED);

    printf("%x \n", COLOR_RED);

    //把宏取消
#undef COLOR_RED

    //找不到宏了COLOR_RED
    //printf("%x \n", COLOR_RED);

    return 0;
}
