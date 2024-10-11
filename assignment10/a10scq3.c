#include <stdio.h>

#define MAX_VERTICES 100

int hasSelfEdges(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (graph[i][i] == 1) {
            return 1; // Self-edge found
        }
    }
    return 0; // No self-edges found
}

int main() {
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (hasSelfEdges(graph, vertices)) {
        printf("The graph has self-edges.\n");
    } else {
        printf("The graph does not have self-edges.\n");
    }

    return 0;
}
