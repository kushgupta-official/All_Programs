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
		ll n=0,k=0;
		cin>>n>>k;
		std::vector<ll> inputs(n);
		ll sum=0;
		bool flag=0;
		ll res=-1;
		for (ll i=0;i<n;i++){
			cin>>inputs[i];
			sum+=inputs[i];
			if (k*(i+1)>sum && flag==0){
				flag=1;
				res=i+1;
			}
		}
		if (flag){
			cout<<res<<endl;
		}
		else{
			cout<<sum/k+1<<endl;
		}
	}
}