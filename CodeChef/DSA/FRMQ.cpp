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

ll n;
vector <ll> v;
ll m;
vector <ll> tree;

void build(ll l, ll r, ll tidx){
	if (l==r){
		tree[tidx]=v[l];
		return;
	}
	ll m=mid(l,r);
	build(l,m,tidx*2+1);
	build(m+1,r,tidx*2+2);
	tree[tidx]=max(tree[tidx*2+1], tree[tidx*2+2]);
}

ll query(ll l, ll r, ll s, ll e, ll tidx){
	//completely outside
	if (s>r or e<l){
		return INT_MIN;
	}
	//completely inside
	if (s<=l and e>=r){
		return tree[tidx];
	}
	ll m=mid(l,r);
	return max(query(l,m,s,e,tidx*2+1),
			   query(m+1,r,s,e,tidx*2+2));
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	cin>>n;
	v.resize(n);
	tree.resize(n*4);
	loop(i,0,n){
		cin>>v[i];
	}
	build(0,n-1,0);
	ll res=0;
	cin>>m;
	ll x=0,y=0;
	cin>>x>>y;
	ll a=min(x,y);
	ll b=max(x,y);
	m--;
	res+=query(0,n-1,a,b,0);
	while(m--){
		x+=7;
		x%=n-1;
		// x=(x+7)%(n-1);
		y+=11;
		y%=n;
		// y=(y+11)%(n);
		a=min(x,y);
		b=max(x,y);
		res+=query(0,n-1,a,b,0);
	}

	cout<<res<<endl;

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}