class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector <string> > res;
        int n=strs.size();
        unordered_map <string,int> mp;
        int curr=0;
        for (int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if (mp[temp]){
                res[mp[temp]-1].push_back(strs[i]);
            }
            else{
                mp[temp]=res.size()+1;
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};