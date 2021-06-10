class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector <vector <int> > matrix(rowSum.size(),vector <int> (colSum.size()));
        for (int i=0;i<rowSum.size();i++){
            for (int j=0;j<colSum.size();j++){
                matrix[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=matrix[i][j];
                colSum[j]-=matrix[i][j];
            }
        }
        return matrix;
    }
};