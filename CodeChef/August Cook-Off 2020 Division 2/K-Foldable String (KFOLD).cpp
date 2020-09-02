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
    ll n=0,k=0;
    cin>>n>>k;
    string s;
    cin>>s;
    ll number_of_0s=0,number_of_1s=0;
    rep(i,0,n){
      if(s[i]=='0'){
        number_of_0s++;
      }
      else{
        number_of_1s++;
      }
    }
    ll n_of_segmets=n/k;
    if(number_of_0s%n_of_segmets==0 && number_of_1s%n_of_segmets==0){
      ll temp0=number_of_0s/n_of_segmets;
      ll temp1=number_of_1s/n_of_segmets;
      for (ll i=0;i<n_of_segmets;i++){
        if(i%2==0){
            for (ll j=0;j<temp0;j++){
              cout<<0;
            }
            for (ll j=0;j<temp1;j++){
              cout<<1;
            }
        }
        else{
            for (ll j=0;j<temp1;j++){
              cout<<1;
            }
            for (ll j=0;j<temp0;j++){
              cout<<0;
            }
        }
      }
    }
    else{
      cout<<"IMPOSSIBLE";
    }
    cout<<endl;
  }
	return 0;
}