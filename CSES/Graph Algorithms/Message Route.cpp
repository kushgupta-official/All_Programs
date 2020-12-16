# include <bits/stdc++.h>
 
using namespace std;
# define ll long long
# define ld long double
# define loop(i,a,b) for(ll i=a;i<b;i++)
# define vi vector<int>
# define vll vector<ll>
# define vvl vector<vector <ll> >
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2
# define fi first
# define se second
 
void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
}
 
void bfs
(vvl &v, ll n, vector <bool> &visited, vector <ll> &previous){
  queue <ll> q;
  q.push(1);
  visited[1]=true;
  while(!q.empty()){
    ll curr=q.front();
    q.pop();
    // visited[curr]=true;
    for (auto i:v[curr]){
      if (visited[i]){
        continue;
      }
      visited[i]=true;
      q.push(i);
      previous[i]=curr;
      if (i==n){
        return;
      }
    }
  }
  return;
}
 
void solve(vvl &v, ll n){
  vector <bool> visited(n+1, false);
  vector <ll> previous(n+1,0);
  bfs(v,n,visited,previous);
  if (visited[n]){
    vector <ll> result;
    ll curr=n;
    result.push_back(n);
    while(curr>=1){
      result.push_back(previous[curr]);
      curr=previous[curr];
    }
    cout<<result.size()-1<<endl;
    for (ll i=result.size()-2;i>=0;i--){
      cout<<result[i]<<" ";
    }
  }
  else{
    cout<<"IMPOSSIBLE";
  }
  return;
}
 
int main()
{
  kush_gupta();
  ll n=0,m=0;
  cin>>n>>m;
  vvl v(n+1);
  for (ll i=1;i<=m;i++){
    ll a=0,b=0;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  solve(v, n);
  return 0;
} 