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

ll count_subarrays(ll n,const vll &a){
  ll toReturn = 1;
  vll res(n);
  res[0]=1;
  rep(i,1,n){
  	res[i]=1;
  	if(a[i]>=a[i-1]){
  		res[i]+=res[i-1];
  	}
  	toReturn+=res[i];
  }
  return toReturn;
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    cin>>n;
    vll a(n);
    rep(i,0,n){
      cin>>a[i];
    }
    ll res=count_subarrays(n,a);
    cout<<res<<endl;
  }
	return 0;
}