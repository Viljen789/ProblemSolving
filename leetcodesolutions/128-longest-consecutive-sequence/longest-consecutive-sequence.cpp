int max(int a, int b){
    return (a>b?a:b);
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> um;
        int n = nums.size();
        int tot = 0;
        for(int i = 0; i<n; i++)um[nums[i]]++;
        for(int i = 0; i<n; i++){
            int k = nums[i];
            int it = 1;
            if(um[k+1]&&!um[k-1])while(um[k+it])it++;
            tot = max(tot, it);
        }
        return tot;
    }
};
