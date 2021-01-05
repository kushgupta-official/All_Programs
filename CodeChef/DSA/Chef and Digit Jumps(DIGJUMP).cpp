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

string s;
vvl g;
vll dist;
vll visited;

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	cin>>s;

	g.resize(10);
	dist.resize(s.size()+1,INT_MAX);
	visited.resize(s.size());

	for (int i=1;i<s.size();i++){
		ll x=s[i]-'0';
		g[x].push_back(i);
	}

	dist[0]=0;
	visited[0]=1;
	queue <ll> q;
	q.push(0);

	while(!q.empty()){
		ll idx=q.front();
		ll u=s[idx]-'0';
		q.pop();
		if (idx==s.size()-1){
			break;
		}
		for (auto idxv:g[u]){
			if (!visited[idxv]){
				dist[idxv]=dist[idx]+1;
				q.push(idxv);
				visited[idxv]=1;
			}
		}
		g[u].clear();
		if (idx-1>=0 and !visited[idx-1]){
			q.push(idx-1);
			dist[idx-1]=dist[idx]+1;
			visited[idx-1]=1;
		}
		if (idx+1<s.size() and !visited[idx+1]){
			q.push(idx+1);
			dist[idx+1]=dist[idx]+1;
			visited[idx+1]=1;
		}
	}

	cout<<dist[s.size()-1];

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}