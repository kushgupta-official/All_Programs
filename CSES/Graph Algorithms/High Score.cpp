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
const ll NINF=INF*(-1);

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

ll n=0,m=0;
vector <tuple <ll,ll,ll> > g;
vector <ll> dist;

void solve(){
	dist[1]=0;
	for (ll i=1;i<=n-1;i++){
		for (auto e:g){
			ll a=0,b=0,w=0;
			tie (a,b,w)=e;
			dist[b]=min(dist[b], dist[a]+w);
			// dist[b]=max(dist[b],NINF);
		}
	}
	for (ll i=1;i<=n-1;i++){
		for (auto e:g){
			ll a=0,b=0,w=0;
			tie (a,b,w)=e;
			// dist[b]=max(dist[b],NINF);
			if (dist[b]>dist[a]+w){
				dist[b]=-1*INF;
			}
			// dist[b]=min(dist[b], dist[a]+w);
		}
	}
	return;
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

	loop(i,0,m){
		ll a=0,b=0,x=0;
		cin>>a>>b>>x;
		g.push_back({a,b,x*(-1)});
	}

	solve();
	if (dist[n]!=(-1)*INF)
		cout<<dist[n]*(-1);
	else{
		// cout<<"yo";
		cout<<-1;
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