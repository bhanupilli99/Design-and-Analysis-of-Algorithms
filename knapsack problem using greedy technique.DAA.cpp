#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratioA = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratioB = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}
void knapsackGreedy(struct Item items[], int n, int capacity) {
     qsort(items, n, sizeof(struct Item), compare);
    int *selected = (int *)calloc(n, sizeof(int)); 
    int currentWeight = 0;
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            selected[i] = 1;
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("Item %d - Value: %d, Weight: %d\n", i + 1, items[i].value, items[i].weight);
        }
    }

    printf("\nTotal value in the knapsack: %.2f\n", totalValue);
    free(selected);
}
int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    knapsackGreedy(items, n, capacity);

    return 0;
}
