class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = -1e8, tot = -1e8;
        for(int i = 0; i<n; i++){
            ans = max(nums[i], ans+nums[i]);
            tot = max(tot, ans);
        }
        return tot;
    }
};