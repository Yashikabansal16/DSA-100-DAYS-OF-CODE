/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    // Push node to stack after visiting all neighbors
    stack[++top] = node;
}

// Topological sort function
void topologicalSort() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (topological order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();

    return 0;
}