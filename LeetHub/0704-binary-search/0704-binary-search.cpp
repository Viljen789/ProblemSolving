int bs(vector<int>& nums, int target, int l, int r){
    if(l>r)return -1;
    int mid = l+(r-l)/2;
    if(nums[mid]>target)return bs(nums,  target, l, mid-1);
    else if (nums[mid]<target)return bs(nums,  target, mid+1,r);
    else return mid;
}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        return bs(nums, target, l, r);
    }
};