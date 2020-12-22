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
vector <ll> coupon_dist;

void dijkstra(){
	dist[1]=0;
	coupon_dist[1]=0;

	priority_queue <pair <ll, pair <ll,ll> >,
					vector <pair <ll, pair <ll,ll> > >,
					greater <pair <ll, pair <ll,ll> > > > pq;

	pq.push({0, {1, 0}});

	while(!pq.empty()){
		ll u=pq.top().second.first;
		ll w=pq.top().first;
		ll flag=pq.top().second.second;
		pq.pop();

		if(flag == 0)
		{
			if(dist[u] < w) continue; 
		}
 
		if(flag == 1)
		{
			if(coupon_dist[u] < w) continue; 
		}
		for (auto e:g[u]){
			ll v=e.first;
			ll c=e.second;
			if (flag==0){
				if (dist[v]>c+w){
					dist[v]=c+w;
					pq.push({dist[v], {v, 0}});
				}
				if (coupon_dist[v]>(c/2)+w){
					coupon_dist[v]=(c/2)+w;
					pq.push({coupon_dist[v], {v, 1}});
				}
			}
			else{
				if (coupon_dist[v]>c+w){
					coupon_dist[v]=c+w;
					pq.push({coupon_dist[v], {v, 1}});
				}
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
	coupon_dist.resize(n+1,INF);

	loop(i,0,m){
		ll a=0,b=0,c=0;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
	}

	dijkstra();

	cout<<coupon_dist[n]<<endl;

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}