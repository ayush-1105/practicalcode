#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
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
    graph->visited = malloc(vertices * sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void dfs(struct Graph* graph, int vertex, struct Node** head) {
    graph->visited[vertex] = 1;
    
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            dfs(graph, adjVertex, head);
        }
        temp = temp->next;
    }

    struct Node* newNode = createNode(vertex);
    newNode->next = *head;
    *head = newNode;
}

void topologicalSort(struct Graph* graph) {
    struct Node* head = NULL;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            dfs(graph, i, &head);
        }
    }

    printf("Topological Sort: ");
    while (head) {
        printf("%d ", head->vertex);
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n");
}

int main() {
    int vertices, edges, src, dest;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    struct Graph* graph = createGraph(vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        printf("Enter the edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    topologicalSort(graph);
    
    return 0;
}
