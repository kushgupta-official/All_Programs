class Solution {
public:
    vector<int>v,v1;int n;
    Solution(vector<int>& nums) {
        v=nums;  
        v1=nums;
     n =v.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
     v=v1;
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
         
        for(int i = n-1;i>0;i--)
        {
        int j =rand() %(i+1);   // each time a new index is produced
        swap(v[i],v[j]);
    }
        return v;
    }
};