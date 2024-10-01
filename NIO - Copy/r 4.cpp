#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> list(N+1), prefixSum(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> list[i];
        prefixSum[i] = prefixSum[i-1] + list[i];
    }
    vector<vector<ll>> dp(N+1, vector<ll>(M+1));
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            if(j == 0) {
                dp[i][j] = prefixSum[i] - dp[max(0, i-M)][M];
            } else {
                dp[i][j] = max(dp[i-1][j-1] + list[i], dp[i-1][j]);
            }
        }
    }
    cout << dp[N][M] << " " << prefixSum[N] - dp[N][M] << "\n";
    return 0;
}