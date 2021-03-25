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
ll longest_common_substring(ll n,ll m,string st1,string st2){
  ll t[n+1][m+1];
  loop(i,0,n+1){
    t[i][0]=0;
  }
  loop(j,0,m+1){
    t[0][j]=0;
  }
  ll mx=-1;
  loop(i,1,n+1){
    loop(j,1,m+1){
      if(st1[i-1]==st2[j-1]){
        t[i][j]=1+t[i-1][j-1];
      }
      else{
        t[i][j]=0;
      }
      mx=max(mx,t[i][j]);
    }
  }
  return mx;
}
void kush_gupta_solves(){
	w(t){
		string a,b;
		cin>>a>>b;
		ll x=a.length();
		ll y=b.length();
		cout<<(x+y)-(2*longest_common_substring(x,y,a,b))<<endl;
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