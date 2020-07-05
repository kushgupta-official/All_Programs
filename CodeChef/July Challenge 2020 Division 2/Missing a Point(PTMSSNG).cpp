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
    ll x=0,y=0;
    set <ll>x_axis;
    set <ll>y_axis;
    for (ll i=0;i<4*n-1;i++){
      cin>>x>>y;
      if (x_axis.find(x)!=x_axis.end()){
        x_axis.erase(x);
      }
      else{
        x_axis.insert(x);
      }
      if (y_axis.find(y)!=y_axis.end()){
        y_axis.erase(y);
      }
      else{
        y_axis.insert(y);
      }
    }
    cout<<*x_axis.begin()<<" "<<*y_axis.begin()<<endl;
  }
	return 0;
}