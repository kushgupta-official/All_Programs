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

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void kush_gupta_solves(){
	vector <vector <pair <ll,ll> > > v(101,vector <pair <ll,ll> > (101));
		for (ll i=2;i<=100;i++){
			v[i][1].first=i-1;
			v[i][1].second=i-1;
		}
		for (ll j=2;j<=100;j++){
			v[1][j].first=j-1;
			v[1][j].second=j-1;
		}
		v[1][1].fi=0;
		v[1][1].se=0;
		//first=max
		//second=min
		for (ll i=2;i<=100;i++){
			for (ll j=2;j<=100;j++){
				v[i][j].fi=max(v[i-1][j].fi+j,v[i][j-1].fi+i);
				v[i][j].se=min(v[i-1][j].se+j,v[i][j-1].se+i);
			}
		}
	w(t){
		ll n=0,m=0,k=0;
		cin>>n>>m>>k;
		if (k<=v[n][m].first and k>=v[n][m].second){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
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