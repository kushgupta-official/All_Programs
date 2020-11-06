# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'

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
	w(test_cases){
	    ll n=0;
	    cin>>n;
	    bool isPrime[n+1];
	    vector<ll> primeFactors(n+1,0);
	    for (ll i=0;i<n+1;i++){
	    	isPrime[i]=1;
	    }
	    primeFactors[1]=1;
	    for (ll i=2;i<=n;i++){
	    	if (isPrime[i]){
	    		primeFactors[i]=i;
	    		for (ll j=i*i;j<=n;j+=i){
	    			isPrime[j]=0;
	    			if (primeFactors[j]==0)
	    				primeFactors[j]=i;
	    		}
	    	}
	    }
	    map <ll,ll> res;
	    while (n!=1){
	    	res[primeFactors[n]]++;
	    	n/=primeFactors[n];
	    }
	    for (auto ite=res.begin();ite!=res.end();ite++){
	    	cout<<ite->first<<" "<<ite->second<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}