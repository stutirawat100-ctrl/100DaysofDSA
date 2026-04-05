from collections import deque

def bfs(n, adj, s):
    visited = [False] * n
    traversal = []
    queue = deque()

    # Start from source
    visited[s] = True
    queue.append(s)

    while queue:
        u = queue.popleft()
        traversal.append(u)

        # Explore neighbors
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                queue.append(v)

    return traversal


# Example usage:
n = 5
adj = [
    [1, 2],    # neighbors of node 0
    [0, 3],    # neighbors of node 1
    [0, 4],    # neighbors of node 2
    [1],       # neighbors of node 3
    [2]        # neighbors of node 4
]
source = 0

print("BFS Traversal:", bfs(n, adj, source))
