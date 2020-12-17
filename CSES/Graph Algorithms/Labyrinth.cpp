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

bool bfs
(ll n, ll m, vector <vector <pair <ll,char> > > &matrix, pair <ll,ll> &start, pair <ll,ll> &end){
	vector <vector <bool> >visited(n+1, vector <bool> (m+1,false));
	queue <pair <ll,ll> > q;
	q.push({start.fi,start.se});
	while (!q.empty()){
		ll i=q.front().fi;
		ll j=q.front().se;
		q.pop();
		visited[i][j]=true;
		// cout<<i<<" "<<j<<" "<<matrix[i][j].se<<endl;
		if (i==end.fi && j==end.se){
			break;
		}
		if (i>1 && matrix[i-1][j].fi && !visited[i-1][j]){
			visited[i-1][j]=true;
			q.push({i-1,j});
			matrix[i-1][j].se='U';
			if (i-1==end.fi && j==end.se){
				break;
			}
		}
		if (j>1 && matrix[i][j-1].fi && !visited[i][j-1]){
			visited[i][j-1]=true;
			q.push({i,j-1});
			matrix[i][j-1].se='L';
			if (i==end.fi && j-1==end.se){
				break;
			}
		}
		if (i<n && matrix[i+1][j].fi && !visited[i+1][j]){
			visited[i+1][j]=true;
			q.push({i+1,j});
			matrix[i+1][j].se='D';
			if (i+1==end.fi && j==end.se){
				break;
			}
		}
		if (j<m && matrix[i][j+1].fi && !visited[i][j+1]){
			visited[i][j+1]=true;
			q.push({i,j+1});
			matrix[i][j+1].se='R';
			if (i==end.fi && j+1==end.se){
				break;
			}
		}
	}
	return visited[end.fi][end.se];
}

void solve
(ll n, ll m, vector <vector <pair <ll,char> > > &matrix, pair <ll,ll> start, pair <ll,ll> end)
{
	if (bfs(n,m,matrix,start,end)){
		cout<<"YES"<<endl;
		string res="";
		pair <ll,ll> curr={end.fi,end.se};
		while(curr!=pair <ll,ll>{start.fi,start.se}){
			ll i=curr.fi,j=curr.se;
			// cout<<i<<" "<<j<<endl;
			// res=matrix[i][j].se+res;
			res+=matrix[i][j].se;
			// res.push_back(matrix[i][j].se);
			if (matrix[i][j].se == 'U'){
				// cout<<"test";
				curr={i+1,j};
			} 
			else if (matrix[i][j].se == 'D'){
				// cout<<"test";
				curr={i-1,j};
			}
			else if (matrix[i][j].se == 'L'){
				curr={i,j+1};
			}
			else if (matrix[i][j].se == 'R'){
				curr={i,j-1};
			}
		}
		reverse(res.begin(), res.end());
		cout<<res.size()<<endl<<res;
	}
	else{
		cout<<"NO"<<endl;
	}
	return;
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif
	ll n=0,m=0;
	cin>>n>>m;
	vector <vector <pair <ll,char> > > matrix(n+1, vector <pair <ll,char> > (m+1,{0,'z'}));
	pair <ll,ll> start,end;
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			char ch;
			cin>>ch;
			if (ch=='.'){
				matrix[i][j].first=1;
			}
			else if (ch=='A'){
				start.fi=i;
				start.se=j;
				matrix[i][j].first=1;
			}
			else if (ch=='B'){
				end.fi=i;
				end.se=j;
				matrix[i][j].first=1;
			} 
		}
	}
	solve(n,m,matrix,start,end);
	
	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		// Calculating total time taken by the program. 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime taken by program is : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif

	return 0;
}