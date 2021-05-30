class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map <char,int> cnt;
        int res=0;
        while(j<s.length()){
            if (cnt[s[j]]){
                while(s[i]!=s[j]){
                    cnt[s[i]]=0;
                    i++;
                }
                cnt[s[i]]=0;
                i++;
                cnt[s[j]]=1;
                res=max(res,j-i+1);
                j++;
            }
            else{
                cnt[s[j]]=1;
                res=max(res,j-i+1);
                j++;
            }
        }
        return res;
    }
};