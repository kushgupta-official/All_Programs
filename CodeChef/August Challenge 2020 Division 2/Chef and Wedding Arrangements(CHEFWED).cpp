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
	w(test_cases){
    unordered_map <ll,ll> mp;
    ll n=0,k=0,res=0;
    cin>>n>>k;
    res=k;
    rep(i,0,n){
      ll temp=0;
      cin>>temp;
      mp[temp]++;
      if(mp[temp]>1 && k!=1){
        res++;
      }
      if(mp[temp]>k){
        res+=k;
        mp.clear();
        mp[temp]++;
      }
    }
    cout<<res<<endl;
  }
	return 0;
}