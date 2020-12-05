# include <bits/stdc++.h>
# define ll long long int
# define mod 1000000007
using namespace std;
 
void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
}
 
ll dp(ll sum,vector <ll> &v,ll n){
  // if (sum==0){
  //   return 1;
  // }
  // if (n==0 and sum!=0){
  //   return 0;
  // }
  // if (v[n-1]<=sum){
  //   return dp(sum-v[n-1],v,n-1)+dp(sum,v,n-1);
  // }
  // else{
  //   return dp(sum,v,n-1);
  // }
  vector <vector <ll> > t(n+1,vector <ll> (sum+1,0));
  for (ll i=0;i<=n;i++){
    t[i][0]=1;
  }
  for(ll i=1;i<=n;i++){
    for (ll j=1;j<=sum;j++){
      if (v[i-1]<=j){
        t[i][j]=(t[i-1][j-v[i-1]]+t[i-1][j])%mod;
      }
      else{
        t[i][j]=(t[i-1][j])%mod;
      }
    }
  }
  return (t[n][sum])%mod;
}
 
int main(){
  kush_gupta();
  ll n=0;
  cin>>n;
  ll sum=(n*(n+1))/2;
  if(sum%2==1){
    cout<<0;
  }
  else{
    vector <ll> v(n);
    for (ll i=0;i<n;i++){
      v[i]=i+1;
    }
    cout<<(dp(sum/2,v,n)*500000004)%mod;
  }
  return 0;
}