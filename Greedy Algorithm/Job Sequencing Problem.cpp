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

ll *parent;

ll find(ll s){
    if (s == parent[s]) 
        return s; 
    return parent[s] = find(parent[s]); 
} 

void merge(ll u, ll v){ 
    parent[v] = u; 
} 

bool comp(pr p1,pr p2){
	return p1.second>p2.second;
}

int main()
{
  kush_gupta();
  w(test_cases){
  	ll numberOfJobs=0,maxProfit=0;
    ll n=0;
    cin>>n;
    ll temp=0;
    vector <pair <ll,ll> > t(n);
    rep(i,0,n){
      cin>>temp;
      cin>>t[i].first>>t[i].second;
    }
    sort(t.begin(), t.end(),comp);
    // rep(i,0,n){
    //   cout<<t[i].first<<" ";
    // }
    // cout<<endl;	
    // rep(i,0,n){
    //   cout<<t[i].second<<" ";
    // }
    // cout<<endl;
    ll maxDeadline=INT_MIN;
    for(ll i=0;i<n;i++){
    	maxDeadline=max(maxDeadline,t[i].first);
    }

    parent=new ll(maxDeadline+1);

    for (ll i=0;i<=maxDeadline;i++){
    	parent[i]=i;
    }
    for (ll i = 0; i < n; i++) 
    {
        ll availableSlot = find(t[i].first);
        if (availableSlot > 0) 
        {
            merge(find(availableSlot - 1),availableSlot); 
            numberOfJobs++;
            maxProfit+=t[i].second;
        } 
    } 
    cout<<numberOfJobs<<" "<<maxProfit<<endl;
  }
  return 0;
}
