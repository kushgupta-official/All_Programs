# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)

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
    ll n=0;
    cin>>n;
    ll a=0,b=0;
    ll sum_a=0,sum_b=0;
    ll win_a=0,win_b=0;
    rep(i,0,n){
      cin>>a>>b;
      if (a>b){
        for (sum_b=0;b!=0;sum_b+=b%10,b/=10);
        //  cout<<sum_b<<endl;
        for (sum_a=0;a!=0;sum_a+=a%10,a/=10){
          if (sum_a>sum_b){
            break;
          }
        }
      //  cout<<sum_a<<endl;
      }
      else{
        for (sum_a=0;a!=0;sum_a+=a%10,a/=10);
        //  cout<<sum_a<<endl;
        for (sum_b=0;b!=0;sum_b+=b%10,b/=10){
          if (sum_b>sum_a){
            break;
          }
        }
      //  cout<<sum_b<<endl;
      }
      if (sum_a>sum_b){
          win_a++;
        }
      else if (sum_a<sum_b){
          win_b++;
        }
      else{
          win_a++;
          win_b++;
        }
    }
    if(win_a>win_b){
      cout<<0<<" "<<win_a<<endl;
    }
    else if (win_b>win_a){
      cout<<1<<" "<<win_b<<endl;
    }
    else{
      cout<<2<<" "<<win_a<<endl;
    }
  }
	return 0;
}