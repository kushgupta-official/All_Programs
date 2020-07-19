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
	w(test_cases){
    ll n=0;
    cin>>n;
    set <char> str;
    for (ll i=0;i<n;i++){
      char temp;
      cin>>temp;
      if (str.find(temp)==str.end()){
        str.insert(temp);
      }
      else{
        str.erase(temp);
      }
    }
    if (str.empty()){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
	return 0;
}