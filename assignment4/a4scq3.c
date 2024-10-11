#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000; // Random numbers from 0 to 9999
}

int main() {
    srand(time(NULL));
    int n = 10000;
    int arr1[n], arr2[n];

    generateRandomArray(arr1, n);
    for (int i = 0; i < n; i++)
        arr2[i] = arr1[i]; // Copy for second sort

    insertionSort(arr1, n);
    selectionSort(arr2, n);

    return 0;
}
