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
vector <tuple <ll, ll, ll> > g;
vector <ll> dist;
vector <ll> previous;

void solve(){
	dist[1]=0;
	ll x=0;
	loop(i,0,n){
		ll u=0, v=0, w=0;
		x=-1;
		for (auto e:g){
			tie(u,v,w)=e;
			if (dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				x=v;
				previous[v]=u;
			}
		}
	}
	if (x==-1){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		vector <ll> res;
		for (ll i=1;i<=n;i++){
			x=previous[x];
		}
		for (ll i=x;;i=previous[i]){
			res.push_back(i);
			if (i==x && res.size()>1){
				break;
			}
		}
		reverse(res.begin(), res.end());
		for (auto i:res){
			cout<<i<<" ";
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
	previous.resize(n+1);
	loop(i,0,m){
		ll a=0, b=0, c=0;
		cin>>a>>b>>c;
		g.push_back({a, b, c});
	}

	solve();

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}