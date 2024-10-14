#define ll long long
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ll>>dp(coins.size(), vector<ll>(amount+1, 0));
        sort(coins.begin(), coins.end());
        int i = 0;
        while(i*coins[0]<=amount)dp[0][i++*coins[0]] = 1;
        i = 0; 
        for(int i = 1; i<coins.size(); i++){
            for(int j = 0; j<=amount; j++){
                if(dp[i][j]>=2e9)return 0;
                dp[i][j] = + dp[i-1][j];
                if(j>=coins[i]){
                    if(dp[i][j] + dp[i][j-coins[i]]>=2e10)return 0;
                    dp[i][j]+=dp[i][j-coins[i]];
                }
            }
        } 
        return dp[n-1][amount];
    }
};