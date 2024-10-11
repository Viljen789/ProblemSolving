class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 0;
        if(nums.size()==1)return 1;
        int n = nums.size();
        vector<int> v(nums.size()+1, -1e5);
        for(int i = 0; i<n; i++){
            if(nums[i]>v[max]){
                v[++max]=nums[i];
            }
            else{
                for(int j = max; j>=0; j--){
                    if(j==0){
                        if(nums[i]<v[0])v[0] = nums[i];
                    }
                    else if(nums[i]<v[j]&&nums[i]>v[j-1]){
                        v[j]=nums[i];
                        break;
                    }
                }
            }
        }
        for(auto i: v)cout << i << endl;
        return max;
    }
};

//[10,9,2,5,7,101,4]
//[2, 4, 7, 18]  