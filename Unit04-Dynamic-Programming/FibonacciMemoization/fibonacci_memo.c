#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long fib_naive(int n) {
    if (n <= 1) return n;
    return fib_naive(n - 1) + fib_naive(n - 2);
}
long long fib_helper(int n, long long memo[]) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) {
        memo[n] = n;
        return n;
    }
    memo[n] = fib_helper(n - 1, memo) + fib_helper(n - 2, memo);
    return memo[n];
}
long long fib_memo(int n) {
    long long *memo = (long long *)malloc((n + 1) * sizeof(long long));
    for (int i = 0; i <= n; i++) memo[i] = -1;
    long long result = fib_helper(n, memo);
    free(memo);
    return result;
}
int main(void) {
    int n = 30;
    clock_t start = clock();
    long long a = fib_naive(n);
    clock_t end = clock();
    printf("naive fib(%d) = %lld, time = %.6f\n", n, a, ((double)(end - start)) / CLOCKS_PER_SEC);
    start = clock();
    long long b = fib_memo(n);
    end = clock();
    printf("memo  fib(%d) = %lld, time = %.6f\n", n, b, ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}
