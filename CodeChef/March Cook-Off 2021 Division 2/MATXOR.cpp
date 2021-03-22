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
	w(t){
		ll n=0,m=0,k=0;
		cin>>n>>m>>k;
		ll res=0,x=n;
		if (n%2==1){
			x=n-1;
		}
		for (ll i=1;i<=x;i++){
			if (i%2){
				res^=1+i+k;
			}
			else{
				res^=m+i+k;
			}
		}
		if (n%2){
			for (ll j=1;j<=m;j++){
				res^=n+j+k;
			}
		}
		cout<<res<<endl;
		// if (n==1){
		// 	for (ll j=1;j<=m;j++){
		// 		res=res^(1+j+k);
		// 	}
		// }
		// else if (m==1){
		// 	for (ll i=1;i<=n;i++){
		// 		res=res^(i+1+k);
		// 	}
		// }
		// else{
		// 	res=(1+1+k)^(n+m+k);
		// }
		// cout<<res<<endl;
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