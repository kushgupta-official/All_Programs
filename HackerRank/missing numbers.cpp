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
	ll n=0,m=0;
  cin>>n;
  vll arr(n);
  rep(i,0,n){
    cin>>arr[i];
  }
  cin>>m;
  vll brr(m);
  rep(i,0,m){
    cin>>brr[i];
  }

  sort (arr.begin(), arr.end());
  sort (brr.begin(), brr.end());
  set <ll> s;
    for (ll i=0,j=0;j<m;j++){
      if (i>=n || brr[j]!=arr[i]){
        // cout<<brr[j]<<" ";
        s.insert(brr[j]);
      }
      else{
        i++;
      }
    }
  for (auto i:s){
    cout<<i<<" ";
  }
	return 0;
}