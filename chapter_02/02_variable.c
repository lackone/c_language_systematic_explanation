#include <stdio.h>

int main() {
    // <type> <name>
    int value;

    // <type> <name> = <value>
    int value2 = 3;

    //赋值
    value2 = 4;

    //取地址
    printf("%llx \n", &value2);
    printf("%p \n", &value2);

    return 0;
}