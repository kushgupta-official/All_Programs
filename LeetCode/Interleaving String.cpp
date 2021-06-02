class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector <vector <bool> > dp(s1.size()+1,vector <bool> (s2.size()+1,false));
        dp[0][0]=1;
        if (s1.size()+s2.size()!=s3.size()){
            return false;
        }
        for (int i=1;i<=s1.size();i++){
            dp[i][0]=(s3[i-1]==s1[i-1]) && dp[i-1][0];
        }
        for (int j=1;j<=s2.size();j++){
            dp[0][j]=(s3[j-1]==s2[j-1]) && dp[0][j-1];
        }
        for (int i=1;i<=s1.size();i++){
            for (int j=1;j<=s2.size();j++){
                dp[i][j]=(s1[i-1]==s3[i+j-1] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};