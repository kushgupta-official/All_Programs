# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
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
	w(t){
    ll n=0,k=0;
    cin>>n>>k;
    //vll p(n);
    ll min=INT_MAX,ans=-1;
    rep(i,0,n){
      ll pos=0;
      cin>>pos;
      if(k%pos==0){
        if(k/pos<min){
          min=k/pos;
          ans=pos;
        }
      }
    }
    cout<<ans<<endl;
  }
	return 0;
}