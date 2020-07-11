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
  std::vector<ll> fibo;
  ll a=0,b=1,temp=0;
  fibo.push_back(a);
  fibo.push_back(b);
	while(1){
    temp=b;
    b=(a+b)%10;
    a=temp;
    if(b==1 && a==0){
      fibo.pop_back();
      break;
    }
    fibo.push_back(b);
  }
  w(test_cases){
    ll n=0;
    cin>>n;
    ll pos = 0;
    while (n >>= 1) ++pos;
    ll index = ((ll)pow(2,pos) -1)%60;
    cout<<fibo[index]<<endl;
  }
	return 0;
}