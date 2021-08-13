class Solution {
public:
    int n,m;
    vector<vector<int>> obstacleGrid,t;
    int solve(int i,int j){
        if (i>=n or j>=m){
            return 0;
        }
        if (t[i][j]!=-1){
            return t[i][j];
        }
        if (obstacleGrid[i][j]){
            return t[i][j]=0;
        }
        if (i==n-1 and j==m-1){
            return t[i][j]=1;
        }
        return t[i][j]=solve(i+1,j)+solve(i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size();
        m=obstacleGrid[0].size();
        t.resize(n+1,vector <int> (m+1,-1));
        this->obstacleGrid=obstacleGrid;
        if (obstacleGrid[0][0] or obstacleGrid[n-1][m-1])
            return 0;
        return solve(0,0);
    }
};