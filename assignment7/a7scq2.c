#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        newNode->next = newNode;
    } else {
        queue->rear->next = newNode;
        newNode->next = queue->front;
        queue->rear = newNode;
    }
}

void splitQueue(struct Queue* originalQueue, int N) {
    if (originalQueue->front == NULL || N <= 0) {
        return;
    }

    struct Queue** queues = (struct Queue**)malloc(N * sizeof(struct Queue*));
    for (int i = 0; i < N; i++) {
        queues[i] = createQueue();
    }

    struct Node* temp = originalQueue->front;
    int count = 0;
    do {
        enqueue(queues[count % N], temp->data);
        count++;
        temp = temp->next;
    } while (temp != originalQueue->front);

    for (int i = 0; i < N; i++) {
        printf("Queue %d: ", i + 1);
        struct Node* qTemp = queues[i]->front;
        if (qTemp == NULL) {
            printf("Queue is empty.\n");
            continue;
        }
        do {
            printf("%d ", qTemp->data);
            qTemp = qTemp->next;
        } while (qTemp != queues[i]->front);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(queues[i]);
    }
    free(queues);
}

int main() {
    int N, numQueues;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &N);

    struct Queue* queue = createQueue();
    for (int i = 1; i <= N; i++) {
        enqueue(queue, i);
    }

    printf("Original Queue: ");
    struct Node* temp = queue->front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
    } else {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != queue->front);
        printf("\n");
    }

    printf("Enter the number of queues to split into: ");
    scanf("%d", &numQueues);
    splitQueue(queue, numQueues);

    return 0;
}
