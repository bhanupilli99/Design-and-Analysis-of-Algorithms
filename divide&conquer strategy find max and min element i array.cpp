#include <stdio.h>
struct MaxMin {
    int max;
    int min;
};
struct MaxMin findMaxMin(int arr[], int low, int high) {
    struct MaxMin result, left, right, middle;
    int mid;
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }
    if (high == low + 1) {
        result.max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        result.min = (arr[low] < arr[high]) ? arr[low] : arr[high];
        return result;
    }
    mid = (low + high) / 2;
    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid + 1, high);
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}
int main() {
    int arr[] = {3, 8, 1, 4, 6, 2, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct MaxMin result = findMaxMin(arr, 0, n - 1);
    printf("Maximum element is %d\n", result.max);
    printf("Minimum element is %d\n", result.min);

    return 0;
}
