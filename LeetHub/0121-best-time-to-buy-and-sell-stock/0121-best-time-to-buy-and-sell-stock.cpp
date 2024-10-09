class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin = 1e9, curmax = -1e9, curtot = 0;
        curmin = min(curmin, prices[0]);
        for (int i = 1; i < prices.size()-1; i++) {
            if (prices[i] >= prices[i - 1] && prices[i] > prices[i + 1]) {
                curmax = max(prices[i], curmax);

            }
            if (prices[i] <= prices[i - 1] && prices[i] < prices[i + 1]){
                if(prices[i]<curmin){
                    curmin = min(prices[i], curmin);
                    curmax = -1e9;
                }
            }
               
            curtot = max(curtot, curmax - curmin);
        }
        curmax = max(curmax, prices[prices.size()-1]);
        curtot = max(curtot, curmax - curmin);
        return curtot;
    }
};