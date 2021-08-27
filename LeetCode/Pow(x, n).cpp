class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if (nn<0)
            nn*=-1;
        while(nn!=0){
            if (nn%2){
                ans*=x;
                nn--;
            }
            else{
                x=x*x;
                nn/=2;
            }
        }
        if (n<0)
            return 1.0/ans;
        else
            return ans;
    }
};