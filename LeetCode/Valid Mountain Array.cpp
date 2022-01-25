class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size()<3)
            return 0;
        int mx=-1,mn=-1;
        int n=arr.size();
        for (int i=0;i<n;i++){
            if (mn!=-1){
                if (arr[i]>=mn){
                    return 0;
                }
                else{
                    mn=arr[i];
                }
            }
            if (arr[i]>mx){
                mx=arr[i];
            }
            else if (arr[i]==mx){
                return 0;
            }
            else if (mn==-1){
                mn=arr[i];
            }
        }
        if (mx==arr[n-1] or mx==arr[0]){
            return 0;
        }
        return 1;
    }
};