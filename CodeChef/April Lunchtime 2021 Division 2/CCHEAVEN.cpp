# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)

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
    string s;
    ll n=0;
    bool flag=0;
    cin>>n>>s;
    ll c0=0,c1=0;
    for (ll i=0;i<n;i++){
      if (s[i]=='0')
        c0++;
      else
        c1++;
      if (c1>=c0){
        flag=1;
        break;
      }
    }
    if (flag){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
  return 0;
}