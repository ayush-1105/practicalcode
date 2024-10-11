#ifndef DSTQUEUE_H
#define DSTQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Deque;

void init(Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(Deque* dq) {
    return dq->front == -1;
}

int isFull(Deque* dq) {
    return (dq->rear + 1) % MAX == dq->front;
}

void addFront(Deque* dq, int x) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->data[dq->front] = x;
}

void deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
}

void addRear(Deque* dq, int x) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->data[dq->rear] = x;
}

void deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
}

void display(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    int i = dq->front;
    while (1) {
        printf("%d ", dq->data[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

#endif
