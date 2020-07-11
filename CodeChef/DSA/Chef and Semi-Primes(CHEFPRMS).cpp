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
  std::vector<bool> table(201,1);
  vll primes;
  for (ll i=2;i*i<=200;i++){
    if(table[i]){
      for (ll j=i*i;j<=200;j+=i){
        table[j]=0;
      }
    }
  }
  for (ll i=2;i<=200;i++){
    if(table[i]){
      primes.push_back(i);
    }
  }
  set<ll> semi_primes;
  for (ll i=0;i<primes.size();i++){
    for (ll j=i+1;j<primes.size();j++){
      semi_primes.insert(primes[i]*primes[j]);
    }
  }
	w(test_cases){
    ll n=0;
    cin>>n;
    set <ll> sum;
    for (auto i=semi_primes.begin();i!=semi_primes.end() && (*i)<n;i++){
      for(auto j=i;j!=semi_primes.end() && (*j)<n;j++){
        sum.insert(*i + *j);
      }
    }
    if (sum.find(n)!=sum.end()){
      cout<<"YES";
    }
    else{
      cout<<"NO";
    }
    cout<<"\n";
  }
	return 0;
}