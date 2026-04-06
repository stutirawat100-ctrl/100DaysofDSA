#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
    visited[node] = 1;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle detected
        }
    }
    return false;
}

bool hasCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<int> adj[V];

    // Example edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(1); // cycle edge
    adj[1].push_back(3);

    if (hasCycle(V, adj))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
