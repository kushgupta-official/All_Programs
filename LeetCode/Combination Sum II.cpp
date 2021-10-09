class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int idx,vector <int> &cand,vector <int> &ds,int target){
        if (target==0){
            ans.push_back(ds);
            return;
        }
        for (int i=idx;i<cand.size();i++){
            if (i!=idx and cand[i-1]==cand[i])
                continue;
            if (cand[i]>target)
                break;
            ds.push_back(cand[i]);
            solve(i+1,cand,ds,target-cand[i]);
            ds.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector <int> ds;
        solve(0,cand,ds,target);
        return ans;
    }
};