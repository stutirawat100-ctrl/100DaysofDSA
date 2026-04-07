#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// adjacency list representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];  // adjacency list
int V;           // number of vertices

// utility function to add edge
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// recursive DFS utility
bool isCyclicUtil(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    Node* temp = adj[v];
    while (temp != NULL) {
        int neighbour = temp->vertex;
        if (!visited[neighbour] && isCyclicUtil(neighbour, visited, recStack))
            return true;
        else if (recStack[neighbour])
            return true;
        temp = temp->next;
    }

    recStack[v] = false; // remove from recursion stack
    return false;
}

// main cycle detection function
bool isCyclic() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    V = 4; // number of vertices
    for (int i = 0; i < V; i++) adj[i] = NULL;

    // Example graph
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0); // cycle here
    addEdge(2, 3);

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
