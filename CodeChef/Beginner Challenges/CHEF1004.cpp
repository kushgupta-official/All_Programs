# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
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

ll dp(const vll &arr,ll n,ll m){
  /*if(x==0){
    return 1;
  }
  if(m==0){
    return 0;
  }
  if (arr[m-1]<=x){
    cout<<x<<" ";
    return dp(arr,x-arr[m-1],m);//+dp(arr,x,m-1);
  }
  else{
    //cout<<arr[m-1]<<" ";
    return dp(arr,x,m-1);
  }*/
  ll t[m+1][n+1];
  rep(i,0,m+1){
    t[i][0]=1;
  }
  rep(j,1,n+1){
    t[0][j]=0;
  }
  rep(i,1,m+1){
    rep(j,1,n+1){
      if (arr[i-1]<=j)
        t[i][j]=t[i][j-arr[i-1]] + t[i-1][j];
      else
        t[i][j]=t[i-1][j];
    }
  }
  return t[m][n];
}

int main()
{
	kush_gupta();
	ll x=0;
  ll n=0;
  cin>>x>>n;
  vll arr(11);
  rep(i,1,11){
    arr[i-1]=pow(i,n);
  }
   rep(i,1,11){
     cout<<arr[i-1]<<" ";
   }
   cout<<endl;
  cout<<dp(arr,x,10);
	return 0;
}