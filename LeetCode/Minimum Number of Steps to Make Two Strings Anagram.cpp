class Solution {
public:
    int minSteps(string s, string t) {
        vector <int> hash(26,0);
        int res=0;
        for (int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }
        for (int i=0;i<26;i++){
            if (hash[i]>0){
                res+=hash[i];
            }
        }
        return res;
    }
};