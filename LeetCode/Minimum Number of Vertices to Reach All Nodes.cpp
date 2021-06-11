class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> res;
        vector <int> hash(n,0);
        for(auto ite:edges){
            hash[ite[1]]=1;
        }
        for (int i=0;i<n;i++){
            if (!hash[i])
                res.push_back(i);
        }
        return res;
    }
};