class Solution {
public:
    int arrangeCoins(int n) {
        long long int lo=1,hi=65536;
        int res=0;
        while(lo<=hi){
            long long int mi=lo+(hi-lo)/2;
            long long int x=(mi*(mi+1))/2;
            if (x>n){
                hi=mi-1;
            }
            else{
                res=mi;
                lo=lo+1;
            }
        }
        return res;
    }
};