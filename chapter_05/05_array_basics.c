#include <stdio.h>

//全局数组，默认值0
int g_int[10];

int main() {
    //数组，就是连续的，类型相同的，一组数据
    //数组下标从零开始
    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    //初始化列表，初始化数组
    double arr2[5] = {3.2, 1.4};
    for (int i = 0; i < 5; i++) {
        printf("arr2[%d] = %lf\n", i, arr2[i]);
    }

    //C99，按位置初始化
    char arr3[5] = {[2] = 'c', 'a'};
    for (int i = 0; i < 5; i++) {
        printf("arr3[%d] = %c\n", i, arr3[i]);
    }
}
