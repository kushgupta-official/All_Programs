//Count number of subsets whose difference comes out to be given value.
//similar question : https://leetcode.com/problems/target-sum/
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

ll count_subset(ll n,const vll &arr,ll sum){
  ll t[n+1][sum+1];
  rep(i,0,n+1){
    t[i][0]=1;
  }
  rep(j,1,sum+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,1,sum+1){
      if (arr[i-1]<=j){
        t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
      }
      else{
        t[i][j]=t[i-1][j];
      }
    }
  }
  return t[n][sum];
}
//3+3+1
//4+2+1
//4+3
//4+3
ll main_function(ll n,const vll &arr,ll sum,ll diff){
  ll sum2=(diff+sum)/2;
  return count_subset(n,arr,sum2);
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    cin>>n;
    ll sum=0;
    vll arr(n);
    rep(i,0,n){
      cin>>arr[i];
      sum+=arr[i];
    }
    ll diff=0;
    cin>>diff;
    ll res=main_function(n,arr,sum,diff);
    cout<<res<<endl;
  }
	return 0;
}