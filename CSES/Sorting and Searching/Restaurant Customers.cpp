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

bool comp(pair<ll,char> p1,pair<ll,char> p2){
	return p1.first<p2.first;
}

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	vector<pair<ll,char> > times(2*n);
	for (ll i=0;i<2*n;i++){
		cin>>times[i].first;
		times[i].second='+';
		cin>>times[++i].first;
		times[i].second='-';
	}
	sort(times.begin(), times.end(),comp);
	ll curr=0,res=INT_MIN;
	for (ll i=0;i<2*n;i++){
		if (times[i].second=='+'){
			curr++;
		}
		else{
			curr--;
		}
		res=max(res,curr);
	}
	cout<<res;
	return 0;
}