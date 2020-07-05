# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

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
	ll test_cases=0;
  cin>>test_cases;
  while(test_cases--){
    ll n=0;
    cin>>n;
    ll a=0,b=0;
    //std::vector<ll> inputs(n);
    ll res=0;
    cin>>a;
    //cin>>inputs[0];
    rep(i,1,n){
      cin>>b;
      res+=abs(b-a)-1;
      a=b;
      //cin>>inputs[i];
      //cout<<res<<endl;
      //res+=abs(inputs[i]-inputs[i-1])-1;
    }
    cout<<res<<endl;
  }
	return 0;
}