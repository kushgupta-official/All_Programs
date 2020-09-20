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
	w(t){
    ll n,k,l;
    cin>>n>>k>>l;
    std::vector<ll> players(k+1,l);
    std::vector<ll> result;
    ll i=0;
    ll temp=n;
    ll prev=0;
    while (n--){
      prev=i;
      i++;
      if (i==k+1){
        i=1;
      }
      if (players[i]!=0 && prev!=i){
        players[i]--;
      }
      else{
        break;
      }
      result.push_back(i);
    }
    if (result.size()!=temp){
      cout<<-1<<endl;
    }
    else{
      rep(i,0,result.size()){
        cout<<result[i]<<" ";
      }
      cout<<endl;
    }
  }
	return 0;
}