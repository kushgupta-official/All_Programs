class Solution {
public:
    int findLength(vector<int>& v1, vector<int>& v2) {
        int n=v1.size();
        int m=v2.size();
        int res=0;
        int dp[n+1][m+1];
        for (int i=0;i<=n;i++){
            for (int j=0;j<=m;j++){
                if (i==0 or j==0){
                    dp[i][j]=0;
                    continue;
                }
                if (v1[i-1]==v2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return res;
    }
};