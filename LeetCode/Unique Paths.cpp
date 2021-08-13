class Solution {
public:
    int n,m;
    vector <vector <int> > t;
    int solve(int i,int j){
        if (i>=n or j>=m){
            return 0;
        }
        if (t[i][j]!=-1){
            return t[i][j];
        }
        if (i==n-1 and j==m-1){
            return t[i][j]=1;
        }
        return t[i][j]=solve(i+1,j)+solve(i,j+1);
    }
    int uniquePaths(int m, int n) {
        this->n=m;
        this->m=n;
        t.resize(this->n+1,vector <int> (this->m+1,-1));
        return solve(0,0);
    }
};