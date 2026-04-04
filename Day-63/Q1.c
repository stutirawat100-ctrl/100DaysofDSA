def dfs_recursive(graph, visited, node, traversal):
    # Mark the current node as visited
    visited[node] = True
    traversal.append(node)

    # Recur for all the vertices adjacent to this vertex
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs_recursive(graph, visited, neighbor, traversal)


def dfs(n, adjacency_list, s):
    visited = [False] * (n + 1)   # assuming vertices are 1-indexed
    traversal = []
    dfs_recursive(adjacency_list, visited, s, traversal)
    return traversal


# Example usage:
n = 5
adjacency_list = {
    1: [2, 3],
    2: [4],
    3: [5],
    4: [],
    5: []
}
start_vertex = 1

print("DFS Traversal:", dfs(n, adjacency_list, start_vertex))
