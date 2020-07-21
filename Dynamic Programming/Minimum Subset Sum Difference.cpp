# include <bits/stdc++.h>

using namespace std;
# define ll long long
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

vll subset_sum(ll n,const vll &a,ll sum){
  bool t[n+1][sum+1];
  rep(i,0,n+1){
    t[i][0]=1;
  }
  rep(j,1,sum+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,1,sum+1){
      if(a[i-1]<=j){
        t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
      }
      else{
        t[i][j]=t[i-1][j];
      }
    }
  }
  vll toreturn;
  for (ll j=0;j<=sum/2;j++){
    if (t[n][j]==1){
      toreturn.push_back(j);
    }
  }
  return toreturn;
}

ll main_function(ll n,const vll &a,ll sum){
  vll arr=subset_sum(n,a,sum);
  ll mn=sum+1;
  rep(i,0,arr.size()){
    mn=min(mn,sum-(2*arr[i]));
  }
  return mn;
}

int main()
{
	kush_gupta();
  w(test_cases){
    ll n=0;
    cin>>n;
    vll a(n);
    ll sum=0;
    rep(i,0,n){
      cin>>a[i];
      sum+=a[i];
    }
    ll res=main_function(n,a,sum);
    cout<<res<<endl;
  }
	return 0;
}