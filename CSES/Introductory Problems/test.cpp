#include<bits/stdc++.h>
#define ll long long int
using namespace std::chrono; 

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

void build_tree(vector <ll> &a,vector <ll> &tree,ll tidx,ll srange,ll erange){
  if(srange==erange){
    tree[tidx]=a[srange];
    return;
  }
  ll mid=srange+(erange-srange)/2;
  build_tree(a,tree,tidx*2+1,srange,mid);
  build_tree(a,tree,tidx*2+2,mid+1,erange);
  tree[tidx]=tree[tidx*2+1]+tree[tidx*2+2];
}

void update(vector <ll> &a,vector <ll> &tree, ll tidx, ll idx, ll value,ll s, ll e){
  if (s==e){
    tree[tidx]=value;
    return;
  }
  ll mid=s+(e-s)/2;
  if (idx<=mid){
    update(a,tree,tidx*2+1,idx,value,s,mid);
  }
  else{
    update(a,tree,tidx*2+2,idx,value,mid+1,e);
  }
  tree[tidx]=tree[tidx*2+1]+tree[tidx*2+2];
}

ll sum(vector <ll> &a,vector <ll> &tree, ll tidx,ll srange, ll erange,ll givenS,ll givenE){
  //completely outside
  if (givenS>erange or givenE<srange){
    return 0;
  }
  //completely inside
  if (srange>=givenS and erange<=givenE){
    return tree[tidx];
  }
  ll mid=srange+(erange-srange)/2;
  ll x=sum(a,tree,tidx*2+1,srange,mid,givenS,givenE);
  ll y=sum(a,tree,tidx*2+2,mid+1,erange,givenS,givenE);
  return x+y;
}

int main()
{
  auto start = high_resolution_clock::now(); 
	kush_gupta();
  ll n=0;
  cin>>n;
  vector <ll> a(n);
  for (ll i=0;i<n;i++){
    cin>>a[i];
  }
  vector <ll> tree(4*n,0);
  build_tree(a,tree,0,0,n-1);
  for (ll i=0;i<4*n;i++){
    cout<<tree[i]<<" ";
  }
  cout<<endl;
  ll q=0;
  cin>>q;
  while(q--){
    char op;
    cin>>op;
    ll index,value;
    cin>>index>>value;
    // a[index]=value;
    // update(ll tidx, ll idx, ll value,ll s, ll e)
    if (op=='u')
      update(a,tree,0,index,value,0,n-1);
    else
      cout<<sum(a,tree,0,0,n-1,index,value)<<endl;
  }
  for (ll i=0;i<4*n;i++){
    cout<<tree[i]<<" ";
  }
  #ifndef ONLINE_JUDGE
  auto stop = high_resolution_clock::now(); 
      auto duration = duration_cast<microseconds>(stop - start); 

  cout << "\nTime taken by function: "
       << duration.count() << " microseconds" << endl; 
  #endif
}

//6 2 8 9 5
