#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Writing sample integers to the file
    fprintf(file, "10\n20\n30\n40\n20\n50\n20\n60\n");
    fclose(file);
}

void readFromFile(const char *filename, int **arr, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Dynamically allocate memory for the array
    *arr = malloc(sizeof(int) * 100); // Initial size
    *size = 0;

    while (fscanf(file, "%d", &(*arr)[*size]) == 1) {
        (*size)++;
    }

    fclose(file);
}

int findLastOccurrence(int arr[], int size, int target) {
    int lastIndex = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            lastIndex = i;
        }
    }

    return lastIndex;
}

int main() {
    const char *filename = "numbers.txt";
    writeToFile(filename); // Create and write to the file

    int *arr;
    int size;

    readFromFile(filename, &arr, &size); // Read the file into an array

    int target;
    printf("Enter the number to find the last occurrence: ");
    scanf("%d", &target);

    int lastOccurrence = findLastOccurrence(arr, size, target);

    if (lastOccurrence != -1) {
        printf("Last occurrence of %d is at index: %d\n", target, lastOccurrence);
    } else {
        printf("%d is not found in the file.\n", target);
    }

    free(arr); // Free dynamically allocated memory
    return 0;
}
