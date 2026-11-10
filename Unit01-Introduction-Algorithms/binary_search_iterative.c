#include <stdio.h>

int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 2, 4, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = binary_search(arr, n, key);
    if (result != -1) printf("Found %d at index %d\n", key, result);
    else printf("Not found\n");

    return 0;
}