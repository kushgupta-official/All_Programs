class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v;        
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue < int,vector<int>,greater<int> > pq;
        long sum=0,ans=0;
        for(auto x : v){
            sum+=x.second;
            pq.push(x.second);
            if(pq.size() > k){
                sum-=pq.top();
                pq.pop();
            }   
            ans=max(ans, sum*x.first);
        }
        return ans%1000000007;
    }
};