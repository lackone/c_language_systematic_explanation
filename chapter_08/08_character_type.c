#include <stdio.h>
#include <ctype.h>

int IsDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int main() {
    printf("%d\n", isdigit('0')); //是否数字
    printf("%d\n", isspace(' ')); //是否空格
    printf("%d\n", isalpha('a')); //是否字母
    printf("%d\n", isalnum('f')); //是否字母和数字
    printf("%d\n", isalnum('1')); //是否字母和数字
    printf("%d\n", ispunct(',')); //是否为标点符号

    printf("%c\n", toupper('c'));
    printf("%c\n", tolower('A'));

    return 0;
}
