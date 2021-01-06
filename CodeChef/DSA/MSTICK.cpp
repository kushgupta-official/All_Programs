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
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

ll n;
vector <ll> v;
ll q;
vector <pair <ll,ll> > tree;

void build(ll l, ll r, ll tidx){
	if (l==r){
		tree[tidx].first=v[l];
		tree[tidx].second=v[l];
		return;
	}
	ll m=mid(l,r);
	build(l,m,tidx*2+1);
	build(m+1,r,tidx*2+2);
	tree[tidx]={min(tree[tidx*2+1].first, tree[tidx*2+2].first), 
				max(tree[tidx*2+1].second, tree[tidx*2+2].second)};
}

ll maxQuery(ll s, ll e, ll l, ll r, ll tidx){
	//fully outside
	if (s>r or e<l){
		return INT_MIN;
	}
	if (s<=l and e>=r){
		return tree[tidx].second;
	}
	ll m=mid(l,r);
	return max( maxQuery(s, e, l, m, tidx*2+1),
				maxQuery(s, e, m+1, r, tidx*2+2) );
}

ll minQuery(ll s, ll e, ll l, ll r, ll tidx){
	//fully outside
	if (s>r or e<l){
		return INF;
	}
	if (s<=l and e>=r){
		return tree[tidx].first;
	}
	ll m=mid(l,r);
	return min( minQuery(s, e, l, m, tidx*2+1),
				minQuery(s, e, m+1, r, tidx*2+2) );
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

	// loop(i,0,n*4){
	// 	cout<<tree[i].first<<" "<<tree[i].second<<endl;
	// }

	cin>>q;

	while(q--){
		ll x=0, y=0;
		cin>>x>>y;
		ll m=minQuery(x,y,0,n-1,0);
		ll M=maxQuery(x,y,0,n-1,0);
		ll M_=max(maxQuery(0, x-1, 0, n-1, 0), 
				  maxQuery(y+1, n-1, 0, n-1, 0) );
		// cout<<m<<" "<<M<<" "<<M_<<endl;
		ld res=m/1.0+max( (M-m)/2.0, M_*1.0 );
		// cout<<res;
		printf("%.1Lf\n",res);
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