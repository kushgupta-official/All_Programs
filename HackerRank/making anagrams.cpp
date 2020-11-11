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

ll lcs(string st1,ll a,string st2,ll b){
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
  return t[a][b];
}

int main()
{
	kush_gupta();
	string s1;
  string s2;
  cin>>s1>>s2;
  vll a(26,0),b(26,0);
  rep(i,0,s1.size()){
    a[s1[i]-'a']++;
  }
  rep(i,0,s2.size()){
      a[s2[i]-'a']--;
  }
  ll res=0;
  rep(i,0,26){
    res+=abs(a[i]);
  }
  cout<<res;
}