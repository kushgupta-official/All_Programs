class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int res=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;res+=matrix[i][j++]){
                if (i and j and matrix[i][j]){
                    matrix[i][j]+=min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]));
                }
            }
        }
        return res;
    }
};