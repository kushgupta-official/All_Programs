class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int col=mat[0].size();
        if (row*col!=r*c){
            return mat;
        }
        vector <vector <int> > res(r,vector <int> (c));
        int ci=0,cj=0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (cj<c){
                    res[ci][cj++]=mat[i][j];
                }
                else{
                    cj=0;
                    ++ci;
                    res[ci][cj++]=mat[i][j];
                }
            }
        }
        return res;
    }
};