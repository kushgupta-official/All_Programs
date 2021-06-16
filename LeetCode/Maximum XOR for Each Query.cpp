class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int t=n;
        vector <int> res(n);
        int temp=0;
        int k=pow(2,maximumBit)-1;
        for (int i=0;i<n;i++){
            temp=temp^nums[i];
            res[--t]=k-temp;
        }
        return res;
    }
};