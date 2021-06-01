class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector <int> res(boxes.size());
        for (int i=0,ops=0,cnt=0;i<boxes.size();i++){
            res[i]+=ops;
            if (boxes[i]=='1')    cnt++;
            ops+=cnt;
        }
        for (int i=boxes.size()-1,ops=0,cnt=0;i>=0;i--){
            res[i]+=ops;
            if (boxes[i]=='1')    cnt++;
            ops+=cnt;
        }
        return res;
    }
};