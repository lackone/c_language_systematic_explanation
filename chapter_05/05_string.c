#include <locale.h>
#include <stdio.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "");

    char str[] = "Hello World";

    //c语言字符串必须 \0 结尾
    printf("%s\n", str);
    printf("%d\n", strlen(str));

    wchar_t str2[] = L"你好，中国";
    wprintf(L"%ls\n", str2);

    return 0;
}
