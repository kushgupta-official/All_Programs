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
	//sieveOfE
	// bool isPrime[]
	// vector <ll> primes;
	vll sol(10000001,0);
	vector <bool> isPrime(10000001,true);
	for (ll i=2;i<10000001;i++){
		if (isPrime[i]){
			sol[i]=1;
			if (i+i<10000001)
				sol[i+i]=-1;
			// primes.push_back(i);
			for (ll j=i*i;j<10000001;j+=i){
				isPrime[j]=false;
			}
		}
	}
	loop(i,2,10000001){
		sol[i]+=sol[i-1];
		// cout<<sol[i]<<" ";
	}
	// loop(i,0,primes.size()){
	// 	cout<<primes[i]<<" ";
	// }
	// cout<<endl;
	// cout<<primes.size()<<endl;
	w(t){
		ll n=0;
		cin>>n;
		ll i=0;
		ll res=0;
		bool flag=0;
		if (n>3)
			cout<<sol[n]+1;
		else
			cout<<sol[n];
		cout<<endl;
		// ll pos=lower_bound(primes.begin(), primes.end(),n)-primes.begin();
		// // cout<<"pos="<<pos<<endl;
		// if (primes[pos]>n){
		// 	pos--;
		// }
		// while(pos>=0){
		// 	if (primes[pos]*2>n){
		// 		res++;
		// 		pos--;
		// 	}
		// 	else{
		// 		flag=1;
		// 		break;
		// 	}
		// }
		// while(i<primes.size() && primes[i]<=n){
		// 	if (primes[i]*2>n){
		// 		res++;
		// 	}
		// 	else{
		// 		flag=1;
		// 	}
		// 	i++;
		// }
		// if (n==2){
		// 	cout<<1<<endl;
		// }
		// else
		// if (res>1)
		// 	res++;
		// cout<<res+flag<<endl;
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