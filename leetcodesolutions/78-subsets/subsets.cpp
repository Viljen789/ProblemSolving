void rec(vector<int>& nums, int t, vector<vector<int>> &ans, vector<int> cur){
    if(t==(nums.size())){
        ans.push_back(cur);
        return;
        }

    rec(nums, t+1, ans, cur);
    cur.push_back(nums[t]);
    rec(nums, t+1, ans, cur);

    
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(nums, 0, ans, {});
        return ans;
    }
};