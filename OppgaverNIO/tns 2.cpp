#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005, M = 400005;
int n, m, k, p, cnt, h[N], e[M], ne[M], match[N], vis[N];
vector<int> g[N];
vector<int> antivirus_nodes;

void add(int a, int b) {
    e[cnt] = b, ne[cnt] = h[a], h[a] = cnt++;
}

bool dfs(int u) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!vis[v]) {
            vis[v] = 1;
            if (!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> k >> p;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    while (p--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += dfs(i);
        fill(vis, vis + n, 0);
    }
    for (int i = 0; i < k; i++) {
        if (!match[i]) {
            for (auto j : g[i]) {
                if (match[j] != i) {
                    match[i] = j;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        if (match[i] > i) {
            match[i] = match[match[i]];
        }
    }
    sort(match, match + k);
    for (int i = 0; i < k; i++) {
        if (match[i] != match[i + 1]) {
            antivirus_nodes.push_back(i);
        }
    }
    cout << k - (unique(match, match + k) - match) << endl;
    cout << "Machines that should have antivirus: ";
    for (int i = 0; i < antivirus_nodes.size(); i++) {
        cout << antivirus_nodes[i] << " ";
    }
    return 0;
}
