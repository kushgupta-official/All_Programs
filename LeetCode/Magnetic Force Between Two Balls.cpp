class Solution {
public:
    bool possible(vector <int> &position,int m,int d){
        int coord=position[0];
        int n=position.size();
        int cnt=1;
        for (int i=1;i<n;i++){
            if (position[i]-coord>=d){
                cnt++;
                coord=position[i];
            }
            if (cnt==m){
                return true;
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1,high=position[n-1]-position[0];
        int res=0;
        while(low<=high){
            int mid=(low+high)>>1;
            if (possible(position,m,mid)){
                low=mid+1;
                res=mid;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};