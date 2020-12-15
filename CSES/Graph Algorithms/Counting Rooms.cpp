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

void mark(vector <vector <ll> > &matrix, vector <vector <bool> > &visited, ll n, ll m, ll i, ll j){
	if (visited[i][j]){
		return;
	}
	visited[i][j]=true;
	if (i>1 && matrix[i-1][j]){
		mark(matrix,visited,n,m,i-1,j);
	}
	if (j>1 && matrix[i][j-1]){
		mark(matrix,visited,n,m,i,j-1);
	}
	if (i<n && matrix[i+1][j]){
		mark(matrix,visited,n,m,i+1,j);
	}
	if (j<m && matrix[i][j+1]){
		mark(matrix,visited,n,m,i,j+1);
	}
	return;
}

ll solve(vector <vector <ll> > &matrix, ll n, ll m){
	vector <vector <bool> > visited(n+1, vector <bool> (m+1, false));
	ll toReturn=0;
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			if (matrix[i][j]==1){
				if (!visited[i][j]){
					toReturn++;
					mark(matrix, visited, n, m, i, j);
				}
			}
		}
	}
	return toReturn;
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
	cout<<solve(matrix,n,m);
	return 0;
}