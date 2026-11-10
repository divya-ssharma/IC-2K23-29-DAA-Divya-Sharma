#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int weight;
    int value;
} Item;
int compare_ratio(const void *a, const void *b) {
    const Item *x = (const Item *)a;
    const Item *y = (const Item *)b;
    double r1 = (double)x->value / x->weight;
    double r2 = (double)y->value / y->weight;
    return (r1 < r2) - (r1 > r2);
}
double fractional_knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare_ratio);
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            total += items[i].value;
            capacity -= items[i].weight;
        } else {
            total += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    return total;
}
int main(void) {
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    printf("Maximum value: %.2f\n", fractional_knapsack(items, n, 50));
    return 0;
}
