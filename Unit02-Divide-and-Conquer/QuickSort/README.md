# Quick Sort
**Divya Sharma - IC-2K23-29**
## Problem Statement
Sort an array of integers in ascending order using quick sort.
## Algorithm
Pick the last element as pivot and partition the array in place so that smaller elements are on the left of the pivot and larger are on the right. Then call quick sort on both sides of the pivot. The pivot ends up in its final position after partition and is never touched again.
The in-place version uses two indices and swaps elements in the same array, so unlike merge sort it does not need extra memory for combining. The tradeoff is that the worst case is O(n²) when the pivot is always the smallest or largest element.
## Pseudocode
```
Partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j = low to high - 1:
        if arr[j] <= pivot:
            i = i + 1
            swap(arr[i], arr[j])
    swap(arr[i + 1], arr[high])
    return i + 1
QuickSort(arr, low, high):
    if low < high:
        p = Partition(arr, low, high)
        QuickSort(arr, low, p - 1)
        QuickSort(arr, p + 1, high)
```
## Complexity
Average and best case are O(n log n). Worst case is O(n²) and happens on already sorted input when the pivot is the first or last element, which is why the last element as pivot is the standard textbook choice but not always the practical one. Space is O(log n) for the recursion stack in the average case.
## Sample Input / Output
```
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]
Input:  [4, 4, 2, 1]
Output: [1, 2, 4, 4]
```
## Comparison with Merge Sort and Heap Sort
Quick sort is the fastest of the three on random data in most runs, but the O(n²) worst case is a real concern - 
the same code can be very fast or very slow depending on which element becomes the pivot. Merge sort is predictable O(n log n) but uses extra O(n) memory, and heap sort is also O(n log n) with O(1) space. On the timing runs for 100 to 2000 elements, quick sort led, heap sort was second, and merge sort trailed slightly due to the temporary array allocation at every merge step.
