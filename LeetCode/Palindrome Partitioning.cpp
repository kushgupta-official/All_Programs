class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector <vector <string> > sol;
        vector <string> res;
        solve(0,s,res,sol);
        return sol;
    }
    void solve
    (int idx,string s,vector <string> &res,vector <vector <string> > &sol)
    {
        if (idx==s.size()){
            sol.push_back(res);
            return;
        }    
        for (int i=idx;i<s.size();++i){
            if (isPalin(s,idx,i)){
                res.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,res,sol);
                res.pop_back();
            }
        }
    }
    bool isPalin(string s,int l,int r){
        while(l<=r){
            if (s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
};