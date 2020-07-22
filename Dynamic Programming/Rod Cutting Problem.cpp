//https://practice.geeksforgeeks.org/problems/rod-cutting/0/
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
		cin>>n;
		vll length(n),price(n);
		rep(i,0,n){
			length[i]=i+1;
			cin>>price[i];
		}
		ll res=dp_unbounded_knapsack(n,n,price,length);
		cout<<res<<endl;
	}
	return 0;
}