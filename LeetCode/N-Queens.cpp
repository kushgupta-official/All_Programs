class Solution {
public:
    vector<vector<string>> res;
    bool isPossible(vector <string> &board,int n,int row,int col){
        int duprow=row,dupcol=col;
        while(duprow>=0 and dupcol>=0){
            if (board[duprow][dupcol]=='Q')
                return false;
            duprow--;
            dupcol--;
        }
        dupcol=col;
        duprow=row;
        while(dupcol>=0){
            if (board[duprow][dupcol]=='Q')
                return false;
            dupcol--;
        }
        dupcol=col;
        duprow=row;
        while(duprow<n and dupcol>=0){
            if (board[duprow][dupcol]=='Q')
                return false;
            duprow++;
            dupcol--;
        }
        return true;
    }
    void solve(int n,vector<string> &board,int col=0){
        if (col==n){
            res.push_back(board);
            return;
        }
        for (int row=0;row<n;row++){
            if (isPossible(board,n,row,col)){
                board[row][col]='Q';
                solve(n,board,col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <string> board(n);
        string s(n,'.');
        for (int i=0;i<n;i++){
            board[i]=s;
        }
        solve(n,board);
        return res;
    }
};