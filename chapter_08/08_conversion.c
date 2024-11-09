#include <stdio.h>
#include <stdlib.h>

int main() {
    //atof atoi atol atoll
    printf("%d\n", atoi("1234")); //1234
    printf("%d\n", atoi("-1234")); //-1234
    printf("%d\n", atoi("    1234abcd")); //1234
    printf("%d\n", atoi("0x10")); //0

    printf("%lf\n", atof("123.456"));
    printf("%lf\n", atof("-12e34"));
    printf("%lf\n", atof("   12.345abcd"));
    printf("%lf\n", atof("0x10"));
    printf("%lf\n", atof("0x10p3.9"));

    //strtol strtoll 转换有符号整型
    //strtoul strtoull 转换无符号整型
    //strtof strtod strtold 转换浮点
    //strtoimax strtoumax 转换表示范围最大的整型
    //atoX  简单，适用简单，要求不高的场景
    //strtoX 可重复解析，更安全，功能更强大

    char *str = "1 20000000  3 -4 5abcd byte";
    char *start = str;
    char *end;
    while (1) {
        errno = 0;
        long i = strtol(start, &end, 10);
        if (start == end) {
            break;
        }
        printf("%.*s \t ===> %ld", (int) (end - start), start, i);

        if (errno == ERANGE) {
            perror("strtol");
        }

        putchar('\n');
        start = end;
    }

    return 0;
}
