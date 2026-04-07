/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V;

// DFS function to detect cycle
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            // If not visited, recurse
            if (!visited[i]) {
                if (dfs(i))
                    return true;
            }
            // If already in recursion stack → cycle
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    // Check for cycle
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}