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
    ll i;
    ll m=0;
    ll n=0;
    ll temp=0;
    cin>>m>>n;
    vp costs;
    vll v(m);
    rep(i,0,n){
      cin>>temp;
      if(temp<m){
        costs.push_back(pair<ll,ll> (temp,i+1));
      }
    }
    sort(costs.begin(), costs.end());
    ll a=-1,b=-1;
    ll j=costs.size()-1;
    // for (i=0;i<j;i++){
    //   a=costs[i].first;
    //   b=costs[j].first;
    //   if(a+b==m){
    //     break;
    //   }
    //   if(b>m-a){
    //     j--;
    //   }
    // }
    i=0;
    while(i<j){
      a=costs[i].first;
      b=costs[j].first;
      if(a+b==m){
        break;
      }
      else if(b>m-a){
        j--;
      }
      else{
        i++;
      }
    }
    if(costs[i].second<costs[j].second){
      cout<<costs[i].second<<" "<<costs[j].second;
    }
    else{
      cout<<costs[j].second<<" "<<costs[i].second;
    }
    cout<<endl;
  }
	return 0;
}