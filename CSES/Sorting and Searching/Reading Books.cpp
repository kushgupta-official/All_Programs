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
	ll sum=0,mx=INT_MIN;
	for (ll i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		mx=max(a[i],mx);
	}
	if (mx>sum-mx){
		cout<<2*mx;
	}
	else{
		cout<<sum;
	}
	cout<<endl;
	return 0;
}