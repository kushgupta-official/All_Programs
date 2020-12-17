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

ll n=0,m=0;
pair <ll,ll> si, ei;
vector <pair <ll,ll> > monster;
vector <vector <pair <ll,char> > > matrix;
vector <pair <ll,ll> > moves={ {-1,0}, {1,0}, {0,-1}, {0,1} };

bool isValid(ll x, ll y, ll timer){
	if (x>0 && y>0 && x<=n && y<=m && timer<matrix[x][y].first){
		return true;
	}
	return false;
}

void preprocess_monster_flow(){
	queue <pair <pair <ll,ll>, ll> > q;
	for (auto m:monster){
		q.push({m,0});
	}
	while(!q.empty()){
		ll cx=q.front().first.first;
		ll cy=q.front().first.second;
		ll timer=q.front().second;
		timer++;
		q.pop();
		for (auto mv:moves){
			ll tx=cx+mv.first;
			ll ty=cy+mv.second;
			if (isValid(tx, ty, timer)){
				q.push({{tx, ty}, timer});
				matrix[tx][ty].first=timer;
			}

		}
	}
}

bool canEscape(ll x, ll y){
	if (x==1 || y==1 || x==n || y==m){
		return true;
	}
	return false;
}

bool canSolve(){
	queue <pair <pair <ll,ll>, ll> > q;
	q.push({si,0});
	while(!q.empty()){
		ll cx=q.front().first.first;
		ll cy=q.front().first.second;
		ll timer=q.front().second;
		timer++;
		q.pop();
		for (auto mv:moves){
			ll tx=mv.first+cx;
			ll ty=mv.second+cy;
			if (isValid(tx, ty, timer)){
				if (mv.first==-1){
					matrix[tx][ty].second='U';
				}
				else if (mv.first==1){
					matrix[tx][ty].second='D';
				}
				else if (mv.second==-1){
					matrix[tx][ty].second='L';
				}
				else if (mv.second==1){
					matrix[tx][ty].second='R';
				}
				if (canEscape(tx, ty)){
					ei={tx,ty};
					matrix[tx][ty].first=timer;
					return true;
				}
				else{
					q.push({{tx, ty}, timer});
					matrix[tx][ty].first=timer;
				}
			}
		}
	}
	return false;
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	cin>>n>>m;
	
	matrix.resize(n+1, vector <pair <ll,char> > (m+1,{INT_MAX,'z'}));

	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			char ch;
			cin>>ch;
			if(ch=='.'){
				matrix[i][j].first=INT_MAX;
			}
			else if(ch=='#'){
				matrix[i][j].first=0;
			}
			else if(ch=='M'){
				matrix[i][j].first=0;
				monster.push_back({i,j});
			}
			else{
				matrix[i][j].first=INT_MAX;
				si={i,j};
			}
		}
	}
	if (canEscape(si.first,si.second)){
		cout<<"YES\n0";
		return 0;
	}
	preprocess_monster_flow();
	if (canSolve()){
		cout<<"YES\n";
		string res="";
		pair <ll, ll> curr=pair <ll,ll> {ei.first,ei.second};
		while(curr!=pair <ll,ll> {si.first,si.second}){
			ll cx=curr.first;
			ll cy=curr.second;
			char ch=matrix[cx][cy].second;
			res.push_back(ch);
			if (ch=='U'){
				cx+=1;
			}
			else if (ch=='D'){
				cx-=1;
			}
			else if (ch=='L'){
				cy+=1;
			}
			else if (ch=='R'){
				cy-=1;
			}
			curr={cx,cy};
		}
		reverse(res.begin(), res.end());
		cout<<res.size()<<endl<<res;
	}
	else{
		cout<<"NO";
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