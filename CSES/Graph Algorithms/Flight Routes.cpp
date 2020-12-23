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
# define INF 1e17
 
void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}
 
ll n=0, m=0, k=0;
vector <vector <pair <ll,ll> > >g;
vector <vector <ll> > dist;
 
void solve(){
	priority_queue <pair <ll,ll>, 
					vector <pair <ll,ll> >, 
					greater <pair <ll,ll> > > pq;
	dist[1][1]=0;
	pq.push({0,1});	//{distance, u}
	while(!pq.empty()){
		ll u=pq.top().second;
		ll w=pq.top().first;
		pq.pop();
		if (dist[u][k]<w)
			continue;
		for (auto e:g[u]){
			ll v=e.first;
			ll c=e.second;
			if (dist[v][k]>w+c){
				dist[v][k]=w+c;
				pq.push({dist[v][k],v});
				sort(dist[v].begin()+1, dist[v].end());
			}
		}
	}
}
 
int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif
 
	cin>>n>>m>>k;
 
	g.resize(n+1);
	dist.resize(n+1, vector <ll> (k+1,INF) );
	loop(i,0,m){
		ll a=0, b=0, c=0;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
	}
 
	solve();
 
	for (ll i=1;i<=k;i++){
		cout<<dist[n][i]<<" ";
	}
 
	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}
