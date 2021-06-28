class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        int mn_diff=INT_MAX;
        int val=0;
        int n=v.size();
        sort(v.begin(),v.end());
        for (int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                if (mn_diff>abs( target-(v[left]+v[right]+v[i] ) ) ){
                    mn_diff=abs(target-(v[left]+v[right]+v[i]));
                    val=v[left]+v[right]+v[i];
                    if (mn_diff==0){
                        break;
                    }
                }
                if (v[left]+v[right]+v[i]<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return val;
    }
};