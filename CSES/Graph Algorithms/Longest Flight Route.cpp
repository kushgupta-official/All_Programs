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
ll n=0, m=0;
vector <vector <pair <ll,ll> > > g;
vector <ll> dist;
vector <ll> parent;

void solve(){
	priority_queue <pair <ll,ll>,
					vector <pair <ll,ll> >,
					greater <pair <ll,ll> > > pq;
	dist[1]=0;
	pq.push({-1,1});

	while(!pq.empty()){
		ll u=pq.top().second;
		ll d=pq.top().first;
		pq.pop();

		for (auto e:g[u]){
			ll v=e.first;
			ll w=e.second;

			if (dist[v] > d+w){
				dist[v]=d+w;
				parent[v]=u;
				pq.push({dist[v], v});
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
	dist.resize(n+1, INF);
	parent.resize(n+1);

	loop(i,0,m){
		ll a=0, b=0;
		cin>>a>>b;
		g[a].push_back({b, -1});
	}

	solve();

	if (dist[n]==INF){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		vector <ll> res;
		for (ll i=n ; i>=1 ; i=parent[i]){
			res.push_back(i);
		}
		reverse(res.begin(), res.end());
		cout<<res.size()<<endl;
		for (auto i:res){
			cout<<i<<" ";
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