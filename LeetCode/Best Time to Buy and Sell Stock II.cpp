class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,sell=0,n=prices.size();
        int res=0;
        while(buy<n and sell<n){
            while(buy<n-1 and prices[buy]>prices[buy+1])
                buy++;
            sell=buy;
            while(sell<n-1 and prices[sell]<prices[sell+1])
                sell++;
            res+=prices[sell]-prices[buy];
            buy=sell+1;
            // sell++;
        }
        return res;
    }
};