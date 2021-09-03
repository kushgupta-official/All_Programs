class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if (n==1)
            return nums[0];
        int lo=0,hi=n-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if (nums[m]==nums[m^1]){  //left half
                lo=m+1;
            }
            else{                   //right half
                hi=m-1;
            }
        }
        return nums[lo];
    }
};