class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> v;
        int n=nums.size();
        v.push_back(nums[0]);
        for (int i=1;i<n;i++){
            if (v.back()<nums[i]){
                v.push_back(nums[i]);
            }
            else{
                auto ind=lower_bound(v.begin(),v.end(),nums[i]);
                *ind=nums[i];
            }
            // cout<<v.size()<<" ";
        }
        return v.size();
    }
};