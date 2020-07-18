//Problem : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
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

ll knapsack(ll n,ll w,vll &values,vll &weights){
  ll t[n+1][w+1];
  for (ll i=0;i<=n;i++){
    for (ll j=0;j<=w;j++){
        if (i==0 || j==0){
            t[i][j]=0;
            continue;
        }
        if (j>=weights[i-1]){
          t[i][j]=max(values[i-1] + t[i-1][j-weights[i-1]],
                        t[i-1][j]);
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
    cin>>n;
    ll w=0;
    cin>>w;
    vll values(n);
    vll weights(n);
    rep(i,0,n){
      cin>>values[i];
    }
    rep(i,0,n){
      cin>>weights[i];
    }
    ll res=knapsack(n,w,values,weights);
    cout<<res<<endl;
  }
  return 0;
}