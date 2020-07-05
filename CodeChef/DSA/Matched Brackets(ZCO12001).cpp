# include <bits/stdc++.h>
using namespace std;
# define ll long long int
int main(){
	ll n=0;
	cin>>n;
	std::vector<int> inputs(n);
	stack <int>s1,s2;
	ll nesting_depth=0,nesting_depth_first=-1;
	ll max_sequence=0,max_sequence_first=-1;
	ll temp;
	for (ll i=0;i<n;i++){
		cin>>inputs[i];
		if(inputs[i]==1){
			s1.push(1);
			if (s2.empty()){
				temp=i+1;
			}
			s2.push(1);
		}
		else if(inputs[i]==2){
			if (s1.size()>nesting_depth){
				nesting_depth=s1.size();
				nesting_depth_first=i;
			}
			s1.pop();
			s2.push(2);
			if (s1.empty()){
				if (s2.size()>max_sequence){
					max_sequence=s2.size();
					max_sequence_first=temp;
					}
				while (!s2.empty()){
					s2.pop();
				}
			}
		}
	}
	cout<<nesting_depth<<" "<<nesting_depth_first<<" ";
	cout<<max_sequence<<" "<<max_sequence_first;
	return 0;
}