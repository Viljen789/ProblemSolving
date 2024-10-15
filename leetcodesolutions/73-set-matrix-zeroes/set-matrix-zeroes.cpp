#define ll long long

void color(vector<vector<int>>& matrix, int i, int j, int tot){
    int n = matrix.size();
    int m = matrix[0].size();
    for(int a = 0; a<m; a++)if(matrix[i][a])matrix[i][a] = tot;
    for(int b = 0; b<n; b++)if(matrix[b][j])matrix[b][j] = tot;
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ll tot = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        if(n==m and n==1)return;
        for(int i = 0; i<n; i++)for(int j = 0; j<m; j++)tot+=abs(matrix[i][j]);
        ll mod = 1e9+7;
        tot%=(mod);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++)if(!matrix[i][j]){
                color(matrix, i, j, tot);

            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++)if(matrix[i][j]==tot)matrix[i][j]=0;
        }
    }
};