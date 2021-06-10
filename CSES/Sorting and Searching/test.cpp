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

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int ncr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

void kush_gupta_solves(){
	w(t){
		ll n=0,l=0,r=0;
		cin>>n>>l>>r;
		vll v(n);
		loop(i,0,n){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		int i,j;
		for (i=0,j=1;i<j;i++){
			if (v[i]+v[j]>=l){
				break;
			}
		}
		ll s=i;
		for (i=s,j=s+1;j<n;j++){
			if (v[i]+v[j]>=l){
				break;
			}
		}
		ll s1=j-1;
		for (i=n-1,j=n-2;j>=0;j--){
			if (v[i]+v[j]<=r){
				break;
			}
		}
		ll e1=n-j;
		ll e=n-1;
		cout<<s<<" "<<s1<<" "<<e1<<" "<<e<<endl;
		cout<<ncr(e-s+1,2)-ncr(s1-1-s+1,2)-ncr(e-e1,2)<<endl;
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