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
	vector <ll> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ll sum=0,best=INT_MIN;
	for (ll i=0;i<n;i++){
		sum=max(sum+a[i],a[i]);
		// cout<<sum<<" ";
		best=max(best,sum);
	}
	cout<<best;
	return 0;
}