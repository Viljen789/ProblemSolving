#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

long long N;
long long B[MAXN], O[MAXN];
long long dp[MAXN][5];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> B[i] >> O[i];
  }

  // Initialize the base case for the DP
  dp[0][0] = 0; // don't sell anything on day 0
  dp[0][1] = B[0]; // sell in Bergen on day 0
  dp[0][2] = O[0]; // sell in Oslo on day 0
  dp[0][3] = 0; // on the way to Bergen
  dp[0][4] = 0; // on the way to Oslo

  // Calculate the maximum profit for each day
  for (int i = 1; i < N; i++) {
    // Don't sell anything
    dp[i][0] = max({dp[i-1][0], dp[i-1][3], dp[i-1][4]});

    // Sell in Bergen
    dp[i][1] = max({dp[i-1][0], dp[i-1][3]}) + B[i];

    // Sell in Oslo
    dp[i][2] = max({dp[i-1][0], dp[i-1][4]}) + O[i];

    // On the way to Bergen
    dp[i][3] = max({dp[i-1][0], dp[i-1][3], dp[i-1][4]});

    // On the way to Oslo
    dp[i][4] = max({dp[i-1][0], dp[i-1][3], dp[i-1][4]});
  }

  // The answer is the maximum profit on the last day
  cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2], dp[N-1][3], dp[N-1][4]}) << endl;

  return 0;
}
