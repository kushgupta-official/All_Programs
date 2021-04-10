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
		ll n=0;
		cin>>n;
		vll b(n+3,-1),sum(n+3,0);
		ll s=0;
		loop(i,1,n+3){
			cin>>b[i];
		}
		sort(b.begin(), b.end());
		loop(i,1,n+3){
			s+=b[i];
			sum[i]=s;
		}
		ll x=sum[n+1]-b[n+2];
		if (x>0 and binary_search(b.begin(), b.end()-1, x) ){
			
			for (ll i=1;i<=n+1;i++){
				if (b[i]==x){
					x=-1;
					continue;
				}
				cout<<b[i]<<" ";
			}
		}
		else if (sum[n]==b[n+1]){
			for (ll i=1;i<=n;i++){
				cout<<b[i]<<" ";
			}
		}
		else{
			cout<<-1;
		}
		cout<<endl;
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