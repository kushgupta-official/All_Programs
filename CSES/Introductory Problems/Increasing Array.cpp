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
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}	
	ll res=0;
	for (ll i=1;i<n;i++){
		if (a[i-1]>a[i]){
			res+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout<<res;
	return 0;
}