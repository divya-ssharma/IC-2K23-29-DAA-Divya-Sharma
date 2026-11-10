#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) left[i] = arr[low + i];
    for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    free(left);
    free(right);
}
void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
        merge_sort(arr, 0, n - 1);
        clock_t end = clock();
        printf("n=%d time=%.6f\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
        free(arr);
    }
    int sample[] = {38, 27, 43, 3, 9, 82, 10};
    int len = sizeof(sample) / sizeof(sample[0]);
    merge_sort(sample, 0, len - 1);
    printf("sorted: ");
    for (int i = 0; i < len; i++) printf("%d ", sample[i]);
    printf("\n");
    return 0;
}
