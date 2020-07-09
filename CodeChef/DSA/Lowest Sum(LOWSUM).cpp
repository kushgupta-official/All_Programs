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
    ll k=0,q=0;
    cin>>k>>q;
    std::vector<ll> a(k);
    std::vector<ll> b(k);
    rep(i,0,k){
      cin>>a[i];
    }
    rep(i,0,k){
      cin>>b[i];
    }
    priority_queue <ll> pq;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (ll i=0;i<k && i<500;i++){
      for (ll j=0;j<k && j<500;j++){
        if(pq.size()<=10000){
          pq.push(a[i]+b[j]);
        }
        else if(pq.top()>a[i]+b[j]){
            pq.pop();
            pq.push(a[i]+b[j]);
        }
      }
    }
  std::vector<ll> result(pq.size());
  for(ll i=pq.size()-1;i>=0;i--){
    result[i]=pq.top();
    pq.pop();
  }
  for (ll i=0;i<q;i++){
    int query=0;
    cin>>query;
    cout<<result[query-1]<<endl;
  }
  }
  return 0;
}