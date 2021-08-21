class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <int> followers(n+1,0),follows(n+1,0);
        int s=trust.size();
        for (int i=0;i<s;i++){
            follows[trust[i][0]]++;
            followers[trust[i][1]]++;
        }
        vector <int> res;
        for (int i=1;i<=n;i++){
            if (follows[i]==0 and followers[i]==n-1){
                res.push_back(i);
            }
        }
        if (res.size()!=1)
            return -1;
        return res[0];
    }
};