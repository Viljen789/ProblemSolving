class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e8);
        dp[0] = 0;
        for(int i = 0; i<coins.size(); i++){
            for(int j = coins[i]; j<amount+1; j++){
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        return dp[amount]>=1e8?-1:dp[amount];
    }
};