class Solution {
public:
    void calculateLPS(string pattern,int m,vector <int> &lps){
        lps[0]=0;
        int i=1;
        int len=0;
        while(i<m){
            if (pattern[i]==pattern[len]){
                lps[i]=++len;
                i++;
            }
            else{
                if (len==0){
                    lps[i++]=0;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if (m==0){
            return 0;
        }
        vector <int> lps(m);
        calculateLPS(needle,m,lps);
        int i=0,j=0;
        while(i<n){
            if (haystack[i]==needle[j]){
                j++;
                i++;
            }
            else{
                if (j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
            if (j==m){
                return i-j;
            }
        }
        return -1;
    }
};