class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=s.length();
        int sum=0;
        for (int i=n-1;i>=0;i--){
            sum=(shifts[i]+sum)%26;
            s[i]=(s[i]-'a'+sum)%26+'a';
        }
        return s;
    }
};