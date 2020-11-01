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
	ll t=0;
	cin>>t;
	while(t--){
		ll n=0,q=0;
		cin>>n>>q;
		ll a[n+1];
		a[0]=-1;
		ll ans=0;
		for (ll i=1;i<=n;i++){
			cin>>a[i];
			ans+=a[i]!=a[i-1]?1:0;
		}
		for (ll i=0;i<q;i++){
			ll x=0,y=0;
			cin>>x>>y;

			ans-=(a[x]!=a[x-1]);

			if (x!=n)
				ans-=(a[x+1]!=a[x]);

			a[x]=y;

			ans+=(a[x]!=a[x-1]);

			if (x!=n)
				ans+=(a[x+1]!=a[x]);

			cout<<ans<<endl;
		}
	}
	return 0;
}