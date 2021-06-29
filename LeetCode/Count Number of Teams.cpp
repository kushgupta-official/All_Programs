class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int res=0;
        for (int j=1;j<n-1;j++){
            int lb=0,ls=0,rb=0,rs=0;
            for (int i=0;i<j;i++){
                if (rating[i]>rating[j]){
                    lb++;
                }
                else{
                    ls++;
                }
            }
            for (int k=j+1;k<n;k++){
                if (rating[k]>rating[j]){
                    rb++;
                }
                else{
                    rs++;
                }
            }
            res+=lb*rs+ls*rb;
        }
        return res;
    }
};