#include <stdio.h>
void subset_sum(int items[], int n, int target) {
    int count = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) total += items[i];
        }
        if (total == target) {
            count++;
            printf("Solution %d: [", count);
            int first = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (!first) printf(", ");
                    printf("%d", items[i]);
                    first = 0;
                }
            }
            printf("]\n");
        }
    }
    printf("Total: %d\n", count);
}
int main(void) {
    int items[] = {11, 13, 24, 7};
    int n = sizeof(items) / sizeof(items[0]);
    subset_sum(items, n, 31);
    return 0;
}
