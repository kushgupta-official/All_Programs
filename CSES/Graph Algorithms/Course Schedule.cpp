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

ll n, m;
vector <vector <ll> > g;
vector <ll> res;
vector <ll> inDegree;
priority_queue <ll, vector <ll>, greater<ll> > pq;
void solve(){
	while(!pq.empty()){
		ll u=pq.top();
		res.push_back(u);
		pq.pop();
		for (auto v:g[u]){
			inDegree[v]--;
			if (!inDegree[v]){
				pq.push(v);
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
	inDegree.resize(n+1);

	loop(i,0,m){
		ll a=0, b=0;
		cin>>a>>b;
		g[a].push_back(b);
		inDegree[b]++;
	}

	loop(i,1,n+1){
		if (!inDegree[i]){
			pq.push(i);
		}
	}

	solve();

	if (res.size()==n){
		for (auto i:res){
			cout<<i<<" ";
		}
	}
	else{
		cout<<"IMPOSSIBLE";
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