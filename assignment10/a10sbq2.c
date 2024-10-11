#include <stdio.h>

#define MAX_VERTICES 100

int isUndirected(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] != graph[j][i]) {
                return 0;
            }
        }
    }
    return 1;
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

    if (isUndirected(graph, vertices)) {
        printf("The graph is undirected.\n");
    } else {
        printf("The graph is directed.\n");
    }

    return 0;
}
