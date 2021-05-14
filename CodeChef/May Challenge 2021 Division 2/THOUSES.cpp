# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp> 
# include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

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
# define MOD 1000000007
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

vvl adj;
// vll values;
vll sum_values;

void dfs(ll s,ll e){
	for (auto u:adj[s]){
		if (u!=e)
			dfs(u,s);
	}
	vp temp;
	for (auto u:adj[s]){
		if (u!=e){
			temp.push_back({sum_values[u],u});
		}
	}
	sort(temp.begin(),temp.end(),greater <pair <ll,ll> >());
	for (ll i=0;i<temp.size();i++){
		if (temp[i].se!=e)
			sum_values[s]+=sum_values[temp[i].se]*(i+1);
	}
}

void kush_gupta_solves(){
	w(t){
		ll n=0,x=0;
		cin>>n>>x;
		adj.clear();
		adj.resize(n+1);
		// values.clear();
		// values.resize(n+1);
		sum_values.clear();
		sum_values.resize(n+1,1);

		for (ll i=1;i<n;i++){
			ll u=0,v=0;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		//evaluate_values(1);
		dfs(1,0);
		ll res=((sum_values[1]%MOD)*(x%MOD))%MOD;
		cout<<res<<endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
		freopen("input.txt", "r", stdin) ;
  		freopen("output.txt", "w", stdout) ;
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	kush_gupta_solves();

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif

	return 0;
}