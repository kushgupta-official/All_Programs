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

int dp(vector <int> &a,int n,int x){
	// if (x==0){
	// 	return 1;
	// }
	// if (n==0){
	// 	return 0;
	// }
	// if (a[n-1]<=x){
	// 	return dp(a,n,x-a[n-1])+dp(a,n-1,x);
	// }
	// else{
	// 	return dp(a,n-1,x);
	// }
	vector <vector <int> > t(n+1,vector <int> (x+1));
	// int t[n+1][x+1];
	for (int i=0;i<=n;i++){
		t[i][0]=1;
	}
	for (int j=1;j<=x;j++){
		t[0][j]=0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=x;j++){
			if (a[i-1]<=j){
				t[i][j]=((t[i][j-a[i-1]]%mod)+(t[i-1][j]%mod))%mod;
			}
			else{
				t[i][j]=t[i-1][j]%mod;
			}
		}
	}
	return t[n][x]%mod;
}

int main(){
	kush_gupta();
	int n=0,x=0;
	cin>>n>>x;
	vector <int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
		//cout<<a[i]<<endl;
	}
	int  res=dp(a,n,x);
	cout<<res;
	return 0;
}