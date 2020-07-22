//link: https://practice.geeksforgeeks.org/problems/longest-common-substring/0

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

ll longest_common_substring(ll n,ll m,string st1,string st2){
  ll t[n+1][m+1];
  rep(i,0,n+1){
    t[i][0]=0;
  }
  rep(j,0,m+1){
    t[0][j]=0;
  }
  ll mx=-1;
  rep(i,1,n+1){
    rep(j,1,m+1){
      if(st1[i-1]==st2[j-1]){
        t[i][j]=1+t[i-1][j-1];
      }
      else{
        t[i][j]=0;
      }
      mx=max(mx,t[i][j]);
    }
  }
  /*rep(i,1,n+1){
    rep(j,1,m+1){
      cout<<t[i][j]<<" ";
    }
    cout<<endl;
  }*/
  return mx;
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0,m=0;
    cin>>n>>m;
    string st1,st2;
    cin>>st1>>st2;
    cout<<longest_common_substring(n,m,st1,st2)<<endl;
  }
	return 0;
}