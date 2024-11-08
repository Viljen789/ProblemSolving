bool lines(vector<vector<char>>& board){
    vector<int> row(9, 0);
    vector<int> col(9, 0);
    for(int j = 0; j<9; j++){
        row = {0,0,0,0,0,0,0,0,0};
        col = {0,0,0,0,0,0,0,0,0};
        for(int i = 0; i<9; i++){
            if(board[i][j]!='.'){
                if(col[board[i][j]-'1'])return 0;
                else col[board[i][j]-'1'] = 1;
            }
            if(board[j][i]!='.'){
                if(row[board[j][i]-'1'])return 0;
                else row[board[j][i]-'1'] = 1;
            }
        }
        // deb2(row, col);
    }
    return 1;
}
bool squares(vector<vector<char>>& board){
    vector<int> checker(0,9);
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            checker = {0,0,0,0,0,0,0,0,0};
            for(int k = 0; k<3; k++){
                for(int l = 0; l<3; l++){
                    if(board[k+3*j][l+3*i]!='.'){
                        if(checker[board[k+3*j][l+3*i]-'1'])return 0;
                        else checker[board[k+3*j][l+3*i]-'1'] = 1;
                    }
                }
            }
        }
    }
    return 1;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return(lines(board)&squares(board));
    }
};