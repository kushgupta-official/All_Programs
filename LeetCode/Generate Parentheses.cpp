class Solution {
public:
    void solve(int start,int close,int n,vector <string> &res,string s=""){
        if (s.size()==2*n)
            res.push_back(s);
        if (start<n)
            solve(start+1,close,n,res,s+"(");
        if (close<start)
            solve(start,close+1,n,res,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        solve(0,0,n,res);
        return res;
    }
};