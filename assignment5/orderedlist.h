#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct OrderedList {
    Node* head;
} OrderedList;

void init(OrderedList* list) {
    list->head = NULL;
}

void insert(OrderedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL || list->head->data >= value) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

Node* search(OrderedList* list, int value) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        if (current->data > value) {
            break; // Stop searching if current data is greater
        }
        current = current->next;
    }
    return NULL;
}

void display(OrderedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Ordered List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

#endif
