#include <stdio.h>
#include <string.h>

int main() {
    char *str = "hello world";

    //strlen strnlen 字符串长度
    printf("%d\n", strlen(str));

    printf("%d\n", strnlen(str, 100));

    //strcmp strncmp 比较
    printf("%d\n", strcmp("hello", "hello"));
    printf("%d\n", strncmp("hello", "hello test", 5));

    return 0;
}
