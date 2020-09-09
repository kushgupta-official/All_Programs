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
    ll n=0,flag=1;
    cin>>n;
    vll arr(n);
    ll temp=0,count=0,same=1,count2=0;
    rep(i,0,n){
      cin>>arr[i];
      if(arr[i]==0){
        temp++;
      }
      else{
        if(temp>count){
          count2=count;
          count=temp;
          flag=1;
        }
        else if(temp==count){
          flag=0;
          same++;
        }
        temp=0;
      }
    }
    if(flag==1){
      if(count%2==0){
        cout<<"No\n";
      }
      else if(count%2==1 && count2<(count+1)/2){
        cout<<"Yes\n";
      }
      else{
        cout<<"No\n";
      }
    }
    else{
      cout<<"No\n";
    }
   }
	return 0;
}