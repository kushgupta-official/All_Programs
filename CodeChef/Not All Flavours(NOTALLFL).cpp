# include <bits/stdc++.h>
using namespace std;

# define ll long long int

int main(){
	int test_cases=0;
	cin>>test_cases;
	while(test_cases--){
		ll n=0;
		ll k=0;
		cin>>n>>k;
		vector<ll> inputs(n);
		ll length=0,maximum=0;
		for (ll i=0;i<n;i++){
			cin>>inputs[i];
			if (inputs[i]<k){
				length++;
			}
			else{
				maximum=max(maximum,length);
				length=0;
			}
		}
		maximum=max(maximum,length);
		cout<<maximum<<endl;
	}
	return 0;
}