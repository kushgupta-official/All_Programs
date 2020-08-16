//non verified
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
	ll n=0;
  cin>>n;
  vll arr(n);
  ll np=0,nn=0,z=0,min=INT_MAX,max=INT_MIN,mi=-1,prod=1;
  rep(i,0,n){
    cin>>arr[i];
    if(arr[i]<0){
      nn++;
      if(arr[i]>max){
        max=arr[i];
        mi=i;
      }
    }
    else if(arr[i]>0){
      np++;
      if(arr[i]<min){
        min=arr[i];
      }
    }
    else{
      z++;
    }
  }
  if(nn==0 && z==0){
    cout<<min<<endl;
  }
  else if(nn==0 && z!=0){
    cout<<0<<endl;
  }
  else{
    if(nn%2==0){
      rep(i,0,n){
        if(arr[i]!=0 && i!=mi){
          prod*=arr[i];
        }
      }
    }
    else{
      rep(i,0,n){
        if(arr[i]!=0){
          prod*=arr[i];
        }
      }
    }
    cout<<prod<<endl;
  }
	return 0;
}