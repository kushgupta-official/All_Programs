class Solution {
public:
    string convert(string s, int numRows) {
        vector <string> v(numRows);
        bool flag=0;
        int j=-1;
        if (numRows==1){
            return s;
        }
        for (int i=0;i<s.size();i++){
            if (!flag){
                j++;
                // if (j==numRows)
                v[j].push_back(s[i]);
                if (j==numRows-1){
                    flag=1;
                }
            }
            else{
                j--;
                if (j<0){
                    j=0;
                }
                v[j].push_back(s[i]);
                if (j==0){
                    flag=0;
                }
            }
        }
        string res;
        for (int i=0;i<numRows;i++){
            res+=v[i];
        }
        return res;
    }
};