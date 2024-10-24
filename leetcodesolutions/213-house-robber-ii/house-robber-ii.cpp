#define mp make_pair
#define f first
#define s second
class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> v(n, vector<int>(2, 0));
    if(n==1)return nums[0];
    v[0] = {nums[0], 0};
    v[1] = {nums[0], nums[1]};

    for(int i = 2; i<n; i++){
        v[i][0] = max(v[i-1][0], v[i-2][0] + nums[i]);
        v[i][1] = max(v[i-1][1], v[i-2][1] + nums[i]);
    }
    
    return max(max(v[n-1][0]-min(nums[n-1], nums[0]),v[n-1][1]), v[n-2][0]);
}
};