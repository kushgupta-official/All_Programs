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
		ll x1,x2,y1,y2;
		bool flag=0;
		vector < vector <char> > v(n, vector <char> (n));
		for (ll i=0;i<n;i++){
			for (ll j=0;j<n;j++){
				cin>>v[i][j];
				if (v[i][j]=='*' and flag){
					x2=i;
					y2=j;
				}
				else if (v[i][j]=='*'){
					x1=i;
					y1=j;
					flag=1;
				}
			}
		}
		ll res1x,res2x,res1y,res2y;
		if (x1!=x2 and y1!=y2){
			res1x=x1; res1y=y2;
			res2x=x2; res2y=y1;
		}
		else if (y1==y2){
			res1x=x1; res2x=x2;
			res1y=(y1+1)%n; res2y=(y2+1)%n;
		}
		else{
			res1y=y1; res2y=y2;
			res1x=(x1+1)%n; res2x=(x2+1)%n;
		}
		v[res1x][res1y]='*';
		v[res2x][res2y]='*';
		for (ll i=0;i<n;i++){
			for (ll j=0;j<n;j++){
				cout<<v[i][j];
			}
			cout<<endl;
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