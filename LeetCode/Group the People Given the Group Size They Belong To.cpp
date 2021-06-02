class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map <int,stack <int> > mp;
        int n=groupSizes.size();
        for (int i=0;i<n;i++){
            mp[groupSizes[i]].push(i);
        }
        vector<vector<int>> res;
        for (auto ite:mp){
            int m=ite.first;
            stack <int> s=ite.second;
            while(!s.empty()){
                vector <int> l;
                for (int i=0;i<m;i++){
                    l.push_back(s.top());
                    s.pop();
                }
                res.push_back(l);
            }
        }
        return res;
    }
};