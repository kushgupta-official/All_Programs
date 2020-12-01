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
	vector <ll> a(n);
	
	for (ll i=0;i<n;i++){
		cin>>a[i];
	}

	ll currsum=0,count=0;
	map<ll,ll> mp;

	for (ll i=0;i<n;i++){
		currsum+=a[i];

		if(currsum%n==0){
			count++;
		}
		ll temp=currsum%n;
		if (temp<0){
			temp+=n;
		}
		if(mp.find(temp)!=mp.end()){
			count+=mp[temp];
			// cout<<1;
		}

		mp[currsum]++;
	}
	// cout<<endl;
	cout<<count;

	return 0;
}