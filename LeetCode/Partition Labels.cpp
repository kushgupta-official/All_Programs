class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> mp(26,0);
        vector <int> res;
        for (int i=0;i<s.size();i++){
            mp[s[i]-'a']=i;
        }
        int temp=0;
        int toSubs=0;
        for (int i=0;i<s.size();i++){
            temp=max(temp,mp[s[i]-'a']);
            if (temp==i){
                res.push_back(i+1-toSubs);
                toSubs+=res.back();
                temp=0;
            }
        }
        return res;
    }
};