class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0;
        int temp=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                temp++;
            }
            else{
                temp--;
            }
            if (temp<0){
                res++;
                temp++;
            }
        }
        res+=temp;
        return res;
    }
};