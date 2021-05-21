class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> res;
        for (int i=0;i<words.size();i++){
            unordered_map<char,char> ump;
            bool flag=1;
            vector <bool> check(26,false);
            for (int j=0;j<pattern.size();j++){
                if (ump.find(pattern[j])==ump.end()){
                    if (!check[words[i][j]-'a']){
                        ump[pattern[j]]=words[i][j];
                        check[words[i][j]-'a']=true;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
                else{
                    if (ump[pattern[j]]!=words[i][j]){
                        flag=0;
                        break;
                    }
                }
            }
            if (flag){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};