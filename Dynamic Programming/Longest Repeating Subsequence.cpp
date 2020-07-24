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

ll lrs(ll n,string str){
  ll t[n+1][n+1];
  rep(i,0,n+1){
    t[i][0]=0;
  }
  rep(j,0,n+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,1,n+1){
      if(str[i-1]==str[j-1] && i!=j){
        t[i][j]=1+t[i-1][j-1];
      }      
      else{
        t[i][j]=max(t[i-1][j],t[i][j-1]);
      }
    }
  }
  return t[n][n];
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    cin>>n;
    string str;
    cin>>str;
    cout<<lrs(n,str)<<endl;
  }
	return 0;
}