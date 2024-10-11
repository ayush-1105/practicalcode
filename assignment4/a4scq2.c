#include <stdio.h>

void insertionSortWithCount(int arr[], int n, int *comparisonCount) {
    *comparisonCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            (*comparisonCount)++;  // Count comparison
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;  // Exit if the current element is not greater
            }
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisonCount = 0;
    insertionSortWithCount(arr, n, &comparisonCount);

    printf("Number of comparisons: %d\n", comparisonCount);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
