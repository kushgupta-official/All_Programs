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

string dp_lcs(ll a,ll b,string st1,string st2){
  ll t[a+1][b+1];
  rep(i,0,a+1){
    t[i][0]=0;
  }
  rep(j,0,b+1){
    t[0][j]=0;
  }
  rep(i,1,a+1){
    rep(j,1,b+1){
      if (st1[i-1]==st2[j-1]){
        t[i][j]=1+t[i-1][j-1];
      }
      else{
        t[i][j]=max(t[i-1][j],t[i][j-1]);
      }
    }
  }
  string toReturn;
  ll i=a,j=b;
  while(i>0 && j>0){
    if (st1[i-1]==st2[j-1]){
      toReturn.push_back(st1[i-1]);
      //cout<<toReturn<<endl;
      i--;
      j--;
    }
    else if (t[i-1][j]>t[i][j-1]){
      i--;
    }
    else{
      j--;
    }
  }
  reverse(toReturn.begin(), toReturn.end());
  return toReturn;
}

int main()
{
  kush_gupta();
  w(test_cases){
    ll a=0,b=0;
    cin>>a>>b;
    string st1,st2;
    cin>>st1>>st2;
    cout<<dp_lcs(a,b,st1,st2)<<endl;
  }
  return 0;
}