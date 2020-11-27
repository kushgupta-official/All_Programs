# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

ll n=0;
vector <bool> chosen;
string permuatation;
set <string> result;

void calculate_permutations(string &s){
	if (permuatation.size()==s.size()){
		result.insert(permuatation);
	}
	else{
		for (ll i=0;i<s.size();i++){
			if (chosen[i])
				continue;
			permuatation.push_back(s[i]);
			chosen[i]=1;
			calculate_permutations(s);
			chosen[i]=0;
			permuatation.pop_back();
		}
	}
}

int main(){
	kush_gupta();
	string s;
	cin>>s;
	sort(s.begin(), s.end());
	chosen.resize(s.size());
	calculate_permutations(s);	
	cout<<result.size()<<endl;
	for (auto ite=result.begin();ite!=result.end();ite++){
		cout<<*ite<<endl;
	}
	return 0;
}