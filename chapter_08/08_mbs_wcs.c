#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main() {
    printf("%d\n", iswalpha(L'a'));
    printf("%d\n", iswdigit(L'2'));

    wchar_t *str = L"你好 hello";
    printf("%d\n", wcslen(str));

    //wmemset
    //wmemcpy
    wprintf(L"%ls\n", str);
    _putws(str);

    //mb  multibytes 多字节，对应的就是窄字符
    //mbs  multibytes string 自然就是窄字符串
    //wc  wide character 宽字符
    //wcs wide character string 宽字符串

    //-DCMAKE_C_FLAGS="/utf-8"

    char *new_locale = setlocale(LC_ALL, "zh_CN.UTF-8");
    if (new_locale) {
        printf("%s\n", new_locale);
    }

    char mbs[] = "你好";
    wchar_t wcs[20] = {0};
    mbstowcs(wcs, mbs, 10);
    wprintf(L"%ls\n", wcs);

    return 0;
}
