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

int main()
{
  kush_gupta();
  ll t=0;
  cin>>t;
  while(t--){
    ll n=0;
    cin>>n;
    vll v(n);
    rep(i,0,n){
      cin>>v[i];
    }
    ll sum=0;
    sum+=v[0];
    ll i=0;
    for (i=1;i<n;i++){
      sum-=1;
      if (sum==-1){
        sum++;
        break;
      }
      sum+=v[i];
    }
    cout<<i+sum-1<<endl;
  }
  return 0;
}