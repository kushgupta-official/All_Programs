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
	ll n=0;
	cin>>n;
	multiset <pair <ll,ll> > ms;
	ll a=0,b=0;
	for (ll i=0;i<n;i++){
		ll a=0,b=0;
		cin>>a>>b;
		ms.insert({a,b});
	}
	ll res=0;
	ll curr=0;
	for (auto ite=ms.begin();ite!=ms.end();ite++){
		curr+=ite->first;
		res+=ite->second - curr;
	}
	cout<<res<<endl;
	return 0;
}