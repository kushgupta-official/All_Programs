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
	ll t=100;
	cout<<t<<endl;
	while(t--){
		ll k=rand()%11;
		k= k==0?1:k;

		ll l=rand()%11;
		l= l==0?1:l;

		ll m=rand()%11;
		m= m==0?1:m;

		ll n=rand()%11;
		n= n==0?1:n;

		ll d=100+rand()%100001;
		cout<<k<<" "<<l<<" "<<m<<" "<<n<<" "<<d;
		cout<<endl;
	}

	return 0;
}