#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 200000;

int n, m, k, p;
vector<int> graph[MAXN];
int antivirus[MAXN];
bool visited[MAXN];

void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k >> p;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u + n - k, v + n - k);
    }
    int antivirus_count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i);
            antivirus_count++;
        }
    }
    cout << antivirus_count << endl;
    return 0;
}

