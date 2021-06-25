class Solution {
public:
    vector <int> res;
    vector <bool> vis;
    vector <vector <int> > adj;
    stack <int> s;
    unordered_set <int> uset;
    bool isCycle=false;
    void dfs(int curr,int prev){
        if (isCycle){
            return;
        }
        vis[curr]=true;
        // cout<<curr<<" ";
        s.push(curr);
        for (int i=0;i<adj[curr].size() and !isCycle;i++){
            if (adj[curr][i]!=prev){
                if (vis[adj[curr][i]]){
                    while(s.top()!=adj[curr][i]){
                        uset.insert(s.top());
                        cout<<s.top()<<" ";
                        s.pop();
                    }
                    isCycle=true;
                    // cout<<"yo ";
                    uset.insert(s.top());
                    return;
                    // break;
                }
                else
                    dfs(adj[curr][i],curr);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vis.resize(n+1,false);
        adj.resize(n+1);
        for (int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(1,-1);
        for (int i=edges.size()-1;i>=0;i--){
            if (uset.find(edges[i][0])!=uset.end() and uset.find(edges[i][1])!=uset.end()){
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
                break;
            }
        }
        return res;
    }
};