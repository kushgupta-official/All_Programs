class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i=0,j=0,n=nums.size();
        int nz=0;
        int mx=INT_MIN;
        while(j<n){
            if (nums[j]==0){
                nz++;
            }
            while(nz>k){
                if (nums[i]==0)
                    nz--;
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};