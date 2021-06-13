class Solution {
public:
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if (s[i]!=s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map <string,int> mp;
        for (int i=0;i<words.size();i++){
            mp[words[i]]=i;
        }
        for (int i=0;i<words.size();i++){
            for (int j=0;j<=words[i].size();j++){
                string prefix=words[i].substr(0,j);
                string suffix=words[i].substr(j);
                if (isPalindrome(prefix)){
                    string rev=suffix;
                    reverse(rev.begin(),rev.end());
                    if (mp.count(rev) && mp[rev]!=i){
                        res.push_back({mp[rev],i});
                    }
                }
                if (isPalindrome(suffix)){
                    string rev=prefix;
                    reverse(rev.begin(),rev.end());
                    if (mp.count(rev) && mp[rev]!=i && !suffix.empty()){
                        res.push_back({i,mp[rev]});
                    }
                }
            }
        }
        return res;
    }
};