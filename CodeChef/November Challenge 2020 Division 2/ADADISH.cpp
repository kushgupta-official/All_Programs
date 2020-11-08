# include <bits/stdc++.h>
# define ll long long int

using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

bool comp(ll a,ll b){
  return a>b;
}

int main()
{
  kush_gupta();
  ll t=0;
  cin>>t;
  while(t--){
    ll solution=-1;
    ll n=0;
    cin>>n;
    vector<ll> arr(n+1);
    for (ll i=1;i<=n;i++){
      cin>>arr[i];
    }
    sort(arr.begin(), arr.end(),comp);
    if (n==1 || n==2){
      solution=arr[0];
    }
    else if (n==3){
      solution=max(arr[0],arr[1]+arr[2]);
    }
    else{
      ll res=INT_MAX;
      res=min(res,max(arr[0],arr[1]+arr[2]+arr[3]));
      res=min(res,max(arr[0]+arr[2],arr[1]+arr[3]));
      res=min(res,max(arr[0]+arr[1],arr[2]+arr[3]));
      res=min(res,max(arr[0]+arr[3],arr[1]+arr[2]));
      res=min(res,max(arr[0]+arr[2]+arr[3],arr[1]));
      solution=res;
    }
    cout<<solution<<endl;
  }
  return 0;
}