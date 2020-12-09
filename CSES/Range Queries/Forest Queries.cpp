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
	ll n=0,q=0;
	cin>>n>>q;
	vector <vector <ll> > v(n+1,vector <ll> (n+1,0));
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=n;j++){
			char ch;
			cin>>ch;
			if (ch=='.'){
				v[i][j]=0;
			}
			else{
				v[i][j]=1;
			}
		}
	}
	vector <vector <ll> > t(n+1,vector <ll> (n+1,0));
	for (ll i=0;i<=n;i++){
		for (ll j=0;j<=n;j++){
			if (i==0 || j==0){
				t[i][j]=0;
			}
			else{
				t[i][j]=t[i][j-1]+t[i-1][j]-t[i-1][j-1]+v[i][j];
			}
		}
	}
	while(q--){
		ll a=0,b=0,c=0,d=0;
		cin>>a>>b>>c>>d;
		// cout<<t[a-1][b-1]<<" "<<t[a-1][d]<<" "<<t[c][b-1]<<" "<<t[c][d]<<endl;
		cout<<t[c][d]-t[a-1][d]-t[c][b-1]+t[a-1][b-1]<<endl;
	}
	return 0;
}