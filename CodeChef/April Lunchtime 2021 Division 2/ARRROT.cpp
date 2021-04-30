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
  ll n=0;
  cin>>n;
  ll sum=0;
  vll v(n);
  for (ll i=0;i<n;i++){
    cin>>v[i];
    sum=sum+v[i];
    sum=(sum+MOD)%MOD;
  }
  sum=sum%MOD;
  w(q){
    ll x=0;
    cin>>x;
    sum=(sum+sum)%MOD;
    cout<<sum<<endl;
  }
  return 0;
}