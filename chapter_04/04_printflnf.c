#include <stdio.h>
#include <stdarg.h>

void printlnf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    vprintf(format, args);
    printf("\n");

    va_end(args);
}

//__FILE__ 文件路径
//__LINE__ 行号
//__FUNCTION__ 函数名
#define PRINTLNF(format, ...) printf("("__FILE__":%d) %s : "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__);

//一个#号，会把value当作字符串字面量
#define PRINT_INT(value) PRINTLNF(#value": %d", value)

int main(void) {
    printlnf("Hello World!");
    printlnf("Hello World!");
    printlnf("Hello World!");

    PRINTLNF("Hello World! %d ", 12131);
    PRINTLNF("Hello World! %d ", 12131);

    int a = 3333;
    PRINT_INT(a);

    PRINT_INT(3 + 4);

    return 0;
}
