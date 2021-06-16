class Solution {
public:
    vector <int> res;
    void solve(int label,int level){
        if (label==1){
            res.push_back(label);
            return;
        }
        res.push_back(label);
        int temp=pow(2,level-1)-(label/2)-1+pow(2,level-2);
        if (level&1){
            // int temp=pow(2,level-1)-p-1+pow(2,level-2);
            solve(temp,level-1);
        }
        else{
            solve(temp,level-1);
        }
    }
    vector<int> pathInZigZagTree(int label) {
        solve(label,floor(log2(label))+1);
        reverse(res.begin(),res.end());
        return res;
    }
};