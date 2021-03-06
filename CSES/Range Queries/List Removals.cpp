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
	if (s>r or e<l){
		return 0;
	}
	if (s<=l and e>=r){
		return tree[tidx];
	}
	ll m=mid(l,r);
	return query(tree,tidx*2+1,s,e,l,m)+
				query(tree,tidx*2+2,s,e,m+1,r);
}

void update(vll &tree, ll tidx, ll index, ll value, ll l, ll r){
	if (l==r){
		tree[tidx]=value;
		return;
	}
	ll m=mid(l,r);
	if (index<=m){
		update(tree,tidx*2+1,index,value,l,m);
	}
	else{
		update(tree,tidx*2+2,index,value,m+1,r);
	}
	tree[tidx]=tree[tidx*2+1]+tree[tidx*2+2];
}

int main()
{
	kush_gupta();
	ll n=0;
	cin>>n;
	vll v(n);
	rep(i,0,n){
		cin>>v[i];
	}	
	vll present(n,1);
	vll tree(4*n,0);
	build(present,tree,0,0,n-1);
	rep(i,0,n){
		ll x=0;
		cin>>x;
		// x--;
		ll lo=0,hi=n-1;
		while(lo<hi){
			ll m=mid(lo,hi);
			ll mid_sum=query(tree,0,0,m,0,n-1);
			if (mid_sum==x){
				if (present[m]==1){
					lo=m;
					break;
				}
				else{
					hi=m-1;
				}
			}
			else if (mid_sum>x){
				hi=m-1;
			}
			else{
				lo=m+1;
			}
		}
		present[lo]=0;
		update(tree,0,lo,0,0,n-1);
		cout<<v[lo]<<' ';
	}
	return 0;
}