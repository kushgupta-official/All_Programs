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
		ll l=0,r=0;
		cin>>l>>r;
		if (r<2*l){
			cout<<r<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}