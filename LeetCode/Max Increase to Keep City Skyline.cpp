class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector <int> v1,v2;
        for (int i=0;i<n;i++){
            int mx=INT_MIN;
            for (int j=0;j<n;j++){
                mx=max(mx,grid[i][j]);
            }
            v1.push_back(mx);
        }
        for (int i=0;i<n;i++){
            int mx=INT_MIN;
            for (int j=0;j<n;j++){
                mx=max(mx,grid[j][i]);
            }
            v2.push_back(mx);
        }
        int res=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]!=max(v1[i],v2[j])){
                    res+=abs(min(v1[i],v2[j])-grid[i][j]);
                    // cout<<i<<" "<<j<<" "<<abs(min(v1[i],v2[j])-grid[i][j])<<endl;
                }
            }
        }
        return res;
    }
};