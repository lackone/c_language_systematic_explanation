#include <stdio.h>

//宏函数
//宏只是简单的替换
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

//多行宏
#define IS_HEX_CHAR(ch) \
  ((ch)>='0' && (ch) <= '9') || \
  ((ch)>='A' && (ch) <= 'F') || \
  ((ch)>='a' && (ch) <= 'f')

int main(void) {
    printf("%d\n", MAX(5, 10));

    printf("%d\n", IS_HEX_CHAR('A'));

    return 0;
}
