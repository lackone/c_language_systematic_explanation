#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);

    int *p = &a;
    printf("%d\n", *p);

    //地址一样
    printf("%x\n", p);
    printf("%x\n", &a);

    printf("%d\n", sizeof(int*));

    int **pp = &p;
    printf("%x\n", &p);
    printf("%x\n", pp);
    printf("%x\n", *pp);

    return 0;
}
