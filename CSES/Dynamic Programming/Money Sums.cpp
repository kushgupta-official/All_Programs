# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	kush_gupta();
	int n=0;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	set <int> s;
	s.insert(a[0]);
	for (ll i=1;i<n;i++){
		vector <ll> v;
		for (auto ite:s){
			v.push_back(a[i]+ite);
		}
		s.insert(a[i]);
		for (auto ite:v){
			s.insert(ite);
		}
	}
	cout<<s.size()<<endl;
	for (auto ite:s){
		cout<<ite<<" ";
	}
	return 0;
}