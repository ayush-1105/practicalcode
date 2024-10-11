#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void printInDegree(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("In-Degree of each vertex:\n");
    for (int i = 0; i < vertices; i++) {
        int inDegree = 0;
        for (int j = 0; j < vertices; j++) {
            inDegree += graph[j][i];
        }
        printf("Vertex %d: %d\n", i, inDegree);
    }
}

void printOutDegree(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Out-Degree of each vertex:\n");
    for (int i = 0; i < vertices; i++) {
        int outDegree = 0;
        for (int j = 0; j < vertices; j++) {
            outDegree += graph[i][j];
        }
        printf("Vertex %d: %d\n", i, outDegree);
    }
}

void displayAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, src, dest;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter the edge (src dest): ");
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    displayAdjacencyMatrix(graph, vertices);
    printInDegree(graph, vertices);
    printOutDegree(graph, vertices);

    return 0;
}
