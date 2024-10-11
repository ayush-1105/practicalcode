#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyList {
    Node* head;
} DoublyList;

void init(DoublyList* list) {
    list->head = NULL;
}

void insert(DoublyList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL) {
        list->head->prev = newNode;
    }

    list->head = newNode;
}

void delete(DoublyList* list, int value) {
    Node* temp = list->head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        list->head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void displayForward(DoublyList* list) {
    Node* temp = list->head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List in forward order: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse(DoublyList* list) {
    Node* temp = list->head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("List in reverse order: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

#endif
