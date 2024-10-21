class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot = 0;
        int n  = cost.size();
        for(int i = 0; i<n; i++)tot+=  gas[i]-cost[i];
        if(n==1){
            if(gas[0]>=cost[0])return 0;
            return -1;
        }

        for(int i = 0; i<n; i++){
            int rest = 0;
            if(gas[i]&&gas[i]!=cost[i]){
                for(int j = 0; j<n; j++){
                    rest += gas[(i+j)%n]-cost[(i+j)%n];
                    if(rest<0)break;
                }
                if(rest>=0)return i;
            }
        }
        return -1;
    }
};