class Solution {
public:
    long maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        int mx1=0,mx2=0;
        for (int i=1;i<horizontalCuts.size();i++){
            mx1=max(horizontalCuts[i]-horizontalCuts[i-1],mx1);
        }
        for (int i=1;i<verticalCuts.size();i++){
            mx2=max(verticalCuts[i]-verticalCuts[i-1],mx2);
        }
        return ((long)mx1*(long)mx2)%1000000007;
    }
};