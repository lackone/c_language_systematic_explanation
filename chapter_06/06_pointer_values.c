#include <stdio.h>

int *g_int = NULL;

void test() {
    int a = 2;
    g_int = &a;
}

int main() {
    int *p = (int *) 0x1cbffb38;

    printf("%x\n", &p);

    int *pp = NULL;

    //野指针
    printf("%d\n", *g_int);

    return 0;
}
