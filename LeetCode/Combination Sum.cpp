class Solution {
public:
    void solve(int idx, vector<int>& candi, 
               vector <vector <int>> &ans,vector <int> &ds, int target){
        if (target==0){
            ans.push_back(ds);
            return;
        }
        if (idx==candi.size()){
            return;
        }
        if (target-candi[idx]>=0){
            ds.push_back(candi[idx]);
            solve(idx,candi,ans,ds,target-candi[idx]);
            ds.pop_back();
        }
            solve(idx+1,candi,ans,ds,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector <int> ds;
        solve(0,candidates,ans,ds,target);
        return ans;
    }
};