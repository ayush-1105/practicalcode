#include "orderedlist.h"
#include <stdio.h>

int main() {
    OrderedList list;
    init(&list);

    int choice, value;
    Node* result;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&list, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(&list, value);
                if (result) {
                    printf("Value %d found in the list.\n", result->data);
                } else {
                    printf("Value %d not found in the list.\n", value);
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
