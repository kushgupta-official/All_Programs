# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
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
	w(test_cases){
    ll n=0;
    cin>>n;
    int flag=0;
    ll minimum=-1;
    for (ll i=sqrt(n);i>0;i--){
      if (n%i==0 && i!=n/i){
        ll x=(i+(n/i))/2;
        ll y=((n/i)-i)/2;
        if (n+(y*y)==x*x){
          minimum=y*y;
          break;
        }
      }
    }
    cout<<minimum<<endl;
  }
	return 0;
}