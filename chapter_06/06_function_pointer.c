#include <stdio.h>
#include <stdlib.h>

void initMem(int **ptr, int len, int value) {
    *ptr = (int *) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        (*ptr)[i] = value;
    }
}

//返回类型int*
int *f(int, double);

//函数指针
int (*f2)(int, double);

//函数指针，返回类型int*
int *(*f3)(int, double);

//int (*f4)(int, double)[];

//函数指针数组
int (*f5[])(int, double);

//定义函数指针类型
typedef int (*funcPtr)(int, double);

typedef int *intPtr;

int test(int, double) {
    printf("test");
}

int main(void) {
    printf("%x\n", main);

    //函数指针
    void (*func)(int **ptr, int len, int value) = initMem;

    int *p = NULL;
    func(&p, 10, 1);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    free(p);

    funcPtr fn = test;
    fn(1, 3.3);

    return 0;
}
