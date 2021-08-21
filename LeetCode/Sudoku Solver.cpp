class Solution {
public:
    vector<vector<char>> board;
    
    bool solve(int i,int j){
        if (i==9 and j==0){
            return true;
        }
        if (board[i][j]!='.'){
            return solve((j+1)==9?i+1:i, (j+1)==9?0:j+1);
        }
        for (char ch='1';ch<='9';ch++){
            if (isValid(i,j,ch)){
                board[i][j]=ch;
                if (solve((j+1)==9?i+1:i, (j+1)==9?0:j+1))
                    return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    
    bool isValid(int r,int c,char ch){
        int rowBlock=3*(r/3);
        int colBlock=3*(c/3);
        for (int i=0;i<9;i++){
            if (board[i][c]==ch)
                return false;
            if (board[r][i]==ch)
                return false;
            if (board[rowBlock+i/3][colBlock+i%3]==ch)
                return false;
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        this->board=board;
        solve(0,0);
        board=this->board;
    }
};