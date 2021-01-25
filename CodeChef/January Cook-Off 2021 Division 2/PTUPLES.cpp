# include <bits/stdc++.h>

using namespace std;
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

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	ll limit=1000000;
	vll prime(limit+1,0);

	for (ll i=2;i*i<=limit;i++){
		if (!prime[i]){
			for (ll j=i*i;j<=limit;j+=i){
				prime[j]=1;
			}
		}
	}
	ll curr=0;
	vll res(limit+1,0);
	for (ll i=2;i<=limit;i++){
		if (!prime[i] && !prime[i+2]){
			res[i]=curr;
			res[i+1]= curr;
			res[i+2]= ++curr;
			i+=1;
		}
		else{
			res[i]=curr;
		}
	}
	w(t){
		ll n=0;
		cin>>n;
		cout<<res[n]<<endl;
	}

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}