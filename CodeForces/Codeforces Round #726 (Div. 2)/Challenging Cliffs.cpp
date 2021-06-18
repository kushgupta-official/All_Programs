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
    ll n;
    cin>>n;
    vll v(n);
    loop(i,0,n){
      cin>>v[i];
    }
    sort(v.begin(), v.end());
    ll min_diff=INT_MAX;
    ll x=-1;
    ll y=-1;
    loop(i,1,n){
      if (v[i]-v[i-1]<min_diff){
        min_diff=v[i]-v[i-1];
        x=i-1;
        y=i;
      }
    }
    if ((x==0 and y==1) or (x==n-2 and y==n-1)){
      cout<<v[x]<<" ";
      loop(i,0,n){
        if (i!=x and i!=y){
          cout<<v[i]<<" ";
        }
      }
      cout<<v[y];
    }
    else{
      cout<<v[x]<<" ";
      loop(i,y+1,n){
        cout<<v[i]<<" ";
      }
      loop(i,0,x){
        cout<<v[i]<<" ";
      }
      cout<<v[y];
    }
    cout<<endl;
  }
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