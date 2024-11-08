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

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int partition = low;
    for (int i = low; i < high; i++) {
        if (array[i] < pivot) {
            swapArray(array, i, partition);
            partition++;
        }
    }
    swapArray(array, partition, high);
    return partition;
}

void quickSort(int array[], int low, int high) {
    if (low >= high) {
        return;
    }
    int partitionIndex = partition(array, low, high);
    quickSort(array, partitionIndex + 1, high);
    quickSort(array, low, partitionIndex - 1);
}

int main(void) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    ShuffleArray(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    quickSort(arr, 0, 9);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
