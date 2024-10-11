#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Graph structure with an adjacency list
struct Graph {
    int numVertices;
    int adjList[MAX][MAX];
};

// Queue structure
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

// Add an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Remove an element from the queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// BFS function
void BFS(struct Graph* graph, int startVertex, int visited[]) {
    struct Queue* q = createQueue();
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjList[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

// Function to check if the graph is connected
int isConnected(struct Graph* graph) {
    int visited[MAX] = {0};
    BFS(graph, 0, visited);

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            return 0; // If any vertex is not visited, the graph is not connected
        }
    }
    return 1; // All vertices are visited, the graph is connected
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    int vertices, edges, v1, v2;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    graph->numVertices = vertices;

    // Initialize the adjacency list with 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjList[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges for the graph
    for (int i = 0; i < edges; i++) {
        printf("Enter the edge (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        graph->adjList[v1][v2] = 1;
        graph->adjList[v2][v1] = 1;
    }

    // Check if the graph is connected
    if (isConnected(graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
