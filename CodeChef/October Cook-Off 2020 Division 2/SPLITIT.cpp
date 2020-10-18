# include <bits/stdc++.h>
# define ll long long int
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
	ll t=0;
	cin>>t;
	while(t--){
		ll n=0;
		cin>>n;
		string s;
		cin>>s;
		bool flag=0;
		char toFind=s[n-1];
		for (ll i=0;i<n-1;i++){
			if (s[i]==toFind){
				flag=1;
				break;
			}
		}
		//cout<<s;
		if (flag){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}