#include <stdio.h>

//数组传参，需要传递长度
//数组传递只是传递了首地址
int sumArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d\n", sumArr(arr, 10));

    return 0;
}
