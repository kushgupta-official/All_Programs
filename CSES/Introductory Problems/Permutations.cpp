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
	if (n<4 && n>1){
		cout<<"NO SOLUTION";
	}
	else{
		ll i=2;
		while(i<=n){
			cout<<i<<" ";
			i+=2;
		}
		i=1;
		while(i<=n){
			cout<<i<<" ";
			i+=2;
		}
	}
	return 0;
}