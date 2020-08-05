# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
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

bool comp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
  return (a.first.first<b.first.first);
}

bool comp2(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
  return (a.first.second<b.first.second);
}

int main()
{
	kush_gupta();
	ll n=0,k=0,p=0;
  cin>>n>>k>>p;
  std::vector <pair <pair <ll,ll>,ll> > a(n);
  rep(i,0,n){
    ll temp=0;
    cin>>temp;
    a[i].first.first=temp;
    a[i].first.second=i+1;
    a[i].second=0;
  }
  sort(a.begin(), a.end(),comp);
  a[0].second=1;
  ll t=1;
  rep(i,1,n){
    if((a[i].first.first-a[i-1].first.first)<=k){
      a[i].second=t;
    }
    else{
      a[i].second=++t;
    }
  }
  sort(a.begin(), a.end(),comp2);
  rep(i,0,p){
    ll x=0;
    ll y=0;
    cin>>x>>y;
    if(a[x-1].second==a[y-1].second){
      cout<<"Yes\n";
    }
    else{
      cout<<"No\n";
    }
  }
	return 0;
}