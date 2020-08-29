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

bool comp(ll x,ll y){
  return x>y;
}

int main()
{
	kush_gupta();
	ll n=0,k=0,s=0,i=0;
  cin>>n>>k>>s;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  sort(a.begin(), a.end(),comp);
  ll sum=0;
  for (i=0;i<k+1;i++){
    sum+=a[i];
  }
  for (i=k+1;i<n;i++){
    if(sum>s){
      break;
    }
    sum+=a[i];
  }
  if(sum>s){
    cout<<i;
  }
  else{
    cout<<-1;
  }
	return 0;
}