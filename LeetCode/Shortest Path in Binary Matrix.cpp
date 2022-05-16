class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        queue <pair <int,int> > q;
        q.push({0,0});
        vector <pair <int,int> > directions=
        {{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1}};
        vector <vector <bool> > visited(n,vector <bool> (n,false));
        visited[0][0]=true;
        int res=0;
        while(!q.empty()){
            cout<<res<<endl;
            int s=q.size();
            res++;
            for (int ite=0;ite<s;ite++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if (i==n-1 and j==n-1){
                    return res;
                }
                for (int k=0;k<8;k++){
                    int nextX=i+directions[k].first;
                    int nextY=j+directions[k].second;
                    // cout<<nextX<<" "<<nextY<<endl;
                    if (nextX>=0 and nextY>=0 and nextX<n and nextY<n and !visited[nextX][nextY] and grid[nextX][nextY]==0){
                        cout<<100<<endl;
                        q.push({nextX,nextY});
                        visited[nextX][nextY]=true;
                    }
                }
            }
        }
        return -1;
    }
};