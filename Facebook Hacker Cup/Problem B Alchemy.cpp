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
	ll test_cases=0;
  cin>>test_cases;
  rep(i,0,test_cases){
    cout<<"Case #"<<i+1<<": ";
    ll n=0;
    cin>>n;
    string s;
    cin>>s;
    ll a=0,b=0;
    rep(i,0,s.length()){
      if(s[i]=='A'){
        a++;
      }
      else{
        b++;
      }
    }
    if(a<(n/2) || b<(n/2)){
      cout<<"N\n";
    }
    else{
      cout<<"Y\n";
    }
  }
	return 0;
}