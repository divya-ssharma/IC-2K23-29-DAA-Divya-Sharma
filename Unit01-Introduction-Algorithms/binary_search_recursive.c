#include <stdio.h>

int binary_search(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] < key) return binary_search(arr, mid + 1, high, key);
    return binary_search(arr, low, mid - 1, key);
}

int main(void) {
    int arr[] = {1, 2, 4, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    int result = binary_search(arr, 0, n - 1, key);
    if (result != -1) printf("Found %d at index %d\n", key, result);
    else printf("Not found\n");

    return 0;
}