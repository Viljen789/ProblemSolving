#define pb push_back
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<nums[i].size(); j++)um[nums[i][j]]++;
        }
        vector<int> ans;
        for(int i = 0; i<1001; i++)if(um[i]==nums.size())ans.pb(i);
        return ans;
    }
};