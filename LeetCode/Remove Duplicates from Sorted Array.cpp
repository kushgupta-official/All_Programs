class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int j=1;
        for (int i=1;i<nums.size();i++){
            if (nums[i]!=nums[i-1]){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};