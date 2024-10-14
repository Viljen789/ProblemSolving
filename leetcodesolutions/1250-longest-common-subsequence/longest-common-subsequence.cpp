int max(int a, int b) { return (a > b ? a : b); }

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = (text1[0]==text2[0]);
        for (int i = 1; i < n; i++)dp[i][0] = max(dp[i - 1][0], (text1[i] == text2[0]));
        for (int i = 1; i < m; i++)dp[0][i] = max(dp[0][i - 1], (text1[0] == text2[i]));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (text1[i] == text2[j])dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};