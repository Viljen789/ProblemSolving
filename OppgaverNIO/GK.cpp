#include <iostream>
#include <vector>
using namespace std;

const int N = 1010, M = 110;

int n, m;
vector<int> e[N];
int cnt[N];

void dfs(int u, int gi) {
    if (gi == 0) return;
    for (int v : e[u]) {
        dfs(v, gi);
        if (cnt[v] < gi) {
            gi -= cnt[v];
            cnt[u] += cnt[v];
        } else {
            cnt[u] += gi;
            return;
        }
    }
    cnt[u] += gi;
}

int main() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;
        e[fa].push_back(i);
    }
    while (m--) {
        int u, gi;
        cin >> u >> gi;
        cnt[u]++;
        dfs(u, gi - 1);
    }
    for (int i = 0; i < n; i++) {
        cout << cnt[i] << ' ';
    }
    return 0;
}
