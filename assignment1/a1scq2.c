#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accessionNumber;
    char title[100];
    char author[100];
    char publisher[100];
    float cost;
} Book;

// Function to accept book details
void acceptBookDetails(Book *book, int accessionNumber) {
    book->accessionNumber = accessionNumber;
    printf("Enter book title: ");
    scanf(" %[^\n]", book->title); // Read string with spaces
    printf("Enter author name: ");
    scanf(" %[^\n]", book->author);
    printf("Enter publisher name: ");
    scanf(" %[^\n]", book->publisher);
    printf("Enter cost: ");
    scanf("%f", &book->cost);
}

// Function to display books by author
void displayBooksByAuthor(Book *books, int n, const char *author) {
    int found = 0;
    printf("\nBooks by author '%s':\n", author);
    printf("%-10s %-50s %-30s %-30s %-10s\n", "Acc No", "Title", "Author", "Publisher", "Cost");
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("%-10d %-50s %-30s %-30s %-10.2f\n", 
                   books[i].accessionNumber, books[i].title, books[i].author, books[i].publisher, books[i].cost);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found by author '%s'.\n", author);
    }
}

// Function to display books by publisher
void displayBooksByPublisher(Book *books, int n, const char *publisher) {
    int found = 0;
    printf("\nBooks published by '%s':\n", publisher);
    printf("%-10s %-50s %-30s %-30s %-10s\n", "Acc No", "Title", "Author", "Publisher", "Cost");
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].publisher, publisher) == 0) {
            printf("%-10d %-50s %-30s %-30s %-10.2f\n", 
                   books[i].accessionNumber, books[i].title, books[i].author, books[i].publisher, books[i].cost);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found published by '%s'.\n", publisher);
    }
}

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n books
    Book *books = (Book *)malloc(n * sizeof(Book));
    if (books == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Accepting details for n books
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for book %d:\n", i + 1);
        acceptBookDetails(&books[i], i + 1); // Accession number starts from 1
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display books of a specific author\n");
        printf("2. Display books published by a specific publisher\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char author[100];
            printf("Enter author name to search: ");
            scanf(" %[^\n]", author);
            displayBooksByAuthor(books, n, author);
        } else if (choice == 2) {
            char publisher[100];
            printf("Enter publisher name to search: ");
            scanf(" %[^\n]", publisher);
            displayBooksByPublisher(books, n, publisher);
        } else if (choice != 3) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    // Free allocated memory
    free(books);
    
    return 0;
}
