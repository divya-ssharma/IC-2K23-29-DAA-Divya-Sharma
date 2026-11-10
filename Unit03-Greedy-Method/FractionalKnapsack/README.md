# Fractional Knapsack
**Divya Sharma - IC-2K23-29**
## Problem Statement
Given items with weights and values, and a knapsack of fixed capacity, take as much total value as possible. Fractions of items are allowed here, unlike the 0/1 version.
## Algorithm
Sort items by value per unit weight in descending order. Take each item fully if it fits, otherwise take the fraction that fits and stop. This works because the greedy choice property holds - the highest ratio item is always part of some optimal solution, since replacing any part of it with a lower ratio item would reduce the total value.
## Pseudocode
```
FractionalKnapsack(items, capacity):
    sort items by value/weight descending
    total = 0
    for each item:
        if capacity >= item.weight:
            total = total + item.value
            capacity = capacity - item.weight
        else:
            total = total + item.value * (capacity / item.weight)
            break
    return total
```
## Complexity
Sorting dominates at O(n log n). The greedy loop afterwards is O(n). Space is O(1) if sorting is done in place, O(n) if a copy is made.
## Sample Input / Output
```
Items: (10, 60), (20, 100), (30, 120)
Capacity: 50
Output: 240.00
```
First two items fit fully (weight 30, value 160), the remaining 20 capacity takes 2/3 of the third item, adding 80.
