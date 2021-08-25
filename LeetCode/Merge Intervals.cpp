class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector <vector <int > > res;
        int l=intervals[0][0],r=intervals[0][1];
        int n=intervals.size();
        for (int i=1;i<n;i++){
            if (intervals[i][0]>=l and intervals[i][0]<=r){
                r=max(r,intervals[i][1]);
            }
            else{
                res.push_back({l,r});
                l=intervals[i][0];
                r=intervals[i][1];
            }
        }
        res.push_back({l,r});
        return res;
    }
};