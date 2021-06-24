class Solution {
public:
    vector <vector<int> > moves={{1,0},{-1,0},{0,1},{0,-1}};
    const int mod=1000000007;
    bool isValid(int i,int j,int m,int n){
        return (i>=0 && i<m) && (j>=0 && j<n);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove==0){
            return 0;
        }
        vector <vector <vector <int> > >dp(maxMove+1,vector<vector<int> >(m,vector <int> (n,0)));
        for (int k=1,i=0;i<m;i++){
            dp[k][i][0]++;
            dp[k][i][n-1]++;
        }
        for (int k=1,j=0;j<n;j++){
            dp[k][0][j]++;
            dp[k][m-1][j]++;
        }
        int res=0;
        res+=dp[1][startRow][startColumn];
        for (int k=2;k<=maxMove;k++){
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    for (int move=0;move<4;move++){
                        if (isValid(i+moves[move][0],j+moves[move][1],m,n)){
                            dp[k][i][j]=(dp[k][i][j]%mod+dp[k-1][i+moves[move][0]][j+moves[move][1]]%mod)%mod;
                        }
                    }
                    if (i==startRow and j==startColumn){
                        res=(res%mod+dp[k][i][j]%mod)%mod;
                    }
                }
            }
        }
        return res;
    }
};