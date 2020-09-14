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

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

void solve(){
  ll n=0;
  cin>>n;
  vll v(n+1);
  if(n!=3){
  rep(i,1,n+1){
    cin>>v[i];
  }
  std::vector<set <ll> > sets(n+1);
  for (ll i=n;i>0;i--){
    for (ll j=i-1;j>0;j--){
      if ((i-j) > ((i+v[i])-(j+v[j]))){
        sets[i].insert(j);
      }
    }
  }
  set <ll> res;
  ll max=INT_MIN,min=INT_MAX;
  for (ll i=1;i<=n;i++){
    res.clear();
    res.insert(i);
    for (auto k:sets[i]){
      res.insert(k);
    }
    for (ll j=i+1;j<=n;j++){
      if( ( j-i ) > ( (j+v[j])-(i+v[i]) ) ){
        res.insert(j);
        for (auto k:sets[j]){
          if (!( k>i && (v[k]>=v[i]) ) )// || (v[k]<=v[i] && k>i))
          // check if inserted one is faster than i or not, if faster don't insert
          // else insert -- to be implemented
          res.insert(k);
        }
      }
    }
    if(res.size()>max){
      max=res.size();
    }
    if(res.size()<min){
      min=res.size();
    }
  }
    cout<<min<<" "<<max<<endl;

  }
  else{
    ll arr[n+1];
    for (ll i=1;i<=n;i++){
    cin>>v[i];
    arr[i]=1;
  }
  // if(n==3){ 
  ll min=INT_MAX,max=INT_MIN;
  for (ll i=1;i<=n;i++){
    for (ll j=i+1;j<=n;j++){
      if (((j+v[j]*5)-(i+v[i]*5))<(j-i)){
        arr[i]++;
        arr[j]++;
      }
    }
    if(arr[i]>max){
      max=arr[i];
    //  cout<<i<<endl;
    }
    if(arr[i]<min){
      min=arr[i];
    }
  }
    cout<<min<<" "<<max<<endl;

  }
}

int main()
{
	kush_gupta();
	w(t){
    solve();
  }
	return 0;
}