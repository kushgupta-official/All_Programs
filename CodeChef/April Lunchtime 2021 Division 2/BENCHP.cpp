# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)
# define MOD 1000000007

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
  w(t){
    ll n=0,w=0,wr=0;
    cin>>n>>w>>wr;
    ll sum=0;
    ll d=0;
    map <ll,ll> mp;
    ll x=0;
    for (ll i=0;i<n;i++){
      cin>>x;
      // sum+=x;
      mp[x]++;
      if (mp[x]==1){
        d+=1;
      }
      else if (mp[x]==2){
        d-=1;
        mp[x]=0;
        sum+=x*2;
      }
    }
    if (wr>=w){
      cout<<"YES\n";
    }
    else if (wr+sum>=w){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
  return 0;
}