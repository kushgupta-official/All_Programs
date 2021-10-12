/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo=1,hi=n;
        while(lo<hi){
            int mi=lo+(hi-lo)/2;
            int res=guess(mi);
            if (res==0){
                return mi;
            }
            else if (res==-1){
                hi=mi-1;
            }
            else{
                lo=mi+1;
            }
        }
        return lo;
    }
};