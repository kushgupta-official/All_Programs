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

string scs(ll n,ll m,string a,string b){
  ll t[n+1][m+1];
  rep(i,0,n+1){
    t[i][0]=0;
  }
  rep(j,0,m+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,1,m+1){
      if(a[i-1]==b[j-1]){
        t[i][j]=t[i-1][j-1]+1;
      }
      else{
        t[i][j]=max(t[i-1][j],t[i][j-1]);
      }
    }
  }
  //cout<<t[n][m];
  string toReturn;
  ll i=n,j=m;
  while(i>0 && j>0){
    if(a[i-1]==b[j-1]){
      toReturn.push_back(a[i-1]);
      i--;
      j--;
    }
    else if(t[i-1][j]>t[i][j-1]){
      toReturn.push_back(a[i-1]);
      i--;
    }
    else{
      toReturn.push_back(b[j-1]);
      j--;
    }
  }
  while(i>0){
    toReturn.push_back(a[i-1]);
    i--;
  }
  while(j>0){
    toReturn.push_back(b[j-1]);
    j--;
  }
  reverse(toReturn.begin(), toReturn.end());
  return toReturn;
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0,m=0;
    cin>>n>>m;
    string str1,str2;
    cin>>str1>>str2;
    cout<<scs(n,m,str1,str2)<<endl;
  }
	return 0;
}