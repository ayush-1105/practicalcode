#include <stdio.h>

int binarySearchInsertPosition(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            return mid;  // Return index if x is found
        } else if (arr[mid] < x) {
            left = mid + 1;  // Move to the right half
        } else {
            right = mid - 1; // Move to the left half
        }
    }
    
    // Return the position where x can be inserted
    return left;  // Left will be the insertion point
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter the number to insert: ");
    scanf("%d", &x);

    int position = binarySearchInsertPosition(arr, n, x);

    printf("The number %d can be inserted at position: %d\n", x, position);
    
    return 0;
}
