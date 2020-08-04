# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define MOD 1000000009
# define max_input 10000001

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}
vll t(max_input,-1);
ll filled=2;
ll dp_solve(ll n){
  if(t[n]!=-1){
    return t[n];
  }
  rep(i,filled,n+1){
    if(i>=3){
      t[i]=(t[i-3]+t[i-2])%MOD;
    }
  }
  filled=n;
  return t[n]%MOD;
}

int main()
{
	kush_gupta();
  t[0]=1;
  t[1]=0;
  t[2]=1;
	w(test_cases){
    ll x=0;
    cin>>x;
    ll res=dp_solve(x);
    cout<<res<<endl;
  }
	return 0;
}