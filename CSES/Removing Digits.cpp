# include <bits/stdc++.h>
# define ll long long int
# define mod (1000000007)
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

ll dp(ll n){
	vector<ll> t(n+1,INT_MAX);
	t[0] = 0;
  	for (ll i = 0; i <= n; i++) {
    	for (char c : to_string(i)) {
      		t[i] = min(t[i], t[i-(c-'0')]+1);
      		// cout<<t[i]<<endl;
    	}
  	}
  	return t[n];
}

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	cout<<dp(n);
	return 0;
}