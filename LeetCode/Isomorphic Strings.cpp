class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector <int> mp(128,-1);
        vector <bool> check(128,false);
        int n=s.size();
        for (int i=0;i<n;i++){
            if (mp[s[i]]==-1 and !check[t[i]]){
                mp[s[i]]=t[i];
                check[t[i]]=true;
            }
            else if (mp[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
    }
};