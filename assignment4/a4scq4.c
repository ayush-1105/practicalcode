#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[low];
    arr[low] = temp; // Move pivot to start

    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    temp = arr[low];
    arr[low] = arr[i - 1];
    arr[i - 1] = temp;
    return i - 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
