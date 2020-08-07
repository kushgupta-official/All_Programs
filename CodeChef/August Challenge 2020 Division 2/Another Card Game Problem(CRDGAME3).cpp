# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
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

vll arr(9);
ll n=9;

ll subset_sum(vll &arr,ll n,ll sum){
  if(n==0){
    return 0;
  }
  if (sum==0){
    return 0;
  }
  if(arr[n-1]<=sum){
    return 1+subset_sum(arr,n,sum-arr[n-1]);
  }
  else{
    return subset_sum(arr,n-1,sum);
  }
}
ll t[10][1000001];
ll done=0;
ll dp_subset_sum(vll &arr,ll n,ll sum){
  if(t[n][sum]!=-1){
    return t[n][sum];
  }
  rep(j,done-1,sum+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,done+1,sum+1){
      if(arr[i-1]<=j){
        t[i][j]=1+t[i][j-arr[i-1]];
      }
      else{
        t[i][j]=t[i-1][j];
      }
    }
  }
  done=sum;
  return t[n][sum];
}

int main()
{
	kush_gupta();
  rep(i,1,10){
    arr[i-1]=i;
  }
  memset(t,-1,sizeof(t));
  rep(i,0,n+1){
    t[i][0]=0;
  }
	w(test_cases){
    ll pc=0,pr=0;
    cin>>pc>>pr;

    ll x=dp_subset_sum(arr,n,pc);
    ll y=dp_subset_sum(arr,n,pr);

    if (x<y){
      cout<<0<<" "<<x<<endl;
    }
    else{
      cout<<1<<" "<<y<<endl;
    }
  }
	return 0;
}