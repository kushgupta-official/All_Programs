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

ll matrix[65][65];

void transpose(ll n){
  for (ll i=1;i<=n;i++){
    for (ll j=i+1;j<=n;j++){
      swap(matrix[i][j],matrix[j][i]);
    }
  }
}

bool condition(ll n){
  for (ll i=2;i<=n;i++){
    if(matrix[1][i]!=i){
      return true;
    }
  }
  return false;
}

int main()
{
	kush_gupta();
	w(test_cases){
    memset(matrix,0,65*65);
    ll n=0;
    cin>>n;
    bool flag=1;
    rep(i,1,n+1){
      rep(j,1,n+1){
        cin>>matrix[i][j];
        if (matrix[i][j]!=(i-1)*n+j){
          flag=0;
        }
      }
    }
    ll ans=0;
    ll curr=1;
    if(!flag){
    while(condition(n)){
      ans++;
      ll j=2,i=2;
      if(matrix[1][j]==j){
        while(j<=n && matrix[1][j]==j){
          j++;
        }
        curr=j-1;
      }
      else{
        while(i<=n && matrix[i][1]==i){
          i++;
        }
        curr=i-1;
      }
      transpose(curr);
    }
    cout<<ans<<endl;
    }
    else{
      cout<<0<<endl;
    }
  }
	return 0;
}