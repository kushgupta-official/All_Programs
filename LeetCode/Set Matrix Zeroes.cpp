class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool rowZero=0,colZero=0;
        for (int i=0;i<n;i++){
            if (matrix[i][0]==0){
                rowZero=1;
                break;
            }
        }
        for (int j=0;j<m;j++){
            if (matrix[0][j]==0){
                colZero=1;
                break;
            }
        }
        for (int i=1;i<n;i++){
            for (int j=1;j<m;j++){
                if (!matrix[i][j]){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for (int i=1;i<n;i++){
            for (int j=1;j<m;j++){
                if (!matrix[i][0] or !matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
        }
        if (rowZero){
            for (int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        if (colZero){
            for (int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
    }
};