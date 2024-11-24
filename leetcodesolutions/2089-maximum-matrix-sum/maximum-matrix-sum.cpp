class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool odd = 0;
        int low = 1e6;
        long long tot = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j]<0)odd = !odd;
                low = min(low, abs(matrix[i][j]));
                tot += abs(matrix[i][j]);
            }
        }
        return odd?tot-2*low:tot;
    }
};