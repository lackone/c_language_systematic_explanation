#include <locale.h>
#include <stdio.h>

int main() {
    setlocale(LC_ALL, "");

    //字符集 ASCII
    char a = 'a'; //97
    char i = 0; // \0

    //字符a的八进制和十六进制表示
    char a_oct = '\141';
    char a_hex = '\x61';

    printf("char a %d \n", a);
    printf("char 0 %d \n", i);

    //%c打印字符
    printf("char a %c \n", a);
    printf("char a %c \n", a_oct);
    printf("char a %c \n", a_hex);

    char zhong = '中';
    printf("%d \n", zhong);

    //宽字符，占2个字节
    wchar_t zhong2 = L'中';
    //宽字符通过 \u + 编码 表示一个宽字符
    wchar_t zhong3 = L'\u4E2D';

    //%lc 打印一个宽字符
    wprintf(L"%lc %x \n", zhong2, zhong2);
    wprintf(L"%lc %x \n", zhong3, zhong3);

    return 0;
}
