# include <bits/stdc++.h>
# define ll long long int
# define mod 1000000007
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
	ll n=0;
	cin>>n;
	std::vector<ll> t(n+1);
	t[0]=t[1]=1;
	for (ll i=2;i<=n;i++){
		for (ll j=1;j<=6;j++){
			if (j>i)
				continue;
			t[i]=((t[i]%mod)+(t[i-j]%mod))%mod;
		}
	}
	cout<<t[n]%mod;
	return 0;
}