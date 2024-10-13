#include <stdio.h>

#define MAX_VERTICES 6  // Maximum number of vertices in the graph

// Adjacency matrix representation of the grap
int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 1, 0, 0, 0}, // Connections for vertex 0
    {1, 0, 0, 1, 0, 0}, // Connections for vertex 1
    {1, 0, 0, 0, 1, 0}, // Connections for vertex 2
    {0, 1, 0, 0, 0, 1}, // Connections for vertex 3
    {0, 0, 1, 0, 0, 1}, // Connections for vertex 4
    {0, 0, 0, 1, 1, 0}  // Connections for vertex 5
};

// Array to track visited vertices
int visited[MAX_VERTICES] = {0};

// DFS function
void dfs(int vertex) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);  // Print the visited vertex

    // Recursively visit all unvisited adjacent vertices
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int startVertex = 0;  // Starting vertex for DFS

    printf("DFS traversal starting from vertex %d:\n", startVertex);
    dfs(startVertex);

    return 0;
}
