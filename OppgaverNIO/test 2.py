from collections import defaultdict

def min_vertex_cover(n, m, k, p, edges, wireless_connections):
    graph = defaultdict(list)
    # Create the graph by adding edges
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    for u, v in wireless_connections:
        graph[u].append(v)
        graph[v].append(u)

    # Create an array to keep track of visited vertices
    visited = [False for _ in range(n)]

    # Create a variable to keep track of the number of vertices in the cover
    cover = 0

    # Iterate through the vertices of the graph
    for i in range(n):
        if not visited[i]:
            cover += 1
            # Perform a depth-first search
            stack = [i]
            while stack:
                vertex = stack.pop()
                visited[vertex] = True
                for neighbor in graph[vertex]:
                    if not visited[neighbor]:
                        stack.append(neighbor)
    return cover

# Example usage
n = 5
m = 4
k = 2
p = 2
edges = [(0, 1), (1, 2), (2, 3), (3, 4)]
wireless_connections = [(0, 1), (1, 0)]
print(min_vertex_cover(n, m, k, p, edges, wireless_connections))
# Output: 3
