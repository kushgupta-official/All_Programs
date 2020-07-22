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

ll main_func(ll v,ll n,const vll &c){
  ll t[n+1][v+1];
  rep(i,1,n+1){
    t[i][0]=0;
  }
  rep(j,0,v+1){
    t[0][j]=INT_MAX-1;
  }
  rep(i,1,n+1){
    rep(j,1,v+1){
      if (c[i-1]<=j)
        t[i][j]=min(1+t[i][j-c[i-1]],t[i-1][j]);
      else
        t[i][j]=t[i-1][j];
    }
  }
  if (t[n][v]==)
  return t[n][v];
}
//2147483646
int main()
{
	kush_gupta();
	w(test_cases){
		ll v=0,n=0;
    cin>>v>>n;
    vll c(n);
    rep(i,0,n){
      cin>>c[i];
    }
    ll res=main_func(v,n,c);
    cout<<res<<endl;
	}
	return 0;
}