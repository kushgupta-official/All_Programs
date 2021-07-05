class Solution {
public:
    int minFlips(string target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int flag=0;
        int res=0;
        int n=target.size();
        for (int i=0;i<n;i++){
            if (target[i]-'0'!=flag){
                flag=1-flag;
                res++;
            }
        }
        return res;
    }
};