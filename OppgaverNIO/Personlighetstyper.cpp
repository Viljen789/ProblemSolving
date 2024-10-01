#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_N = 26;

int n, m;
string company;
vector<int> graph[MAX_N];
bool visited[MAX_N];
int dp[MAX_N];

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

bool isCompatible(int u, int v) {
    if (!visited[u] || !visited[v]) {
        return false;
    }
    for (int i : graph[u]) {
        if (i == v) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m >> company;
    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        int ui = u - 'A', vi = v - 'A';
        graph[ui].push_back(vi);
        graph[vi].push_back(ui);
    }

    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1] + 1;
        for (int j = i-1; j >= 0; j--) {
            if (isCompatible(company[i] - 'A', company[j] - 'A')) {
dp[i] = min(dp[i], dp[j] + 1);
break;
}
}
}
// if no previous character is compatible with current character, start new department
for (int i = 1; i < n; i++) {
if (!isCompatible(company[i] - 'A', company[i-1] - 'A')) {
dp[i] = dp[i-1] + 1;
}
}
cout << dp[n-1] << endl;
return 0;
}
           
