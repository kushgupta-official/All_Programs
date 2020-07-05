# include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	std::vector<ll> solution;
	ll test_cases=0;
	cin>>test_cases;

	while(test_cases--){
		ll n=0;
		cin>>n;
		std::vector<ll> input(n);
		for (ll i=0;i<n;i++){
			cin>>input[i];
		}
		stack <ll>s;
		s.push(input[0]);
		for (int i=1;i<n;i++){
			if (s.top()>input[i]){
				s.push(input[i]);
			}
			else{
				s.push(s.top());
			}
		}
		ll sol=0;
		while(!s.empty()){
			sol+=s.top();
			s.pop();
		}
		solution.push_back(sol);
	}

	for (ll i=0;i<solution.size();i++){
		cout<<solution[i]<<endl;
	}
}