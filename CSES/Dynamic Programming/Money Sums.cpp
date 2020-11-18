# include <bits/stdc++.h>

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

int dp(int n,vector <int> &a){
	if (n==0){
		return 0;
	}
	return 1+dp(n-1,a);
}

int main(){
	kush_gupta();
	int n=0;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dp(n,a);
	return 0;
}