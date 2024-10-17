
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cm = 0;
        int n = prices.size();
        vector<int> sell(n);
        vector<int> prof(n, 0);
        sell[n-1] = prices[n-1];
        for(int i = n-2; i>=0; i--)sell[i] =max(sell[i+1], prices[i]);
        prof[0] = sell[0]-prices[0];
        for(int i = 1; i<n; i++)prof[i] = max(prof[i-1], sell[i]-prices[i]);
        return prof[n-1];

    }
};