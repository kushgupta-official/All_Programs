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
    ll n=0;
    cin>>n;
    vll a(n),b(n);
    rep(i,0,n){
      cin>>a[i];
    }
    rep(i,0,n){
      cin>>b[i];
    }
    map <ll,ll> mp,mpa,mpb;
    rep(i,0,n){
      mp[a[i]]++;
      mp[b[i]]++;
      mpa[a[i]]++;
      mpb[b[i]]++;
    }
    int flag=0;
    for (auto ite : mp){
      if (ite.second%2!=0){
        flag=1;
        break;
      }
    }
    if (flag==1){
      cout<<-1<<endl;
      continue;
    }
    else{
      vll ans;
      ll res=0;
      for (auto ite : a)
    }
  }
	return 0;
}