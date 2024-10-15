class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i = 0; i<n; i++)s.insert(nums[i]);
        int tot = 0;
        int start = 0; 
        int end = 0;
        for(int i = 0; i<n; i++){
            if(s.find(nums[i])!=s.end()&&s.find(nums[i]-1)==s.end()){
                int j = nums[i];
                while(s.find(j++)!=s.end())tot = max(tot, j-nums[i]);
            }
        }
        return tot;

    }
};