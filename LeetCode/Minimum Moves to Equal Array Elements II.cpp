class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target=nums[(nums.size()-1)/2];
        int res=0;
        for (auto i:nums){
            res+=abs(i-target);
        }
        return res;
    }
};