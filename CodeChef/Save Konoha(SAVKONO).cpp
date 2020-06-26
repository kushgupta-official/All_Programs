# include <bits/stdc++.h>

using namespace std;
# define ll long long

int main(){
	ll test_cases=0;
	cin>>test_cases;
	while(test_cases--){
		ll n=0,z=0;
		cin>>n>>z;
		std::vector<ll> powers(n);
		for (ll i=0;i<n;i++){
			cin>>powers[i];
		}
		ll result=0;
		while(z>=1){
			sort(powers.begin(),powers.end(),greater <>());
			z-=powers[0];
			powers[0]/=2;
			result++;
		}
		cout<<result;
	}
	return 0;
}