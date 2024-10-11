#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 20
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int stdCode;
} City;

// Function to generate random city names
void generateRandomCityName(char *name, int length) {
    const char *cities[] = {"NewYork", "LosAngeles", "Chicago", "Houston", "Phoenix",
                             "Philadelphia", "SanAntonio", "SanDiego", "Dallas", "SanJose"};
    int index = rand() % (sizeof(cities) / sizeof(cities[0]));
    strncpy(name, cities[index], length);
}

// Bubble sort function
void bubbleSort(City c[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(c[j].name, c[j + 1].name) > 0) {
                City temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}

// Linear search function with comparison count
int linearSearch(City c[], int n, char *target, int *comparisonCount) {
    for (int i = 0; i < n; i++) {
        (*comparisonCount)++;
        if (strcmp(c[i].name, target) == 0) {
            return i;
        }
    }
    return -1;
}

// Binary search function with comparison count
int binarySearch(City c[], int n, char *target, int *comparisonCount) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        (*comparisonCount)++;
        int cmp = strcmp(c[mid].name, target);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n = MAX_CITIES;
    City c[MAX_CITIES];
    char citySearch[MAX_NAME_LENGTH];

    // Seed the random number generator
    srand(time(NULL));

    // Generate random cities and STD codes
    for (int i = 0; i < n; i++) {
        generateRandomCityName(c[i].name, MAX_NAME_LENGTH);
        c[i].stdCode = rand() % 1000 + 100;  // Random STD code between 100 and 1099
    }

    // Sort the array of cities
    bubbleSort(c, n);

    // Display generated cities
    printf("Generated Cities:\n");
    for (int i = 0; i < n; i++) {
        printf("City: %s, STD Code: %d\n", c[i].name, c[i].stdCode);
    }

    // Search for a city
    printf("\nEnter the name of the city you want to search: ");
    scanf("%s", citySearch);

    // Perform linear search
    int linearComparisons = 0;
    int foundLinear = linearSearch(c, n, citySearch, &linearComparisons);
    if (foundLinear != -1) {
        printf("City found (Linear Search): STD Code is %d\n", c[foundLinear].stdCode);
        printf("Number of comparisons made in Linear Search: %d\n", linearComparisons);
    } else {
        printf("The city is not present (Linear Search)\n");
    }

    // Perform binary search
    int binaryComparisons = 0;
    int foundBinary = binarySearch(c, n, citySearch, &binaryComparisons);
    if (foundBinary != -1) {
        printf("City found (Binary Search): STD Code is %d\n", c[foundBinary].stdCode);
        printf("Number of comparisons made in Binary Search: %d\n", binaryComparisons);
    } else {
        printf("The city is not present (Binary Search)\n");
    }

    return 0;
}
