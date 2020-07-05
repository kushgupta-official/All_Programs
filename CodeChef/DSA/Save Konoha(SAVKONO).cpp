# include <bits/stdc++.h>

using namespace std;
# define ll long long

int main(){
	ll test_cases=0;
	cin>>test_cases;
	while(test_cases--){
		ll n=0,z=0;
		cin>>n>>z;
		priority_queue<ll> powers;
		ll temp=0;
		for (ll i=0;i<n;i++){
			cin>>temp;
			powers.push(temp);
		}
		ll result=0;
		int flag=1;
		while(z>=1){
			//sort(powers.begin(),powers.end(),greater <>());
			if(powers.top()==0){
				flag=0;
				break;
			}
			temp=powers.top();
			z-=temp;
			temp/=2;
			powers.push(temp);
			result++;
		}
		if (flag==1){
			cout<<result<<endl;
		}
		else{
			cout<<"Evacuate"<<endl;
		}
	}
	return 0;
}