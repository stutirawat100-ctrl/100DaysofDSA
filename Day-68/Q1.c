#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];      // Adjacency matrix
int in_degree[MAX];     // In-degree array
int queue[MAX];         // Queue
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void topologicalSort(int n) {
    int topo[MAX], count = 0;

    // Step 1: Initialize in-degree = 0
    for (int i = 0; i < n; i++) {
        in_degree[i] = 0;
    }

    // Step 2: Calculate in-degree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    // Step 3: Add nodes with in-degree 0 to queue
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            enqueue(i);
        }
    }

    // Step 4: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 5: Check for cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int n, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) for u -> v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort(n);

    return 0;
}
