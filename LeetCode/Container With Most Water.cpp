class Solution {
public:
    int maxArea(vector<int>& h) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int mxArea=0;
        int n=h.size();
        int i=0,j=n-1;
        while(i<j){
            int mn=min(h[i],h[j]);
            mxArea=max(mxArea,(j-i)*mn);
            while (h[i]<=mn and i<j)
                i++;
            while (h[j]<=mn and i<j)
                j--;
        }
        return mxArea;
    }
};