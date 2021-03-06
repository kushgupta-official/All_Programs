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

ll lcs(ll n,string a){
  string b=a;
  reverse(b.begin(), b.end());
  if(b==a){
    return 0;
  }
  ll t[n+1][n+1];
  rep(i,0,n+1){
    t[i][0]=0;
  }
  rep(j,0,n+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,1,n+1){
      if(a[i-1]==b[j-1]){
        t[i][j]=t[i-1][j-1]+1;
      }
      else{
        t[i][j]=max(t[i-1][j],t[i][j-1]);
      }
    }
  }
  return n-t[n][n];
}

int main()
{
	kush_gupta();
	w(test_cases){
    string a;
    cin>>a;
    cout<<lcs(a.length(),a)<<endl;
  }
	return 0;
}