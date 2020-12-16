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
bool flag=1;
void dfs(vvl &v, ll n, vll &visited, ll i){
  //visited[i]=(visited[i]%2)+1;
  if (!visited[i]){
    visited[i]=(visited[i]%2)+1;
  }
  for (auto j:v[i]){
    if (visited[j]==visited[i]){
      flag=0;
      return;
    }
    else if (visited[j]==0){
      visited[j]=(visited[i]%2)+1;
      dfs(v,n,visited,j);
    }
  }
  return;
}
 
void solve(vvl &v, ll n){
  vll visited(n+1,0);
  for (ll i=1;i<=n;i++){
    if (!visited[i]){
      // visited[i]=(visited[i]%2)+1;
      dfs(v,n,visited,i);
    }
  }
  if (flag){
    for (ll i=1;i<=n;i++){
      cout<<visited[i]<<" ";
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