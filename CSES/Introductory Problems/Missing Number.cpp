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
	vector <bool> isThere(n+1,0);
	ll temp=0;
	for (ll i=0;i<n-1;i++){
		cin>>temp;
		isThere[temp]=1;
	}
	for (ll i=1;i<=n;i++){
		if (!isThere[i]){
			cout<<i;
			break;
		}
	}
	return 0;
}