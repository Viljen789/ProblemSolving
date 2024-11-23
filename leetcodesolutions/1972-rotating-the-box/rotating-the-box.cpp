class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> res(m, vector<char>(n));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                for(int k = 0; k<m-1; k++){
                    if(box[i][k+1]=='.'&&box[i][k]=='#'){
                        box[i][k+1]='#';
                        box[i][k]='.';
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res[j][n-i-1] = box[i][j];
            }
        }
        return res;
    }
};