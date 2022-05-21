class Solution {
public:
    bool solve(vector <int> &nums,int n,int s,vector <vector <int> > &dp){
        if (s==0){
            return true;
        }
        if (n==0){
            return false;
        }
        if (dp[n][s]!=-1)
            return dp[n][s];
        if (nums[n-1]<=s){
            return dp[n][s]=solve(nums,n-1,s-nums[n-1],dp) || solve(nums,n-1,s,dp);
        }
        return dp[n][s]=solve(nums,n-1,s,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for (int i=0;i<n;i++){
            s+=nums[i];
        }
        if (s%2==0){
            vector <vector <int> > dp(n+1,vector <int> (s/2+1,-1));
            return solve(nums,n,s/2,dp);
        }
        return false;
    }
};