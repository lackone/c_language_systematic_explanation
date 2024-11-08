#include <stdio.h>
#include "include/factorial.h"

//<> 查找工程的头文件搜索路径
//"" 首先查找当前源文件所在路径，查找工程的头文件搜索路径

int main() {
    printf("%d\n", Factorial(10));
    return 0;
}
