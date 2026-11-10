#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
        heap_sort(arr, n);
        clock_t end = clock();
        printf("n=%d time=%.6f\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
        free(arr);
    }
    int sample[] = {12, 11, 13, 5, 6, 7};
    int len = sizeof(sample) / sizeof(sample[0]);
    heap_sort(sample, len);
    printf("sorted: ");
    for (int i = 0; i < len; i++) printf("%d ", sample[i]);
    printf("\n");
    return 0;
}
