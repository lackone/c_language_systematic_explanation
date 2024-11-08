#include <stdio.h>

int sumArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

//避免函数返回值带来的开销
//实现函数的多个返回值的目的
void sumArr2(int arr[], int size, int *ret) {
    for (int i = 0; i < size; i++) {
        *ret += arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //内存进行了2次拷贝
    int sum = sumArr(arr, 10);

    printf("%d\n", sum);

    //内存只进行一次拷贝
    int sum2 = 0;
    sumArr2(arr, 10, &sum2);
    printf("%d\n", sum2);

    return 0;
}
