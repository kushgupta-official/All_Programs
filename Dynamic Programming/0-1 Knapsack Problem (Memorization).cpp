//Problem : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vectorx<int>
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
vector <vector <ll> > t (1001, vector <ll> (1001,-1));
ll knapsack(ll n,ll w,vll &values,vll &weights){
  if (n==0 || w==0){
    return 0;
  }
  if (t[n][w]!=-1){
    return t[n][w];
  }
  if (w>=weights[n-1]){
    return t[n][w]=max(values[n-1] + knapsack(n-1,w-weights[n-1],values,weights)
                ,knapsack(n-1,w,values,weights));
  }
  else if (w<weights[n-1]){
    return t[n][w]=knapsack(n-1,w,values,weights);
  }
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
    for (ll i=0;i<1001;i++){
      for (ll j=0;j<1001;j++){
        t[i][j]=-1;
      }
    }
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