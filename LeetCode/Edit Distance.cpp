class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector <int> prev(m+1),curr(m+1);
        for (int i=0;i<=n;i++){
            for (int j=0;j<=m;j++){
                if (i==0)
                    curr[j]=j;
                else if (j==0)
                    curr[j]=i;
                else if (word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }
                else{
                    int res=1+prev[j-1];
                    res=min(res,1+prev[j]);
                    res=min(res,1+curr[j-1]);
                    curr[j]=res;
                }
            }
            prev=curr;
        }
        return curr[m];
    }
};