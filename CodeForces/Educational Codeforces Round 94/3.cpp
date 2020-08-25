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

int main()
{
	kush_gupta();
	w(test_cases){
    string s,w;
    cin>>s;
    ll n=s.length();
    rep(i,0,n){
      w.pb('2');
    }
    ll x=0;
    cin>>x;
    x--;
    for (ll i=0;i<s.length();i++){
      if(s[i]=='1' && i>x){
        w[i-x]='1';
      }
      else if(s[i]=='1' && i+x<n){
        w[i+x]='1';
      }
      else{
        w[i]='0';
      }
    }
    ll flag=0;
    rep(i,0,n){
      if(w[i]=='2'){
        flag=1;
      }
    }
    cout<<w<<endl;
    if(flag==1){
      cout<<-1<<endl;
    }
    else{
      cout<<w<<endl;
    }
  }
	return 0;
}