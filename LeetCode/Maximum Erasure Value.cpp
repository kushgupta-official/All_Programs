class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int j=0,i=0;
        int mx=INT_MIN,sum=0;
        unordered_map <int,int> ump;
        while(j<nums.size()){
            if (ump[nums[j]]!=0){
                while(nums[i]!=nums[j]){
                    sum-=nums[i];
                    ump[nums[i]]--;
                    i++;
                }
                ump[nums[i]]--;
                sum-=nums[i];
                i++;
                sum+=nums[j];
                mx=max(mx,sum);
                ump[nums[j]]++;
                j++;                
            }
            else{
                sum+=nums[j];
                mx=max(sum,mx);
                ump[nums[j]]++;
                j++;
            }
            // cout<<nums[i]<<" "<<nums[j]<<endl;
        }
        return mx;
    }
};