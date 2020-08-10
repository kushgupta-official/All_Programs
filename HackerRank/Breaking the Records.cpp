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
	ll n=0;
  cin>>n;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  ll min=a[0],max=a[0],c_min=0,c_max=0;
  rep(i,1,n){
    if(a[i]<min){
      min=a[i];
      c_min++;
    }
    else if (a[i]>max){
      max=a[i];
      c_max++;
    }
  }
  cout<<c_max<<" "<<c_min;
	return 0;
}