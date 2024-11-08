#include <stdio.h>

//变长数组，最后一维需要确定
int sumArr(int row, int col, int arr[][col], int ret[]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ret[i] += arr[i][j];
        }
    }
}

int main() {
    int veh_limits[5][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10}
    };

    int ret[5] = {0};
    sumArr(5, 2, veh_limits, ret);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", ret[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            veh_limits[i][0] = 0;
        }
    }

    return 0;
}
