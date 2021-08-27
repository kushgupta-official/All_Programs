class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m-1;
        while(i>=0 and i<n and j<m and j>=0){
            // cout<<i<<" "<<j<<endl;
            if (matrix[i][j]==target){
                return true;
            }
            else if (target<matrix[i][j]){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};