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
	ll t=0;
	cin>>t;
	while(t--){
		ll n=0;
		cin>>n;
		vector<ll> b(n+1);
		for (ll i=1;i<=n;i++){
			cin>>b[i];
		}
		vector<ll> a(n+1);
		for (ll i=1;i<=n;i++){
			a[b[i]]=b[i]
		}
	}
	return 0;
}