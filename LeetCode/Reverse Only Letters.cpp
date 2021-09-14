class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if (isalpha(s[l]) and isalpha(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if (isalpha(s[l])){
                r--;
            }
            else if (isalpha(s[r])){
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        return s;
    }
};