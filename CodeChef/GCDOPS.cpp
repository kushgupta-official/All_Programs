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

bool solve(){
  ll n=0;
  cin>>n;
  vll b(n+2),a(n+1);
  rep(i,1,n+1){
    cin>>b[i];
  }
  rep(i,1,n+1){
    if (i%b[i]!=0){
      return false;
    }
  }
  return true;
}

int main()
{
  kush_gupta();
  w(t){
    if(solve()){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
  return 0;
}