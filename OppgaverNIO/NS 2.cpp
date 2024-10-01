#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200000;

int n, m, k, p;
vector<int> graph[MAXN];
bool visited[MAXN];
bool has_antivirus[MAXN];

void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int u, int parent) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (v == parent) continue;
        if (!visited[v]) {
            if (!has_antivirus[u]) {
                has_antivirus[v] = true;
            }
            dfs(v, u);
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
    
    for (int i = 0; i < n; i++) {
        has_antivirus[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    int antivirus_count = 0;
    for (int i = 0; i < n; i++) {
        if (has_antivirus[i]) antivirus_count++;
    }
    cout << antivirus_count << endl;
    return 0;
}
