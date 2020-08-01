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
	ll n=0;
  ll m=0;
  cin>>n>>m;
  ll sum=(n*(n+1))/2;
  ll first=1;
  ll last=n;
  while(m--){
    ll temp=0;
    cin>>temp;
    if ((temp>1 && temp<n) || temp==first || temp==last){
      swap(first,last);
    }
    else{
      sum-=last;
      last=temp;
      sum+=temp;
    }
    cout<<sum<<endl;
  }
	return 0;
}