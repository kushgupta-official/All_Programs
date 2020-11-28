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
  ll i=2;
  w(t){
    ll x=0,y=0,n=0;
    cin>>x>>y>>n;
    ll res=0;
    rep(z,0,n+1){
      if ((x^z)<(y^z)){
        // cout<<z<<" ";
        res++;
      }
    }
    cout<<res<<endl;
    //cout<<endl<<i++<<" "<<res<<endl;
  }
  return 0;
}