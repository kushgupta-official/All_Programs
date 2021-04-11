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
		ll n;
		cin>>n;
		vll v(n+1);
		loop(i,1,n+1){
			cin>>v[i];
		}
		set <ll> s1;
		set <ll> s2;
		loop(i,1,n+1){
			s1.insert(i);
			s2.insert(i);
		}
		ll k=1;
		ll max=INT_MIN;
		vll min_perm(n+1);
		vll max_perm(n+1);
		ll j;
		loop(i,1,n+1){
			if (max<v[i]){
				min_perm[i]=v[i];
				max_perm[i]=v[i];
				max=v[i];
				s1.erase(v[i]);
				s2.erase(v[i]);
				j=max-1;
			}
			else{
				k=*s1.begin();
				min_perm[i]=k;
				s1.erase(s1.begin());
				auto ite=s2.lower_bound(max);
				ite--;
				j=*ite;
				max_perm[i]=j;
				s2.erase(j);
			}
		}
		loop(i,1,n+1){
			cout<<min_perm[i]<<" ";
		}
		cout<<endl;
		loop(i,1,n+1){
			cout<<max_perm[i]<<" ";
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