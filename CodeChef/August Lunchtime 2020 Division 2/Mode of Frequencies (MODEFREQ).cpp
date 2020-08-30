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
    ll n=0;
    cin>>n;
    vll arr(n);
    vll frequencies(11,0);
    rep(i,0,n){
      cin>>arr[i];
      frequencies[arr[i]]++;
    }
    vll n_of_frequencies(10002,0);
    rep(i,1,11){
      if(frequencies[i]!=0){
        n_of_frequencies[frequencies[i]]++;
      }
    }
    ll mx=INT_MIN,mn=INT_MAX,mx_id=-1,mn_id=-1;
    rep(i,1,10002){
      if(n_of_frequencies[i]>mx){
        mx=n_of_frequencies[i];
        mx_id=i;
      }
    }
    cout<<mx_id;
    cout<<endl;
  }
	return 0;
}