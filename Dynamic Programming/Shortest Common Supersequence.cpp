//link : https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
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

ll lcs(ll n,ll m,string st1,string st2){
  ll t[n+1][m+1];
  rep(i,0,n+1){
    t[i][0]=0;
  }
  rep(j,0,m+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,1,m+1){
      if (st1[i-1]==st2[j-1]){
        t[i][j]=t[i-1][j-1]+1;
      }
      else{
        t[i][j]=max(t[i-1][j],t[i][j-1]);
      }
    }
  }
  /*rep(i,0,n+1){
    rep(j,0,m+1){
      cout<<t[i][j]<<" ";
    }
    cout<<endl;
  }*/
  return t[n][m];
}

int main()
{
	kush_gupta();
  w(test_cases){
    string st1,st2;
    cin>>st1>>st2;
    ll n=st1.length();
    ll m=st2.length();
    cout<<n+m-lcs(n,m,st1,st2)<<endl;
  }	
	return 0;
}