# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

bool comp(pair <ll,ll> a,pair <ll,ll> b){
	if (a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}

ll query(vector <ll> &tree,ll s,ll e,ll tidx,ll l,ll r){
	if (s>r or e<l){
		return 0;
	}
	if (s>=l && e<=r){
		return tree[tidx];
	}
	ll mid=l+(r-l)/2;
	ll left=query(tree,s,e,tidx*2+1,l,mid);
	ll right=query(tree,s,e,tidx*2+2,mid+1,r);
	return max(left,right);
}

void update(vector <ll> &tree, vector <ll> &res, ll index, ll value,ll tidx,ll l,ll r){
	if (l==r){
		tree[tidx]=value;
		res[index]=value;
	}
	ll mid=l+(r-l)/2;
	if (mid>index){
		update(tree,res,index,value,tidx*2+1,l,mid);
	}
	else{
		update(tree,res,index,value,tidx*2+2,mid+1,r);
	}
	tree[tidx]=max(tree[tidx*2+1],tree[tidx*2+2]);
}

int main(){
	kush_gupta();
	ll n=0;
	cin>>n;
	vector <pair <ll,ll> > a(n);
	for (ll i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a.begin(), a.end(),comp);
	vector <ll> tree(n*4,0);
	vector <ll> res(n,0);
	for (ll i=0;i<n;i++){
		ll ele=a[i].first;
		ll index=a[i].second;
		ll res=query(tree,0,index,0,0,n-1);
		// tree,res,index,value,tidx*2+1,l,mid
// void update(vector <ll> &tree, vector <ll> &res, ll index, ll value,ll tidx,ll l,ll r){
		update(tree,res,index,res+1,0,0,n-1);
	}
	ll answer=INT_MIN;
	for (ll i=0;i<n;i++){
		answer=max(answer,res[i]);
	}
	cout<<answer;
	return 0;
}