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

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	vector <vector <ll> > grid(n,vector <ll> (n,0));
	for (ll i=0;i<n;i++){
		for (ll j=0;j<n;j++){
			char ch;
			cin>>ch;
			grid[i][j]=ch=='.'?0:1;
		}
	}
	for (ll i=n-1;i>=0;i--){
		for (ll j=n-1;j>=0;j--){
			if (i==n-1 && j==n-1){
				grid[i][j]=grid[i][j]==1?0:1;
			}
			else if (grid[i][j]==0){
				if (i+1<n)
					grid[i][j]=(grid[i][j]+grid[i+1][j])%mod;
				if (j+1<n)
					grid[i][j]=(grid[i][j]+grid[i][j+1])%mod;
			}
			else{
				grid[i][j]=0;
			}
		}
	}
	cout<<grid[0][0]%mod;
	return 0;
}