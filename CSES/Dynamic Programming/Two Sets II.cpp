# include <bits/stdc++.h>
# define ll long long int
# define mod 1000000007
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

ll dp(ll sum,vector <ll> &v,ll n){
	if (sum==0){
		return 1;
	}
	if (n==0){
		return 0;
	}
	if (v[n-1]<=sum){
		return dp(sum-v[n-1],v,n-1)+dp(sum,v,n-1);
	}
	else{
		return dp(sum,v,n-1);
	}
}

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	ll sum=(n*(n+1))/2;
	if(sum%2==1){
		cout<<0;
	}
	else{
		vector <ll> v(n);
		for (ll i=0;i<n;i++){
			v[i]=i+1;
		}
		cout<<dp(sum/2,v,n);
	}
	return 0;
}