# include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ll test_cases=0;
	cin>>test_cases;
	std::vector<ll> solution;
	while(test_cases--){
		string input;
		ll sumA=0,sumB=0;
		//ll sol=0;
		ll n=0;
		cin>>n;
		cin>>input;
		ll i=0,r1=n,r2=n;
		for (i=0;i<2*n;i++){
			if (i%2==0){
				sumA+=int(input[i])-48;
				r1--;
			}
			else{
				sumB+=int(input[i])-48;
				r2--;
				
			}
			if (sumA-sumB>r2){
					break;
				}
			else if (sumB-sumA>r1){
					break;
				}
		}
		if (sumA==sumB){
			i--;
		}
		solution.push_back(i+1);
	}

	for (ll i=0;i<solution.size();i++){
		cout<<solution[i]<<endl;
	}
	return 0;
}