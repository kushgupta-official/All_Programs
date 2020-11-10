# include <bits/stdc++.h>
# define ll long long int

using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int main(){
	kush_gupta();
	ll max=4000000;
	vector<bool> isPrime(max+1,1);
	vector<ll> primes;
	for (ll i=2;i*i<=max;i++){
		if (isPrime[i]){
			for (ll j=i*i;j<=max;j+=i){
				isPrime[j]=0;
			}
		}
	}
	for (ll i=2;i<=max;i++){
		if (isPrime[i]){
			primes.push_back(i);
			// cout<<i<<" ";
		}
	}

	ll t=0;
	cin>>t;
	while(t--){
		ll n=0;
		cin>>n;
		vector<ll> b(n+1);
		for (ll i=1;i<=n;i++){
			cin>>b[i];
		}
		vector<ll> a(n+1,0);
		ll max=4000000,j=0;
		for (ll i=1;i<=n;i++){
			if (a[i]==0 && b[i]==i){
				a[i]=primes[j];
				j++;
			}
			else if (b[i]!=i){
				if (a[b[i]]==0){
					a[b[i]]=primes[j];
					j++;
				}
				a[i]=a[b[i]];
			}
		}

		for (ll i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}