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
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ar[n], br[n];
	for (int i = 0; i < n; ++i) cin >> ar[i] >> br[i];
	sort(ar, ar + n);
	sort(br, br + n);
	int a = 0, b = 0, ct = 0, res = 0;
	while (a < n && b < n) {
		if (ar[a] < br[b]) ++a, ++ct;
		else ++b, --ct;
		res = max(res, ct);
	}
	cout << res << '\n';
	return 0;
}
*/