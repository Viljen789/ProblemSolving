class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size()-1, l = 0, tot = 0;
        while(l<r){
            tot = max(tot, min(height[l], height[r])*(r-l));
            if(height[l]<height[r])l++;
            else r--;
        }
        return tot;
    }
};