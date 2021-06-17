//https://www.youtube.com/watch?v=ZIJFMQzrNVY&list=PLEI-q7w3s9gRGYr0jtVjqir5_8SpnQ6Og&t=3s
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int s=0,e=0;
        int toAdd=0;
        int res=0;
        int n=nums.size();
        while(e<n){
            if (nums[e]>=left and nums[e]<=right){
                toAdd=e-s+1;
            }
            else if (nums[e]>right){
                toAdd=0;
                s=e+1;
            }
//             else if (nums[e]<left){
                 // toAdd=toadd;
//             }
            e++;
            res+=toAdd;
        }
        return res;
    }
};