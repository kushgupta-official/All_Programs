class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue <int> pq;
        int ans=0;
        int cd=0,i=0;
        int cf=startFuel;
        while(cd<target){
            cd+=cf;
            cf=0;
            if (cd>=target){
                break;
            }
            while(i<stations.size() && stations[i][0]<=cd){
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()){
                return -1;
            }
            cf+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};