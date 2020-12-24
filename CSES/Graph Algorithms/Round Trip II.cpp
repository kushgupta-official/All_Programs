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
vector <ll> parent;
vector <bool> visited;
vector <bool> recStack;
ll x,y;

bool cyclePresent(ll u, ll p){
	visited[u]=true;
	recStack[u]=true;
	parent[u]=p;
	for (auto v:g[u]){
		if (!visited[v] && cyclePresent(v, u)){
			return true;
		}
		else if (recStack[v]){
			x=v;
			y=u;
			return true;
		}
	}

	recStack[u]=false;
	return false;
}

bool isCycle(){
	loop(i,1,n+1){
		if (!visited[i]){
			if (cyclePresent(i, 0)){
				return true;
			}
		}
	}
	return false;
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	cin>>n>>m;

	g.resize(n+1);
	parent.resize(n+1);
	visited.resize(n+1, false);
	recStack.resize(n+1, false);

	loop(i,0,m){
		ll a=0, b=0;
		cin>>a>>b;
		g[a].push_back(b);
	}

	if (isCycle()){
		vector <ll> res;
		// cout<<x<<endl;
		res.push_back(x);
		for (ll i=y;;i=parent[i]){
			res.push_back(i);
			if (i==x){
				break;
			}
		}
		// reverse(res.begin(), res.end());
		cout<<res.size()<<endl;
		for (ll i=res.size()-1;i>=0;i--){
			cout<<res[i]<<" ";
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