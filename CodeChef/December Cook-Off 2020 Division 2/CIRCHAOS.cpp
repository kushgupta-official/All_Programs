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

ll lcf(ll x, ll n){
	ll m=0;
	for (ll i=1;i<=sqrt(x) && i<=n;i++){
		if (x%i==0){
			m=max(m, i);
			if (x/i<=n)
				m=max(m, x/i);
		}
	}
	return m;
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	w(t){
		ll n=0, m=0;
		cin>>n>>m;
		vll v(m);
		loop(i,0,m){
			cin>>v[i];
		}
		ll gcd=0;
		loop(i,0,m){
			gcd=__gcd(gcd,v[i]);
		}
		if (gcd>n){
			ll largestCommonFactorLessThanN=lcf(gcd,n);
			gcd=largestCommonFactorLessThanN;
		}
		cout<<n-gcd<<endl;
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