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
	ll a=0,b=0;
	cin>>a>>b;
	vector <vector <ll> > t(a+1,vector <ll> (b+1,INT_MAX));
	for (ll i=0;i<=a;i++){
		for (ll j=0;j<=b;j++){
			// horizontol cuts
			if(i==j){
				t[i][j]=0;
			}
			for (ll k=1;k<j;k++){
				t[i][j]=min(t[i][j],1+t[i][k]+t[i][j-k]);
			}

			//vertical cuts
			for (ll k=1;k<i;k++){
				t[i][j]=min(t[i][j],1+t[k][j]+t[i-k][j]);
			}
		}
	}
	cout<<t[a][b];
	return 0;
}