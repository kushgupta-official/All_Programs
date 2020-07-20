//Check whether a subset exist in a given array whose sum of elements id equal to the given value.
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

bool subset_sum(ll sum,const vll &arr, ll n){
  if (sum<0 || n<0){
    return 0;
  }
  if (sum==0){
    //cout<<"hi";
    return 1;
  }
  if (arr[n-1]<=sum){
    if(!subset_sum(sum-arr[n-1],arr,n-1)){
      subset_sum(sum,arr,n-1);
    }
    else{
      return 1;
    }
  }
  else{
    subset_sum(sum,arr,n-1);
  }
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

int main()
{
	kush_gupta();
	w(test_cases){
    ll sum=0;
    cin>>sum;
    ll n=0;
    cin>>n;
    vll arr(n);
    rep(i,0,n){
      cin>>arr[i];
    }
    bool res2=subset_sum_dp(sum,arr,n);
    bool res=subset_sum(sum,arr,n);
    cout<<res<<endl;
    cout<<res2<<endl;
  }
	return 0;
}