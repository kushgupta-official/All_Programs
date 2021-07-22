class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n=nums.size();
        int mx=nums[0];
        int mxt=mx;
        int l=1;
        for (int i=1;i<n;i++){
            if (nums[i]<mx){
                l=i+1;
                mx=mxt;
            }
            else{
                mxt=max(mxt,nums[i]);
            }
        }
        return l;
    }
};