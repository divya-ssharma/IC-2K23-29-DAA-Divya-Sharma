# Exhaustive Search (Subset Sum)
**Divya Sharma - IC-2K23-29**
## Problem Statement
Find all subsets of a set of positive integers whose sum equals a target.
## Algorithm
For n elements there are 2^n subsets. Loop mask from 0 to 2^n - 1, and for each mask include element i if bit i is set. Sum the included elements and compare with target.
This is the brute force baseline. It always finds every solution but the 2^n makes it impractical beyond about n=20.
## Pseudocode
```
SubsetSum(items, target):
    n = length(items)
    for mask from 0 to (1 << n) - 1:
        subset = empty
        total = 0
        for i from 0 to n-1:
            if mask has bit i set:
                add items[i] to subset
                total = total + items[i]
        if total == target:
            print subset
```
## Complexity
Time is O(2^n * n) because there are 2^n masks and each mask iterates over n elements. Space is O(n) for the current subset, or O(2^n) if all solutions are stored.
## Sample Input / Output
```
Items: 11 13 24 7
Target: 31
Solution 1: [11, 13, 7]
Solution 2: [24, 7]
Total: 2
```
