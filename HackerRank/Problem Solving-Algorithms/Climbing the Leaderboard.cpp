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

ll bin_search(vll &v, ll x){
	ll n=v.size();
	// cout<<v.size()<<endl;
	ll li=0,ui=n-1;
	while(li<=ui){
		// cout<<ui<<" "<<li<<endl;
		ll m=mid(li,ui);
		if (v[m]==x){
			return m+1;
		}
		if (v[m]<x){
			ui=m-1;
		}
		else{
			li=m+1;
		}
	}
	return li+1;
}

void kush_gupta_solves(){
	ll n=0;
	cin>>n;
	vll ranked;
	ll temp=0;
	cin>>temp;
	ranked.pb(temp);
	loop(i,1,n){
		cin>>temp;
		if (ranked.back()!=temp){
			ranked.pb(temp);
		}
	}
	ll m=0;
	cin>>m;
	vll player(m);
	loop(i,0,m){
		cin>>player[i];
	}
	loop(i,0,m){
		cout<<bin_search(ranked,player[i])<<endl;
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