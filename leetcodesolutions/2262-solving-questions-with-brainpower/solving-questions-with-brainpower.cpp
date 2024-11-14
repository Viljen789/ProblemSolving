#define ll long long
ll max(int a, int b){
    return a>b?a:b;
}
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp (n, 0);
        dp[n-1] = questions[n-1][0];
        for(int i = n-2; i>=0; i--){
            if((questions[i][1]+i+1)>=dp.size())dp[i] = max(dp[i+1], questions[i][0]);
            else dp[i] = max(dp[i+1], dp[i+questions[i][1]+1]+ questions[i][0]);
        }
        return dp[0];
    }
};