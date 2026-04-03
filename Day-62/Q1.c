# Input
n = int(input("Enter number of vertices: "))
m = int(input("Enter number of edges: "))

# Create adjacency list
adj = [[] for _ in range(n)]

# Read edges
print("Enter edges (u v):")
for _ in range(m):
    u, v = map(int, input().split())
    
    # Add edge (undirected graph)
    adj[u].append(v)
    adj[v].append(u)

# Output adjacency list
print("\nAdjacency List:")
for i in range(n):
    print(f"{i} -> {adj[i]}")
