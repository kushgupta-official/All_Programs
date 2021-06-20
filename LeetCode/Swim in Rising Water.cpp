class Solution {
public:
    int n;
    bool isValid(int i,int j){
        if (i<0 or j<0 or i>=n or j>=n){
            return false;
        }
        return true;
    }
    vector <vector <int> > changes={ {1,0}, {-1,0}, {0,1}, {0,-1} };
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        vector <vector <bool> > visited(n+1,vector <bool> (n+1,false));
        priority_queue <pair <int,pair<int,int> > ,vector <pair <int,pair<int,int> > >, greater <pair <int,pair<int,int> > > > pq;
        pq.push({grid[0][0],{0,0}});
        int ans=grid[0][0];
        visited[0][0]=true;
        while(!pq.empty()){
            int d;
            pair <int,int> p;
            tie(d,p)=pq.top();
            int i,j;
            tie(i,j)=p;
            ans=max(ans,d);
            if (i==n-1 and j==n-1){
                break;
            }
            pq.pop();
            for (int k=0;k<4;k++){
                int x=i+changes[k][0];
                int y=j+changes[k][1];
                if (isValid(x,y) and !visited[x][y]){
                    visited[x][y]=true;
                    pq.push({grid[x][y],{x,y}});
                }
            }
        }
        return ans;
    }
};