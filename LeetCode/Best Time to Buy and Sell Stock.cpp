class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnPrice=INT_MAX;
        int profit=0;
        int n=prices.size();
        for (int i=0;i<n;i++){
            mnPrice=min(mnPrice,prices[i]);
            profit=max(profit,prices[i]-mnPrice);
        }
        return profit;
    }
};