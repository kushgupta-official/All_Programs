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
pair <ll,ll> p;
bool comp(pair <ll,ll> p1,pair <ll,ll> p2){
  return int(sqrt(pow((p1.first-p.first),2)+pow((p1.second-p.second),2)))
          <int(sqrt(pow((p2.first-p.first),2)+pow((p2.second-p.second),2)));
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    cin>>n;
    std::vector<pair <ll,ll> > a;
    ll f=0,s=0;
    rep(i,0,n){
      cin>>f;
      cin>>s;
      a.push_back(pair<ll,ll>(f,s));
    }
    //p=a[0];
    // //sort(a.begin(), a.end(),comp);
    rep(i,0,n){
      cout<<a[i].first<<" "<<a[i].second<<endl;
    }
  }
	return 0;
}