#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* indegree; // Array to store indegree of each vertex
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->indegree = calloc(vertices, sizeof(int)); // Initialize indegree to 0

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    graph->indegree[dest]++; // Increment indegree of the destination vertex
}

void printIndegree(struct Graph* graph, int vertex) {
    if (vertex >= 0 && vertex < graph->numVertices) {
        printf("Indegree of vertex %d: %d\n", vertex, graph->indegree[vertex]);
    } else {
        printf("Invalid vertex index.\n");
    }
}

void displayAdjacencyList(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, src, dest;
    struct Graph* graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    int edges;
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (v1 v2): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    displayAdjacencyList(graph);
    
    for (int i = 0; i < vertices; i++) {
        printIndegree(graph, i);
    }

    return 0;
}
