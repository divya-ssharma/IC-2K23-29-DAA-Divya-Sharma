# Heap Sort
**Divya Sharma - IC-2K23-29**
## Problem Statement
Sort an array of integers in ascending order using heap sort.
## Algorithm
Build a max-heap from the input array, then repeatedly swap the root (largest element) with the last element and shrink the heap by one. After the swap, restore the heap property by calling heapify on the new root. After n-1 iterations the array is sorted in ascending order.
Heap sort is not a divide and conquer algorithm in the same sense as merge sort and quick sort, but it is grouped with them in this unit because it achieves the same O(n log n) bound with a different structure.
## Pseudocode
```
HeapSort(arr):
    n = length(arr)
    for i = n/2 - 1 down to 0:
        Heapify(arr, n, i)
    for i = n-1 down to 1:
        swap(arr[0], arr[i])
        Heapify(arr, i, 0)
Heapify(arr, n, i):
    largest = i
    left = 2*i + 1
    right = 2*i + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        swap(arr[i], arr[largest])
        Heapify(arr, n, largest)
```
## Complexity
Best, average and worst case are all O(n log n). The heap construction is O(n) and each of the n-1 removals costs O(log n). Space is O(1) because the heap is built inside the same array - unlike merge sort, no temporary array is needed.
## Sample Input / Output
```
Input:  [12, 11, 13, 5, 6, 7]
Output: [5, 6, 7, 11, 12, 13]
```
## Comparison with Merge Sort and Quick Sort
Heap sort guarantees O(n log n) like merge sort but with O(1) space instead of O(n), which is its main advantage. Its disadvantage is that the constant factor in the O(n log n) is larger than quick sort, because heapify jumps around memory and doesn't have good cache locality. On the timing runs for 100 to 2000 elements, heap sort was slightly slower than quick sort and roughly on par with merge sort, but without the memory overhead. For an in-place sort where memory is tight, heap sort is the safer choice than quick sort's worst case.
