// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++q->rear] = value;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[q->front++];
    }
    return -1;
}

// Topological Sort using Kahn's Algorithm
void kahnTopologicalSort(int vertices, int adj[vertices][vertices]) {
    int in_degree[vertices];
    for (int i = 0; i < vertices; i++) {
        in_degree[i] = 0;
    }

    // Step 1: Calculate in-degree
    for (int u = 0; u < vertices; u++) {
        for (int v = 0; v < vertices; v++) {
            if (adj[u][v]) {
                in_degree[v]++;
            }
        }
    }

    // Step 2: Initialize queue with nodes having in-degree 0
    Queue q;
    initQueue(&q);
    for (int i = 0; i < vertices; i++) {
        if (in_degree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int count = 0;
    int topo_order[vertices];

    // Step 3: Process queue
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        topo_order[count++] = node;

        for (int v = 0; v < vertices; v++) {
            if (adj[node][v]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (count != vertices) {
        printf("Graph has a cycle, topological sort not possible.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 6;
    int adj[6][6] = {0};

    // Example edges
    adj[0][1] = 1; // 1 -> 2
    adj[0][2] = 1; // 1 -> 3
    adj[2][3] = 1; // 3 -> 4
    adj[1][3] = 1; // 2 -> 4
    adj[3][4] = 1; // 4 -> 5
    adj[4][5] = 1; // 5 -> 6

    kahnTopologicalSort(vertices, adj);

    return 0;
}
