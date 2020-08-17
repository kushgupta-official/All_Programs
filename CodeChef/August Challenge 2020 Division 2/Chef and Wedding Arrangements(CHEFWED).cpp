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
/*
  a[i]=min(a[i],)
*/
ll solve(ll n,ll k,const vll &a){
  vll dp(n+1);
  dp[0]=0;
  for (ll i=1;i<n+1;i++){
    dp[i]=dp[i-1]+k;
    map <ll,ll> mp;
    ll repeats=0;
    for (ll j=i;j>0;j--){
      mp[a[j]]++;
      if(mp[a[j]]==2){
        repeats+=2;
      }
      else if(mp[a[j]]>2){
        repeats++;
      }
      dp[i]=min(dp[i],dp[j-1]+k+repeats);
    }
  }
  return dp[n]; 
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0,k=0;
    cin>>n>>k;
    vll arr(n+1,0);
    rep(i,1,n+1){
      cin>>arr[i];
    }
    ll res=solve(n,k,arr);
    cout<<res<<endl;
  }
	return 0;
}