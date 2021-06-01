class Solution {
    
public:
    int res,temp;
    vector <vector <bool> > visited;
    vector <pair <int,int> > directions;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if (i<0 or i>=grid.size() or j<0 or j>=grid[0].size()){
            return; 
        }
        if (grid[i][j]==0){
            return;
        }
        if (visited[i][j]){
            return;
        }
        visited[i][j]=1;
        temp++;
        for (int k=0;k<4;k++){
            dfs(grid,i+directions[k].first,j+directions[k].second);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        res=0;
        directions={ {1,0} , {-1,0} , {0,1} , {0,-1} };
        visited.resize(grid.size());
        for (int i=0;i<grid.size();i++){
            visited[i].resize(grid[0].size(),false);
        }
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j] && !visited[i][j]){
                    temp=0;
                    dfs(grid,i,j);
                    res=max(res,temp);
                }
            }
        }
        return res;
    }
};