#include <stdio.h>

int main() {
    int a, b, c;

    //赋值运算符
    c = b = a = 11;
    //运算符 + - * /
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);
    c = a - b;
    printf("%d - %d = %d\n", a, b, c);
    c = a * b;
    printf("%d * %d = %d\n", a, b, c);
    c = a / b;
    printf("%d / %d = %d\n", a, b, c);

    //关系运算符 > == < != >= <=
    printf("%d \n", a > b);
    printf("%d \n", a < b);
    printf("%d \n", a == b);
    printf("%d \n", a != b);
    printf("%d \n", a >= b);
    printf("%d \n", a <= b);

    //逻辑运算符 && ||
    printf("%d \n", a && b);
    printf("%d \n", a || b);

    //自增++ 自减--
    printf("%d \n", ++a);
    printf("%d \n", a++);
    printf("%d \n", --a);
    printf("%d \n", a--);

    //位运算 & | ^ ~
    printf("%d \n", 0x01 & 0x10); //0x0
    printf("%d \n", 0x01 | 0x10); //0x11
    printf("%d \n", 0x01 ^ 0x10); //0x11
    printf("%d \n", ~0x01); //0xfffffffe

    //移位运算符
    printf("%d \n", 0x1 << 10);
    printf("%d \n", 0x1 >> 10);

    //复合赋值运算符
    a *= 2;
    a /= 2;
    a += 2;
    a -= 2;
    a %= 2;

    //逗号运算符
    a = (b * 2, b * 3);
    printf("%d \n", a);

    return 0;
}
