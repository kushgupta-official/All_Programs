class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        int j=0;
        string res;
        for (int i=0;i<n;i++){
            if (res.size()>=m and res.substr(res.size()-m)==part){
                res.erase(res.size()-m);
            }
            res.push_back(s[i]);
        }
        if (res.size()>=m and res.substr(res.size()-m)==part){
            res.erase(res.size()-m);
        }
        return res;
    }
};