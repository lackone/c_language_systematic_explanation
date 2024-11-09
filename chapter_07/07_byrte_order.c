#include <stdio.h>

//小端，数据低位放低地址，高位放高地址  对于0x100, 存放 00 01
//大端，数据低位放高地址，高位放低地址  对于0x100，存放 01 00
int IsBigEndian() {
    union {
        char c[2];
        short s;
    } value = {.s = 0x100};

    return value.c[0] == 1;
}

int IsBigEndian2() {
    short s = 0x100;
    char *p = (char *) &s;
    return p[0] == 1;
}

int toggleEndian(int original) {
    union {
        char c[4];
        int i;
    } value = {.i = original};

    char tmp = value.c[0];
    value.c[0] = value.c[3];
    value.c[3] = tmp;
    tmp = value.c[1];
    value.c[1] = value.c[2];
    value.c[2] = tmp;

    return value.i;
}

int toggleEndian2(int original) {
    char *p = (char *) &original;
    char tmp = p[0];
    p[0] = p[3];
    p[3] = tmp;
    tmp = p[1];
    p[1] = p[2];
    p[2] = tmp;
    return original;
}

int main() {
    printf("%d\n", IsBigEndian());

    int original = 0x12345678;
    printf("%x\n", toggleEndian(original));

    printf("%x\n", toggleEndian2(original));

    return 0;
}
