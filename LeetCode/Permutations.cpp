class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int> > sol;
        solve(0,nums,sol);
        return sol;
    }
    void solve(int idx,vector <int> &nums,vector <vector <int> > &sol)
    {
        if (idx==nums.size()){
            sol.push_back(nums);
        }    
        for (int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            solve(idx+1,nums,sol);
            swap(nums[i],nums[idx]);
        }
    }
};