#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int *array, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % size;
        swap(&array[i], &array[j]);
    }
}

int *partition(int *low, int *high) {
    int pivot = *(low + (high - low) / 2);
    int *p = low;
    int *q = high;

    while (1) {
        while (*p < pivot) p++;
        while (*q > pivot) q--;

        if (p >= q) break;
        swap(p, q);
    }
    return q;
}

void quick_sort(int *low, int *high) {
    if (low >= high) return;
    int *p = partition(low, high);
    quick_sort(low, p - 1);
    quick_sort(p + 1, high);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    shuffle(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    quick_sort(arr, arr + 9);

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}
