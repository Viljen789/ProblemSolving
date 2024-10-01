
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x, y;
    vector<int> adj;
};

int main() {
    int n;
    cin >> n;

    vector<Node> nodes(n);

    // Read in coordinates
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].x >> nodes[i].y;
    }

    // Check adjacency and add edges
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = nodes[i].x - nodes[j].x;
            int dy = nodes[i].y - nodes[j].y;
            if (dx * dx + dy * dy == 1) {
                nodes[i].adj.push_back(j);
                nodes[j].adj.push_back(i);
            }
        }
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " is adjacent to:";
        for (int j : nodes[i].adj) {
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}