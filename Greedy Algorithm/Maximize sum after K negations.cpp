# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
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

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0,k=0;
    cin>>n>>k;
    vll v(n);
    ll temp=0,sum=0;
    rep(i,0,n){
      cin>>v[i];
      sum+=v[i];
    }
    sort(v.begin(), v.end());
    ll j=0;
    rep(i,0,k){
      if(v[j]<0){
        sum-=v[j];
        sum+=v[j]*-1;
        v[j]*=-1;
        if(v[j+1]<=0 || (v[j+1]>0 && v[j]<0))
          j++;
        if(j>n-1){
          j=n-1;
        }
      }
      else if(v[j]==0){
        break;
      }
      else{
        if(j>0 && v[j]>v[j-1]){
          sum-=v[j-1];
          v[j-1]*=-1;
          sum+=v[j-1];
        }
        else{
          sum-=v[j];
          v[j]*=-1;
          sum+=v[j];
        }
      }
    }
    cout<<sum<<endl;
  }
	return 0;
}