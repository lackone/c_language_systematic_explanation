#include <stdio.h>

//函数原型
//函数名
//返回值类型，如果没写，默认为int
//参数个数和类型，顺序，参数名不重要
void printMsg();

int main() {
    printMsg();
    return 0;
}

void printMsg() {
    printf("test\n");
}
