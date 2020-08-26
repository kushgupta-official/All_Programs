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
# define max 100000000000000000
void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

bool comp(pair<ll,ll> a,pair<ll,ll> b){
  return a.first>b.first;
}

int main()
{
	kush_gupta();
	ll n=0;
  cin>>n;
  vp price(n);
  ll temp;
  rep(i,0,n){
    cin>>temp;
    price[i].first=temp;
    price[i].second=i;
  }
  //cout<<max<<endl;
  sort(price.begin(), price.end(),comp);
  // rep(i,0,n){
  //   cout<<price[i].first<<" "<<price[i].second<<"\n";
  // }
  ll minimum=max;
  rep(i,0,n-1){
    if(price[i].second<price[i+1].second){
      minimum=min(minimum,price[i].first-price[i+1].first);
    }
  }
  cout<<minimum;
	return 0;
}