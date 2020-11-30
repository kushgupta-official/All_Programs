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
	ll n=0,x=0;
	cin>>n>>x;
	vector <ll> a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll currsum=0,count=0;
	unordered_map <ll,ll> ump;
	for (ll i=0;i<n;i++){
		currsum+=a[i];
		if (currsum==x){
			count++;
		}
		if (ump.find(currsum-x)!=ump.end()){
			count+=ump[currsum-x];
		}
		ump[currsum]++;
	}
	cout<<count;
	return 0;
}