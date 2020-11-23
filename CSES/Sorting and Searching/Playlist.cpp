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
	vector <ll> ids(n);
	for (ll i=0;i<n;i++){
		cin>>ids[i];
	}
	set <ll> s;
	ll res=0;
	for (ll i=0,j=0;i<n;i++){
		if (s.find(ids[i])!=s.end()){
			while(ids[j]!=ids[i]){
				s.erase(ids[j]);
				j++;
			}
			s.erase(ids[j]);
			j++;
		}
		s.insert(ids[i]);
		res=max(res,i-j+1);
	}
	cout<<res<<endl;
	return 0;
}