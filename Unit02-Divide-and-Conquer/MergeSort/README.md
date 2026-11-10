# Merge Sort
**Divya Sharma - IC-2K23-29**
## Problem Statement
Sort an array of integers in ascending order using divide and conquer.
## Algorithm
Split the array into two halves, sort each half by calling the same function on it, and merge the two sorted halves back together. The recursion stops when a piece has one element, since one element is already sorted. The merge step walks both halves with two pointers and writes the smaller element each time into a temporary array, then copies it back.
## Pseudocode
```
MergeSort(arr, low, high):
    if low < high:
        mid = (low + high) / 2
        MergeSort(arr, low, mid)
        MergeSort(arr, mid + 1, high)
        Merge(arr, low, mid, high)
Merge(arr, low, mid, high):
    temp = new array
    i = low, j = mid + 1, k = 0
    while i <= mid and j <= high:
        if arr[i] <= arr[j]:
            temp[k++] = arr[i++]
        else:
            temp[k++] = arr[j++]
    copy rest of left half
    copy rest of right half
    copy temp back to arr
```
## Complexity
Best, average and worst case are all O(n log n). The log n comes from the number of split levels and the n from the merge work at each level. Space is O(n) because of the temporary array.
## Sample Input / Output
```
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]
```
## Comparison with Quick Sort and Heap Sort
Merge sort is the only one of the three that guarantees O(n log n) in the worst case. Quick sort is usually faster in practice on random data because of better cache locality and fewer writes, but it degrades to O(n²) on adversarial input. Heap sort is also O(n log n) in the worst case like merge sort but sorts in place, so its space is O(1) instead of O(n). On random integer arrays of 100, 500, 1000 and 2000 elements, all three scaled as expected - quick sort was fastest, heap sort and merge sort were close to each other.
