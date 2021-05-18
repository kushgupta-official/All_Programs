class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            if (nums[i]+nums[j]==target){
                result.push_back(i);
                result.push_back(j);
            }
            else if (nums[i]+nums[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return result;
    }
};