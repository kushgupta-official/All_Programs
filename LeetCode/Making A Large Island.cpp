class Solution {
public:
    unordered_map <int,int> area;
    int n,m;
    vector <vector <int> > pos={ {1,0}, {0,1}, {-1,0}, {0,-1} }; 
    int dfs(vector<vector<int>>& grid,int i,int j,int id){
        int ans=1;
        grid[i][j]=id;
        for (int k=0;k<4;k++){
            int r=i+pos[k][0];
            int c=j+pos[k][1];
            if (r>=0 and r<n and c>=0 and c<m and grid[r][c]==1){
                ans+=dfs(grid,r,c,id);
            }
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int id=2;
        int ans=INT_MIN;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    int ar=dfs(grid,i,j,id);
                    area[id++]=ar;
                    ans=max(ans,ar);
                }
            }
        }
        // for (auto i:area){
        //     cout<<i.first<<"->"<<i.second<<" ";
        // }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!grid[i][j]){
                    int ar=0;
                    unordered_set <int> s;
                    for (int k=0;k<4;k++){
                        int r=i+pos[k][0];
                        int c=j+pos[k][1];
                        if (r>=0 and r<n and c>=0 and c<m and grid[r][c]){
                            s.insert(grid[r][c]);
                        }
                    }
                    for (auto ite:s){
                        ar+=area[ite];
                    }
                    ans=max(ans,ar+1);
                }
            }
        }
        return ans;
    }
};