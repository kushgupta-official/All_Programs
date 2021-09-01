class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        int res=0;
        for (int i=0;i<n;i++){
            if (nums[i]==1)
                cnt++;
            else
                cnt=0;
            res=max(res,cnt);
        }
        return res;
    }
};