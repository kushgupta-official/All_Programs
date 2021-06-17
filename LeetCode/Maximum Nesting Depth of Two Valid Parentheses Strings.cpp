class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector <int> res;
        int d=0;
        for (auto ch:seq){
            if (ch=='('){
                d+=1;
            }
            res.push_back(d%2);
            if (ch==')'){
                d-=1;
            }
        }
        return res;
    }
};