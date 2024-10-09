class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, 10);
        unordered_map<int, int> um = {};
        for(int num  = 0; num<nums.size(); num++){
            if(um[target - nums[num]]){
                ans = {num, um[target-nums[num]]-10};
                return(ans);
            }
            um[nums[num]]=num+10;
        }   
        return ans;

    }
};