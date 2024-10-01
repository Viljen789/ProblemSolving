#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Step 1: Parse input
    int N, M;
    cin >> N >> M;

    vector<int> elevation(N);
    for (int i = 0; i < N; ++i) {
        cin >> elevation[i];
    }

    // Step 2: Initialize dp array
    vector<int> dp(N, 0);

    // Step 3: Calculate maximum horizontal distance for each position
    for (int i = 1; i < N; ++i) {
        int max_height = 0;

        // Considering the terrain height
        max_height = max(max_height, elevation[i]);

        // Update max_height by considering tower heights
        dp[i] = max(dp[i], dp[i - 1] + 1); // Horizontal distance is at least the previous one

        // Update dp array for the current position
        dp[i] = max(dp[i], max_height);

        // Output to debug if needed
        // cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    // Step 4: Parse tower proposals and output results
    for (int j = 0; j < M; ++j) {
        int x, h;
        cin >> x >> h;

        // Step 5: Output maximum horizontal distance for each tower proposal
        cout << dp[x] << endl;
    }

    return 0;
}
