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

bool comp(pair <pair <ll,ll>,ll> p1, pair <pair <ll,ll>,ll> p2){
  return p1.first.second<p2.first.second;
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    cin>>n;
    vpp t(n);
    rep(i,0,n){
      cin>>t[i].first.first;
      t[i].second=i+1;
    }
    rep(i,0,n){
      cin>>t[i].first.second;
    }
    sort(t.begin(), t.end(),comp);
    ll next=0;
    rep(i,0,n){
      if(t[i].first.first>=next){
        cout<<t[i].second<<" ";
        next=t[i].first.second;
      }
    }
    cout<<endl;
  }
	return 0;
}