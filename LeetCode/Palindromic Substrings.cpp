class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int res=0;
        vector<vector<int>> dp(n,vector <int>(n,0));
        for (int i=n-1;i>=0;i--){
            for (int j=i;j<n;j++){
                if (i==j)
                    dp[i][j]=1;
                else if (j==i+1){
                    dp[i][j]=s[i]==s[j];
                }
                else{
                    dp[i][j]=s[i]==s[j]?dp[i+1][j-1]:0;
                }
                res+=dp[i][j];
            }
        }
        return res;
    }
};