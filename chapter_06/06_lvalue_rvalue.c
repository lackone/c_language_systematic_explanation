#include <stdio.h>

int main() {
    //在值，表示的是内存空间
    //右值，表示的是一个值
    int a = 2;
    int *p = &a;
    *p = 5; //*p相当于左值

    int b = *p; //*p又相当于右值

    //&a = p; 错误
    //*p + 1 = 3; 错误

    int arr[5] = {0};
    int *pa = arr;
    *pa = 2;
    *(pa++) = 3;
    *(pa + 2) = 4;

    return 0;
}
