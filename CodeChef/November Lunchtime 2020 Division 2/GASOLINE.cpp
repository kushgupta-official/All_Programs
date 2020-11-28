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

bool comp(pair <ll,ll> p1,pair <ll,ll> p2){
  // return double(p1.first/p1.second)>double(p2.first/p2.second);
  return (p1.first*p2.second)>(p2.first*p1.second);
}

bool comp2(pair<ll,ll> p1,pair<ll,ll> p2){
  return p1.second<p2.second;
}

int main()
{
  kush_gupta();
  w(t){
    ll n=0;
    cin>>n;
    vp v(n);
    rep(i,0,n){
      cin>>v[i].first;
    }
    rep(i,0,n){
      cin>>v[i].second;
    }
    //sort(v.begin(), v.end(),comp);
    sort(v.begin(), v.end(),comp2);
    ll res=0;

    for (ll i=0;n>0;i++){
      res+=min(v[i].first,n)*v[i].second;
      n-=min(v[i].first,n);
    }
    cout<<res<<endl;
  }
  return 0;
}