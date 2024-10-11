#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    CircularList list;
    init(&list);

    int choice, n, value;

    do {
        printf("\nMenu:\n");
        printf("1. Append random integers\n");
        printf("2. Append user-defined integers\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of random integers to append: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    value = rand() % 100; // Generate random integer between 0 and 99
                    append(&list, value);
                }
                printf("%d random integers appended.\n", n);
                break;
            case 2:
                printf("Enter number of integers to append: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter integer %d: ", i + 1);
                    scanf("%d", &value);
                    append(&list, value);
                }
                break;
            case 3:
                display(&list);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
