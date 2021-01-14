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

ll n,m;
vector <vector <pair <ll,ll> > > g;
vector <ll> dist;
ll max=INT_MIN;
ll min=1e17;
vector <ll> parent;

void dijkstra(){
	dist[1]=0;
	priority_queue <pair <ll,ll>, 
					vector <pair <ll,ll> >, 
					greater <pair <ll,ll> > > pq;
	pq.push({0,1});
	while(!pq.empty()){
		ll u=pq.top().second;
		ll w=pq.top().first;
		pq.pop();

		for (auto e:g[u]){
			ll v=e.first;
			ll d=e.second;
			if (dist[v]>d+w){
				dist[v]=d+w;
				pq.push({dist[v],v});
				parent[v]=u;
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

	cin>>n>>m;

	g.resize(n+1);
	dist.resize(n+1, 1e17);
	parent.resize(n+1);

	loop(i,0,m){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	dijkstra();

	vector <ll> visited(n+1,0);

	for (ll i=1;i<=n;i++){
		if (!visited[i]){
			ll max=INT_MIN, min=1e17;
			visited[i]=1;
			
		}
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