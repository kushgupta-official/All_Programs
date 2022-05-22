// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool canColor(bool graph[101][101],int node,int color,int n,vector <int> &colored){
    for (int i=0;i<n;i++){
        if (i!=node and graph[node][i] and colored[i]==color)
            return false;
    }
    return true;
}

bool solve(bool graph[101][101], int idx, int m, int n,vector <int> &colored){
    if (idx==n){
        return true;
    }
    for (int i=1;i<=m;i++){
        if (canColor(graph,idx,i,n,colored)){
            colored[idx]=i;
            if (solve(graph,idx+1,m,n,colored))
                return true;
            colored[idx]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector <int> colored(n,0);
    return solve(graph,0,m,n,colored);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends