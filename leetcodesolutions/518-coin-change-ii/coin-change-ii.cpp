#define ll long long
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<ll> dp(amount+1, 0);
        sort(coins.begin(), coins.end());
        int i = 0;
        while(i*coins[0]<=amount)dp[i++*coins[0]] = 1;
        i = 0; 
        for(int i = 1; i<coins.size(); i++){
            for(int j = 0; j<=amount; j++){
                if(dp[j]>=2e9)return 0;
                if(j>=coins[i]){
                    if(dp[j] + dp[j-coins[i]]>=2e10)return 0;
                    dp[j]+=dp[j-coins[i]];
                }
            }
        } 
        return dp[amount];
    }
};