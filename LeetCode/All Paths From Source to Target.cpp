class Solution {
public:
    int target;
    vector <vector <int> > res;
    vector <int> temp;
    
    void dfs(vector<vector<int>>& graph,int curr=0){
        temp.push_back(curr);
        if (curr==target)
            res.push_back(temp);
        else{
            for (auto i:graph[curr]){
                dfs(graph,i);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target=graph.size()-1;
        dfs(graph);
        return res;
    }
};