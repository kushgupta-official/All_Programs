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
	ll n=0,k=0;
  cin>>n>>k;
  vll a(n),b(k,0);
  rep(i,0,n){
    cin>>a[i];
    b[a[i]%k]++;
  }
  ll count=0;
  count+=(b[0]*(b[0]-1))/2;
  for (ll i=1;i<=k/2 && i!=k-i;i++){
    count+=b[i]*b[k-i];
  }
  if(k%2==0){
    count+=(b[k/2]*(b[k/2]-1))/2;
  }
  cout<<count;
	return 0;
}