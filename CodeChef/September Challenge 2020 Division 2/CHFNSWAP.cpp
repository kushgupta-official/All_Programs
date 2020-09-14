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
	w(test_cases){
    ll n=0;
    cin>>n;
    vll arr(n+1),sl(n+1,0),sr(n+1,0);
    for (ll i=1;i<=n;i++){
      arr[i]=i;
      sl[i]+=sl[i-1]+arr[i];
    }
    for (ll i=n,j=1;i>0;i--,j++){
      sr[j]+=sr[j-1]+arr[i];
    }
    rep(i,1,n+1){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    rep(i,1,n+1){
      cout<<sl[i]<<" ";
    }
    cout<<endl;
    rep(i,1,n+1){
      cout<<sr[i]<<" ";
    }
    cout<<endl;
    ll res=0;
    for (ll m=1;m<n;m++){
      if(sl[m]==sr[n-m]){
        res++;
      }
    }
    cout<<endl<<res<<endl<<endl;
  }
	return 0;
}