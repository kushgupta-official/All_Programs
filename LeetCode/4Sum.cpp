class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        vector <vector<int> > res;
        int n=v.size();
        sort(v.begin(),v.end());
        for (int i=0;i<n-3;i++){
            // int t=target-v[i];
            for (int j=i+1;j<n-2;j++){
                // t2-=v[j];
                int left=j+1;
                int right=n-1;
                while(left<right){
                    int t=v[i]+v[j]+v[left]+v[right];
                    if (t==target){
                        vector <int> temp={v[i],v[j],v[left],v[right]};
                        res.push_back(temp);
                        while(left<right and v[left]==temp[2]){
                            left++;
                        }
                        while(left<right and v[right]==temp[3]){
                            right--;
                        }
                    }
                    else if (t<target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
                while(j+1<n and v[j+1]==v[j]){
                    j++;
                }
            }
            while(i+1<n and v[i+1]==v[i]){
                i++;
            }
        }
        return res;
    }
};