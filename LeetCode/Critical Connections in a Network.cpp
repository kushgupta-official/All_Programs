class Solution {
public:
    vector <vector <int> > adj;
    vector <int> visited,disc,low;
    vector <vector <int> > res;
    int time;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n,0);
        disc.resize(n,-1);
        low.resize(n,-1);
        time=0;
        for (int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0);
        return res;
    }
    void dfs(int node,int parent=-1){
        disc[node]=low[node]=++time;
        visited[node]=1;
        for (auto child:adj[node]){
            if (child==parent)
                continue;
            if (!visited[child]){
                dfs(child,node);
                low[node]=min(low[node],low[child]);
                if (low[child]>disc[node]){
                    res.push_back({node,child});
                }
            }
            else{
                low[node]=min(low[node],disc[child]);
            }
        }
    }
};