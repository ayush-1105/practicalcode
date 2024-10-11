#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularList {
    Node* last;
} CircularList;

void init(CircularList* list) {
    list->last = NULL;
}

void append(CircularList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (list->last == NULL) {
        newNode->next = newNode; // Point to itself
        list->last = newNode;     // Initialize last pointer
    } else {
        newNode->next = list->last->next; // New node points to the first node
        list->last->next = newNode;       // Last node points to the new node
        list->last = newNode;              // Update last to the new node
    }
}

void display(CircularList* list) {
    if (list->last == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = list->last->next; // Start from the first node
    printf("Circular List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->last->next);
    printf("(back to first node)\n");
}

#endif
