class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> stck;
        for (auto ch:s){
            // cout<<ch<<" ";
            if (!stck.empty() and stck.top()==ch){
                stck.pop();
            }
            else{
                stck.push(ch);
            }
        }
        string res;
        while(!stck.empty()){
            res+=stck.top();
            stck.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};