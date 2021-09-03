class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if (n==1){
            if (nums[0]==target)
                return 0;
            else
                return -1;
        }
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (nums[mid]==target){
                return mid;
            }
            //checking if left side is sorted
            if (nums[mid]>=nums[low]){
                if (nums[low]<=target and nums[mid]>=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //if right half is sorted
            else{
                if (nums[mid]<=target and nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};