#include <stdio.h>
#include <string.h>

int main() {
    //strchr strrchr 查找字符
    char *str = "hello world";

    printf("%s\n", strchr(str, 'o'));
    printf("%s\n", strrchr(str, 'o'));

    //strpbrk
    char *str2 = "c, 1972; c++, 1983; java, 1995";
    int count = 0;
    char *p = str2;
    do {
        p = strpbrk(p, ",;");
        if (p) {
            puts(p);
            p++;
            count++;
        }
    } while (p);
    printf("%d\n", count);

    //strstr 查找子串
    printf("%s\n", strstr(str, "wor"));
}
