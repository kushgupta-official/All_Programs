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
		vector<ll> frequency(k+1,0);
		ll count=0;
		ll length=0,maximum=0;
		for (ll i=0;i<n;i++){
			cin>>inputs[i];
		}
		ll j=0;
		for (ll i=0;i<n && i>=j;i++){
			if (count==k){
				frequency[inputs[j]]--;
				if (frequency[inputs[j]]==0){
					count--;
				}
				j++;
				i--;
				length--;
				continue;
			}
			if (frequency[inputs[i]]==0){
				frequency[inputs[i]]++;
				count++;
				length++;
				if(count!=k){
					maximum=max(maximum,length);
				}
			}
			else{
				frequency[inputs[i]]++;
				length++;
				maximum=max(maximum,length);
			}
		}
		cout<<maximum<<endl;
	}
	return 0;
}