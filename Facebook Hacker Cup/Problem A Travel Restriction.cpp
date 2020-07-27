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

int main()
{
	kush_gupta();
  ll test_cases=0;
  cin>>test_cases;
	rep(i,0,test_cases){
    ll n=0;
    cin>>n;
    string a,b;
    cin>>a>>b;
    char t[n][n];
    memset(t,'N',sizeof(t));
    rep(i,0,n){
      rep(j,0,n){
        if(i==j){
          t[i][j]='Y';
        }
        else if(j==(i-1) || j==(i+1)){
          if(b[i]=='Y' && a[j]=='Y'){
            t[i][j]='Y';
            ll k=j;
            while(k>=0){
              k--;
              if(t[i][k]=='N' && b[k+1]=='Y' && a[k]=='Y'){
                t[i][k]='Y';
              }
              else{
                break;
              }
            }
          }
        }
        else if(t[i][j-1]=='Y' && b[j-1]=='Y' && a[j]=='Y'){
          t[i][j]='Y';
          ll k=j;
            while(k>=0){
              k--;
              if(t[i][k]=='N' && b[k+1]=='Y' && a[k]=='Y'){
                t[i][k]='Y';
              }
              else{
                break;
              }
            }
        }
      }
    }
    /*rep(i,0,n){
      t[i][i]='Y';
      if(i!=0 && b[i]=='Y' && a[i-1]=='Y'){
        t[i][i-1]='Y';
      }
      if(i!=(n-1) && b[i]=='Y' && a[i+1]=='Y'){
        t[i][i+1]='Y';
      }
    }*/
    cout<<"Case #"<<i+1<<":\n";
    rep(i,0,n){
      rep(j,0,n){
        cout<<t[i][j];
      }
      cout<<endl;
    }
    /*rep(i,1,n+1){
      ll j=i-1;
      t[i][i]='Y';
      if(j!=0 && b[j-1]=='Y' && a[j-1]=='Y'){
        t[i][i-1]='Y';
      }
      if(j!=(n-1) && b[j+1]=='Y' && a[j+1]=='Y'){
        t[i][i+1]='Y';
      } 
    }
    cout<<"Case #"<<i+1<<":\n";
    rep(i,1,n+1){
      rep(j,1,n+1){
        cout<<t[i][j];
      }
      cout<<endl;
    }*/
  }
	return 0;
}