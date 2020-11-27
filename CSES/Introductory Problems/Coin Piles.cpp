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
	ll t=0;
	cin>>t;
	while(t--){
		ll a=0,b=0;
		cin>>a>>b;
		if(max(a,b)>2*min(a,b)){
			cout<<"NO\n";
		}
		else if((a+b)%3==0){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}	
	return 0;
}