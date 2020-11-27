# include <bits/stdc++.h>
 
using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)
 
void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}
 
int main()
{
  kush_gupta();
  string s;
  cin>>s;
  vector <ll> v(26,0);
  for (ll i=0;i<s.size();i++){
    v[s[i]-'A']++;
  }
  ll countOfOdd=0;
  ll oddChar;
  for (ll i=0;i<26;i++){
    if(v[i]%2!=0 && countOfOdd==0){
      countOfOdd=1;
      oddChar=i;
    }
    else if(v[i]%2!=0 && countOfOdd==1){
      cout<<"NO SOLUTION";
     return 0;
    }
  }
  string res; res=s;
  ll x=0,y=s.size()-1;
  for (ll i=0;i<26;i++){
    if(countOfOdd==0 || i!=oddChar){
      while(v[i]!=0){
        res[x++]='A'+i;
        res[y--]='A'+i;
        v[i]-=2;
      }
    }
  }
  if(countOfOdd==1){
    while(v[oddChar]!=0){
      res[x++]='A'+oddChar;
      v[oddChar]--;
    }
  }
  cout<<res;
  return 0;
}