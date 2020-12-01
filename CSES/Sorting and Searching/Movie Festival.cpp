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
 
bool comp(pair <ll,ll> a,pair <ll,ll> b){
	return a.second<b.second;
}
 
int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	vector<pair <ll,ll> > timings(n);
	for (ll i=0;i<n;i++){
		cin>>timings[i].first>>timings[i].second;
	}
	sort(timings.begin(), timings.end(),comp);
	ll res=1;
	pair<ll,ll> prev=timings[0];
	for (ll i=1;i<n;i++){
		if (timings[i].first>=prev.second){
			prev=timings[i];
			res++;
		}
	}
	cout<<res;
	return 0;
}