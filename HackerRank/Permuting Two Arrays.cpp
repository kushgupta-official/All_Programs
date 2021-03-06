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

bool comp(ll a,ll b){
  return a>b;
}

int main()
{
	kush_gupta();
	w(q){
    ll n=0,k=0;
    cin>>n>>k;
    vll a(n),b(n);
    rep(i,0,n){
      cin>>a[i];
    }
    rep(i,0,n){
      cin>>b[i];
    }
    sort (a.begin(), a.end());
    sort (b.begin(), b.end(),comp);
    bool flag=1;
    rep(i,0,n){
      if (a[i]+b[i]<k){
        flag=0;
        break;
      }
    }
    if (flag){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
	return 0;
}