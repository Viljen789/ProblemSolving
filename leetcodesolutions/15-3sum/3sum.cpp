#define ll long long 

int bs(vector<int> &v, int t, int l, int r){
    //if(t==0&&v[r]==0&&v[l]==0&&r-1)return -1;
    int L =l, R =r;
    int mid;
    while(l<=r){
        mid = (l + r)/2;
        if(v[mid]==t)return 1;
        else if(v[mid]<t)l = mid+1;
        else r = mid-1;
    }
    return -1;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(auto i : nums)cout << i << " ";
        cout << endl;
        int n = nums.size();
        if(nums[0]==nums[n-1]&&nums[0]==0)return {{0,0,0}};
        vector<vector<int>> v;
        vector<vector<int>> cur(3);
        for(int i = 0; i<n; i++){
            for(int j = n-1; j>i; j--){
                if(bs(nums, -(nums[j] + nums[i]), i+1, j-1)!=-1){
                    v.push_back({nums[i], -(nums[j] + nums[i]), nums[j]});
                }
            }
        }
        set<vector<int>> s;
        for(auto i : v)s.insert(i);
        vector<vector<int>> ans;
        for(auto i : s){
            ans.push_back(i);
        }

        return ans;
    }
};