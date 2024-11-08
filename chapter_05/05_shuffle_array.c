#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapArray(int array[], int a, int b) {
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

void ShuffleArray(int array[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int num = rand() % i;
        swapArray(array, i, num);
    }
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ShuffleArray(array, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
