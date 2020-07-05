# include <bits/stdc++.h>
using namespace std;

int main(){
	int test_cases=0;
	cin>>test_cases;
	std::vector<int> solution;
	while(test_cases--){
		int n=0;
		cin>>n;
		int maximum=0;
		std::vector<int> shops(n);
		std::vector<int> value(n);
		std::vector<int> persons(n);
		for (int i=0;i<n;i++){
			cin>>shops[i];
			cin>>persons[i];
			cin>>value[i];
			maximum=max(maximum,((persons[i]/(shops[i]+1))*value[i]));
		}
		solution.push_back(maximum);
	}

	for (int i=0;i<solution.size();i++){
		cout<<solution[i]<<endl;
	}
	return 0;
}