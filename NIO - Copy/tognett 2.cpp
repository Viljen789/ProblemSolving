#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y) {
            return false;
        }

        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_x] = root_y;
            rank[root_y]++;
        }

        return true;
    }
};

vector<int> shut_down_flight_routes(int N, vector<pair<int, int>>& flights, vector<pair<int, int>>& trains) {
    DSU dsu(N);
    vector<int> result;

    for (auto& train : trains) {
        int u = min(train.first, train.second);
        int v = max(train.first, train.second);
        dsu.unite(u, v);

        int shut_down_count = 0;
        for (auto& flight : flights) {
            if (dsu.find(flight.first) == dsu.find(flight.second)) {
                shut_down_count++;
            }
        }

        result.push_back(shut_down_count);
    }

    return result;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> flights(M);
    for (int i = 0; i < M; ++i) {
        cin >> flights[i].first >> flights[i].second;
    }

    vector<pair<int, int>> trains(K);
    for (int i = 0; i < K; ++i) {
        cin >> trains[i].first >> trains[i].second;
    }

    vector<int> result = shut_down_flight_routes(N, flights, trains);

    for (int count : result) {
        cout << count << endl;
    }

    return 0;
}
