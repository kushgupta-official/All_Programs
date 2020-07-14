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
    ll k=0;
    cin>>k;
    for (ll i=0;i<8;i++){
      for (ll j=0;j<8;j++){
        if (i==0 && j==0){
          cout<<'O';
          k--;
        }
        else if (k!=0){
          cout<<'.';
          k--;
        }
        else{
          cout<<'X';
        }
      }
      cout<<endl;
    }
  }
	return 0;
}