# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp> 
# include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

# define ll long long
# define ld long double
# define loop(i,a,b) for(ll i=a;i<b;i++)
# define vi vector<int>
# define vll vector<ll>
# define vvl vector<vector <ll> >
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2
# define fi first
# define se second

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void kush_gupta_solves(){
  w(t){
    ll n,k,a;
    cin>>n>>k>>a;
    vll sp(k);
    for (ll i=0;i<k;i++){
      cin>>sp[i];
    }
    vector <vector <ll> > adj(n+1);
    vector <vector <ll> > matrix(n+1,vector <ll> (n+1));
    for (ll i=1;i<n;i++){
      ll x=0,y=0;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
      matrix[x][y]=1;
      matrix[y][x]=1;
    }
    vvl dist(n+1,vector <ll> (n+1,INT_MAX));
    for (ll i=1;i<=n;i++){
      for (ll j=1;j<=n;j++){
        if (i==j) dist[i][j]=0;
        else if (matrix[i][j])
          dist[i][j]=matrix[i][j];
        else
          dist[i][j]=INT_MAX;
      }
    }
    for (ll k=1;k<=n;k++){
      for (ll i=1;i<=n;i++){
        for (ll j=1;j<=n;j++){
          // if (i==j) dist[i][j]=0;
          // else
            dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        }
      }
    }
    vll result;
    for (ll i=1;i<=n;i++){
      ll m=INT_MIN;
      ll temp=0;
      for (auto ite:sp){
        if (dist[a][ite]-dist[i][ite]>m){
          m=dist[a][ite]-dist[i][ite];
          temp=ite;
        }
      }
      cout<<m<<" ";
      result.push_back(temp);
    }
    cout<<endl;
    for (auto ite:result){
      cout<<ite<<" ";
    }
    cout<<endl;
  }
    // for ()
}

int main()
{
  #ifndef ONLINE_JUDGE
    auto __start = chrono::high_resolution_clock::now(); 
    freopen("input.txt", "r", stdin) ;
      freopen("output.txt", "w", stdout) ;
  #endif

  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  kush_gupta_solves();

  #ifndef ONLINE_JUDGE
    auto __end = chrono::high_resolution_clock::now(); 
    double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
    __time_taken *= 1e-9; 
    cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
    cout << " sec" << endl;
  #endif

  return 0;
}