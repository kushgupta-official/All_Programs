class Solution {
public:
    int sum;
    int maxResult(vector<int>& nums, int k) {
        vector <int> dp(nums.size(),INT_MIN);
        dp[0]=nums[0];
        multiset <int> ms;
        ms.insert(nums[0]);
        for (int i=1;i<nums.size();i++){
            if (i>k)
                ms.erase(ms.find(dp[i-k-1]));
            dp[i]=*rbegin(ms)+nums[i];
            ms.insert(dp[i]);
        }
        return dp.back();
    }
};