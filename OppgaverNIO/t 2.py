def min_antivirus(N, M, K, P, wire_connections, wireless_connections):
    graph = [[] for _ in range(N)]
    for u, v in wire_connections:
        graph[u].append(v)
        graph[v].append(u)
    for u, v in wireless_connections:
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * N
    

    def dfs(node):
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)
                antivirus_nodes.add(neighbor)
    for i in range(N):
        if not visited[i]:
            dfs(i)
    return len(antivirus_nodes)



if __name__ == "__main__":
    antivirus_nodes = set()
    N = 6
    M = 4
    K = 3
    P = 2
    wire_connections = [(0, 3), (4, 3), (5, 2), (2, 4), (2, 1), (2, 0)]
    wireless_connections = [(0, 2), (2, 1)]
    output = min_antivirus(N, M, K, P, wire_connections, wireless_connections)
    print(f"The minimum number of machines that need to have antivirus: {output}")
    print(f"Antivirus Nodes: {antivirus_nodes}")
