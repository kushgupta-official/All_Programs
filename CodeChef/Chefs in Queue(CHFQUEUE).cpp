# include <bits/stdc++.h>

using namespace std;
# define ll long long int

int main(){
	ll n=0;
	ll k=0;
	ll fearfulness=1;
	cin>>n>>k;
	std::vector<ll> inputs(n);
	for (ll i=0;i<n;i++){
		cin>>inputs[i];
	}

	ll i=0,j=0;
	while(i<n && j<n){
		if (inputs[j+1]<inputs[i]){
			j++;
		}
		else{
			fearfulness*=j-i+1;
			j++;
			i=j;
		}
	}
	if (i!=n || j!=n){
		fearfulness*=j-i+1;
	}
	cout<<fearfulness%1000000007;
	return 0;
}