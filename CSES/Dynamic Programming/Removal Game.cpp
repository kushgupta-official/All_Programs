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
	vector <vector <ll> > t(n,vector <ll> (n,0));
	for (ll len=1;len<=n;len++){
		for (ll i=0;i+len<=n;i++){
			ll j=i+len-1;

			ll x= i+2<=j ? t[i+2][j]:0;
			ll y= i+1<=j-1 ? t[i+1][j-1]:0;
			ll z= i<=j-2 ? t[i][j-2]:0;

			t[i][j]=max(a[i]+min(x,y),a[j]+min(y,z));
		}
	}
	cout<<t[0][n-1];
	return 0;
}