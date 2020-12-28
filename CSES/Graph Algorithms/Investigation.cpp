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

const ll mod=(1e9+7);

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

ll n, m;
vector <vector <pair <ll, ll> > > g;
vector <ll> route;
vector <ll> max_flights;
vector <ll> min_flights;
vector <ll> dist;

void solve(){
	priority_queue <
					pair <ll,ll>,
					vector <pair <ll,ll> >,
					greater <pair <ll,ll> > 
				   > pq;
	pq.push({0,1});
	route[1]=1;
	dist[1]=0;
	while(!pq.empty()){
		ll u=pq.top().second;
		ll d=pq.top().first;
		pq.pop();

		for (auto e:g[u]){
			ll v=e.first;
			ll c=e.second;
			if (dist[v]>d+c){
				dist[v]=d+c;
				route[v]=route[u];
				max_flights[v]=max_flights[u]+1;
				min_flights[v]=min_flights[u]+1;
				pq.push({dist[v],v});
			}
			else if (dist[v]==d+c){
				route[v]+=route[u];
				route[v]%=mod;
				max_flights[v]=max(max_flights[v], max_flights[u]+1);
				min_flights[v]=min(min_flights[v], min_flights[u]+1);
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
	route.resize(n+1);
	max_flights.resize(n+1);
	min_flights.resize(n+1);
	dist.resize(n+1, INF);

	loop(i,0,m){
		ll a=0, b=0, c=0;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
	}

	solve();	

	cout<<dist[n]<<" "<<route[n]<<" "<<min_flights[n]<<" "<<max_flights[n];

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}