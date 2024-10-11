#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int code;
    char name[50];
    float price;
    int quantity;
} Item;

// Function to accept item details
void acceptItemDetails(Item *item) {
    printf("Enter item code: ");
    scanf("%d", &item->code);
    printf("Enter item name: ");
    scanf(" %[^\n]", item->name); // To read string with spaces
    printf("Enter item price: ");
    scanf("%f", &item->price);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
}

// Function to display item details
void displayItemDetails(Item **items, int n) {
    printf("\nInventory Details:\n");
    printf("%-10s %-30s %-10s %-10s %-10s\n", "Code", "Name", "Price", "Quantity", "Total");
    for (int i = 0; i < n; i++) {
        float itemTotal = items[i]->price * items[i]->quantity;
        printf("%-10d %-30s %-10.2f %-10d %-10.2f\n", 
                items[i]->code, items[i]->name, items[i]->price, items[i]->quantity, itemTotal);
    }
}

// Function to calculate total cost
float calculateTotalCost(Item **items, int n) {
    float totalCost = 0.0;
    for (int i = 0; i < n; i++) {
        totalCost += items[i]->price * items[i]->quantity;
    }
    return totalCost;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Array of pointers to Item
    Item **items = (Item **)malloc(n * sizeof(Item *));
    if (items == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Accepting details for n items
    for (int i = 0; i < n; i++) {
        items[i] = (Item *)malloc(sizeof(Item));
        if (items[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        printf("Enter details for item %d:\n", i + 1);
        acceptItemDetails(items[i]);
    }

    // Display item details
    displayItemDetails(items, n);

    // Calculate and display total cost
    float totalCost = calculateTotalCost(items, n);
    printf("\nTotal Cost of Inventory: %.2f\n", totalCost);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(items[i]);
    }
    free(items);

    return 0;
}
