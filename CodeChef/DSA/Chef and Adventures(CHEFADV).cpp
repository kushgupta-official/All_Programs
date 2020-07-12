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
    ll n=0,m=0,x=0,y=0;
    cin>>n>>m>>x>>y;
    if (n-1>=0 && m-1>=0 && ((n-1)%x==0 && (m-1)%y==0)){
      cout<<"Chefirnemo\n";
    }
    else if (n-2>=0 && m-2>=0 && ((n-2)%x==0 && (m-2)%y==0)){
      cout<<"Chefirnemo\n";
    }
    else{
      cout<<"Pofik\n";
    }
  }
	return 0;
}