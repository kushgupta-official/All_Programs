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

int main()
{
	kush_gupta();
	string s="BBBAABAABAB";
  string toPrint=s.substr(0,s.length()-3);
  ll a=0,b=0;
  rep(i,s.length()-3,s.length()){
          if(s[i]=='A'){
            a++;
          }
          else{
            b++;
          }
        }
  cout<<a<<" "<<b<<" "<<toPrint;
	return 0;
}