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

struct Queue* createQueueWithNElements(int N) {
    struct Queue* queue = createQueue();
    for (int i = 1; i <= N; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        if (queue->rear == NULL) {
            queue->front = queue->rear = newNode;
            newNode->next = newNode;
        } else {
            queue->rear->next = newNode;
            newNode->next = queue->front;
            queue->rear = newNode;
        }
    }
    return queue;
}

void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = queue->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

void splitQueue(struct Queue* originalQueue, int N) {
    if (originalQueue->front == NULL || N <= 0) {
        printf("Queue is empty or invalid number of queues.\n");
        return;
    }

    struct Queue** queues = (struct Queue**)malloc(N * sizeof(struct Queue*));
    for (int i = 0; i < N; i++) {
        queues[i] = createQueue();
    }

    struct Node* temp = originalQueue->front;
    int count = 0;
    do {
        queues[count % N]->rear->next = temp;
        if (queues[count % N]->front == NULL) {
            queues[count % N]->front = temp;
        }
        queues[count % N]->rear = temp;
        count++;
        temp = temp->next;
    } while (temp != originalQueue->front);
    queues[count % N]->rear->next = queues[count % N]->front;

    for (int i = 0; i < N; i++) {
        printf("Queue %d: ", i + 1);
        displayQueue(queues[i]);
    }

    for (int i = 0; i < N; i++) {
        free(queues[i]);
    }
    free(queues);
}

int main() {
    int N;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &N);

    struct Queue* queue = createQueueWithNElements(N);
    printf("Original Queue: ");
    displayQueue(queue);

    int numQueues;
    printf("Enter the number of queues to split into: ");
    scanf("%d", &numQueues);
    splitQueue(queue, numQueues);

    return 0;
}
