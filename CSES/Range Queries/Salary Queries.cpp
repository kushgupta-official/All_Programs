# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}



int main()
{
	kush_gupta();
	ll n=0,q=0;
	cin>>n>>q;
	vll v(n);
	rep(i,0,n){
		cin>>v[i];
	}
	// set <ll> s;	
	// vp change;
	// vll ranges;
	while (q--){
		char ch; ll a=0,b=0;
		cin>>ch>>a>>b;
		if (ch=='!'){
			// change.push_back({a-1,b});
		}
		else{
			// s.insert(a);
			// s.insert(b);
		}
	// }
	// for (auto ite=s.begin();ite!=s.end();ite++){
	// 	ranges.push_back(*ite);
	// }
	// ll s=ranges.size();
	// vll tree(s*4,0);
	// build(ranges, tree, 0, 0 , s-1);
	return 0;
}