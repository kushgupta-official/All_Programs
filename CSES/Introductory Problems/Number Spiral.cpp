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
		ll x=0,y=0;
		cin>>x>>y;
		if (x==y){
			cout<<x*(x-1)+1;
		}
		else{
			ll m=max(x,y);
			ll v=m*(m-1)+1;
			if(m%2==0){
				cout<<v+x-y;
			}
			else{
				cout<<v-x+y;
			}
		}
		cout<<"\n";
	}	
	return 0;
}