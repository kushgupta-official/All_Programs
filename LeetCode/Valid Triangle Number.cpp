class Solution {
public:
    bool valid(int i,int j,int k){
        if (i+j>k and i+k>j and j+k>i){
            return true;
        }
        return false;
    }
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        sort(nums.begin(),nums.end());
        for (int i=2;i<n;i++){
            int start=0;
            int end=i-1;
            while(start<end){
                if (nums[start]+nums[end]>nums[i]){
                    res+=end-start;
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return res;
    }
};