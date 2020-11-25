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
	ll x=0,n=0;
	cin>>x>>n;
	set <ll> s;
	multiset <ll> ms;
	s.insert(0);p
	s.insert(x);
	ms.insert(x);
	for (ll i=0;i<n;i++){
		ll a=0;
		cin>>a;
		auto ite=s.lower_bound(a);
		auto ite2=ite;
		ite2--;
		ms.erase(ms.find(*ite - *ite2));
		ms.insert(a-*ite2);
		ms.insert(*ite-a);
		cout<<*--ms.end()<<" ";
		s.insert(a);
	}
	return 0;
}