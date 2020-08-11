#include<bits/stdc++.h> 
using namespace std; 
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pr pair <ll,ll>
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
struct Job 
{ 
  char id; 
  ll deadLine, profit; 
}; 
struct DisjointSet 
{ 
  ll *parent; 
  DisjointSet(ll n) 
  { 
    parent = new ll[n+1]; 

    for (ll i = 0; i <= n; i++) 
      parent[i] = i; 
  } 

  ll find(ll s) 
  { 
    if (s == parent[s]) 
      return s; 
    return parent[s] = find(parent[s]); 
  } 

  void merge(ll u, ll v) 
  { 
    parent[v] = u; 
  } 
}; 
bool cmp(Job a, Job b) 
{ 
  return (a.profit > b.profit); 
} 

ll findMaxDeadline(vector<Job> &arr, ll n) 
{ 
  ll ans = INT_MIN; 
  for (ll i = 0; i < n; i++) 
    ans = max(ans, arr[i].deadLine); 
  return ans; 
} 

void printJobScheduling(vector<Job> &arr, ll n) 
{ 
  sort(arr.begin(), arr.end(), cmp); 
  ll maxDeadline = findMaxDeadline(arr, n); 
  DisjointSet ds(maxDeadline); 
  ll profit=0,count=0;
  for (ll i = 0; i < n; i++) 
  { 
    ll availableSlot = ds.find(arr[i].deadLine); 
    if (availableSlot > 0) 
    { 
      ds.merge(ds.find(availableSlot - 1),availableSlot); 
      profit+=arr[i].profit;
      count++; 
    } 
  } 
  cout<<count<<" "<<profit<<endl;
} 

int main() 
{ 
  kush_gupta();
  w(test_cases){
    //cout<<"hi";
    ll n=0;
    cin>>n;
    std::vector<Job> t(n);
    rep(i,0,n){
      cin>>t[i].id;
      cin>>t[i].deadLine;
      cin>>t[i].profit;
    }
    printJobScheduling(t,n);
  } 
  return 0; 
} 
