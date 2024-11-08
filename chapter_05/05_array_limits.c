#include <stdio.h>

int main() {
    //数组是有边界的，从0开始到，数组长度-1
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d \n", arr[0]);
    //越界了
    printf("%d \n", arr[10]);

    // arr[5] = arr + 5
    printf("%d \n", *(int *) (arr + 5));

    //C99, 变长数组，gcc可以，msvc不行
    int value = 2;
    int arr2[value];

    return 0;
}
