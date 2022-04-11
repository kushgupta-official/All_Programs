class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector <vector <int> > newGrid(n, vector <int> (m,-1001));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int newRow=(i+(j+k)/m)%n;
                int newCol=(j+k)%m;
                newGrid[newRow][newCol]=grid[i][j];
            }
        }
        return newGrid;
    }
};