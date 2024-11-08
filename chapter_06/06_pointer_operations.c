#include <stdio.h>

int main() {
    int a = 2;
    int *p = &a;

    //指针的运算，跟解引用后的类型相关
    printf("%d\n", p);
    printf("%d\n", p + 1);

    double b = 3.14;
    double *p2 = &b;

    printf("%d\n", p2);
    printf("%d\n", p2 + 1);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p3 = arr;
    for (int i = 0; i < 10; i++) {
        printf("%d\n", *(p3 + i));
        printf("%d\n", arr[i]);
    }

    //指针的比较
    printf("%d \n", (p + 1) > (p + 2));
}
