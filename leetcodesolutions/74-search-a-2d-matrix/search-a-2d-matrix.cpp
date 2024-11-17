class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n-1;
        int targrow = -1; 
        while(l<=r){
            int mid = (l+r)/2;

            if(target>=matrix[mid][0] && target <= matrix[mid][m-1]){
                targrow = mid;
                break;
            }
            else if(target>matrix[mid][0])l=mid+1;
            else r = mid-1;
        }
        if(targrow==-1)return 0;
        l = 0;
        r = m-1;

        while(l<=r){
            int mid = (l+r)/2;
            if(target==matrix[targrow][mid])return 1;
            else if(target<matrix[targrow][mid])r=mid-1;
            else l=mid+1;
        }
        return 0;
        }
};