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
    vll a(n);
    vll b(n);
    rep(i,0,n){
      cin>>a[i]>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll res=0;
    rep(i,0,n){
      if (a[i]!=b[i]){
        if (a[i]<b[i]){
          auto ite=upper_bound(b.begin()+i+1, b.end(),b[i]);
          cout<<*(--ite)<<endl;
          if (*ite==a[i]){
            swap(*ite,a[i]);
            cout<<"hi";
            res+=a[i];
          }
          else{
            res=-1;
            break;
          }
        }
        else{
         auto ite=upper_bound(a.begin()+i+1, a.end(),a[i]);
         cout<<*(--ite)<<endl;
          if (*ite==b[i]){
            swap(*ite,b[i]);
            cout<<"hi";
            res+=b[i];
          }
          else{
            res=-1;
            break;
          } 
        }
      }
    }
    rep(i,0,n){
      cout<<a[i]<<" ";
    }
    cout<<endl;
    rep(i,0,n){
      cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<res<<endl;
  }
	return 0;
}