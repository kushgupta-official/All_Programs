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
    vll a(n);
    rep(i,0,n){
      cin>>a[i];
    }
    ll temp=0,i=0,j=0,rounds=0;
    for (i=0;i<n;i++){
      temp=k;
      if(a[i]<=temp){
        temp-=a[i];
        rounds++;
      //  cout<<temp<<endl;
      }
      else{
        break;
      }
      for (j=i+1;j<n;j++){
        if(a[j]<=temp){
          temp-=a[j];
          i=j;
        //  cout<<temp<<endl;
        }
        else{
          j=n;
        }
      }
    //  cout<<temp<<" ";
    }
    if(rounds==0 || i<n-1){
    //  cout<<i<<" "<<-1<<endl;
      cout<<-1<<endl;
    }
    else{
      cout<<rounds<<endl;
    }
  }
	return 0;
}
/*4
4 4
4 3 2 1
4 8
7 8 9 10
10 10
1 2 3 4 5 6 7 8 9 10
4 8
1 4 8 7*/