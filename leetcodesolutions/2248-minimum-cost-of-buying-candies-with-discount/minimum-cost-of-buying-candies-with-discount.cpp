class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int tot = 0; 
        for(int i = 0; i<n; i++)tot+=cost[i];
        n-=3;
        while(n>=0){
            tot-=cost[n];
            n-=3;
        }
        return tot;
    }
};