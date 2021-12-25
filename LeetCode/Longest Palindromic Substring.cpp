class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector <vector <bool> > dp(n,vector <bool> (n,false));
        for (int i=0;i<n;i++){
            dp[i][i]=true;
        }
        string res="";
        res+=s[0];
        for (int i=n-1;i>=0;i--){
            for (int j=i+1;j<n;j++){
                if (s[i]==s[j]){
                    if (j-i==1 or dp[i+1][j-1]){
                        dp[i][j]=true;
                        if (j-i+1>res.size()){
                            res=s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return res;
    }
};