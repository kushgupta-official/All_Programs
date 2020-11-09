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
	ll n=0,x=0;
	cin>>n>>x;
	std::vector<ll> a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}
	std::vector<ll> t(x+1,0);
	t[0]=1;
	sort(a.begin(), a.end());
	for (ll i=1;i<=x;i++){
		for (ll j=0;j<n;j++){
			if (a[j]>i)	break;
			t[i]=((t[i]%mod)+(t[i-a[j]]%mod))%mod;
		}
	}
	cout<<t[x]%mod;
	return 0;
}