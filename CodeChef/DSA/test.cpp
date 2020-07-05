#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n, k, ans = 1;
	cin >> n >> k;
	stack<pair<ll, ll>> s;
	vector<ll> a(n);
	for(ll i = n-1; i >= 0; i--)
		cin >> a[i];

	for(ll i = 0; i < n; i++) {
		while(!s.empty() && s.top().first >= a[i])
			s.pop();
		if(!s.empty()){
			ans = (ans * (i-s.top().second+1)%M)%M;
			cout<<i<<" "<<s.top().second<<" ans = "<<ans<<endl;
		}
		s.push({a[i], i});
	}
	cout << ans << '\n';
}