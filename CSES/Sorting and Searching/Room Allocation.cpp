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
	ll n=0;
	cin>>n;
	multiset <ll> arrival,departure;
	ll a=0,b=0;
	for (ll i=0;i<n;i++){
		cin>>a>>b;
		arrival.insert(a);
		departure.insert(b);
	}
	return 0;
}