class Solution {
public:
    vector <vector <bool> > vis;
    int n,m;
    vector <vector <int> > moves={ {1,0}, {0,1}, {-1,0}, {0,-1} };
    bool valid(int x,int y){
        if (x>=0 and x<n and y>=0 and y<m)
            return true;
        return false;
    }
    bool bfs(vector<vector<char>>& board,int i,int j){
        bool flag=1;
        queue <pair <int,int> > q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            int n=q.size();
            // cout<<q.front().first<<" "<<q.front().second<<" "<<n<<endl;
            if (n>1){
                flag=0;
            }
            for (int k=0;k<n;k++){
                int x,y;
                tie(x,y)=q.front();
                q.pop();
                // cout<<1<<endl;
                for (int l=0;l<4;l++){
                    // cout<<l<<endl;
                    if (valid(x+moves[l][0],y+moves[l][1]) and
                        board[x+moves[l][0]][y+moves[l][1]]=='X' and 
                        !vis[x+moves[l][0]][y+moves[l][1]])
                    {
                        vis[x+moves[l][0]][y+moves[l][1]]=true;
                        q.push({x+moves[l][0],y+moves[l][1]});
                    }
                }
            }
        }
        return flag;
    }
    int countBattleships(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vis.resize(n,vector <bool> (m,false));
        int res=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]=='X' and !vis[i][j]){
                    if (bfs(board,i,j)){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};