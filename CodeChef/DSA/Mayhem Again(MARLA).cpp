# include <bits/stdc++.h>
#define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

ll matrix[1001][1001];
bool visited[1001][1001];
queue <pair<ll,ll> > q;

ll dfs(ll i,ll j,ll n,ll m){
  ll ans=0,x=0,y=0;
  ll value=matrix[i][j];
  visited[i][j]=1;
  q.push({i,j});
  while(!q.empty()){
    ans++;
    x=q.front().first;
    y=q.front().second;
    q.pop();
    if (x+1>=0 && y>=0 && x+1<n && y<m && !visited[x+1][y] && matrix[x+1][y]==value){
      q.push({x+1,y});
      visited[x+1][y]=1;
    }
    if (x-1>=0 && y>=0 && x-1<n && y<m && !visited[x-1][y] && matrix[x-1][y]==value){
      q.push({x-1,y});
      visited[x-1][y]=1;
    }
    if (x>=0 && y+1>=0 && x<n && y+1<m && !visited[x][y+1] && matrix[x][y+1]==value){
      q.push({x,y+1});
      visited[x][y+1]=1;
    }
    if (x>=0 && y-1>=0 && x<n && y-1<m && !visited[x][y-1] && matrix[x][y-1]==value){
      q.push({x,y-1});
      visited[x][y-1]=1;
    }
  }
  return ans;
}

pair<ll,ll> solve(ll n,ll m){
  ll max_path=INT_MIN,min_strength=-1;
  ll res=0;
  for (ll i=0;i<n;i++){
    for (ll j=0;j<m;j++){
      if(!visited[i][j]){
        res=dfs(i,j,n,m);
        if(res>max_path){
          max_path=res;
          min_strength=matrix[i][j];
        }
        else if(res==max_path && min_strength>matrix[i][j]){
          min_strength=matrix[i][j];
        }
      }
    }
  }
  pair<ll,ll> ans;
  ans.first=min_strength;
  ans.second=max_path;
  return ans;
}

int main(){
  kush_gupta();
  ll n=0,m=0;
  cin>>n>>m;
  for (ll i=0;i<n;i++){
    for (ll j=0;j<m;j++){
      cin>>matrix[i][j];
      visited[i][j]=0;
    }
  }
  pair <ll,ll> res=solve(n,m);
  cout<<res.first<<" "<<res.second;
}