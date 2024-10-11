#ifndef STTSTACK_H
#define STTSTACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void init(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Memory allocation error\n");
        return;
    }
    temp->data = x;
    temp->next = s->top;
    s->top = temp;
}

int pop(Stack* s, int* poppedValue) {
    if (isEmpty(s)) {
        return 0;  // Stack is empty, pop failed
    }

    Node* temp = s->top;
    *poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);

    return 1;  // Pop successful
}

int top(Stack* s) {
    if (!isEmpty(s)) {
        return s->top->data;
    }
    return -1;  // Stack is empty
}

#endif
