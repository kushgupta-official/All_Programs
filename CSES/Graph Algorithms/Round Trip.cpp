# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define loop(i,a,b) for(ll i=a;i<b;i++)
# define vi vector<int>
# define vll vector<ll>
# define vvl vector<vector <ll> >
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2
# define fi first
# define se second

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}
vector <ll> result;
bool flag=1;

void dfs(vvl &v, ll n, vector <bool> &visited, ll i, ll parent){
	if (!flag){
		return;
	}
	visited[i]=true;
	// cout<<i<<" ";
	result.push_back(i);
	for (auto j:v[i]){
		if (!visited[j]){
			dfs(v,n,visited,j,i);
			// cout<<" hi ";
			if (!flag){
				return;
			}
		}
		else if (j!=parent){
			// cout<<j<<endl;
			flag=0;
			result.push_back(j);
			return;
		}
	}
	return;	
}

void solve(vvl &v, ll n){
	vector <bool> visited(n+1,false);
	vector <ll> res;
	for (ll i=1;i<=n;i++){
		if (!visited[i]){
			dfs(v, n, visited, i, -1);
			if (!flag){
				res.push_back(result.back());
				ll j=0;
				for (j=result.size()-2;result[j]!=res[0];j--){
					res.push_back(result[j]);
				}
				res.push_back(result[j]);
				cout<<res.size()<<endl;
				for (j=0;j<res.size();j++){
					cout<<res[j]<<" ";
				}
				// cout<<res[0];
				return;
			}
		}
	}
	cout<<"IMPOSSIBLE";
	return;
}

int main()
{
	kush_gupta();
	ll n=0,m=0;
	cin>>n>>m;
	vvl v(n+1);
	for (ll i=1;i<=m;i++){
		ll a=0,b=0;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	solve(v, n);
	return 0;
}