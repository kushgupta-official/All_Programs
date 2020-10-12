# include <bits/stdc++.h>
using namespace std;
# define ll long long int

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
	ll test_cases=0;
	cin>>test_cases;
	while(test_cases--){
		ll n=0,k=0,x=0,y=0;
		cin>>n>>k>>x>>y;
		ll i=0;
		set <ll> record;
		bool flag=0;
		while(i<n){
			if (record.find(x)==record.end())
				record.insert(x);
			else
				break;
			if (x==y)
				flag=1;
			x=(x+k)%n;
			i++;
		}
		if (flag){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}