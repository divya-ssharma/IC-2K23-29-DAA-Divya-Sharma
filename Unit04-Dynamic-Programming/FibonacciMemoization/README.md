# Fibonacci with Memoization
**Divya Sharma - IC-2K23-29**
## Problem Statement
Compute the nth Fibonacci number with recursion and memoization, and compare the time against plain recursion.
## Algorithm
Plain recursion recomputes the same subproblems many times - fib(5) calls fib(3) twice and fib(2) three times. Memoization stores each computed value in an array and checks it before recursing, so each fib(k) for k in 0..n is computed exactly once.
An array of size n+1 initialised to -1 works as the memo in C. A dictionary is not needed because the keys are just 0 to n.
## Pseudocode
```
memo[0..n] = -1
Fib(n):
    if memo[n] != -1:
        return memo[n]
    if n <= 1:
        memo[n] = n
        return n
    memo[n] = Fib(n-1) + Fib(n-2)
    return memo[n]
```
## Complexity
With memoization, time is O(n) and space is O(n) for the memo and the recursion stack. Without memoization, time is O(2^n) because the recursion tree has roughly 2^n nodes.
## Sample Input / Output
```
n=10 plain: 55
n=30 plain: 832040, time ≈ 0.28s
n=30 memo:  832040, time ≈ 0.00002s
```
