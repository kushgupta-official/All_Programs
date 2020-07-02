# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0;cin>>x;while(x--)

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}
ll find_gcd(ll a,ll b){
  ll temp=0;
  while(b!=0){
    temp=b;
    b=a%b;
    a=temp;
  }
  return a;
}
int main()
{
	  kush_gupta();
	  w(test_cases){
    ll n=0,a=0,b=0,k=0;
    cin>>n>>a>>b>>k;
    ll lcm=(a*b)/find_gcd(a,b);
    if (n/a + n/b - n/lcm -n/lcm >= k){
      cout<<"Win\n";
    }
    else{
      cout<<"Lose\n";
    }
  }
	return 0;
}