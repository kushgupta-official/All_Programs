class Solution {
public:
    vector<vector<int>> grid,t;
    int n,m;
    int dp(int i,int j){
        if (i>=n or j>=m)
            return (int)1e8;
        if (t[i][j]!=-1){
            return t[i][j];
        }
        if (i==n-1 and j==m-1)
            return t[i][j]=grid[i][j];
        int left=dp(i,j+1);
        int right=dp(i+1,j);
        return t[i][j]=grid[i][j]+min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        this->grid=grid;
        n=grid.size();
        m=grid[0].size();
        t.resize(n+1,vector <int> (m+1,-1));
        return dp(0,0);
    }
};