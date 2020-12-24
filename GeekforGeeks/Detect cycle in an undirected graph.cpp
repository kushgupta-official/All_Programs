#include<bits/stdc++.h>
using namespace std;

bool cyclePresent(vector<int> g[], vector <bool> &isVisited, int u, int p){
    isVisited[u]=true;
    for (int i=0; i<g[u].size(); i++){
        int v=g[u][i];
        if (v==p){
            continue;
        }
        if (!isVisited[v]){
            if (cyclePresent (g, isVisited, v, u)){
                return true;
            }
        }
        else{
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   vector <bool> isVisited(V, false);
   for (int i=0;i<V;i++){
       if (!isVisited[i]){
            if (cyclePresent(g, isVisited, i, -1))
                return true;
       }
   }
   return false;
}

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
}

int main()
{
	kush_gupta();
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}