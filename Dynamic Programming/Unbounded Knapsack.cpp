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

/*ll naive_unbounded_knapsack(ll n,ll w,const vll &values,const vll &weights){
  if (n==0 || w==0){
    return 0;
  }
  if (weights[n-1]<=w){
    return max(values[n-1] + naive_unbounded_knapsack(n,w-weights[n-1],values,weights)
                ,naive_unbounded_knapsack(n-1,w,values,weights));
  }
  else{
    return naive_unbounded_knapsack(n-1,w,values,weights);
  }
}*/

ll dp_unbounded_knapsack(ll n,ll w,const vll &values,const vll &weights){
  ll t[n+1][w+1];
  rep(i,0,n+1){
    t[i][0]=0;
  }
  rep(j,0,w+1){
    t[0][j]=0;
  }
  rep(i,1,n+1){
    rep(j,1,w+1){
      if (weights[i-1]<=j){
        t[i][j]=max(values[i-1]+t[i][j-weights[i-1]],t[i-1][j]);
      }
      else{
        t[i][j]=t[i-1][j];
      }
    }
  }
  return t[n][w];
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    ll w=0;
    cin>>n>>w;
    vll values(n),weights(n);
    rep(i,0,n){
      cin>>values[i];
    }
    rep(i,0,n){
      cin>>weights[i];
    }
    ll res=dp_unbounded_knapsack(n,w,values,weights);
    cout<<res<<endl;
  }
	return 0;
}