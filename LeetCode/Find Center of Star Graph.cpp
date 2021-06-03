class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map <int,int> mp;
        for(int i=0;i<2;i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        for (auto ite:mp){
            if (ite.second==2){
                return ite.first;
            }
        }
        return 0;
    }
};