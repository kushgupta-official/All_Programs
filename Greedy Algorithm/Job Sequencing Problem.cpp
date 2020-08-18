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
# define pr pair <ll,ll>
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

bool comp(pr p1,pr p2){
  return (p1.first*p2.second)>(p1.second/p2.first);
}

int main()
{
  kush_gupta();
  w(test_cases){
    ll n=0;
    cin>>n;
    ll temp=0;
    vector <pair <ld,ld> > t(n);
    rep(i,0,n){
      cin>>temp;
      cin>>t[i].first>>t[i].second;
    }
    sort(t.begin(), t.end(),comp);
    // rep(i,0,n){
    //   cout<<t[i].first<<" ";
    // }
    // cout<<endl;
    // rep(i,0,n){
    //   cout<<t[i].second<<" ";
    // }
    // cout<<endl;
  ll profit=0,count=0;
  rep(i,0,n){
    if(count<t[i].first){
      count++;
      profit+=t[i].second;
    }
  }
  cout<<count<<" "<<profit<<endl;
}
  return 0;
}