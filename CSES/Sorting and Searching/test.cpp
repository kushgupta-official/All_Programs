# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
}

void trav(vector <vector <ll> > &v, vector <bool> &visited, ll i){
  if (visited[i]){
    return;
  }
  visited[i]=true;
  cout<<i<<" ";
  for (auto i:v[i]){
    trav(v,visited,i);
  }
}

void dfs(ll n, ll m, vector <vector <ll> > &v){
  vector <bool> visited(n+1,false);
  for (ll i=1;i<=n;i++){
    if (visited[i])
      continue;
    trav(v, visited, i);
  }
}

int main()
{
  kush_gupta();
  ll n=0,m=0;
  cin>>n>>m;
  vector <vector <ll> > v(n+1);
  rep(i,1,m+1){
    ll x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  } 
  dfs(n,m,v);
  return 0;
}