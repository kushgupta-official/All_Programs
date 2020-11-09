# include <bits/stdc++.h>
# define ll long long int
# define mod (1000000007)
using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

ll dp(vector<ll> &a,ll n,ll x){
	// if (x==0){
	// 	return 0;
	// }
	// if (n==0){
	// 	return INT_MAX;
	// }

	// if (a[n-1]<=x){
	// 	return min(dp(a,n,x-a[n-1])+1,dp(a,n-1,x));
	// }
	// else{
	// 	return dp(a,n-1,x);
	// }

	ll t[n+1][x+1];
	for (ll i=0;i<=n;i++){
		t[i][0]=0;
	}
	for (ll j=0;j<=x;j++){
		t[0][j]=INT_MAX-1;
	}
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=x;j++){
			if (a[i-1]<=j){
				t[i][j]=min(t[i][j-a[i-1]]+1,t[i-1][j]);
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}
	cout<<INT_MAX-1<<endl;
	if (t[n][x]!=INT_MAX || t[n][x]!=INT_MAX-1)
		return t[n][x];
	else
		return -1;
}

int main(){
	kush_gupta();
	ll n=0,x=0;
	cin>>n>>x;
	std::vector<ll> a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dp(a,n,x);
	return 0;
}