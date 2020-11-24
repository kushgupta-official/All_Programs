# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

int main(){
	kush_gupta();
	ll n=0,q=0;
	cin>>n>>q;
	vector <ll> a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}
	vector <ll> sum(n);
	sum[0]=a[0];
	for (ll i=1;i<n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	ll x=0,y=0;
	for (ll i=0;i<q;i++){
		cin>>x>>y;
		cout<<sum[y-1]-sum[x-1]+a[x-1]<<endl;
	}
	return 0;
}