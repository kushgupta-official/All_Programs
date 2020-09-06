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
		set <ll> s;
		ll n=0;
		cin>>n;
		ll temp=0;
		for (ll i=0;i<n;i++){
			cin>>temp;
			if(temp!=0)
				s.insert(temp);
		}
		// for (auto ite:s){
		// 	cout<<ite<<" ";
		// }
		cout<<s.size()<<endl;
	}
}