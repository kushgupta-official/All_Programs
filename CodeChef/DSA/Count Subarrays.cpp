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

/*ll count_subarrays(ll n,ll m,const vll &a,const vll &b){
  if(n==0 || m==0){
    return 0;
  }
  if(a[n-1]==b[m-1]){
    return 1+count_subarrays(n-1,m-1,a,b);
  }
  else{
    return max(count_subarrays(n-1,m,a,b),count_subarrays(n,m-1,a,b));
  }
}*/
ll count_subarrays(ll n,const vll &a){
  ll t[n],sum=1;
  t[0]=1;
  rep(i,1,n){
    if(a[i-1]<=a[i]){
      t[i]+=t[i-1]+1;
    }
   sum+=t[i];
  }
  return sum;
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
    ll m=n;
    /*vll b=a;
    sort(b.begin(), b.end());
*/
    ll res=count_subarrays(n,a);
    cout<<res<<endl;
  }
	return 0;
}