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

ll t[1001][1001];

ll mcm(const vll &arr,ll i,ll j){
  if (i>=j){
    return 0;
  }
  if(t[i][j]!=-1){
    return t[i][j];
  }
  ll mn=INT_MAX;
  for (ll k=i;k<=j-1;k++){
    ll temp_ans=mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
    if(temp_ans<mn){
      mn=temp_ans;
    }
  }
  return t[i][j]=mn;
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    cin>>n;
    vll arr(n);
    rep(i,0,n){
      cin>>arr[i];
    }
    memset(t,-1,sizeof(t));
    ll res=mcm(arr,1,n-1);
    cout<<res<<endl;
  }
	return 0;
}