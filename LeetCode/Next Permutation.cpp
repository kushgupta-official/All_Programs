class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1=-1,idx2=-1;
        int n=nums.size();
        for (int i=n-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                idx1=i;
                break;
            }
        }
        if (idx1==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for (int i=n-1;i>=0;i--){
            if (nums[i]>nums[idx1]){
                idx2=i;
                break;
            }
        }
        swap(nums[idx1],nums[idx2]);
        int i=idx1+1,j=n-1;
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
    }
};