# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

ll solve(vector <vector <ll> > &matrix, ll n, ll m){
	vector <bool> visited(n+1,false);
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			visited[]
		}
	}
}

int main()
{
	kush_gupta();
	ll n=0,m=0;
	cin>>n>>m;
	vector <vector <ll> > matrix(n+1,vector <ll> (m+1,0));
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			char ch;
			cin>>ch;
			if (ch=='.'){
				matrix[i][j]=1;
			}
		}
	}
	ll res=solve(matrix,n,m);
	return 0;
}