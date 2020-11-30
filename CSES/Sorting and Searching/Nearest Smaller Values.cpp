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

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	stack <ll> s;
	vector <ll> a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}
	for (ll i=0;i<n;i++){
		while(!s.empty() && a[s.top()-1]>=a[i]){
			s.pop();
		}
		if(s.empty()){
			cout<<0;
		}
		else{
			cout<<s.top();
		}
		s.push(i+1);
		cout<<" ";
	}	
	return 0;
}