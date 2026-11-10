#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main(void) {
    int arr[] = {4, 2, 9, 7, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = linear_search(arr, n, key);
    if (result != -1) printf("Found %d at index %d\n", key, result);
    else printf("Not found\n");

    return 0;
}