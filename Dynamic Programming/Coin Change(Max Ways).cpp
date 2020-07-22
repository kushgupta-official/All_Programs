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

ll coin_change(ll m,const vll &arr,ll n){
  //cout<<m<<" "<<n<<endl;
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
  /*rep(i,0,m+1){
    rep(j,0,n+1){
      cout<<t[i][j]<<" ";
    }
    cout<<endl;
  }*/
  return t[m][n];
}

int main()
{
	kush_gupta();
	w(test_cases){
		ll m=0;
    cin>>m;
    vll arr(m);
    rep(i,0,m){
      cin>>arr[i];
    }
    ll n=0;
    cin>>n;
    ll res=coin_change(m,arr,n);
    cout<<res<<endl;
	}
	return 0;
}