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
vector <bool> visited;
vector <ll> previous;
ll y,z;

bool cyclePresent(ll x, ll parent){
	visited[x]=true;
	previous[x]=parent;
	for (auto e:g[x]){
		if (!visited[e]){
			if (cyclePresent(e, x))
				return true;
		}
		else if (e!=parent){
			y=e;
			z=x;
			return true;
		}
	}

	return false;
}

bool visitAll(){
	loop(i,1,n+1){
		if (!visited[i]){
			if (cyclePresent(i,0)){
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
	visited.resize(n+1, false);
	previous.resize(n+1);

	loop(i,0,m){
		ll a=0, b=0;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector <ll> result;

	if (visitAll()){
		result.push_back(y);
		for (ll i=z;;i=previous[i]){
			result.push_back(i);
			if (i==y and result.size()>1){
				break;
			}
		}
		cout<<result.size()<<endl;
		for (auto i:result){
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