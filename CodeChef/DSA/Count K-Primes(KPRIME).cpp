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
  ll n=100000;
  std::vector<bool> soe(n+1,1);
  std::vector<ll> prime_factors(n+1,0);
  //std::vector<ll> max_prime_factor(n+1);
  //max_prime_factor[1]=1;
  for (ll i=2;i<=n;i++){
    if (soe[i]){
      prime_factors[i]++;
      //max_prime_factor[i]=i;
      for (ll j=i+i;j<=n;j+=i){
        soe[j]=0;
        prime_factors[j]++;
      }
    }
  }
  /*for (ll i=2;i<prime_factors.size();i++){
    cout<<i<<" = "<<prime_factors[i].size()<<endl;
  }*/
	w(test_cases){
    ll a=0,b=0,k=0;
    cin>>a>>b>>k;
    ll res=0;
    for (ll i=a;i<=b;i++){
     //cout<<prime_factors[i]<<endl;
      if (prime_factors[i]==k){
        res++;
      }
    }
    //cout<<"res = ";
    cout<<res<<endl;
  }
	return 0;
}