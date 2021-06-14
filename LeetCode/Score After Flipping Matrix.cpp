class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int i,j;
        for (i=0,j=0;i<grid.size();i++){
            if (grid[i][j]==0){
                for (int k=0;k<grid[0].size();k++){
                    grid[i][k]=1-grid[i][k];
                }
            }
        }
        vector <bool> v(grid[0].size(),false);
        for (int j=1;j<grid[0].size();j++){
            int count1=0;
            for (int i=0;i<grid.size();i++){
                if (grid[i][j])
                    count1++;
                else
                    count1--;
            }
            if (count1<0){
                v[j]=1;
            }
        }
        int res=0;
        for (int i=0;i<grid.size();i++){
            int p=0;
            for (int j=grid[0].size()-1;j>=0;j--){
                if (v[j]){
                    res+=(1-grid[i][j])*pow(2,p++);
                }
                else{
                    res+=grid[i][j]*pow(2,p++);
                }
            }
        }
        return res;
    }
};