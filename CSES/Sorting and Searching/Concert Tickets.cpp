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
	ll n=0,m=0;
	cin>>n>>m;
	vector <ll> tickets(n);
	vector <ll> customers(m);
	multiset <ll,greater<int> > ms;
	for (ll i=0;i<n;i++){
		cin>>tickets[i];
		ms.insert(tickets[i]);
	}
	for (ll j=0;j<m;j++){
		cin>>customers[j];
	}
	for (ll i=0;i<m;i++){
		auto ite=ms.lower_bound(customers[i]);
		if(ite==ms.end()){
			cout<<-1;
		}
		else{
			cout<<*ite;
			ms.erase(ite);
		}
		cout<<endl;
	}
	return 0;
}