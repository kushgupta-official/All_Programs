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
  map <ll,ll> mp;
  cin>>n;
  vll v(n);
  rep(i,0,n){
    cin>>v[i];
  }
  cin>>m;
  ll temp=0;
  rep(i,0,m){
    cin>>temp;
    mp[temp]++;
  }
  vll missing;
  rep(i,0,n){
    if(mp[v[i]]>1){
      mp[v[i]]--;
    }
    else if(mp[v[i]]>0){
      mp.erase(v[i]);
    }
    else{
      missing.push_back(v[i]);
    }
  }
  for (auto ite:mp){
    missing.push_back(ite.first);
  }
  sort(missing.begin(), missing.end());
  for (ll i=0;i<missing.size();i++){
    cout<<missing[i]<<" ";
  }
	return 0;
}