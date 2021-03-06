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
# define INF 1e17
void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

ll n=0,m=0,q=0;
vector <vector <ll> > matrix;

void solve(){
	for(ll k=1;k<=n;k++){
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=n;j++){
				matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
			}
		}
	}
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	cin>>n>>m>>q;
	matrix.resize(n+1, vector <ll> (n+1, INF));
	loop(i,0,m){
		ll a=0,b=0,c=0;
		cin>>a>>b>>c;
		matrix[a][b]=min(matrix[a][b],c);
		matrix[b][a]=min(matrix[b][a],c);
	}
	for (ll i=0;i<=n;i++){
		matrix[i][i]=0;
	}
	solve();
	while(q--){
		ll a=0,b=0;
		cin>>a>>b;
		if (matrix[a][b]==INF){
			cout<<-1<<endl;
		}
		else{
			cout<<matrix[a][b]<<endl;
		}
	}
	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}