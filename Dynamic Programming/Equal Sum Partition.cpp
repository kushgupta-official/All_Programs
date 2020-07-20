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

bool subset_sum_dp(ll sum,const vll &arr,ll n){
  bool a[n+1][sum+1];
  for (ll i=0;i<n+1;i++){
      if (i==0){
        a[i][0]=1;
      }
    }
    for (ll j=1;j<sum+1;j++){
      if (j==0){
        a[0][j]=0;
      }
    }
  for (ll i=1;i<n+1;i++){
    for (ll j=1;j<sum+1;j++){
      if (arr[i-1]<=j){
        a[i][j]=a[i-1][j-arr[i-1]] || a[i-1][j];
      }
      else{
        a[i][j]=a[i-1][j];
      }
    }
  }
  return a[n][sum];
}


bool equal_sum_partition(const vll &arr,ll n){
  ll sum=0;
  for (ll i=0;i<n;i++)
    sum+=arr[i];
  if (sum%2==0){
    return subset_sum_dp(sum/2,arr,n);
  }
  else{
    return 0;
  }
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    cin>>n;
    vll arr(n);
    for (ll i=0;i<n;i++){
      cin>>arr[i];
    }
    if(equal_sum_partition(arr,n)){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
	return 0;
}