class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> ump;
        int i=0;
        for (i=0;i<nums.size();i++){
            auto ite=ump.find(target-nums[i]);
            if (ite!=ump.end()){
                break;
            }
            ump[nums[i]]=i;
        }
        return vector <int> {i,ump[target-nums[i]]};
    }
};