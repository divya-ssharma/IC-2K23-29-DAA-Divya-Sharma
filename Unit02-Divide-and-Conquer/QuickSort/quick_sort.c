#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}
int main(void) {
    int sizes[] = {100, 500, 1000, 2000};
    srand(42);
    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
        clock_t start = clock();
        quick_sort(arr, 0, n - 1);
        clock_t end = clock();
        printf("n=%d time=%.6f\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
        free(arr);
    }
    int sample[] = {10, 7, 8, 9, 1, 5};
    int len = sizeof(sample) / sizeof(sample[0]);
    quick_sort(sample, 0, len - 1);
    printf("sorted: ");
    for (int i = 0; i < len; i++) printf("%d ", sample[i]);
    printf("\n");
    return 0;
}
