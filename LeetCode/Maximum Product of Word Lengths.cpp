class Solution {
public:
    bool anyCommon(vector <bool> &a,vector <bool> &b){
        for (int i=0;i<26;i++){
            if (a[i] and b[i]){
                return true;
            }
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int mx=0;
        vector <vector <bool> > v(n,vector <bool> (26,false));
        for (int i=0;i<n;i++){
            for (auto ch:words[i]){
                v[i][ch-'a']=1;
            }
            for (int j=0;j<i;j++){
                if (!anyCommon(v[i],v[j])){
                    mx=max(mx,(int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return mx;
    }
};