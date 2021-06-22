class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector <vector <int> > v(26);
        int n=s.size();
        for (int i=0;i<n;i++){
            v[s[i]-'a'].push_back(i);
        }
        n=words.size();
        int res=0;
        for (int i=0;i<n;i++){
            int m=words[i].size();
            int idx=-1;
            for (int j=0;j<m;j++){
                auto ite=upper_bound(v[words[i][j]-'a'].begin(),v[words[i][j]-'a'].end(),idx);
                if (ite!=v[words[i][j]-'a'].end()){
                    idx=*ite;
                    if (j==m-1){
                        res++;
                    }
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};