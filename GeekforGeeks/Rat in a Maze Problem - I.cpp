// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector <pair<string,pair<int,int>>> directions={{"L",{0,-1}},{"U",{-1,0}},{"R",{0,1}},{"D",{1,0}}};
    void solve(string str,vector <vector <int>> &m,int n,vector <string> &res,int r,int c,vector <vector <bool>> &visited){
        // cout<<str<<endl;
        if (r==n-1 and c==n-1){
            res.push_back(str);
            return;
        }
        for (int i=0;i<4;i++){
            int newR=r+directions[i].second.first;
            int newC=c+directions[i].second.second;
            if (newR>=0 and newC>=0 and newR<n and newC<n and m[newR][newC] and !visited[newR][newC]){
                str+=directions[i].first;
                visited[newR][newC]=1;
                solve(str,m,n,res,newR,newC,visited);
                visited[newR][newC]=0;
                str.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector <string> res;
        if (m[0][0]==0)
            return res;
        vector <vector <bool>> visited(n,vector <bool> (n,false));
        string str="";
        visited[0][0]=1;
        solve(str,m,n,res,0,0,visited);
        sort(res.begin(),res.end());
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends