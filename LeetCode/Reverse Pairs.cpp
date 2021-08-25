class Solution {
public:
    int merge(vector <int> &nums,int l,int m,int r){
        int inv_cost=0;
        int j=m;
        for (int i=l;i<m;i++){
            while(j<=r and nums[i]>(long long)2*nums[j]){
                j++;
            }
            inv_cost+=j-m;
        }
        vector <int> temp(r-l+1);
        int idx=0,i=l;
        j=m;
        while(i<m and j<=r){
            if (nums[i]<=nums[j]){
                temp[idx++]=nums[i++];
            }
            else{
                temp[idx++]=nums[j++];
            }
        }
        while(i<m){
            temp[idx++]=nums[i++];
        }
        while(j<=r){
            temp[idx++]=nums[j++];
        }
        for (int k=0;k<r-l+1;k++){
            nums[l+k]=temp[k];
        }
        return inv_cost;
    }
    int mergeSort(vector <int> &nums,int l,int r){
        int inv_cost=0;
        if (l<r){
            int m=l+(r-l)/2;
            inv_cost+=mergeSort(nums,l,m);
            inv_cost+=mergeSort(nums,m+1,r);
            inv_cost+=merge(nums,l,m+1,r);
        }
        return inv_cost;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};