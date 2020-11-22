# include <bits/stdc++.h>
# define ll long long int
# define ld long double
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
	vector <ll> arr(n);
	for (ll i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(), arr.end());
	ll mid=arr[n/2],ans=0;
	for (ll i=0;i<n;i++){
		ans+=abs(arr[i]-mid);
	}
	cout<<ans;
	return 0;
}