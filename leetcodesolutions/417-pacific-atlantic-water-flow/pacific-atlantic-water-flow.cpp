void dfs(vector<vector<bool>> &visited, vector<vector<int>> &res, int prev, int i, int j, int m, int n){
    if((i<0)||(i>n+1)||(j>m+1)||(j<0))return;
    if(res[i][j] >= prev && !visited[i][j]){
        visited[i][j]=1;
        dfs(visited, res, res[i][j], i+1, j, m, n);
        dfs(visited, res, res[i][j], i-1, j, m, n);
        dfs(visited, res, res[i][j], i, j+1, m, n);
        dfs(visited, res, res[i][j], i, j-1, m, n);

    }
}


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int INF = 1e9;
        vector<vector<int>> res(n+2, vector<int>(m+2, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                res[i][j] = heights[i-1][j-1];
            }
        }
        vector<vector<bool>> pac(n+2, vector<bool>(m+2, 0));
        res[0][m+1]= INF;
        res[n+1][0]= INF;
        vector<vector<bool>> atl(n+2, vector<bool>(m+2, 0));
        for(int i = 0; i<n; i++)pac[i][m+1]=INF;
        for(int i = 0; i<m; i++)pac[n+1][i]=INF;
        for(int i = 0; i<n; i++)atl[i][0]=INF;
        for(int i = 0; i<m; i++)atl[0][i]=INF;
        
        dfs(pac, res, 0, 0, 0, m, n);
        dfs(atl, res, 0, n+1, m+1, m, n);
        pac[n+1][0] = 0;
        pac[0][m+1] = 0;
        atl[n+1][0] = 0;
        atl[n+1][0] = 0;
        vector<vector<int>> ans;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(pac[i][j]&&atl[i][j])ans.push_back({i-1, j-1});
            }
        }
        return ans;
    }
};