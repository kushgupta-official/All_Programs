class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector <int> > res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for (int i=0;i<n-2;i++){
            if (nums[i]>0){
                break;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                if (nums[i]+nums[j]+nums[k]==0){
                    vector <int> temp={nums[i],nums[j],nums[k]};
                    res.push_back(temp);
                    while(j<k and nums[j]==temp[1]){
                        j++;
                    }
                    while(k>j and nums[k]==temp[2]){
                        k--;
                    }
                }
                else if (nums[j]+nums[k]+nums[i]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
            while(i+1<n and nums[i+1]==nums[i]){
                i++;
            }
        }
        return res;
    }
};