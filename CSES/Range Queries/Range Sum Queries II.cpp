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

void build(vll &a, vll &tree, ll tidx, ll l, ll r){
	if (l==r){
		tree[tidx]=a[l];
		return;
	}
	ll m=mid(l,r);
	build(a,tree,tidx*2+1,l,m);
	build(a,tree,tidx*2+2,m+1,r);
	tree[tidx]=tree[tidx*2+1]+tree[tidx*2+2];
}

ll query(vll &tree, ll tidx, ll s, ll e, ll l, ll r){
	//outside
	if (s>r or e<l){
		return 0;
	}
	//fully inside
	if (s<=l and e>=r){
		return tree[tidx];
	}
	ll m=mid(l,r);
	return query(tree,tidx*2+1,s,e,l,m)
				+ query(tree,tidx*2+2,s,e,m+1,r);
}

void update(vll &tree, ll tidx, ll value, ll index, ll l, ll r){
	if (l==r){
		tree[tidx]=value;
		return;
	}
	ll m=mid(l,r);
	if (m>=index){
		update(tree,tidx*2+1,value,index,l,m);
	}
	else{
		update(tree,tidx*2+2,value,index,m+1,r);
	}
	tree[tidx]=tree[tidx*2+1]+tree[tidx*2+2];
}

int main()
{
	kush_gupta();
	ll n=0,q=0;
	cin>>n>>q;
	vll v(n);
	rep(i,0,n){
		cin>>v[i];
	}
	vll tree(n*4,0);
	build(v,tree,0,0,n-1);
	while(q--){
		ll k,a,b;
		cin>>k>>a>>b;
		if (k==1){
			v[a-1]=b;
			update(tree, 0, b, a-1, 0, n-1);
		}
		else{
			cout<<query(tree,0,a-1,b-1,0,n-1)<<endl;
		}
	}
	return 0;
}