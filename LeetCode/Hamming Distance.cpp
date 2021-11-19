class Solution {
public:
    int hammingDistance(int x, int y) {
        int sol=0;
        int n=x^y;
        while(n){
            sol++;
            n&=n-1;
        }
        return sol;
    }
};