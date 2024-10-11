#ifndef STTSTACK_H
#define STTSTACK_H

#define MAX 100

typedef struct {
    int top;
    int data[MAX];
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int x) {
    if (!isFull(s)) {
        s->data[++(s->top)] = x;
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;  // Return -1 if stack is empty
}

int top(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;  // Return -1 if stack is empty
}

void deleteLast(Stack* s) {
    Stack temp;
    init(&temp);

    while (s->top > 0) {
        push(&temp, pop(s));
    }

    pop(s);  // Remove the last element

    while (!isEmpty(&temp)) {
        push(s, pop(&temp));
    }
}

#endif
