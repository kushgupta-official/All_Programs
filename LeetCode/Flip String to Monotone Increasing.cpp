class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt=0;
        int flip=0;
        for(auto i:s)
        {
            if(i=='0')
                flip++;
            else
                cnt++;
            flip=min(flip,cnt);
        }
        return flip;
        
    }
};