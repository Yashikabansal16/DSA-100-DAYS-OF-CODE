/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Input edges
    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Add nodes with 0 indegree to queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX], count = 0;

    // Kahn's Algorithm
    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Check for cycle
    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}