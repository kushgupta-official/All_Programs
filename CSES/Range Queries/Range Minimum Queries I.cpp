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

void build(vll &tree,vll &a,ll tidx,ll l,ll r){
	if (l==r){
		tree[tidx]=a[l];
		return;
	}
	ll m=mid(l,r);
	build(tree,a,tidx*2+1,l,m);
	build(tree,a,tidx*2+2,m+1,r);
	tree[tidx]=min(tree[tidx*2+1], tree[tidx*2+2]);
}

ll query(vll &tree, ll tidx, ll x, ll y, ll l, ll r){
	//outside
	if (x>r or y<l){
		return INT_MAX;
	}
	//fully inside
	if (x<=l and y>=r){
		return tree[tidx];
	}
	ll m=mid(l,r);
	return min(query(tree,tidx*2+1,x,y,l,m),
						query(tree,tidx*2+2,x,y,m+1,r));
}

int main()
{
	kush_gupta();
	ll n=0,q=0;
	cin>>n>>q;
	vll a(n);
	rep(i,0,n){
		cin>>a[i];
	}
	vll tree(n*4,0);
	build(tree,a,0,0,n-1);
	while(q--){
		ll x=0,y=0;
		cin>>x>>y;
		cout<<query(tree,0,x-1,y-1,0,n-1)<<endl;
	}
	return 0;
}