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
// # define endl '\n'
# define mid(l,r) l+(r-l)/2
# define fi first
# define se second

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void kush_gupta_solves(){
	ll n=0;
	cin>>n;
	ll bi=1,bj=-1;
	ll wi=1,wj=0;
	ll temp=0;
	loop(k,0,n*n){
		cin>>temp;
		if (temp==1){
			if (bi+1>n and bj+2>n){
				if (wj+2>n){
					wi+=1;
					wj= wj+2==n+1 ? 2 : 1;
				}
				else{
					wj+=2;
				}
				cout<<3<<" "<<wi<<" "<<wj<<endl;
			}
			else{
				if (bj+2>n){
					bi+=1;
					// if (bj+2==n+1)
					// 	bj=1;
					bj= bj+2==n+1 ? 2 : 1;
				}
				else{
					bj+=2;
				}
				cout<<2<<" "<<bi<<" "<<bj<<endl;
			}
		}
		else if (temp==2){
			if (wi+1>n and wj+2>n){
				if (bj+2>n){
					bi+=1;
					bj= bj+2==n+1 ? 2 : 1;
				}
				else{
					bj+=2;
				}
				cout<<3<<" "<<bi<<" "<<bj<<endl;
			}
			else{
				if (wj+2>n){
					wi+=1;
					wj= wj+2==n+1 ? 2 : 1;
				}
				else{
					wj+=2;
				}
				cout<<1<<" "<<wi<<" "<<wj<<endl;
			}
		}
		else{
			if (wj+2<=n or wi+1<=n){
				if (wj+2>n){
					wi+=1;
					wj= wj+2==n+1 ? 2 : 1;
				}
				else{
					wj+=2;
				}
				cout<<1<<" "<<wi<<" "<<wj<<endl;
			}
			else{
				if (bj+2>n){
					bi+=1;
					bj= bj+2==n+1 ? 2 : 1;
				}
				else{
					bj+=2;
				}
				cout<<2<<" "<<bi<<" "<<bj<<endl;
			}
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

	// ios::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);

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