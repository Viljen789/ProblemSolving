#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;


    vector<int> prefix(n + 1, 0);


    for (int i = 0; i < k; i++) {
        int s, e;
        cin >> s >> e;
        prefix[s]++;
        prefix[e + 1]--;
    }


    for (int i = 1; i <= n; i++) {
        prefix[i] += prefix[i - 1];
    }


    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (prefix[i] % 2 == 1) {
            ones++;
        }
    }


    cout << n - ones << endl;

    return 0;
}
