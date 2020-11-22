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
	ll curr=1;
	ll fp=0,sp=1;
	ll res=INT_MIN;
	while (fp<n-1 && sp<n){
		if(fp==sp){
			sp++;
		}
		if (ids[fp]==ids[sp]){
			fp++;
			curr=1;
		}
		else{
			sp++;
			curr++;
		}
		res=max(curr,res);
		cout<<fp<<" "<<sp<<" ";
	}
	cout<<endl<<res;
	return 0;
}