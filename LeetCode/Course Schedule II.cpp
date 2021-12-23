class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector <int> indegree(n,0);
        vector <vector <int> > adj(n);
        for (int i=0;i<v.size();i++){
            indegree[v[i][0]]++;
            adj[v[i][1]].push_back(v[i][0]);
        }
        queue <int> q;
        for (int i=0;i<n;i++){
            if (!indegree[i]){
                q.push(i);
            }
        }
        int cnt=0;
        vector <int> res;
        while(!q.empty()){
            int curr=q.front();
            // cout<<curr<<endl;
            q.pop();
            cnt++;
            res.push_back(curr);
            for (auto i:adj[curr]){
                if (--indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if (cnt==n){
            return res;
        }
        return vector <int> {};
    }
};