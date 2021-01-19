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

	vector <ll> prime (20001,1);
	vector <ll> first_prime(20001,0);
	for (ll i=2;i<=20000;i++){
		if (prime[i]==1){
			first_prime[i]=i;
			for (ll j=i+i;j<=20000;j+=i){
				if (prime[j]==1){
					first_prime[j]=i;
				}
				prime[j]++;
			}
		}
	}
	vector <ll> res;
	for (ll i=1;i<=10000;i++){
		if (prime[i]>=3 && first_prime[i]-1>=i){
			res.push_back(i);
		}
		else{
			res.push_back(-1);
		}
	}

	w(t){
		ll d=0;
		cin>>d;
		if (res[d]==-1){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
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