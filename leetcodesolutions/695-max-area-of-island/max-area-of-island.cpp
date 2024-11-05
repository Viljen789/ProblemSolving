#define mp make_pair
#define f first
#define s second
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> v(n+2, vector<int>(m+2, 0));
    vector<vector<bool>> visited(n+2, vector<bool>(m+2, 0));
    for(int i = 1; i<=n; i++){
        for(int j= 1; j<=m; j++){
            v[i][j] = grid[i-1][j-1];
        }
    }
    queue<pair<int, int>> q;
    pair<int, int> p;
    int ans = 0, c = 0;		

    for(int i = 1; i<=n; i++){
            for(int j=1; j<=m; j++){
            	if(v[i][j])q.push(mp(i, j));
            	c = 0;
           		while(!q.empty()){
            	p = q.front();
                if(!visited[p.f][p.s]){
                    if(v[p.f][p.s+1]&&!visited[p.f][p.s+1])q.push(mp(p.f, p.s+1));
                    if(v[p.f][p.s-1]&&!visited[p.f][p.s-1])q.push(mp(p.f, p.s-1));
                    if(v[p.f+1][p.s]&&!visited[p.f+1][p.s])q.push(mp(p.f+1, p.s));
                    if(v[p.f-1][p.s]&&!visited[p.f-1][p.s])q.push(mp(p.f-1, p.s));
                    c++;
                }
                q.pop();
                visited[p.f][p.s] = 1;
            }
            ans = max(ans, c);
            }
            
        }
        return ans;
    }
};