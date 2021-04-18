# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp> 
# include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

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

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void build(vll &v, vll &tree, ll tidx, ll l, ll r){
	if (l==r){
		tree[tidx]=v[l];
		return;
	}
	ll m=mid(l,r);
	build(v,tree,tidx*2+1,l,m);
	build(v,tree,tidx*2+2,m+1,r);
	tree[tidx]=tree[tidx*2+1] | tree[tidx*2+2];
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
	return query(tree,tidx*2+1,s,e,l,m) | query(tree,tidx*2+2,s,e,m+1,r);
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
	tree[tidx]=tree[tidx*2+1] | tree[tidx*2+2];
}

void kush_gupta_solves(){
	w(t){
		ll n=0,q=0;
		cin>>n>>q;
		vll v(n);
		loop(i,0,n){
			cin>>v[i];
		}
		vll tree(4*n,0);
		build(v,tree,0,0,n-1);
		cout<<query(tree,0,0,n-1,0,n-1)<<endl;
		ll x=0,a=0;
		while(q--){
			cin>>x>>a;
			update(tree,0,a,x-1,0,n-1);
			cout<<query(tree,0,0,n-1,0,n-1)<<endl;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
		freopen("input.txt", "r", stdin) ;
  		freopen("output.txt", "w", stdout) ;
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	kush_gupta_solves();

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif

	return 0;
}