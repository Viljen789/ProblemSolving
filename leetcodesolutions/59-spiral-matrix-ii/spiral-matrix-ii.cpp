class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        bool l = 0, r = 1, u = 0, d = 0;
        int x = -1, y = 0; 
        int i = 1;
        while(i<=n*n){
            if(r){
                if(x==(n-1)||ans[y][x+1]){
                    d = 1;
                    r = 0;
                    y++;
                }else{
                    x++;
                }
                ans[y][x]=i; 
                i++;
                continue;
            }if(l){
                if(x==0||ans[y][x-1]){
                    u = 1;
                    l = 0;
                    y--;
                }else{
                    x--;
                }
                ans[y][x]=i; 
            i++;
            continue;
            }if(u){
                if(y==0||ans[y-1][x]){
                    r = 1;
                    u = 0;
                    x++;
                }else{
                    y--;
                }
                ans[y][x]=i; 
            i++;
            continue;
            }if(d){
                if(y==(n-1)||ans[y+1][x]){
                    d = 0;
                    l = 1;
                    x--;
                }else{
                    y++;
                }
                ans[y][x]=i; 
            i++;
            continue;
            }
            
        }
        return ans;
    }
};