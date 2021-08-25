class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a=0,b=sqrt(c);
        while(a<=b){
            long long int x=a*a+b*b;
            // cout<<x<<endl;
            if (x==(long long int)c){
                return true;
            }
            if (x<c){
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};